''' PROBLEM #34:
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: as 1! = 1 and 2! = 2 are not sums they are not included.
'''

from math import factorial

def main():

    f = map(factorial, range(10))

    total = 0

    for n in xrange(10,1000000):
        if sum(f[d] for d in map(int,str(n))) == n:
            total += n

    print total

if __name__=='__main__':
    main()
