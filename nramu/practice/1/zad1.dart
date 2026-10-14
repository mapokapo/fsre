void main() {
  final zadaci = <Zadatak>[
    const Zadatak(naslov: "Instalacija"),
    const Zadatak(naslov: "Git", zavrsen: true),
    const Zadatak(naslov: "Dart"),
  ];

  // 1. Dohvati otvorene zadatke
  final zavrseni = zadaci.where((z) => !z.zavrsen).toList();

  // 2. Ispisite njihove naslova
  for (final z in zavrseni) {
    print(z.naslov);
  }

  // 3. Dodajte metodu kopiraj(zavrsen: ...)
  // dodano
  final kopijaPrvog = zadaci[0].kopiraj(zavrsen: true);
  print("${kopijaPrvog.naslov}");
  print(zadaci[0]);
}

class Zadatak {
  final String naslov;
  final bool zavrsen;

  const Zadatak({required this.naslov, this.zavrsen = false});

  Zadatak kopiraj({required bool zavrsen}) {
    return Zadatak(naslov: this.naslov, zavrsen: zavrsen);
  }
}
