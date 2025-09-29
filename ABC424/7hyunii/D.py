import sys
input = sys.stdin.readline
from itertools import combinations

t = int(input())
for _ in range(t):
    h, w = map(int, input().split())
    board = []
    for _ in range(h):
        board.append(list(input().strip()))

    # B = 검은색 개수 찾기
    black = []
    for i in range(h):
        for j in range(w):
            if board[i][j] == '#':
                black.append((i, j))
    
    B = len(black)

    # 가능한 상황인가?
    def check(board, h, w):
        for i in range(h-1):
            for j in range(w-1):
                if (board[i][j] == "#" and board[i][j+1] == "#" and board[i+1][j] == "#" and board[i+1][j+1] == "#"):
                    return False
        return True
    
    # k개 씩 칠해보기
    for k in range(B + 1):
        Done = False
        for select in combinations(black, k):

            # 보드 체크
            check_board = []
            for row in board:
                check_board.append(row[:])
  
            for i, j in select:
                check_board[i][j] = '.'
            
            Check = True
            for i in range(h-1):
                for j in range(w-1):
                    if (check_board[i][j] == "#" and check_board[i][j+1] == "#" and check_board[i+1][j] == "#" and check_board[i+1][j+1] == "#"):
                        Check = False
                        break

                if not Check:
                    break

            if Check:
                print(k)
                Done = True
                break
        
        if Done:
            break