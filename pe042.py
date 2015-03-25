''' PROBLEM #42:
The nth term of the sequence of triangle numbers is given by, tn = n(n+1); so the first ten triangle numbers are:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
'''

from string import ascii_uppercase as letters
from math import floor, sqrt

def loadWords():
    f = open("words.txt", 'r')
    words = eval("[%s]" % f.read())
    f.close()
    return words

def isTriangleNumber(n):
    s = floor(sqrt(2*n))
    return s * (s + 1) == 2*n

def wordValue(w):
    return sum(letters.index(l)+1 for l in w)

def isTriangleWord(w):
    return isTriangleNumber(wordValue(w))

def main():

    words = loadWords()

    answer = sum(isTriangleWord(w) for w in words)

    print answer

if __name__=='__main__':
    main()
