'''
' Insertion Sort, Page 18 (CRLS section 2.1)
' @author Rahul Kadyan
'''

def insertion_sort(A):
    for j in xrange(1, len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i + 1] = A[i]
            i -= 1
        A[i + 1] = key


if __name__ == '__main__':
    n = int(raw_input())
    A = list(map(int, raw_input().split()))

    insertion_sort(A)

    print ' '.join(map(str, A)) + ' '
