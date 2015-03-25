''' PROBLEM #37:
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
'''

from pe027 import PrimeTester
import string

def nary_str(num, ary, digits=string.digits+string.ascii_uppercase):
    r = ''
    n = num
    while n >= ary:
        r += digits[n % ary]
        n //= ary
    return r

def nary_dec(num, ary, digits=range(10)):
    r = 0
    n = num
    while n >= ary:
        r = r * 10 + digits[n % ary]
        n //= ary
    return r

def main():

    P = PrimeTester()

    t = []
    i = 9
    while len(t) < 11:
        i += 1
        n = int(nary_dec(i, 3, [3, 7, 9]))
        print n
        x = n
        while x and P.isPrime(x):
            x //= 10
        if x:
            continue
        x = n
        while x > 9 and P.isPrime(x):
            x = int(str(x)[1:])
        if x > 9:
            continue
        if x < 9:
            t.append(n)

    print t

if __name__=='__main__':
    main()
