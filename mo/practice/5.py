def f(x: float):
    return 4*x + x**2


# start and end of interval
a = -8
b = 4

e = 0.01  # resolution

num = 0


def fib(n: int, do_count: bool = True) -> int:
    if do_count:
        global num
        num += 1
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n - 1, False) + fib(n - 2, False)


print("Task: minimize the function 4*x + x**2")
length = b - a
print(f"Lower bound: {a}, upper bound: {b}, distance: {length}")

n = 1
while fib(n) < length / e:
    n += 1

print(
    f"Index of smallest Fibonacci number larger than length/e = {length}/{e} = {length/e} is: {n} ({fib(n)})")

x1 = a + (fib(n - 2)/fib(n)) * length
x2 = a + (fib(n - 1)/fib(n)) * length

fx1 = f(x1)
fx2 = f(x2)

print(f"Starting n: {n}")
print(
    f"Computed points: (x1, x2) = ({x1:.6f}, {x2:.6f}) | (f(x1), f(x2)) = ({fx1:.6f}, {fx2:.6f})")

while n > 2:
    n -= 1
    if fx1 > fx2:
        print(
            f"The value of the function at x1 ({fx1:.6f}) is greater than the value of the function at x2 ({fx2:.6f}), so we need to discard all values on the 'larger' side (the left side of x1), so we set the lower bound (a = {a:.6f}) to x1 ({x1:.6f})")
        a = x1
        x1 = x2
        fx1 = fx2
        length = b - a
        x2 = a + (fib(n - 1)/fib(n)) * length
        fx2 = f(x2)
    elif fx1 < fx2:
        print(
            f"The value of the function at x1 ({fx1:.6f}) is smaller than the value of the function at x2 ({fx2:.6f}), so we need to discard all values on the 'larger' side (the right side of x2), so we set the upper bound (b = {b:.6f}) to x2 ({x2:.6f})")
        b = x2
        x2 = x1
        fx2 = fx1
        length = b - a
        x1 = a + (fib(n - 2)/fib(n)) * length
        fx1 = f(x1)
    else:
        x1 += e

    if abs(b - a) < e:
        print(
            f"The distance between the bounds (a, b) is {abs(b - a)}, which is smaller than the error limit ({e:.6f}), so we have found a satisfactory solution")
        break

print(
    f"Of the 2 points (x1, x2), we pick the one with the smaller f(x) value. The values are: ({fx1:.6f}, {fx2:.6f}), so we pick {fx1 if fx1 < fx2 else fx2}")
solution = (x1, fx1) if fx1 < fx2 else (x2, fx2)

print(f"The solution is: x = {solution[0]:.6f}, f(x) = {solution[1]:.6f}")
print(f"Called fib(n) a total of {num} times")
