#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define PLUS        '+'
#define MINUS       '-'
#define MULTIPLY    '*'
#define DIVIDE      '/'
#define LPAREN      '('
#define RPAREN      ')'


#define IS_PRIORITY_OPERATOR(operator)                                              \
    ((*operator == MULTIPLY || *operator == DIVIDE))

#define IS_OPERATOR(ch)                                                             \
    ((ch == PLUS || ch == MINUS || ch == MULTIPLY || ch == DIVIDE || ch == RPAREN))

#define IS_EXPRESSION(val)                                                          \
    (*(val) == LPAREN || (*(val) == MINUS && *(val + 1) == LPAREN))

#define EXTRACT_VALUE(val, ptr)                                                     \
    (IS_EXPRESSION(val) ? (*val == MINUS ? -evaluate(++val, ptr)                    \
                                         : evaluate(++val, ptr))                    \
                        : atof(val))


char*
next_operator(char* from)
{
    if (from == NULL)
      return NULL;

    ++from;

    while (*from && !IS_OPERATOR(*from))
        ++from;

    return (*from) ? from : NULL;
}


char*
next_value(char* from)
{

    if (from == NULL)
      return NULL;

    ++from;
    while (*from && isspace(*from))
        ++from;

    return (*from) ? from : NULL;
}


double
perform_operation(double lval,
                  double rval,
                  char   op)
{
    switch (op)
    {
        case PLUS:
            return lval + rval;

        case MINUS:
            return lval - rval;

        case MULTIPLY:
            return lval * rval;

        case DIVIDE:
            return lval / rval;

        default:
            exit(1); /* this is very bad */
    }
}


double
evaluate(char *expr, char** endptr)
{
    double lval, rval;
    char   *tail, *head, *op, *next_op;

    /* Skip leading spaces */
    while (isspace(*expr))
        ++expr;

    lval = EXTRACT_VALUE(expr, &expr);
    op = next_operator(expr);

    while (op && *op != RPAREN) {
        tail    = next_value(op);
        rval    = EXTRACT_VALUE(tail, &tail);
        next_op = next_operator(tail);

        while (next_op && !IS_PRIORITY_OPERATOR(op) && IS_PRIORITY_OPERATOR(next_op)) {
            head    = next_value(next_op);
            rval    = perform_operation(rval, EXTRACT_VALUE(head, &head), *next_op);
            next_op = next_operator(head);
        }

        lval = perform_operation(lval, rval, *op);
        op   = next_op;
    }

    if (endptr)
        *endptr = op;

    return lval;
}


double 
calculate(const char* expression) 
{
  return evaluate(expression, NULL);
}
