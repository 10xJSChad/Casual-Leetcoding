class interpreter:
    class instructions:      
        #interpreter.instructions methods will be very straightforward, little care for safety here :)   
        def call(args):
            global IDX
            RET_STACK.append(IDX)
            IDX = LABEL[args['x']]
            
        def msg(line):
            #inefficiency time
            global OUTPUT
            in_string, comma = False, False
            built_line = ""
            for char in line:
                if char == '\'': 
                    in_string = not in_string
                    comma = False if comma else comma
                if in_string and char != '\'': built_line += char    
                if not in_string and char == ',': comma = True
                if not in_string and char.isalpha() and comma:
                    built_line += str(REG[char])
                    comma = False
            OUTPUT = built_line
            
        def ret():
            global IDX
            IDX = RET_STACK[0]
            RET_STACK.pop(0)
            
        def mov(args):
            if not isinstance(args['x'], str): return
            val_in = REG[args['y']] if isinstance(args['y'], str) else args['y']
            REG[args['x']] = val_in
        
        def end():
            global END
            END = True
            
        def inc(args): REG[args['x']] += 1
        def dec(args): REG[args['x']] -= 1
        def add(args): REG[args['x']] += REG[args['y']] if isinstance(args['y'], str) else args['y']
        def sub(args): REG[args['x']] -= REG[args['y']] if isinstance(args['y'], str) else args['y']
        def mul(args): 
            REG[args['x']] *= REG[args['y']] if isinstance(args['y'], str) else args['y']
            REG[args['x']] = int(REG[args['x']])
        def div(args): 
            REG[args['x']] /= REG[args['y']] if isinstance(args['y'], str) else args['y']
            REG[args['x']] = int(REG[args['x']])
        
        
    class utility:
        def clean_line(line):
            return " ".join(line.split()).split(";")[0]
        
        def parse_arguments(line, arg_count):
            split_args = [int(arg) if arg.isnumeric() else arg for arg in line.replace(",", "").split()[1:]]
            parsed_args = {
            }
            parsed_args['x'] = split_args[0] if arg_count > 0 else None      
            parsed_args['y'] = split_args[1] if arg_count > 1 else None            
            return parsed_args
        
        def get_instruction(line):
            if line == '': return
            elif line.split()[0] in INST: return INST[line.split()[0]]
        
        def get_register_value(register):
            return REG[register]
        
        def get_labels_and_fill_dict(code):
            for i, line in enumerate(code):
                split_line = line.strip().split(":")
                label_name = split_line[0] if len(split_line) == 2 and split_line[0].count(" ") == 0 else None
                if label_name: LABEL[label_name] = i
        
        
    def interperet(code):
        global IDX
        interpreter.utility.get_labels_and_fill_dict(code)
        while IDX < len(code):
            instruction = interpreter.utility.get_instruction(code[IDX])
            if instruction:
                line = interpreter.utility.clean_line(code[IDX]) if instruction['clean'] else code[IDX]
                args = interpreter.utility.parse_arguments(line, instruction['args'])
                
                if instruction['args'] > 0: instruction['func'](args)
                elif instruction['args'] == 0: instruction['func']()
                else: instruction['func'](line)
                
                if END: return OUTPUT
            if interpreter.utility.clean_line(code[IDX]) != '': print(interpreter.utility.clean_line(code[IDX]), IDX, RET_STACK, REG)
            IDX += 1
        return OUTPUT
    


IDX = 0
REG = {}
INST = {
    'mov': {'func': interpreter.instructions.mov, 'args': 2, 'clean': True},
    'inc': {'func': interpreter.instructions.inc, 'args': 1, 'clean': True},
    'dec': {'func': interpreter.instructions.dec, 'args': 1, 'clean': True},
    'add': {'func': interpreter.instructions.add, 'args': 2, 'clean': True},
    'sub': {'func': interpreter.instructions.sub, 'args': 2, 'clean': True},
    'mul': {'func': interpreter.instructions.mul, 'args': 2, 'clean': True},
    'div': {'func': interpreter.instructions.div, 'args': 2, 'clean': True},
    'call': {'func': interpreter.instructions.call, 'args': 1, 'clean': True},
    'ret': {'func': interpreter.instructions.ret, 'args': 0, 'clean': True},
    'end': {'func': interpreter.instructions.end, 'args': 0, 'clean': True},
    'msg': {'func': interpreter.instructions.msg, 'args': -1, 'clean': False},
} 
LABEL = {}
RET_STACK = []
END = False
OUTPUT = ""

def assembler_interpreter(program):
    global IDX, REG, INST, LABEL, RET_STACK, END, OUTPUT
    IDX = 0 ; REG, LABEL = {}, {}; RET_STACK = []; END = False; OUTPUT = ""
    if len(LABEL) != 0: return
    #return interpreter.interperet(["mov a, 500", "dec a", "mov b, 50"])
    return interpreter.interperet([line for line in program.split('\n')])
