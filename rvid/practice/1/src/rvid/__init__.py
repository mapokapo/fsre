import numpy as np
import matplotlib.pyplot as plt
import math

def main() -> None:
    t = np.linspace(0, 2 * math.pi, 1000)

    x = 16 * np.sin(t)**3
    y = 13 * np.cos(t) - 5 * np.cos(2*t) - 2 * np.cos(3*t) - np.cos(4*t)

    plt.figure(figsize=(6, 6))
    plt.plot(x, y, color='red', linewidth=2)
    plt.fill(x, y, color='pink')  # Optional: fill the heart
    plt.title("Parametric Heart Curve")
    plt.axis('equal')
    plt.axis('off')
    plt.show()