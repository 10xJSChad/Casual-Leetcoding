def spin_words(sentence):
    sentence = sentence.split()
    for i, x in enumerate(sentence):
        if len(x) > 4: sentence[i] = x[::-1]
    return(" ".join(sentence))
