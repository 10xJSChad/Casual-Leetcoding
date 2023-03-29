def validate_battlefield(field):
    scanned_grid = [[]]
    get_val = lambda a : field[a[0]][a[1]]
    for i in range(10):
        coords = [offset for j in range(i+1) for 
             offset in [[9-j, i-j], [9-i+j, 9-j], 
                          [j, 9-i+j], [j, i-j]]]
            
        scanned_grid[0].append([[get_val(coords[(int((k * 4) / 4) + (4 * l))]) for 
                k in range(4) for l in range(int(len(coords) / 4))][j:j + i+1] 
                                         for j in range(0, (i + 1) * 4, i+1)])
        
        scanned_grid.append(str(field) + str([[field[i][j] for 
    i, row in enumerate(field)] for j in list(range(0, 10))]))
    
    
    search = lambda a : str(scanned_grid[1]).count(str([1 for x in range(a)])[1:-1])
    return(list(map(search, [1, 2, 3, 4])) == [40, 7, 3, 1] and 
                        not str(scanned_grid[0]).count("1, 1"))
