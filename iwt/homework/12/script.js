const articles = document.querySelectorAll("section > article");
const articleNames = ["obrazovanje", "kontakt", "jezici", "hobi"];
const articleContent = [
  `<h4>Osnovna skola: ________________<br />Srednja skola: _________________<br />Fakultet: _______________________<br /></h4>`,
  `<h4>Ime i prezime:<br />________________<br />Adresa:<br />________________<br />Telefon:<br />________________<br /></h4>`,
  `<h4><ul><li>Hrvatski</li><li>Engleski</li><li>...</li></ul></h4>`,
  `<h4><ul><li>Nogomet</li><li>...</li><li>...</li></ul></h4>`,
];

function otvori(articleName) {
  const i = articleNames.indexOf(articleName);
  articles.item(i).innerHTML = articleContent[i];
}
