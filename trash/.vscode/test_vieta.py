
moves = list(map(int, input("Введите зоны: ").split()))
n = len(moves)
ideal_move = 0

for i in range(n): 
    for j in range(i, n): 
        path = moves[i:j + 1] 
        if path == path[::-1]:  
            ideal_move = max(ideal_move, j - i + 1)  

if ideal_move == 0:
    print(0)
else:
    print(ideal_move)