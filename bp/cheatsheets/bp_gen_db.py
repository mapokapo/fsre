from faker import Faker
import sqlite3
from random import random, choice
from unicodedata import normalize
from pydantic import ValidationError

Faker.seed(33422)

create_tables_sql = [
    """
CREATE TABLE IF NOT EXISTS ODJEL
( SIFRA_ODJELA 	NUMERIC(5) 	NOT NULL, 
  NAZIV_ODJELA	VARCHAR(50) 	NOT NULL,
  CONSTRAINT odjel_pk PRIMARY KEY(SIFRA_ODJELA)
);
""",
    """
CREATE TABLE IF NOT EXISTS RADNO_MJESTO
( SIFRA_RADMJ	VARCHAR(10) 	NOT NULL, 
  NAZIV_RADMJ	VARCHAR(50) 	NOT NULL,
  SIFRA_ODJELA	NUMERIC(5),
  CONSTRAINT radmj_pk PRIMARY KEY(SIFRA_RADMJ),
  CONSTRAINT radmj_odjel_fk FOREIGN KEY(SIFRA_ODJELA) REFERENCES ODJEL(SIFRA_ODJELA)
);
""",
    """
CREATE TABLE IF NOT EXISTS ZUPANIJA
( SIFRA_ZUPANIJE VARCHAR(5) 	NOT NULL, 
  NAZIV_ZUPANIJE VARCHAR(50) 	NOT NULL,
  CONSTRAINT zupanija_pk PRIMARY KEY(SIFRA_ZUPANIJE)
);
""",
    """
CREATE TABLE IF NOT EXISTS OPCINA
( SIFRA_OPCINE	NUMERIC(5) 	NOT NULL, 
  NAZIV_OPCINE	VARCHAR(50) 	NOT NULL,
  SIFRA_ZUPANIJE VARCHAR(5) 	NOT NULL,
  CONSTRAINT opcina_pk PRIMARY KEY(SIFRA_OPCINE),
  CONSTRAINT opcina_zupanija_fk FOREIGN KEY(SIFRA_ZUPANIJE) REFERENCES ZUPANIJA(SIFRA_ZUPANIJE)
);
""",
    """
CREATE TABLE IF NOT EXISTS TVRTKA
( SIFRA_TVRTKE	NUMERIC(5) 	NOT NULL, 
  NAZIV_TVRTKE 	VARCHAR(50) 	NOT NULL,
  SIFRA_OPCINE 	NUMERIC(5)	NOT NULL,
  CONSTRAINT tvrtka_pk PRIMARY KEY(SIFRA_TVRTKE),
  CONSTRAINT tvrtka_opcina_fk FOREIGN KEY(SIFRA_OPCINE) REFERENCES OPCINA(SIFRA_OPCINE)
);
""",
    """
CREATE TABLE IF NOT EXISTS DJELATNIK
( ID_DJELATNIKA NUMERIC(5) 	NOT NULL, 
  IME 		VARCHAR(25) 	NOT NULL, 
  PREZIME 	VARCHAR(25) 	NOT NULL,
  SPOL	 	CHAR(2) 	NOT NULL,
  EMAIL 	VARCHAR(50),
  TELEFON	VARCHAR(20),
  DATUM_ZAPOSLENJA DATETIME	NOT NULL,
  PLACA		NUMERIC(7,2)	NOT NULL,
  DODATAK 	NUMERIC(5,2),
  ID_SEFA	NUMERIC(5),
  SIFRA_OPCINE	NUMERIC(5) 	NOT NULL,
  SIFRA_RADMJ	VARCHAR(10) 	NOT NULL,
  CONSTRAINT djelatnik_pk PRIMARY KEY(ID_DJELATNIKA),
  CONSTRAINT djelatnik_djelatnik_fk FOREIGN KEY(ID_SEFA) REFERENCES DJELATNIK(ID_DJELATNIKA),
  CONSTRAINT djelatnik_opcina_fk FOREIGN KEY(SIFRA_OPCINE) REFERENCES OPCINA(SIFRA_OPCINE),
  CONSTRAINT djelatnik_radmj_fk FOREIGN KEY(SIFRA_RADMJ) REFERENCES RADNO_MJESTO(SIFRA_RADMJ)
);
""",
    """
CREATE TABLE IF NOT EXISTS RANIJA_ZAPOSLENJA
( SIFRA		NUMERIC(5) 	NOT NULL, 
  ID_DJELATNIKA NUMERIC(5) 	NOT NULL,
  SIFRA_TVRTKE 	NUMERIC(5)	NOT NULL,
  DATUM_OD	DATETIME 	NOT NULL,
  DATUM_DO 	DATETIME	NOT NULL,
  CONSTRAINT zaposlenja_pk PRIMARY KEY(SIFRA),
  CONSTRAINT zaposlenja_djelatnik_fk FOREIGN KEY(ID_DJELATNIKA) REFERENCES DJELATNIK(ID_DJELATNIKA),
  CONSTRAINT zaposlenja_tvrtka_fk FOREIGN KEY(SIFRA_TVRTKE) REFERENCES TVRTKA(SIFRA_TVRTKE)
);
""",
]


def insert_odjel(conn, cur, id, name):
  sql = """
  INSERT INTO ODJEL
  VALUES (?, ?)
  """
  cur.execute(sql, (id, name))
  conn.commit()
  return cur.lastrowid


def insert_radno_mjesto(conn, cur, id, name, odjel_id):
  sql = """
  INSERT INTO RADNO_MJESTO
  VALUES (?, ?, ?)
  """
  cur.execute(sql, (id, name, odjel_id))
  conn.commit()
  return cur.lastrowid


def insert_zupanija(conn, cur, id, name):
  sql = """
  INSERT INTO ZUPANIJA
  VALUES (?, ?)
  """
  cur.execute(sql, (id, name))
  conn.commit()
  return cur.lastrowid


def insert_opcina(conn, cur, id, name, zupanija_id):
  sql = """
  INSERT INTO OPCINA
  VALUES (?, ?, ?)
  """
  cur.execute(sql, (id, name, zupanija_id))
  conn.commit()
  return cur.lastrowid


def insert_tvrtka(conn, cur, id, name, opcina_id):
  sql = """
  INSERT INTO TVRTKA
  VALUES (?, ?, ?)
  """
  cur.execute(sql, (id, name, opcina_id))
  conn.commit()
  return cur.lastrowid


def insert_djelatnik(conn, cur, id, name, surname, gender, email, tel,
                     employment_date, salary, bonus, boss_id, opcina_id,
                     radmj_id):
  sql = """
  INSERT INTO DJELATNIK
  VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
  """
  cur.execute(sql, (id, name, surname, gender, email, tel, employment_date,
                    salary, bonus, boss_id, opcina_id, radmj_id))
  conn.commit()
  return cur.lastrowid


def insert_ranije_zaposlenje(conn, cur, id, djelatnik_id, tvrtka_id, date_from,
                             date_to):
  sql = """
  INSERT INTO RANIJA_ZAPOSLENJA
  VALUES (?, ?, ?, ?, ?)
  """
  cur.execute(sql, (id, djelatnik_id, tvrtka_id, date_from, date_to))
  conn.commit()
  return cur.lastrowid


fake = Faker("hr_HR")

conn = None
try:
  conn = sqlite3.connect("test.db")

  cursor = conn.cursor()

  try:
    for sql in create_tables_sql:
      cursor.execute(sql)
    print("Tables created")
  except Exception as e:
    print("Error creating tables", e)

  # create 50 djelatnik
  zupanije = []
  opcine = []
  tvrtke = []
  odjeli = []
  radna_mjesta = []
  djelatnici = []
  ranija_zaposlenja = []

  for _ in range(5):
    zupanija = {
        "id": len(zupanije) + 1,
        "name": fake.city(),
    }
    zupanije.append(zupanija)
    insert_zupanija(conn, cursor, zupanija["id"], zupanija["name"])

  for _ in range(10):
    opcina = {
        "id": len(opcine) + 1,
        "name": fake.city(),
        "zupanija_id": choice(zupanije)["id"],
    }
    opcine.append(opcina)
    insert_opcina(conn, cursor, opcina["id"], opcina["name"],
                  opcina["zupanija_id"])

  for _ in range(10):
    tvrtka = {
        "id": len(tvrtke) + 1,
        "name": fake.company(),
        "opcina_id": choice(opcine)["id"],
    }
    tvrtke.append(tvrtka)
    insert_tvrtka(conn, cursor, tvrtka["id"], tvrtka["name"],
                  tvrtka["opcina_id"])

  for _ in range(5):
    odjel = {
        "id": len(odjeli) + 1,
        "name": " ".join(fake.words(nb=2)),
    }
    odjeli.append(odjel)
    insert_odjel(conn, cursor, odjel["id"], odjel["name"])

  for _ in range(10):
    name = fake.job()
    words = name.upper().split(" ")
    id = "-".join([w[0] for w in words]) if len(words) > 1 else words[0][0:2]
    radno_mjesto = {
        "id": id,
        "name": name,
        "odjel_id": choice(odjeli)["id"],
    }
    radna_mjesta.append(radno_mjesto)
    insert_radno_mjesto(conn, cursor, radno_mjesto["id"], radno_mjesto["name"],
                        radno_mjesto["odjel_id"])

  for _ in range(50):
    gender = choice(["M", "F"])
    name = fake.first_name_male() if gender == "M" else fake.first_name_female(
    )
    surname = fake.last_name_male(
    ) if gender == "M" else fake.last_name_female()
    email = "{}.{}@{}".format(
        normalize("NFKD", name.lower()).encode("ascii", "ignore").decode(),
        normalize("NFKD", surname.lower()).encode("ascii", "ignore").decode(),
        fake.domain_name())
    djelatnik = {
        "id":
        len(djelatnici) + 1,
        "name":
        name,
        "surname":
        surname,
        "gender":
        gender,
        "email":
        email,
        "tel":
        fake.unique.phone_number(),
        "employment_date":
        fake.date_between(start_date="-30y", end_date="now"),
        "salary":
        fake.pyint(min_value=500, max_value=5000),
        "bonus":
        fake.pyint(min_value=20, max_value=200) if random() > 0.8 else None,
        "boss_id":
        choice(djelatnici)["id"]
        if random() > 0.2 and len(djelatnici) > 0 else None,
        "opcina_id":
        choice(opcine)["id"],
        "radmj_id":
        choice(radna_mjesta)["id"],
    }
    djelatnici.append(djelatnik)
    insert_djelatnik(conn, cursor, djelatnik["id"], djelatnik["name"],
                     djelatnik["surname"], djelatnik["gender"],
                     djelatnik["email"], djelatnik["tel"],
                     djelatnik["employment_date"], djelatnik["salary"],
                     djelatnik["bonus"], djelatnik["boss_id"],
                     djelatnik["opcina_id"], djelatnik["radmj_id"])

  for _ in range(20):
    date_from = fake.date_between(start_date="-30y", end_date="now")
    date_to = fake.date_between(start_date=date_from, end_date="now")
    ranije_zaposlenje = {
        "id": len(ranija_zaposlenja) + 1,
        "djelatnik_id": choice(djelatnici)["id"],
        "tvrtka_id": choice(tvrtke)["id"],
        "date_from": date_from,
        "date_to": date_to,
    }
    ranija_zaposlenja.append(ranije_zaposlenje)
    insert_ranije_zaposlenje(conn, cursor, ranije_zaposlenje["id"],
                             ranije_zaposlenje["djelatnik_id"],
                             ranije_zaposlenje["tvrtka_id"],
                             ranije_zaposlenje["date_from"],
                             ranije_zaposlenje["date_to"])

except sqlite3.Error as e:
  print(e)
finally:
  if conn:
    conn.commit()
    cursor.close()
    conn.close()
