/*
Zadaca 3: Za slanje ranga procesa 0 upotrijebljen je MPI::Comm.Bcast svim procesima unutar komunikatora. Nakon primitka procesi vraćaju procesu 0 naziv računala koje je primilo poruku. Proces 0 prima poruku od ostalih procesa MPI::Comm.Irecv. Ispisati na zaslon da su primljene poruke na strani procesa 0. Program napisati korištenjem C++ funkcija.

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

  // Root proces salje svoj rang svim ostalim procesima
  int root_rank = 0;
  MPI::COMM_WORLD.Bcast(&root_rank, 1, MPI::INT, 0);

  MPI::Get_processor_name(ime_racunala, duzina_ime);

  // Non-root procesi salju ime racunala nazad root procesu
  if (rang != 0)
  {
    MPI::COMM_WORLD.Send(ime_racunala, duzina_ime, MPI::CHAR, 0, 0);
  }
  // Root proces prima imena racunala od svih ostalih procesa
  else
  {
    vector<vector<char>> buffers(velicina);
    vector<MPI::Request> requests(velicina);

    for (int i = 1; i < velicina; i++)
    {
      buffers[i].resize(MPI::MAX_PROCESSOR_NAME);
      requests[i] = MPI::COMM_WORLD.Irecv(buffers[i].data(),
                                          MPI::MAX_PROCESSOR_NAME,
                                          MPI::CHAR,
                                          i,
                                          0);
    }

    MPI::Request::Waitall(velicina - 1, &requests[1]);

    for (int i = 1; i < velicina; i++)
    {
      buffers[i][MPI::MAX_PROCESSOR_NAME - 1] = '\0';
      cout << "Proces 0 je primio poruku od procesa " << i
           << " sa racunala: " << buffers[i].data() << endl;
    }
  }

  MPI::Finalize();
  return 0;
}