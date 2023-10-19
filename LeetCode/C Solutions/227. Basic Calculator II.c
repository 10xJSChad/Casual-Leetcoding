static inline
char* skip(char** s) {
    while (**s && **s == ' ')
        ++(*s);

    return (**s && !isdigit(**s)) ? (*s)++ : *s;
}


int calculate(char* s) {
    int lval = strtol(skip(&s), &s, 10);
    int op   = *skip(&s);

    while (*s) {
        int rval    = strtol(skip(&s), &s, 10);
        int next_op = *skip(&s);

        while ((op == '+' || op == '-') && (next_op == '*' || next_op == '/')) {
            if (next_op == '*') rval *= strtol(skip(&s), &s, 10);
            if (next_op == '/') rval /= strtol(skip(&s), &s, 10);
            next_op = *skip(&s);
        }

        switch (op)
        {
            case '+': lval += rval; break;
            case '-': lval -= rval; break;
            case '/': lval /= rval; break;
            case '*': lval *= rval; break;
        }

        op = next_op;
    }

    return lval;
}
