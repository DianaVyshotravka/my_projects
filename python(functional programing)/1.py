#The first element and the difference of the arithmetic progression are given.
#Describe the recursive function of determining:
#1) n element of the progression;
#2) sums of the first n elements of the progression
def element(a1, b, n):
    result = 0
    if n != 1:
        result = a1 + b + element(0, b, n-1)
        return result
    if n == 1:
        return a1


def rec(d, a1, n, max):
    if n > max:
        return 0
    return a1 + rec(d, a1 + d, n + 1, max)


b1, d, b_n = int(input("input the first element: ")), int(input("Input the difference:")), int(input("Input the number of element you want to find:")),
print(b_n, "element =", element(b1, d, b_n))
print("Summ", rec(d, b1, 1, b_n))