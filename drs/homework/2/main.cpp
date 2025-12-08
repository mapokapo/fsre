/*
Zadaca 1: Za slanje ranga procesa 0 upotrijebljen je MPI::Comm.Bcast svim procesima unutar komunikatora. Nakon primitka procesi vraćaju procesu 0 naziv računala koje je primilo poruku. Proces 0 prima poruku od ostalih procesa MPI::Comm.Irecv. Ispisati na zaslon da su primljene poruke na strani procesa 0. Program napisati korištenjem C++ funkcija.

Leo Petrović 695/RM
*/

#include <iostream>
#include <mpi.h>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  // root proces salje svoj rang svim ostalim procesima
  // rang root procesa se mora definirati kao nova varijabla jer ce se u nju spremiti vrijednost u svim non-root procesima
  int root_rank = 0;
  MPI::COMM_WORLD.Bcast(&root_rank, 1, MPI::INT, 0);

  // dohvacanje imena racunala
  char ime_racunala[MPI::MAX_PROCESSOR_NAME];
  int duzina_ime = 0;
  MPI::Get_processor_name(ime_racunala, duzina_ime);

  if (rang != 0)
  // ulazna grana za obicne procese
  {
    // proces salje ime racunala nazad root procesu
    MPI::COMM_WORLD.Send(ime_racunala, duzina_ime, MPI::CHAR, 0, 0);
  }
  else
  // ulazna grana za root proces
  {
    // root proces prima imena racunala od svih ostalih procesa
    vector<string> imena(velicina);
    vector<MPI::Request> requests(velicina);

    // mora ici od 1-velicina umjesto od 0-velicina jer je 0 root proces, pozivanje Irecv bi tada napravilo beskonacnu petlju
    for (int i = 1; i < velicina; i++)
    {
      imena[i].resize(MPI::MAX_PROCESSOR_NAME);
      requests[i] = MPI::COMM_WORLD.Irecv(imena[i].data(),
                                          imena[i].size(),
                                          MPI::CHAR,
                                          i,
                                          0);
    }

    // root proces mora sacekati sve zahtjeve da zavrse prije nego sto se mogu ispisati
    MPI::Request::Waitall(velicina - 1, &requests[1]);

    // mora ici od 1-velicina umjesto od 0-velicina jer je 0 root proces
    for (int i = 1; i < velicina; i++)
    {
      cout << "Proces 0 je primio poruku od procesa " << i
           << " sa racunala: " << imena[i].data() << endl;
    }
  }

  MPI::Finalize();
  return 0;
}