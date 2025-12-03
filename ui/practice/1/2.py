from typing import Literal, Union

prijevod = {
    "sretan": "happy",
    "sretna": "happy",
    "nova": "new",
    "godina": "year",
    "čestit": "merry",
    "cestit": "merry",
    "božić": "christmas",
    "bozic": "christmas",
    "i": "and"
}

Mode = Union[Literal["croatian-to-english"], Literal["english-to-croatian"]]


def main():
    while True:
        mode_input = input(
            "Odaberite način prijevoda (1 - HR->EN, 2 - EN->HR): ")
        if mode_input == "1":
            mode: Mode = "croatian-to-english"
            break
        elif mode_input == "2":
            mode: Mode = "english-to-croatian"
            break
        else:
            print("Nevažeći unos. Pokušajte ponovno.")

    if mode == "croatian-to-english":
        text = input("Unesite cestitku: ").lower()
        translated = [prijevod.get(rijec, "<UNKNOWN>")
                      for rijec in text.split()]

        print(f"Prijevod na engleski: {' '.join(translated)}")
    else:
        text = input("Enter the greeting: ").lower()
        reverse_prijevod = {v: k for k, v in prijevod.items()}
        translated = [reverse_prijevod.get(
            word, "<UNKNOWN>") for word in text.split()]

        print(f"Prijevod na hrvatski: {' '.join(translated)}")


if __name__ == "__main__":
    main()
