var izvrseno = false;

function dodajRezultat(dogadjaj) {
  var rezultat = document.getElementById("rezultat");
  if (izvrseno) {
    rezultat.value = "";
    izvrseno = false;
  }

  dogadjaj = dogadjaj || window.event;
  var kliknutiElement = dogadjaj.currentTarget;
  var vrijednost = kliknutiElement.innerText;
  rezultat.value += vrijednost;
}

function izvrsiIzraz(dogadjaj) {
  var rezultat = document.getElementById("rezultat");
  rezultat.value = eval(rezultat.value);
  izvrseno = true;
}

function izbrisi(dogadjaj) {
  var rezultat = document.getElementById("rezultat");
  rezultat.value = "";
}
