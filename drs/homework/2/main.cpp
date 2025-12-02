#include <iostream>
#include <mpi.h>

using namespace std;

#define SIZE 100

/*
Zadaca 2: Napišite program korištenjem C++ funkcija u kojem će jedan proces poslati vektor od 100 elemenata svim ostalim procesima, nakon čega će svaki proces vratiti taj vektor procesu pošiljatelju, ali uvećan za N+1, gdje je N broj procesa. Pripazite na količinu vraćenih podataka!

Objasnjeno:
- root process salje niz od 100 elemenata (svi elementi su 0) svim ostalim procesima (njih 99)
- svaki process primi niz, uvecava svaki element za N+1 (N je rang tog procesa), i salje nazad root procesu
- root process prima nizove od svih ostalih procesa i ispisuje elemente svakog procesa
- niz unutar svakog procesa ce imati istih 100 elemenata, i oni ce biti jednaki rangu tog procesa (npr. proces 70 ce imati niz od 100 brojeva, gdje je svaki broj 71)

mpic++ main.cpp
mpirun -np 100 --oversubscribe ./a.out

Leo Petrović 695/RM
*/

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();
  int niz[SIZE];

  // Proces nula ("root process") inicijalizira niz od 100 elemenata ispunjen brojem 0
  if (rang == 0)
  {
    for (int i = 0; i < SIZE; i++)
    {
      niz[i] = 0;
    }
  }

  // Root proces salje niz svim ostalim procesima (njih 99)
  // Ovim pozivom se ujedno i primi taj niz u non-root procesima
  MPI::COMM_WORLD.Bcast(niz, SIZE, MPI_INT, 0);

  // Ulazna grana za non-root procese
  if (rang != 0)
  {
    for (int i = 0; i < SIZE; i++)
    {
      // Svaki element niza se uveca za N + 1, gdje je N rang trenutnog procesa
      // npr. ako je trenutni rang procesa 1, onda ce niz biti popunjen brojem 2
      niz[i] += rang + 1;
    }

    // Modificirani niz se posalje root procesu
    MPI::COMM_WORLD.Send(niz, SIZE, MPI_INT, 0, 0);
  }
  // Ulazna grana za root proces
  else
  {
    // Alociranje memorije za primljene nizove
    // Svaki niz ima 100 elemenata, i root proces ce primiti od svakog procesa po jedan niz
    // npr. ako je broj procesa u komunikatoru 100, onda ce biti 99 nizova po 100 elemenata
    int *gathered = new int[(velicina - 1) * SIZE];

    for (int i = 1; i < velicina; i++)
    {
      // Memorijski prostor za niz od 100 elemenata od nekog non-root procesa (rang od 1 do 100, ukljucivo)
      int *buf = &gathered[(i - 1) * SIZE];

      // Root proces prima niz za trenutni proces
      MPI::COMM_WORLD.Recv(buf, SIZE, MPI_INT, i, 0);

      // Ispis
      cout << "Prvih i zadnjih 5 elemenata procesa " << i << ":";
      for (int j = 0; j < 5; j++)
      {
        cout << " " << buf[j];
      }
      cout << " ...";
      for (int j = SIZE - 5; j < SIZE; j++)
      {
        cout << " " << buf[j];
      }
      cout << endl;
    }

    // Ciscenje memorije
    delete[] gathered;
  }

  MPI::Finalize();

  return 0;
}