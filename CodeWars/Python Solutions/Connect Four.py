def who_is_winner(pieces_position_list):
    board = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]

    def parse_move(move):
        letter_index = {
            "A": 0,
            "B": 1,
            "C": 2,
            "D": 3,
            "E": 4,
            "F": 5,
            "G": 6,
        }
        
        side_value = {
            "Yellow": 1,
            "Red": 2,
        }
        move = move.split("_")
        move_column = letter_index.get(move[0])
        move_side = side_value.get(move[1])
        return(move_column, move_side)
   
   #Assumes all moves are valid (not played on the wrong turn)
    def apply_move(move):
        i = 5
        column = move[0]
        side = move[1]
        
        while(i >= 0):
            if(board[i][column]) == 0:
                board[i][column] = side
                break
            
            i -= 1
        return(i)
    
    def check_winning_move(row, column):
        side = board[row][column]
        if side == 0: return
        vertical = 1
        horizontal = 1
        diagonalUp = 1
        diagonalDown = 1
              
        halts = {
            "vertDown": False,
            "horizRight": False,
            "diagUpRight": False,
            "diagDownRight": False,
        }
        
        i = 1
        while(i <= 6):
            if(not halts['vertDown'] and row+i <= 5 and board[row+i][column] == side):
                vertical += 1
            else: halts['vertDown'] = True
            
            if(not halts['horizRight'] and column+i <= 6 and board[row][column+i] == side):
                horizontal += 1
            else: halts['horizRight'] = True
            
            if(not halts['diagDownRight'] and column+i <= 6 and row+i <= 5 and board[row+i][column+i] == side):
                diagonalDown += 1
            else: halts['diagDownRight'] = True
            
            if(not halts['diagUpRight'] and column+i <= 6 and row-i >= 0 and board[row-i][column+i] == side):
                diagonalUp += 1
            else: halts['diagUpRight'] = True
            i += 1
            
        if(vertical >= 4 or horizontal >= 4 or diagonalDown >= 4 or diagonalUp >= 4):
            return side
        else: return 0
        
    for x in pieces_position_list:
        parsed_move = parse_move(x)
        row = apply_move(parsed_move)
        for i in range(0, len(board)):
            for j in range(0, len(board[i])):
                result = check_winning_move(i, j)
                if(result == 1): return "Yellow"
                if(result == 2): return "Red"    

    return "Draw"