#include <iostream>
#include <sstream>
#include <string> 

int reverse(int x) {
    std::string reversed;
    std::string s = std::to_string(x);
    bool isNegative = false;

    if (x < 0) { isNegative = true; }

    int n = s.length();
    for (int i = s.length() - 1; i >= 0; i--)
        reversed += s[i];

    std::stringstream intValue(reversed);
    intValue >> x;

    if (isNegative) { x *= -1; }
    if (x >= 2147483647) { x = 0; }
    if (x <= -2147483648) { x = 0; }
    return x;
}