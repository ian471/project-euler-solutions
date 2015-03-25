''' PROBLEM #27:
Euler published the remarkable quadratic formula:
n + n + 41
It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41 + 41 + 41 is clearly divisible by 41.
Using computers, the incredible formula n  79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, 79 and 1601, is 126479.
Considering quadratics of the form:

n + an + b, where |a|  1000 and |b|  1000
where |n| is the modulus/absolute value of ne.g. |11| = 11 and |4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
'''

N = 1000

class PrimeTester(object):
    def __init__(self):
        self.primes = [2]
    def isPrime(self, n):
        if n < 2:
            return False
        toobig = False
        while n > self.primes[-1]:
            toobig = True
            c = self.primes[-1]
            cprime = False
            while not cprime:
                c += 1
                for p in self.primes:
                    if p > c / 2:
                        cprime = True
                        break
                    if not c % p:
                        break
            self.primes.append(c)
        if toobig:
            return n == self.primes[-1]
        '''
        low, high = 0, len(self.primes)
        while low + 1 < high:
            if n == self.primes[low]:
                return True
            middle = low + (high - low) / 2
            if n < self.primes[middle]:
                high = middle
            else:
                low = middle
        return False
        '''
        return n in self.primes

def main():

    P = PrimeTester()
    
    maxn = 0
    maxab = (0,0)
    
    for a in range(-N+1, N):
        for b in range(-N+1, N):
            n = 0
            while P.isPrime(n*n+a*n+b):
                n += 1
            if n > maxn:
                maxn = n
                maxab = (a, b)

    a, b = maxab
    print "a=%d b=%d ab=%d" %(a, b, a*b)
    print "generates %d primes" %maxn

if __name__=='__main__':
    main()
