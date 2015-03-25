''' PROBLEM #40:
An irrational decimal fraction is created by concatenating the positive integers:
0.123456789101112131415161718192021...
It can be seen that the 12th digit of the fractional part is 1.
If dn represents the nth digit of the fractional part, find the value of the following expression.
d1  d10  d100  d1000  d10000  d100000  d1000000
'''

from math import log, floor

N = 1000000

def main():

    answer = 1

    target = 1

    places = 0
    i = 1
    digits = 1
    while target <= N:
        if places + floor(log(i, 10)) + 1 >= target:
            digit = int(str(i)[target - places - 1])
            print "d%d = %d" %(target, digit)
            answer *= digit
            target *= 10
        places += digits
        i += 1
        if i >= 10**digits:
            digits += 1
    
    print answer

if __name__=='__main__':
    main()
