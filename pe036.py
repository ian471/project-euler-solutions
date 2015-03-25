''' PROBLEM #36:
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
'''

N = 1000000

def main():

    total = 0
    for n in xrange(N):
        if str(n) == str(n)[::-1] and bin(n)[2:] == bin(n)[:1:-1]:
            total += n

    print total

if __name__=='__main__':
    main()
