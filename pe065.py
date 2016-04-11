from fractions import Fraction

N = 100

n = 0
for i in xrange(N, 1, -1):
    if i % 3 == 0:
        c = i * 2 / 3
    else:
        c = 1
    n = 1 / Fraction(c + n)
n = 2 + n

print sum(int(digit) for digit in str(n.numerator))
