''' PROBLEM #24:
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
012 021 102 120 201 210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
'''

from math import factorial

def numPermutations(n):
    """
    What is the number of permutations of n things?
    """
    return factorial(n)

def getPermutation(lst, n):
    """
    Get the nth lexicographic permutation of lst
    """
    if len(lst) <= 1:
        return lst[:]
    # Once we choose a first item, the rest of the list has p permutations
    p = numPermutations(len(lst)-1)
    first = n // p
    return [lst[first]] + getPermutation(lst[:first]+lst[first+1:], n-first*p)

def main():

    answer = ''.join(getPermutation(list('0123456789'), 999999))

    print answer

if __name__=='__main__':
    main()
