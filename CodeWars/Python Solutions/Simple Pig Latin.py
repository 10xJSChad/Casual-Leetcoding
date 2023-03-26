def pig_it(text):
    text = text.split()
    for i, x in enumerate(text):
        if x.isalpha():
            text[i] = x[1:] + x[:1] + "ay"
    return(" ". join(text))        
