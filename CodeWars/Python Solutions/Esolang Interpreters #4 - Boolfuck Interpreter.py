def get_matching_bracket(index, code):
    counter = 0  
    if code[index] == "[":
        for i in range(index, len(code)):
            if code[i] == "[": counter += 1
            elif code[i] == "]": counter -= 1

            if counter == 0: 
                return(i)
    else:
        for i in range(index, 0, -1):
            if code[i] == "[": counter -= 1
            elif code[i] == "]": counter += 1

            if counter == 0: 
                return(i)

def input_to_bits(input):
    input_bits = []
    for x in input:
        input_bits.append(format(ord(x), 'b'))
        
    for i, x in enumerate(input_bits):
        while(len(input_bits[i]) < 8): input_bits[i] = "0" + input_bits[i]
               
        #It is already in the right order and on its own does not need to be reversed
        #However, if left as is, it will be reversed into the wrong order at the end of the interpretation
        input_bits[i] = input_bits[i][::-1] 
    return ''.join(input_bits)

def boolfuck(code, input=""):
    tape = [0] * 30000
    pointer = code_index = input_index = 0
    input_converted = input_to_bits(input)
    
    #Parsing time
    output = ""
    while code_index < len(code):
        instruction = code[code_index]
        if instruction == '+': tape[pointer] = int(not tape[pointer])
        if instruction == '<': pointer += 1
        if instruction == '>': pointer -= 1
        if instruction == '[' and tape[pointer] == 0: 
            code_index = get_matching_bracket(code_index, code)
        if instruction == ']' and tape[pointer] == 1:
            code_index = get_matching_bracket(code_index, code) 
        if instruction == ';': 
            output += str(tape[pointer])
        if instruction == ',' and input_index < len(input_converted): 
                tape[pointer] = int(input_converted[input_index])
                input_index += 1
        code_index += 1
    
    #Padding the output until it's divisible by eight
    while(len(output) > 0 and len(output) % 8 != 0):
        output += "0"
    
    #Fixing up the output
    buffer = ""
    output_formatted = ""
    for x in output:
        buffer += x
                
        if len(buffer) == 8:
            #Reverse into the correct order, convert to char, add to formatted output, clear buffer
            buffer = buffer[::-1]
            converted_char = chr(int(buffer, 2))
            output_formatted += converted_char
            buffer = ""
            
    return(output_formatted)
