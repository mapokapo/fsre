#include <stdio.h>
#include <mpi.h>

/*
Zadaca 1: Napišite program koji će ispisati proizvoljnu poruku na monitor onoliko puta koliki je rang procesa koji ispisuje poruku. Pokrenite dobiveni program na 1, 2, 7 i 11 procesora.

Leo Petrović 695/RM
*/

int main(int argc, char *argv[])
{
    int rang, velicina;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);
    MPI_Comm_size(MPI_COMM_WORLD, &velicina);

    for (int i = 0; i < rang; i++)
    {
        printf("Procesor %d: Ovo je poruka broj %d\n", rang, i + 1);
    }

    return MPI_Finalize();
}
