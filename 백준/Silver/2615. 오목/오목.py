from itertools import product


def check(board, x, y, color):
    return (x, y) in product(range(19), range(19)) and board[x][y] == color


def is_five(board, x, y):
    if board[x][y]==0:
        return False
    dirs = [(1,0), (0,1), (1,1), (-1, 1)]
    for dx, dy in dirs:
        for k in range(5):
            if not check(board, x+k*dx, y+k*dy, board[x][y]):
                break
        else:
            if not check(board, x+5*dx, y+5*dy, board[x][y]) and not check(board, x-dx, y-dy, board[x][y]):
                return True
    return False


def main():
    board = [list(map(int, input().split())) for _ in range(19)]
    for i, j in product(range(19), range(19)):
        if is_five(board, i, j):
            print(board[i][j], i+1, j+1)
            break
    else:
        print(0)

if __name__ == "__main__":
    main()