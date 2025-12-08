/*
Zadaca 3: Generirati proizvoljnu matricu. Distribuirati pojedini redak pojedinom računalu(procesu). Formirati donju trokutastu matricu sa ispisom naziva računala(procesa) koji je ispisao pojedini redak. Program napisati korištenjem C++ funkcija.

Leo Petrović 695/RM
*/

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  // dohvacanje imena racunala
  char ime_racunala[MPI::MAX_PROCESSOR_NAME];
  int duzina_ime = 0;
  MPI::Get_processor_name(ime_racunala, duzina_ime);

  if (rang == 0)
  {
    // root generira matricu - koristi se flat kvadratna matrica iste velicine kao broj procesa u komunikatoru
    vector<int> matrica(velicina * velicina);

    // generiranje random brojeva (0-9)
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

    // slanje svakog retka odgovarajućem procesu - ukljucuje i root proces
    for (int i = 0; i < velicina; i++)
    {
      MPI::COMM_WORLD.Send(&matrica[i * velicina], velicina, MPI::INT, i, 0);
    }
  }

  // svaki proces ce primiti jedan red matrice - lista brojeva
  // matrica se pretpostavlja da ima m redova, gdje je m broj procesa u komunikatoru (inace bi postojali procesi koji ne mogu nijedan red uzeti pa ne bi nista uradili)
  vector<int> red(velicina);

  MPI::COMM_WORLD.Recv(red.data(), velicina, MPI::INT, 0, 0);

  for (int turn = 0; turn < velicina; ++turn)
  {
    if (rang == turn)
    {
      // ispis donjeg trokuta
      cout << "Redak od procesa " << rang << " na racunalu " << ime_racunala << " je: ";
      for (int j = 0; j <= rang; ++j)
        cout << red[j] << " ";
      cout << endl
           << flush;
    }

    // radi ljepseg ispisa, cekamo da procesi zavrse u pravilnom redoslijedu
    MPI::COMM_WORLD.Barrier();
  }

  MPI::Finalize();
  return 0;
}