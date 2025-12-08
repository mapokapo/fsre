/*
Zadaca 9: Razmak između uzastopnih prostih brojeva 2 i 3 je samo 1, dok je razmak između uzastopnih prostih brojeva 7 i 11 jednak 4. Napiši paralelni program za određivanje svih cijelih brojeva manjih od 1.000.000, sa najvećim razmakom između para uzastopnih prostih brojeva. Napišite program koji će izvršiti naveden postupak u C++ programskom jeziku.

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

  int n = 1000000;
  // npr. ako imamo 5 procesa, onda ce proces 0 obraditi brojeve 1-200.000, proces 1 brojeve 200.001-400.000, itd., proces 4 brojeve 800.001 - 1.000.000
  int start = rang * (n / velicina) + 1;
  int kraj = (rang == velicina - 1) ? n : (rang + 1) * (n / velicina);

  // svaki proces obraduje svoj skup brojeva (provjerava je li prost)
  vector<int> prosti;
  for (int i = start; i <= kraj; i++)
  {
    bool je_prost = true;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        je_prost = false;
        break;
      }
    }
    if (je_prost)
    {
      prosti.push_back(i);
    }
  }

  // koristeci proste brojeve u svojem skupu, svaki proces trazi par indeksa brojeva koji cine najveci razmak
  int najbolji[4] = {0, -1, -1, rang}; // razmak, indeks prvog broja, indeks drugog broja, rang procesa

  for (size_t i = 1; i < prosti.size(); i++)
  {
    int razmak = prosti[i] - prosti[i - 1];
    if (razmak > najbolji[0])
    {
      najbolji[0] = razmak;
      najbolji[1] = prosti[i - 1];
      najbolji[2] = prosti[i];
    }
  }

  // sada svaki proces salje svoj rezultat procesu 0
  vector<int> svi;
  if (rang == 0)
    svi.resize(4 * velicina);

  MPI::COMM_WORLD.Gather(najbolji, 4, MPI::INT,
                         rang == 0 ? svi.data() : nullptr, 4, MPI::INT,
                         0);

  // proces 0 ispisuje rezultat
  if (rang == 0)
  {
    int razmak_max = -1, p1 = -1, p2 = -1, pobjednik = -1;
    for (int i = 0; i < velicina; ++i)
    {
      int r = svi[i * 4];
      if (r > razmak_max)
      {
        razmak_max = r;
        p1 = svi[i * 4 + 1];
        p2 = svi[i * 4 + 2];
        pobjednik = svi[i * 4 + 3];
      }
    }
    cout << "Najveci razmak iznosi: " << razmak_max << "\n"
         << "Izmedu brojeva: " << p1 << " i " << p2
         << " koje je pronasao proces " << pobjednik << endl;
  }

  MPI::Finalize();
  return 0;
}