''' PROBLEM #33:
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
'''

from fractions import Fraction

def main():

    r = []

    def test1(a,b,c):
        if Fraction(10*a+b, b*10+c) == Fraction(a, c):
            r.append((10*a+b, b*10+c))
    def test2(a,b,c):
        if Fraction(10*b+a, c*10+b) == Fraction(a, c):
            r.append((10*b+a, c*10+b))

    for b in range(1,10):
        for a in range(1,b):
            for c in range(1,10):
                test1(a,b,c)
        for c in range(b+1,10):
            for a in range(10):
                test2(a,b,c)

    #print r
    
    f = map(lambda x:Fraction(*x), r)
    #print f
    
    p = reduce(lambda a,b:a*b, f)
    print p
    
if __name__=='__main__':
    main()
