def main():
    numbers = [int(n.strip()) for n in input(
        "Unesite listu brojeva (npr. 1,2,3,4): ").split(",")]

    output: dict[str, list[int]] = {
        "parni": [],
        "neparni": []
    }
    for n in numbers:
        if n % 2 == 0:
            output["parni"].append(n)
        else:
            output["neparni"].append(n)

    output["parni"].sort()
    output["neparni"].sort()

    print(f"Rezultat: {output}")


if __name__ == "__main__":
    main()
