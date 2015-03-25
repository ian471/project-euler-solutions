''' PROBLEM #30:
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.
Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
'''

n5 = [n**5 for n in range(0,10)]

def main():

    total = 0
    for n in range(2, 4*(9**5)+1):
        if n == sum(n5[int(i)] for i in str(n)):
            total += n

    print total

if __name__=='__main__':
    main()
