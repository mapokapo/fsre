'''
Leo Petrović 695/RM

6. Postaviti parametre kružnice (r, i koordinate središta: a, b).
Zatim je potrebno učitavati 10 točaka koordinatnog sustava (realni brojevi).

a) Za učitane točke provjeriti nalaze li se na kružnici. (25 bodova)
b) Nakon što se učita točka (0, 0), ispisati koliki je omjer pogodaka kružnice ((broj točaka na kružnici)/(ukupni broj točaka)) u postotku (25 bodova)

Formula kružnice : (x-a)^2 + (y-b)^2 = r^2
'''


def get_coords(text: str = "Unesite tocku (x, y): "):
    coords = [float(n)
              for n in input(text).split(",")]

    return (coords[0], coords[1])


def is_on_circle(radius: float, circle_center: tuple[float, float], point: tuple[float, float], epsilon: float = 0.01) -> bool:
    value = (point[0] - circle_center[0]
             )**2 + (point[1] - circle_center[1])**2
    lower_bound = value - epsilon
    upper_bound = value + epsilon

    return lower_bound <= radius**2 <= upper_bound


(a, b) = get_coords("Unesite koordinate kruznice (x, y): ")
r = float(input("Unesite polumjer kruznice: "))

points: list[tuple[float, float]] = []
for _ in range(10):
    point = get_coords()
    if point == (0, 0):
        break

    points.append(point)

on_circle_count = 0
for point in points:
    if is_on_circle(r, (a, b), point):
        print(f"Tocka {point} se nalazi na kruznici")
        on_circle_count += 1
    else:
        print(f"Tocka {point} se NE nalazi na kruznici")

print(f"{on_circle_count} tocaka na kruznici od ukupno {len(points)} unesenih ({round(on_circle_count / len(points), 4) * 100}%)")
