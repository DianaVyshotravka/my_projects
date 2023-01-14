#Calculate the sum of the elements of the given row
# of the array located at a distance of one element, starting from the first
def mas(n, element):
    s = []
    summ = 0
    for i in range(n):
        print("Input the", i, "line of your array:")
        row = input().split()
        for j in range(len(row)):
            row[j] = float(row[j])
        s.append(row)
    print("Your array:")
    for i in range(n):
        for j in range(len(row)):
            print(s[i][j], end=" ")
        print()
    for i in range(0, n+1, 2):
        summ += s[element][i]
    return summ


n = int(input("Input the number of lines:"))
el = int(input("input the number of line:"))
print("Result:", mas(n, el))