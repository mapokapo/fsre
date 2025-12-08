/*
Zadaca 6: Napišite program u kojem će svi procesi generirati jedan nasumičan broj, nakon čega će jedan od procesa načiniti aritmetičku sumu brojeva svih procesa koristeći operaciju redukcije, te će dobivenu aritmetičku srednju vrijednost poslati svim ostalim procesima. Procesi će nakon toga izračunati odstupanje u postocima u odnosu na dobivenu srednju vrijednost. Koristite isključivo kolektivnu komunikaciju. Program napisati korištenjem C++ funkcija.

Leo Petrović 695/RM
*/

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  // inicijalizacija generatora slucajnih brojeva
  srand(time(0) + rang);

  // generiramo nasumicni broj izmedu 1 i 100
  double rand_number = rand() % 100 + 1;

  // smjestamo sve brojeve u sumu koristeci redukciju (operacija MPI::SUM)
  double suma = 0.0;
  MPI::COMM_WORLD.Reduce(&rand_number, &suma, 1, MPI::DOUBLE, MPI::SUM, 0);

  // racunamo srednju vrijednost na root procesu
  double sredina = 0.0;
  if (rang == 0)
  {
    sredina = suma / velicina;
  }

  // saljemo srednju vrijednost svim procesima
  MPI::COMM_WORLD.Bcast(&sredina, 1, MPI::DOUBLE, 0);

  // svaki proces racuna svoje odstupanje u postocima u odnosu na srednju vrijednost
  double odstupanje = fabs(rand_number - sredina) / sredina * 100.0;

  cout << "Proces " << rang << ": izabrani broj = " << rand_number
       << ", sredina = " << sredina
       << ", odstupanje = " << odstupanje << "%" << endl;

  MPI::Finalize();
  return 0;
}