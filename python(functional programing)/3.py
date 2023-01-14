#Write a program that swaps the first element
#with the smallest even element of a one-dimensional array (vector)
# of n elements of integer type
def mas(n):
    s = []
    for i in range(n):
        print("enter", i, "element of array:")
        s.append(float(input()))
    print("Your array: ", s)
    k = s[0]
    k1 = 0
    for i in range(n):
        if s[i] % 2 == 0 and s[i] <= k:
            k = s[i]
            k1 = i
    s[0], s[k1] = s[k1], s[0]
    return s


n = int(input("Input the number of elements:"))
print("Result: ", mas(n))



