/*
Zadaca 4: Generirati proizvoljnu matricu. Distribuirati pojedini redak pojedinom računalu(procesu). Formirati donju trokutastu matricu sa ispisom naziva računala(procesa) koji je ispisao pojedini redak. Program napisati korištenjem C++ funkcija.

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

  char ime_racunala[MPI::MAX_PROCESSOR_NAME];
  int duzina_ime = 0;

  MPI::Get_processor_name(ime_racunala, duzina_ime);

  vector<int> red(velicina); // svaki proces prima jedan red matrice

  if (rang == 0)
  {
    // root generira matricu
    vector<int> matrica(velicina * velicina);

    // generiranje brojeva
    for (int i = 0; i < velicina * velicina; i++)
      matrica[i] = rand() % 10;

    // ispis matrice
    cout << "Generirana matrica:" << endl;
    for (int i = 0; i < velicina; i++)
    {
      for (int j = 0; j < velicina; j++)
        cout << matrica[i * velicina + j] << " ";
      cout << endl;
    }
    cout << endl;

    // slanje svakog retka odgovarajućem procesu
    for (int i = 0; i < velicina; i++)
    {
      MPI::COMM_WORLD.Send(&matrica[i * velicina], velicina, MPI::INT, i, 0);
    }
  }

  // svi procesi primaju svoj redak
  MPI::COMM_WORLD.Recv(red.data(), velicina, MPI::INT, 0, 0);

  // ispis donjeg trokuta
  cout << "Redak od procesa " << rang << " na racunalu " << ime_racunala << " je: ";
  for (int j = 0; j <= rang; j++)
    cout << red[j] << " ";
  cout << endl;

  MPI::Finalize();
  return 0;
}