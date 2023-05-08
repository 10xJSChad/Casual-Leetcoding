def encode_rail_fence_cipher(string, n):
    rails = []
    current_rail, direction = 0, 1
    for i in range(0, n):
        rails.append([])
        
    j = 0
    while j < len(string):
        rails[current_rail].append(string[j])
        if(current_rail == 0): direction = 1
        if(current_rail == n-1): direction = -1   
        current_rail += direction; j += 1
        
    return "".join(sum(rails, []))

def decode_rail_fence_cipher(string, n):
    if(string == ""): return ""
    #mega tired, bad solution coming up :)
    rails = [] #this one will come back
    rails_values = []
    for i in range(0, n):
        rails_values.append(0)
        rails.append("")
    
    current_rail, direction = 0, 1
    for x in string:
        rails_values[current_rail] += 1
        current_rail += direction
        if(current_rail == 0): direction = 1
        if(current_rail == n-1): direction = -1  
    
    
    #ok time to decode, way cleaner ways to do it than what ive decided to do but :shrug:
    i, j = 0, 0
    while j < len(rails):
        #reconstructing the rails list
        rails[j] += string[i]
        rails_values[j] -= 1
        if(rails_values[j] <= 0):
            rails[j] = [*rails[j]] #listin' time
            j += 1
        i += 1
        
    #and now we finish it off
    current_rail, direction = 0, 1
    decoded_ans = ""
    while len(decoded_ans) < len(string):
        print(rails, current_rail)
        decoded_ans += rails[current_rail][0]; rails[current_rail].pop(0)
        if(current_rail == 0): direction = 1
        if(current_rail == n-1): direction = -1   
        current_rail += direction;
    
    return(decoded_ans)
