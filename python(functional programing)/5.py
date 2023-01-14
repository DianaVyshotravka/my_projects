#Write a program for finding the largest and smallest elements
# in even columns of a rectangular matrix
def mas(rows):
    s = []
    s_min = []
    for i in range(rows):
        print("Input the", i, "row of your array:")
        line = [float(j) for j in input().split()]
        s.append(line)
    print("Your array:")
    for i in range(rows):
        for j in range(len(line)):
            print(s[j][i], end = " ")
        print()
    for i in range(0, rows, 2):
        min_row = []
        for j in range(len(line)):
            min_row.append(s[i][j])
        s_min.append(min(min_row))
    result = max(s_min)
    return result


rows = int(input("input the number of rows:"))
print("Your result", mas(rows))




    



