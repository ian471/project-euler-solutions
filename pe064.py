from __future__ import division


def f(S, m=0, d=1, a=None, _a0=None, _already=None):
    if a is None:
        sqrt = S**.5
        _a0 = a = int(sqrt)
        if a == sqrt:
            raise StopIteration
    if _already is None:
        _already = set()
    if (m, d, a) in _already:
        raise StopIteration
    _already.add((m, d, a))
    yield m, d, a

    m1 = int(d * a - m)
    d1 = int((S - m1 ** 2) / d)
    a1 = int((_a0 + m1) / d1)

    for t in f(S, m1, d1, a1, _a0, _already):
        yield t

count = 0
for N in xrange(2, 10001):
    period = sum(1 for m, d, a in f(N)) - 1
    if period >= 0 and period % 2:
        count += 1

print count