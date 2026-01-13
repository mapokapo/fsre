'''
1. Generirati matricu A dimenzija 4x5 sa slučajno odabranim cijelim brojevima od 0 do 100
2. Potencirati svaki element matrice potencijom 2
3. Generirati matricu B dimenzija 3x5 slučajno odabranim brojevima od 1 do 10
4. Pomnožiti matricu A i B (dopuniti matricu B nulama kako bi dimenzije dviju matrica bile iste)
5. Rezultat spremiti u varijablu "rezultat" i svaki element u dobivenoj matrici povećati za 2
6. U prvi redak rezultata postaviti sve nule umjesto postojećih elemenata
7. Transponirati dobivenu matricu rezultat
8. U varijablu b spremiti vektor čiji su elementi sume elemenata stupca matrice
9. Ispisati dobiveni vektor b

Napomena: Obavezno koristiti naredbe za rad s matricama i rješenje spremiti kao zadatak2.py i pozivati iz naredbenog retka
'''

import numpy as np

print("\n\n1. Create matrix a with size 4x5 filled with random integers 0-100")
a = np.random.randint(0, 100, size=(4, 5))
print(f"a = {a}")

print("\n\n2. Square all values in matrix a")
a = a ** 2
print(f"a = {a}")

print("\n\n3. Create matrix b with size 3x5 filled with random integers 1-10")
b = np.random.randint(1, 10, size=(3, 5))
print(f"b = {b}")

print("\n\n4. Resize matrix b to 4x5 and multiply matrices a and b element-wise")
b.resize(4, 5, refcheck=False)
print(f"b = {b}")
print(f"a * b = {a * b}")

print("\n\n5. Store result in variable and add 2 to every element")
rezultat = a * b
print(f"rezultat = {rezultat}")
rezultat += 2
print(f"rezultat + 2 = {rezultat}")


print("\n\n6. Set first row of resulting matrix to all zeros")
rezultat[0][:] = 0
print(f"rezultat = {rezultat}")

print("\n\n7. Transpose")
print(f"rezultat.T = {rezultat.T}")

# U varijablu b spremiti vektor čiji su elementi sume elemenata stupca matrice

print("\n\n8. Create vector b whose elements are the sums of the corresponding column of the matrix")
vec_b = np.array([int(sum(col)) for col in rezultat.T])

print("\n\n9. Print vector b")
print(f"vec_b = {vec_b}")

