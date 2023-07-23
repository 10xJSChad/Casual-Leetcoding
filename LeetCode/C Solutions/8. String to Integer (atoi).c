int 
myAtoi(char *str)
{
    long result = 0;
    int  sign   = 1;

    while (*str == ' ')
        ++str;

    if (*str == '+' || *str == '-') {
        sign = (*str == '+') ? 1 : -1;
        ++str;
    }

    while (isdigit(*str)) {
        result *= 10;
        result += *str - '0';

        if (result > INT_MAX)
            return ((sign == 1) ? INT_MAX : INT_MIN);

        ++str;
    }

    return result * sign;
}
