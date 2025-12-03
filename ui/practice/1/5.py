def set_partitions(s: set[int]) -> set[frozenset[frozenset[int]]]:
    if not s:
        return {frozenset()}

    first = next(iter(s))
    rest = s - {first}
    partitions_without_first = set_partitions(rest)
    all_partitions: set[frozenset[frozenset[int]]] = set()

    for partition in partitions_without_first:
        new_partition = frozenset(partition | {frozenset({first})})
        all_partitions.add(new_partition)

        for subset in partition:
            new_subset = frozenset(subset | {first})
            new_partition = frozenset((partition - {subset}) | {new_subset})
            all_partitions.add(new_partition)

    return all_partitions


def main():
    numbers = {int(n.strip()) for n in input(
        "Unesite listu brojeva (npr. 1,2,3,4): ").split(",")}

    print(f"Particije skupa: {str(set_partitions(numbers))}")


if __name__ == "__main__":
    main()
