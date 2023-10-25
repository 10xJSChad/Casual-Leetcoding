/*
 * Slightly lazy solution, tried to avoid doing _too_ much recursion, but
 * that may not have paid off in terms of readability.
 */

bool isMatch(char* str, char* pattern) {
    while (*str) {
        if (*pattern && *(pattern + 1) == '*') {
            char  ch     = *pattern;
            char* next   =  pattern += 2;

            /* Find the next required character */
            while (*next && *(next + 1) == '*')
                next += 2;

            while ((*str) && (ch == *str || ch == '.')) {
                if ((*str == *next || *next == '.') && isMatch(str, pattern))
                    return true;

                ++str;
            }

            if ((*str + *next) == 0)
                pattern = next;

        } else if (*pattern == *str || *pattern == '.') {
            ++pattern;
            ++str;
        } else {
            break;
        }
    }


    /* Just skip through these so the return value is correct */
    while (*pattern && *(pattern + 1) == '*')
        pattern += 2;

    return (*str + *pattern) == 0;
}
