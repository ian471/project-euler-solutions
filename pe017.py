''' PROBLEM #17:
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used? 

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
'''

tens = ['','teen','twenty','thirty','forty','fifty','sixty',
        'seventy','eighty','ninety']

small = ['','one','two','three','four','five','six','seven','eight',
         'nine','ten','eleven','twelve','thirteen','fourteen','fifteen',
         'sixteen','seventeen','eighteen','nineteen']

def words(num):
    num = int(num)
    if num == 1000:
        return 'onethousand'
    if num > 99:
        if num % 100:
            return "%shundredand%s" % (words(num/100), words(num % 100))
        return "%shundred" % words(num/100)
    if num > 19:
        return tens[num/10] + words(num % 10)
    else:
        return small[num]

def main():

    for i in range(80,130):
        print words(i)

    answer = sum(map(len, (words(n) for n in range(1,1001))))

    print answer

if __name__=='__main__':
    main()
