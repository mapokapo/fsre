/*
Zadaca 5: Uporabom MPI-a izraditi simulaciju raspodijeljenog problema n filozofa. Pri svakoj promjeni program mora vizualno prikazati za sve filozofe što oni rade. Npr. kada filozof 4 ide jesti, tada treba ispis izgledati otprilike ovako:
"Stanje filozofa: X o O X o" (X-jede, O-razmišlja, o-čeka na vilice).

Problem pet filozofa: filozofi obavljaju samo dvije različite aktivnosti: misle ili jedu. To rade na poseban način. Na jednom okruglom stolu nalazi se pet tanjura te pet štapića (između svaka dva tanjura po jedan). Filozof prilazi stolu, uzima lijevi štapić, pa desni te jede. Zatim vraća štapiće na stol i odlazi misliti.

Program napisati korištenjem C++ funkcija.

Leo Petrović 695/RM
*/

#include <iostream>
#include <mpi.h>
#include <vector>
#include <unistd.h>

using namespace std;

enum Stanje
{
  MISLI = 0,
  CEKA = 1,
  JEDE = 2
};

void ispisi_stanja(const vector<int> &stanje)
{
  cout << "Stanje filozofa: ";
  for (int s : stanje)
  {
    if (s == JEDE)
      cout << "X ";
    else if (s == CEKA)
      cout << "o ";
    else
      cout << "O ";
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  int N = velicina - 1; // broj filozofa

  if (rang == 0)
  {
    // root kontrolira vilice
    vector<bool> vilica(N, true); // sve vilice slobodne
    vector<int> stanje(N, MISLI);

    while (true)
    {
      MPI::Status status;
      int zahtjev[2];
      MPI::COMM_WORLD.Recv(zahtjev, 2, MPI::INT, MPI_ANY_SOURCE, 0, status);

      int filozof = zahtjev[0];
      int akcija = zahtjev[1];

      int L = filozof;           // lijeva vilica
      int D = (filozof + 1) % N; // desna vilica

      if (akcija == 1) // filozof trazi vilice
      {
        stanje[filozof] = CEKA;
        ispisi_stanja(stanje);

        if (vilica[L] && vilica[D])
        {
          vilica[L] = vilica[D] = false;
          stanje[filozof] = JEDE;
          MPI::COMM_WORLD.Send(&akcija, 1, MPI::INT, filozof + 1, 0);
        }
        else
        {
          int wait = 0;
          MPI::COMM_WORLD.Send(&wait, 1, MPI::INT, filozof + 1, 0);
        }

        ispisi_stanja(stanje);
      }
      else if (akcija == 2) // filozof zavrsio jesti
      {
        vilica[L] = vilica[D] = true;
        stanje[filozof] = MISLI;
        ispisi_stanja(stanje);
      }
    }
  }
  else
  {
    // FILOZOF proces
    int id = rang - 1;

    while (true)
    {
      sleep(1); // misli

      // salje serveru zahtjev za vilice
      int zahtjev[2] = {id, 1};
      MPI::COMM_WORLD.Send(zahtjev, 2, MPI::INT, 0, 0);

      int odgovor;
      MPI::COMM_WORLD.Recv(&odgovor, 1, MPI::INT, 0, 0);

      while (odgovor == 0) // vilice zauzete
      {
        sleep(1);
        MPI::COMM_WORLD.Send(zahtjev, 2, MPI::INT, 0, 0);
        MPI::COMM_WORLD.Recv(&odgovor, 1, MPI::INT, 0, 0);
      }

      sleep(1); // jede

      int zavrsi[2] = {id, 2};
      MPI::COMM_WORLD.Send(zavrsi, 2, MPI::INT, 0, 0);
    }
  }

  MPI::Finalize();
  return 0;
}