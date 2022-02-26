if __name__ == '__main__':
    a, b = int(input()), int(input())
    print(a * (b % 10), a * (b // 10 % 10), a * (b // 100), a * b)
