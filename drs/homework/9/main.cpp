/*
Zadaca 9: Svaki procesor ima niz podataka od 100 elemenata (vektor). Svaki od tih lokalnih vektora je dio jednog većeg, globalnog. Potrebno je
izračunati srednju vrijednost svih elemenata u globalnom vektoru. Preferirani postupak jest taj, da se podaci daju matičnom procesu pomoću MPI::Comm.Gather funkcije, zbroje elementi dobivenog vektora, podijele s ukupnim brojem elemenata i rezultat se pošalje svim procesima. Napišite program koji će izvršiti naveden postupak u C++ programskom jeziku.

Leo Petrović 695/RM
*/

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  srand(static_cast<unsigned>(time(0)) + rang);

  vector<int> elementi(100, 0);
  for (int i = 0; i < 100; i++)
  {
    elementi[i] = rand() % 100;
  }

  vector<int> globalniElementi;
  if (rang == 0)
  {
    globalniElementi.resize(velicina * 100, 0);
  }

  MPI::COMM_WORLD.Gather(elementi.data(), 100, MPI::INT,
                         globalniElementi.data(), 100, MPI::INT,
                         0);

  if (rang == 0)
  {
    cout << "Root proces je prikupio vrijednosti: " << endl;
    for (int i = 1; i < velicina; i++)
    {
      cout << "Proces " << i << ": ";
      for (int j = 0; j < 100; j++)
      {
        cout << globalniElementi[i * 100 + j] << " ";
      }
      cout << endl;
    }
  }

  if (rang == 0)
  {
    for (int i = 1; i < velicina; i++)
    {
      int sum = 0;
      for (int j = 0; j < 100; j++)
      {
        sum += globalniElementi[i * 100 + j];
      }
      double avg = sum / 100.0;

      MPI::COMM_WORLD.Send(&avg, 1, MPI::DOUBLE, i, 0);
    }
  }
  else
  {
    double avg = 0;
    MPI::COMM_WORLD.Recv(&avg, 1, MPI::DOUBLE, 0, 0);

    cout << "Proces " << rang << " - Srednja vrijednost: " << avg << endl;
  }

  MPI::Finalize();
  return 0;
}