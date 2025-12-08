/*
Zadaca 1: Napišite program korištenjem C++ funkcija u kojem će jedan proces poslati vektor od 100 elemenata svim ostalim procesima, nakon čega će svaki proces vratiti taj vektor procesu pošiljatelju, ali uvećan za N+1, gdje je N broj procesa. Pripazite na količinu vraćenih podataka!

Leo Petrović 695/RM
*/

#include <iostream>
#include <mpi.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  // vektor sa kapacitetom 100
  vector<int> brojevi(100);

  // root ispuni vektor sa brojevima 0-99
  if (rang == 0)
  {
    for (int i = 0; i < 100; i++)
    {
      brojevi[i] = i;
    }
  }

  // root salje vektor svim procesima
  MPI::COMM_WORLD.Bcast(brojevi.data(), brojevi.size(), MPI_INT, 0);

  if (rang != 0)
  // ulazna grana za obicne procese
  {
    // proces dodaje svoj rang na kraj primljenog vektora
    brojevi.push_back(rang);

    // modificirani vektor se salje nazad root procesu
    MPI::COMM_WORLD.Send(brojevi.data(), brojevi.size(), MPI_INT, 0, 0);
  }
  else
  // ulazna grana za root proces
  {
    // kapacitet je 101 jer svaki proces doda svoj rang na kraj
    vector<int> primljeni_brojevi(101);

    // mora ici od 1-velicina umjesto od 0-velicina jer je 0 root proces, pozivanje Recv bi tada napravilo beskonacnu petlju
    for (int i = 1; i < velicina; i++)
    {
      // root proces prima vektor od procesa sa rangom i
      MPI::COMM_WORLD.Recv(primljeni_brojevi.data(), primljeni_brojevi.size(), MPI_INT, i, 0);

      // ispis
      cout << "Prvih i zadnjih 5 elemenata procesa " << i << ":";
      for (int j = 0; j < 5; j++)
      {
        cout << " " << primljeni_brojevi[j];
      }
      cout << " ...";
      for (int j = primljeni_brojevi.size() - 5; j < primljeni_brojevi.size(); j++)
      {
        cout << " " << primljeni_brojevi[j];
      }
      cout << endl;
    }
  }

  MPI::Finalize();
  return 0;
}