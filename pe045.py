from itertools import imap

def integers():
    i = 0
    while True:
        yield i
        i += 1

gens = [
    imap(lambda n: n*(n + 1)/2, integers()),
    imap(lambda n: n*(3*n - 1)/2, integers()),
    imap(lambda n: n*(2*n - 1), integers()),
]

xx = map(next, gens)
m = 1
while True:
    for i, x in enumerate(xx):
        if x < m:
            break
    else:
        if m > 40755:
            print m
            break
    xx[i] = next(gens[i])
    m = max(m, xx[i])
