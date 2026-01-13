'''
- Definirati vektor a u intervalu [0,10] s korakom 0.1.
- Definirati vektor b=a^2. Na istom grafu (u istom prostoru - figure) nacrtati:
- vektor b (zelenom bojom, crtkana linija) i
- sin(b) (crvenom bojom)
- dodati labele za svaki
- Naslov slike treba biti "ispitni zadatak"
- naslov x-ose "x-osa" (interval [-1,10])
- naslov y-ose "y-osa" (interval [-2,9]).
'''

from matplotlib import pyplot as plt
import numpy as np


a = np.arange(0, 10, 0.1)
b = a ** 2
sin_b = np.sin(b)

plt.plot(a, b, color="green", linestyle="dashed", label="b")
plt.plot(a, sin_b, color="red", label="sin(b)")

plt.xlabel("x-osa")
plt.ylabel("y-osa")
plt.xlim(-1, 10)
plt.ylim(-2, 9)
plt.title("Ispitni zadatak")
plt.legend()
plt.show()