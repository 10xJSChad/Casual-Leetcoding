/*
 * I don't love the code here at all, but it works
 * and it works pretty damn well.
 *
 * No cheeky strlen ahead of time like most other C solutions,
 * just raw char for char string readin', as it should be. :)
 */


/* luv me macros, simple as */
#define STATE_NONE    0
#define STATE_IPV4    1
#define STATE_IPV6    2

char*
validIPAddress(char* queryIP)
{
    int state       = STATE_NONE;
    int digits      = 0;
    int separators  = 0;

    do {
        /* isxdigit returns true if the char is a hex digit */
        if (isxdigit(*queryIP)) {
            ++digits;

            /* Possibly determine what kind of address to treat it as */
            if (state == STATE_NONE && (!isdigit(*queryIP) || digits > 3))
                state = STATE_IPV6;
            else if (state == STATE_IPV4 && (!isdigit(*queryIP)))
                return "Neither";

        } else {
            if (*queryIP != '\0')
                ++separators;

            /* 
             * DEFINITELY determine what kind of address to treat it as.
             * Unless *queryIP fails both the conditions, then the address
             * is invalid, and we return "Neither" at the end.
             */
            if (state == STATE_NONE)
                if (*queryIP == '.')
                    state = STATE_IPV4;

                if (*queryIP == ':')
                    state = STATE_IPV6;

            /* IPv4 Validation */
            if (state == STATE_IPV4) {
                /* Validate digits */
                if (digits > 0 && digits < 4) {
                    /* leading zero check */
                    if (digits > 1 && *(queryIP - digits) == '0')
                        return "Neither";

                    if (digits == 3)
                        /* I felt like this was better than atoi'ing char by char as it's being read. */
                        if (*(queryIP - 3) >= '2' && *(queryIP - 2) >= '5' && *(queryIP - 1) > '5')
                            return "Neither";
                } else {
                    return "Neither";
                }

                /* Validate separators, IPv4 must have three. */
                if (separators > 3 || (*queryIP == '\0' && separators < 3))
                    return "Neither";
            }
            /* IPv6 Validation, simpler than IPv4 */
            if (state == STATE_IPV6) {
                /* 
                 * Separator and digit validation rolled into one if statement as there is
                 * no need to perform leading zero or value checks here.
                 */
                if (digits == 0 || digits > 4 || separators > 7 || (*queryIP == '\0' && separators < 7))
                    return "Neither";
            }

            /* By now the state would have been changed if the address was valid */
            if (state == STATE_NONE)
                return "Neither";

            digits = 0;
        }
    } while (*queryIP++);

    return state == STATE_IPV4 ? "IPv4" : "IPv6";
}
