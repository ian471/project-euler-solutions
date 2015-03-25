''' PROBLEM #19:
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
'''


def main():

    weekday = 1 # monday
    total = 0
    for year in range(1900, 2001):
        numdays = [31,
                   28 + bool(not year % 4 and
                             (year % 100 or not year % 400)),
                   31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        for monthdays in numdays:
            if year > 1900:
                total += weekday == 0
            weekday = (weekday + monthdays) % 7

    print total

if __name__=='__main__':
    main()
