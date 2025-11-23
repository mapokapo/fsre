from typing import Any


def print_matrix(matrix: list[list[Any]]) -> str:
    output = ""

    for row in matrix:
        for cell in row:
            output += f"{str(cell)}\t"
        output += "\n"

    return output


def main():
    n = int(input("Unesite velicinu matrice: "))
    matrix: list[list[int]] = []

    for i in range(n):
        row: list[int] = []
        for j in range(n):
            if i == j or i == n - j - 1:
                row.append(1)
            else:
                row.append(0)
        matrix.append(row)

    print(f"Matrica je:\n{print_matrix(matrix)}")


if __name__ == "__main__":
    main()
