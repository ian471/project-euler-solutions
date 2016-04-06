from __future__ import division

import bisect
import itertools
from math import ceil


class Primes(object):

    def __init__(self):
        # A list of all the prime numbers <= max_p
        self.primes = [2, 3, 5, 7]
        self.max_p = 10

    def __iter__(self):
        i = 0
        while True:
            if i >= len(self.primes):
                self._expand()
            yield self.primes[i]
            i += 1

    def _expand(self):
        # Double the size of our list and sift up to the new max_p
        
        new_max_p = self.max_p * 2
        min_product = self.max_p + 1
        max_factor = int(new_max_p ** .5)

        sieve = range(min_product, new_max_p+1)
        factors = iter(self)
        f = 0
        while f <= max_factor:
            f = factors.next()
            start_product = int(ceil(min_product / f)) * f
            for multiple in xrange(start_product, new_max_p+1, f):
                sieve[multiple - min_product] = None
        self.primes += [p for p in sieve if p is not None]
        self.max_p = new_max_p

    def prime_pairs(self):
        for x in self:
            for y in self:
                if y >= x: break
                if (self.is_prime(int(str(x)+str(y))) and
                    self.is_prime(int(str(y)+str(x)))):
                    yield y, x

    def is_prime(self, n):

        # Is n in our list of primes?
        if n <= self.max_p:
            # Since the list is sorted, use bisection to speed up searching
            i = bisect.bisect_left(self.primes, n)
            return i != len(self.primes) and self.primes[i] == n

        # Use trial division by all the primes in our list, expanding the list
        # as necessary.
        stop = int(n**.5)
        for factor in self:
            if factor > stop:
                return True
            if n % factor == 0:
                return False


def solve(N=5):
    primes = Primes()

    # Maps n -> {x: (x, n) is a prime pair}
    edges = {}

    for count, (x, y) in enumerate(primes.prime_pairs()):
        edges.setdefault(x, set()).add(y)
        edges.setdefault(y, set()).add(x)

        # Since x and y connect to eachother, if they share any order-3
        # connected subgraphs, we have an order-5 connected subgraph!
        shared = frozenset(edges[x] & edges[y])
        for subset in itertools.combinations(shared, N - 2):
            for a, b in itertools.combinations(subset, 2):
                if a not in edges[b] or b not in edges[a]:
                    break
            else:
                print
                return sorted(subset + (x, y))
        if count % 10 == 0:
            print '\r', '{}%'.format(count//140),


if __name__=='__main__':
    solution = solve()
    print 'solution:', solution
    print 'sum =', sum(solution)
