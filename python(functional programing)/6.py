#Arrange the rows of a rectangular matrix of integers
# so that the number of identical elements in each row increases.
# Output the number of the first column
# that does not contain a single negative element.
def mas(lines):
    s = []
    k = 0
    counter = 0
    for i in range(lines):
        print("Input the", i, "line of your array:")
        row = input().split()
        for j in range(len(row)):
            row[j] = float(row[j])
            if k < row.count(row[j]):
                k = row.count(row[j])

        row.append(k)
        s.append(row)
        k = 0

    print("Your array:")
    for i in range(lines):
        for j in range(len(row)-1):
            print(s[i][j], end=" ")
        print()
    for run in range(lines - 1):
        for i in range(lines - 1 - run):
            if s[i][len(row)-1] > s[i+1][len(row)-1]:
                for j in range(len(row)):
                    s[i][j], s[i+1][j] = s[i+1][j], s[i][j]
    print("Your result:")
    for i in range(lines):
        for j in range(len(row) - 1):
            print(s[i][j], end=" ")
        print()
    for j in range(len(row) - 1):
        for i in range(lines):
            if s[i][j] >= 0:
                counter += 1
        if counter == lines:
            return j
        counter = 0


l = int(input("Input the number of lines in your array"))
result = mas(l)
print("a number of column that does not contain negative elements:", result)