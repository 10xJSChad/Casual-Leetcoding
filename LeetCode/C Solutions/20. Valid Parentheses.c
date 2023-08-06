/*
 * Super simple solution.
 * You could go ahead and write one that doesn't use a stack and instead
 * just repeatedly checks the next and previous chars, but I didn't.
 */


#define LPAREN   '('
#define RPAREN   ')'
#define LBRACKET '['
#define RBRACKET ']'
#define LBRACE   '{'
#define RBRACE   '}'


bool 
isValid (char* s)
{
    int  i = 0;
    char stack[10000] = { 0, };

    do {
        if (*s == LPAREN || *s == LBRACKET || *s == LBRACE)
            stack[++i] = *s;

        switch (*s)
        {
            case RPAREN:
                if (stack[i--] != LPAREN)
                    return false;
                break;

            case RBRACKET:
                if (stack[i--] != LBRACKET)
                    return false;
                break;

            case RBRACE:
                if (stack[i--] != LBRACE)
                    return false;
                break;
        }
        
    } while (*s++);

    return i == 0;
}
