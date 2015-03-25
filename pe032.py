''' PROBLEM #32:
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39  186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
'''

from itertools import permutations

def digits2number(d):
    return sum(10**(len(d)-i-1)*n for i,n in enumerate(d))

def main():

    r = set()
    for p in permutations(range(1,10)):
        a = digits2number(p[:2])
        b = digits2number(p[2:5])
        c = digits2number(p[5:])
        if a*b==c:
            r.add(c)

        a = digits2number(p[:1])
        b = digits2number(p[1:5])
        if a*b==c:
            r.add(c)

    answer = sum(r)

    print answer

if __name__=='__main__':
    main()
