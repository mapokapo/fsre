def dvoclani_podskupovi(numbers: set[int]) -> set[tuple[int, int]]:
    output: set[tuple[int, int]] = set()

    for a in numbers:
        for b in numbers:
            if a != b:
                output.add((a, b))

    return output


def main():
    numbers = {int(n.strip()) for n in input(
        "Unesite listu brojeva (npr. 1,2,3,4): ").split(",")}

    print(f"Svi dvoclani podskupovi: {dvoclani_podskupovi(numbers)}")


if __name__ == "__main__":
    main()
