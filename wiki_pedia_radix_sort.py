def sort(number, d):
    length = len(number)
    k = 0
    n = 1
    temp = []
    for i in range(length):
        temp.append([0] * length)
    order = [0] * length
    while n <= d:
        for i in range(length):
            lsd = (number[i]  // n) % 10
            temp[lsd][order[lsd]] = number[i]
            order[lsd] += 1

        for i in range(length):
            if order[i] != 0:
                for j in range(order[i]):
                    number[k] = temp[i][j]
                    k += 1
            order[i] = 0
        n *= 10
        k = 0

def main():
    number = [73, 22, 93, 43, 55, 14, 28, 65, 39, 81, 33, 100]
    sort(number, 100)
    print(number)

if __name__ == '__main__':
    main()