# x = 20.5 +- 0.7, odrediti relativnu gresku

x = 20.5
x_abs_greska = 0.7
x_rel_greska = x_abs_greska/abs(x)

print(f"Relativna greska = {x_rel_greska * 100:.2f}%")
