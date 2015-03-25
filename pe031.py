''' PROBLEM #31:
In England the currency is made up of pound, , and pence, p, and there are eight coins in general circulation:
1p, 2p, 5p, 10p, 20p, 50p, 1 (100p) and 2 (200p).
It is possible to make 2 in the following way:
11 + 150p + 220p + 15p + 12p + 31p
How many different ways can 2 be made using any number of coins?
'''

coins = [2,5,10,20,50,100,200]
N = 200

def main():

    Cb = [1]*(N+1)

    for c, coin in enumerate(coins):
        Ca = Cb
        Cb = [0]*(N+1)
        for x in xrange(N+1):
            Cb[x] = sum(Ca[x - i * coin] for i in xrange(x//coin+1))

    answer = Cb[N]

    print answer

if __name__=='__main__':
    main()
