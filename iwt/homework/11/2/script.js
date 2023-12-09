var red = "iks";
var potezi = [];
for (var i = 0; i < 3; i++) {
  potezi[i] = [];
}
function odigraj(x, y, dogadjaj) {
  if (potezi[x][y] == "iks" || potezi[x][y] == "oks") {
    alert("Pogrešan potez, molimo pokušajte ponovno.");
    return;
  }
  potezi[x][y] = red;
  dogadjaj = dogadjaj || window.event;
  var kliknutiElement = dogadjaj.target;
  if (red == "iks") {
    kliknutiElement.src = "iks.png";
    red = "oks";
  } else {
    kliknutiElement.src = "oks.png";
    red = "iks";
  }
  var pobjednik = provjeri_pobjedu();
  if (pobjednik) {
    window.location.reload();
  }
}
function provjeri_pobjedu() {
  var igraci = ["iks", "oks"];
  for (var idx = 0; idx < 2; idx++) {
    var igrac = igraci[idx];
    for (var i = 0; i < 3; i++)
      if (
        potezi[0][i] == igrac &&
        potezi[1][i] == igrac &&
        potezi[2][i] == igrac
      ) {
        return igrac;
      }
    for (var i = 0; i < 3; i++)
      if (
        potezi[i][0] == igrac &&
        potezi[i][1] == igrac &&
        potezi[i][2] == igrac
      ) {
        return igrac;
      }
    if (
      potezi[0][0] == igrac &&
      potezi[1][1] == igrac &&
      potezi[2][2] == igrac
    ) {
      return igrac;
    }
    if (
      potezi[0][2] == "iks" &&
      potezi[1][1] == "iks" &&
      potezi[2][0] == "iks"
    ) {
      return "iks";
    }
  }
}
