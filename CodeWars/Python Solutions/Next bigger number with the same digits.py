def swapper(n, original=-1):
    s = [*str(n)] #Convert n to string, split string to list
    i, end = 1, 1
    possibilities = []
    
    while n > 9:
        num = s.copy() #Copy the list
        num[-end] = s[-i] #Swapping time
        num[-i] = s[-end] #Swapping time vol.2
        num = int("".join(num)) #Back into an integer
        
        #oof owie ouch ugly conditional
        if (((num > n and original == -1) and (num > n)) or
            ((num < n and original != -1) and (num > original))): possibilities.append(num)
        
        if i == len(s):
            end += 1
            i = end
            if(end == len(s)):
                break
        else:
            i += 1
    
    if possibilities == []:
        if original == -1: return -1
        else: return n
    
    return(min(possibilities))

def next_bigger(n):
    ans = swapper(n)
    if(ans == -1): return -1
    
    while True:
        new_ans = swapper(ans, n)
        if ans == new_ans: break
        else: ans = new_ans
            
    return ans
        
    
    
