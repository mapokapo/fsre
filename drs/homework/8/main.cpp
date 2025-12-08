/*
Zadaca 8: Treba napraviti Kvazi šahovsku igru. Igra se odvija na kvadratnoj ploči dimenzija 𝑚 × 𝑚. U igri sudjeluju tri vrste figura: top, lovac i pijun. Top se kreće kao i u standardnoj šahovskoj igri, tj. vertikalno ili horizontalno za proizvoljan broj mjesta. Lovcu je dozvoljena kretnja samo po jedno mjesto dijagonalno od mjesta na kome se trenutno nalazi, a pijunu samo po jedno mjesto vertikalno ili horizontalno. Top je jači od lovca, lovac je jači od pijuna, a pijun je jači od topa. Kada se dvije različite figure nađu na istom polju, ostaje ona koja je jača.

Ukoliko neka figura odigra na polje gdje se već nalazi figura istog tipa, ta figura jede dolazeću figuru, tj. uzima se da je jača jer brani svoju teritoriju. Figure se proizvoljno kreću po ploči u ovisnosti od svog tipa, i ne mogu odigrati potez izvan ploče. Ukoliko figura ipak izabere da se kreće izvan ploče, ostaje u mjestu. Igra se završava kada na ploči ostane jedna figura, i ta figura je označena kao pobjednik. Program napisati korištenjem C++ funkcija.

U MPI programu prvo kreirati strukture:
Figura:
- int id – id figure,
- int x – globalna x koordinata figure,
- int y – globalna y koordinata figure,
- int tip – tip figure, 0-top, 1-lovac, 2-pijun,
- int brojPojedenih – koliko je figura pojela drugih figura,
- int brojPoteza – broj odigranih poteza figure

Polje:
- int id – id figure koja se nalazi na polju (-1 označava da je polje prazno),
- int tip – tip figure koja se nalazi na danom polju.

Učitati dimenziju ploče m. Smatrati da je m djeljivo brojem procesa. Učitati i broj figura na svakom procesu. Inicijalno, svaki proces treba postaviti sve figure na dijelu ploče za koji je zadužen, vodeći računa o tome da se na jednom polju može naći samo jedna figura. Koordinate x i y figure su globalne. U svakom koraku igre svaka figura odigra po jedan potez sve dok se igra ne završi, odnosno dok ne ostane jedna figura na ploči. Ispisati koja je figura pobjednik i koliko je ta figura pojela drugih figura.

Leo Petrović 695/RM
*/

#include <iostream>
#include <mpi.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Figura
{
  int id;
  int x;
  int y;
  int tip; // 0-top, 1-lovac, 2-pijun
  int brojPojedenih;
  int brojPoteza;
};

struct Polje
{
  int id;  // id figure na polju, -1 ako je prazno
  int tip; // tip figure na polju
};

bool isStronger(int attacker, int victim)
{
  return (attacker == 0 && victim == 1) || // top > lovac
         (attacker == 1 && victim == 2) || // lovac > pijun
         (attacker == 2 && victim == 0);   // pijun > top
}

void pomjeriFiguru(Figura &f, int m)
{
  int nx = f.x;
  int ny = f.y;
  int smjer = rand() % 4;

  if (f.tip == 0)
  { // top - horizontalno ili vertikalno
    int korak = rand() % m + 1;
    switch (smjer)
    {
    case 0:
      nx -= korak;
      break;
    case 1:
      nx += korak;
      break;
    case 2:
      ny -= korak;
      break;
    default:
      ny += korak;
      break;
    }
  }
  else if (f.tip == 1)
  { // lovac - dijagonalno za jedno mjesto
    switch (smjer)
    {
    case 0:
      nx--;
      ny--;
      break;
    case 1:
      nx--;
      ny++;
      break;
    case 2:
      nx++;
      ny--;
      break;
    default:
      nx++;
      ny++;
      break;
    }
  }
  else
  { // pijun - vertikalno ili horizontalno za jedno mjesto
    switch (smjer)
    {
    case 0:
      nx--;
      break;
    case 1:
      nx++;
      break;
    case 2:
      ny--;
      break;
    default:
      ny++;
      break;
    }
  }

  if (nx >= 0 && nx < m && ny >= 0 && ny < m)
  {
    f.x = nx;
    f.y = ny;
  }
  f.brojPoteza++; // potez se broji i ako figura ostane na mjestu
}

vector<Figura> razrijesiSukobe(const vector<Figura> &ulaz, int m)
{
  vector<Figura> prezivjeli;
  prezivjeli.reserve(ulaz.size());
  unordered_map<int, int> pozicije; // key = x*m + y

  for (const auto &f : ulaz)
  {
    if (f.x < 0 || f.x >= m || f.y < 0 || f.y >= m)
      continue;

    int key = f.x * m + f.y;
    auto it = pozicije.find(key);
    if (it == pozicije.end())
    {
      prezivjeli.push_back(f);
      pozicije[key] = static_cast<int>(prezivjeli.size()) - 1;
    }
    else
    {
      Figura &trenutna = prezivjeli[it->second];
      if (trenutna.tip == f.tip || isStronger(trenutna.tip, f.tip))
      {
        trenutna.brojPojedenih++;
      }
      else
      {
        Figura pobjednik = f;
        pobjednik.brojPojedenih += 1;
        prezivjeli[it->second] = pobjednik;
      }
    }
  }
  return prezivjeli;
}

int main(int argc, char *argv[])
{
  MPI::Init(argc, argv);

  int rang = MPI::COMM_WORLD.Get_rank();
  int velicina = MPI::COMM_WORLD.Get_size();

  srand(static_cast<unsigned>(time(0)) + rang);

  int m = 0;
  vector<int> brojFiguraPoProcesu(velicina, 0);

  if (rang == 0)
  {
    cout << "Unesite dimenziju ploce m: ";
    cin >> m;
    if (m % velicina != 0)
    {
      cerr << "Dimenzija m mora biti djeljiva s brojem procesa." << endl;
      MPI::COMM_WORLD.Abort(1);
    }

    cout << "Unesite broj figura za svaki proces (" << velicina << " vrijednosti): ";
    for (int i = 0; i < velicina; ++i)
    {
      cin >> brojFiguraPoProcesu[i];
    }
  }

  MPI::COMM_WORLD.Bcast(&m, 1, MPI::INT, 0);
  MPI::COMM_WORLD.Bcast(brojFiguraPoProcesu.data(), velicina, MPI::INT, 0);

  if (m % velicina != 0)
  {
    MPI::COMM_WORLD.Abort(1);
  }

  int redakaPoProcesu = m / velicina;
  int pocetakReda = rang * redakaPoProcesu;

  vector<Polje> lokalnoPolje(redakaPoProcesu * m, {-1, -1});
  vector<Figura> lokalneFigure;
  lokalneFigure.reserve(brojFiguraPoProcesu[rang]);

  for (int i = 0; i < brojFiguraPoProcesu[rang]; ++i)
  {
    Figura f{};
    f.id = rang * 100000 + i;
    f.tip = rand() % 3;
    f.brojPojedenih = 0;
    f.brojPoteza = 0;

    int lx, ly, indeks;
    do
    {
      lx = pocetakReda + rand() % redakaPoProcesu;
      ly = rand() % m;
      indeks = (lx - pocetakReda) * m + ly;
    } while (lokalnoPolje[indeks].id != -1);

    f.x = lx;
    f.y = ly;
    lokalnoPolje[indeks].id = f.id;
    lokalnoPolje[indeks].tip = f.tip;
    lokalneFigure.push_back(f);
  }

  MPI::Datatype tipFigure = MPI::INT.Create_contiguous(6);
  tipFigure.Commit();

  vector<Figura> globalneFigure;

  while (true)
  {
    for (auto &f : lokalneFigure)
    {
      pomjeriFiguru(f, m);
    }

    int lokalniBroj = static_cast<int>(lokalneFigure.size());
    vector<int> brojFiguraSvaki(velicina, 0);
    MPI::COMM_WORLD.Gather(&lokalniBroj, 1, MPI::INT, brojFiguraSvaki.data(), 1, MPI::INT, 0);

    vector<int> displs;
    vector<Figura> sveFigure;
    int ukupno = 0;
    if (rang == 0)
    {
      displs.resize(velicina, 0);
      for (int i = 1; i < velicina; ++i)
      {
        displs[i] = displs[i - 1] + brojFiguraSvaki[i - 1];
      }
      ukupno = displs[velicina - 1] + brojFiguraSvaki[velicina - 1];
      sveFigure.resize(ukupno);
    }

    Figura *sendPtr = lokalneFigure.empty() ? nullptr : lokalneFigure.data();
    Figura *recvPtr = (rang == 0 && !sveFigure.empty()) ? sveFigure.data() : nullptr;

    MPI::COMM_WORLD.Gatherv(sendPtr, lokalniBroj, tipFigure,
                            recvPtr, brojFiguraSvaki.data(),
                            displs.empty() ? nullptr : displs.data(),
                            tipFigure, 0);

    int globalniBroj = 0;
    if (rang == 0)
    {
      vector<Figura> prezivjeli = razrijesiSukobe(sveFigure, m);
      globalniBroj = static_cast<int>(prezivjeli.size());
      globalneFigure.swap(prezivjeli);
    }

    MPI::COMM_WORLD.Bcast(&globalniBroj, 1, MPI::INT, 0);

    if (globalniBroj <= 1)
    {
      if (rang == 0)
      {
        if (globalniBroj == 1)
        {
          const Figura &pobjednik = globalneFigure[0];
          cout << "Pobjednik je figura " << pobjednik.id
               << " (tip " << pobjednik.tip << ") koja je pojela "
               << pobjednik.brojPojedenih << " figura nakon "
               << pobjednik.brojPoteza << " poteza." << endl;
        }
        else
        {
          cout << "Nema prezivjelih figura." << endl;
        }
      }
      break;
    }

    if (rang != 0)
    {
      globalneFigure.resize(globalniBroj);
    }
    MPI::COMM_WORLD.Bcast(globalneFigure.data(), globalniBroj, tipFigure, 0);

    lokalneFigure.clear();
    for (const auto &f : globalneFigure)
    {
      int vlasnik = f.x / redakaPoProcesu;
      if (vlasnik == rang)
      {
        lokalneFigure.push_back(f);
      }
    }
  }

  tipFigure.Free();

  MPI::Finalize();
  return 0;
}