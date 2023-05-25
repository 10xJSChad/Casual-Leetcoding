typedef struct RomanNumeral {
    char* roman_value;
    int decimal_value;
} RomanNumeral;


char*
intToRoman(
    int num)
{
    /*
     * I was just itching to use a struct for this
     * really no reason to, a lot more concise to just go
     * ahead and use two arrays or something instead.
     */
    RomanNumeral roman_i = {.roman_value = "I", .decimal_value = 1};
    RomanNumeral roman_iv = {.roman_value = "IV", .decimal_value = 4};
    RomanNumeral roman_v = {.roman_value = "V", .decimal_value = 5};
    RomanNumeral roman_ix = {.roman_value = "IX", .decimal_value = 9};
    RomanNumeral roman_x = {.roman_value = "X", .decimal_value = 10};
    RomanNumeral roman_xl = {.roman_value = "XL", .decimal_value = 40};
    RomanNumeral roman_l = {.roman_value = "L", .decimal_value = 50};
    RomanNumeral roman_xc = {.roman_value = "XC", .decimal_value = 90};
    RomanNumeral roman_c = {.roman_value = "C", .decimal_value = 100};
    RomanNumeral roman_cd = {.roman_value = "CD", .decimal_value = 400};
    RomanNumeral roman_d = {.roman_value = "D", .decimal_value = 500};
    RomanNumeral roman_cm = {.roman_value = "CM", .decimal_value = 900};
    RomanNumeral roman_m = {.roman_value = "M", .decimal_value = 1000};

    RomanNumeral romans[13] = {roman_m, roman_cm, roman_d, roman_cd, roman_c, roman_xc,
                               roman_l, roman_xl, roman_x, roman_ix, roman_v, roman_iv, roman_i};

    // couldnt be bothered to calculate the actual max bytes
    char* ans = calloc(1, 500);

loop_top:;
    for (int i = 0; i < 13; ++i) {
        if ((num - romans[i].decimal_value) >= 0) {
            num -= romans[i].decimal_value;
            strcat(ans, romans[i].roman_value);
            goto loop_top;
        }
    }
    return ans;
}
