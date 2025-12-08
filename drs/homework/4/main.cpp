/*
Zadaca 4: Uporabom MPI-a izraditi simulaciju raspodijeljenog problema n filozofa. Pri svakoj promjeni program mora vizualno prikazati za sve filozofe što oni rade. Npr. kada filozof 4 ide jesti, tada treba ispis izgledati otprilike ovako:
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

  // N = broj filozofa (1 proces mora biti "server")
  int N = velicina - 1;

  if (rang == 0)
  // ulazna grana za root proces ("server")
  {
    // server kontrolira vilice - true znaci da je vilica slobodna
    vector<bool> vilica(N, true);
    // stanje svakog filozofa - pocetno stanje je MISLI
    vector<int> stanje(N, MISLI);

    while (true)
    {
      vector<int> before = stanje;

      // server primi zahtjev od bilo kojeg procesa/filozofa
      // zahtjev se sastoji od ranga procesa/filozofa i akcije koje zeli postici (trazi vilice, zavrsio jesti)
      MPI::Status status;
      int zahtjev[2];
      MPI::COMM_WORLD.Recv(zahtjev, 2, MPI::INT, MPI_ANY_SOURCE, 0, status);

      int filozof = zahtjev[0];
      int akcija = zahtjev[1];

      int L = filozof;           // lijeva vilica
      int D = (filozof + 1) % N; // desna vilica - modulo N jer je stol okrugao

      // filozof trazi vilice
      if (akcija == 1)
      {
        stanje[filozof] = CEKA;

        // ako su vilice slobodne, dodijeli ih filozofu
        if (vilica[L] && vilica[D])
        {
          // oznaci vilice kao zauzete
          vilica[L] = vilica[D] = false;
          stanje[filozof] = JEDE;
          // server salje filozofu potvrdu da moze jesti
          MPI::COMM_WORLD.Send(&akcija, 1, MPI::INT, filozof + 1, 0);
        }
        else
        {
          // vilice zauzete, server salje filozofu da saceka
          int wait = 0;
          MPI::COMM_WORLD.Send(&wait, 1, MPI::INT, filozof + 1, 0);
        }
      }
      // filozof zavrsio jesti
      else if (akcija == 2)
      {
        // oslobodi vilice
        vilica[L] = vilica[D] = true;
        stanje[filozof] = MISLI;
      }

      // ispisi stanje samo ako se dogodila promjena
      if (before != stanje)
      {
        ispisi_stanja(stanje);
      }
    }
  }
  else
  // ulazna grana za obicne procese (filozofe)
  {
    // posto je rang 0 zauzeo server, svaki filozof ima rang od 1 do N, pa oduzmemo 1 da dobijemo indeks (0 do N-1)
    int id = rang - 1;

    while (true)
    {
      // misli - simuliraj spavanjem
      sleep(1);

      // salje serveru zahtjev za vilice (akcija 1)
      int zahtjev[2] = {id, 1};
      MPI::COMM_WORLD.Send(zahtjev, 2, MPI::INT, 0, 0);

      // server odgovara je li moze jesti ili mora sacekati
      int odgovor;
      MPI::COMM_WORLD.Recv(&odgovor, 1, MPI::INT, 0, 0);

      // server odgovorio da su vilice zauzete
      while (odgovor == 0)
      {
        // filozof ceka neko vrijeme prije ponovnog slanja zahtjeva
        sleep(1);
        MPI::COMM_WORLD.Send(zahtjev, 2, MPI::INT, 0, 0);
        MPI::COMM_WORLD.Recv(&odgovor, 1, MPI::INT, 0, 0);
      }

      // jede - simuliraj spavanjem
      sleep(1);

      // salje serveru obavijest da je zavrsio jesti (akcija 2)
      int zavrsi[2] = {id, 2};
      MPI::COMM_WORLD.Send(zavrsi, 2, MPI::INT, 0, 0);
    }
  }

  MPI::Finalize();
  return 0;
}