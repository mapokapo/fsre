/*
Zadaca 6: Napišite program korištenjem C++ funkcija u kojem će svi procesi učitati podatke iz proizvoljne datoteke, sinkronizirati se na barijeri, te zatim ispisati učitane elemente, i to na način da proces 0 ispiše prvi, proces 1 drugi, itd. Program mora biti moguće izvršiti na proizvoljnom broju procesora bez gubitka funkcionalnosti.

Leo Petrović 695/RM
*/

#include <iostream>
#include <fstream>
#include <mpi.h>
#include <vector>

using namespace std;

vector<int> ucitaj_podatke(const string &filename)
{
  vector<int> podatci;
  ifstream file(filename);
  if (!file)
  {
    cerr << "Ne mogu otvoriti datoteku " << filename << endl;
    MPI::COMM_WORLD.Abort(1);
  }
  int x;
  while (file >> x)
  {
    podatci.push_back(x);
  }
  return podatci;
}

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  string ime_datoteke = "podatci.txt";
  vector<int> podatci = ucitaj_podatke(ime_datoteke);

  // svi procesi cekaju da zavrse ucitavanje
  MPI::COMM_WORLD.Barrier();

  // ispis podataka
  for (int i = 0; i < velicina; i++)
  {
    if (rang == i)
    {
      cout << "Proces " << rang << " je učitao podatke: ";
      int max_index = min((int)podatci.size(), rang + 1);
      for (int j = 0; j < max_index; ++j)
      {
        cout << podatci[j] << " ";
      }
      cout << endl;
    }
    MPI::COMM_WORLD.Barrier();
  }

  MPI::Finalize();
  return 0;
}