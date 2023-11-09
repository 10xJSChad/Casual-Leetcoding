int numJewelsInStones(char* jewels, char* stones) {
    char jewels_arr[123] = {0};
    int ans = 0;

    while (*jewels)
        jewels_arr[*(jewels++)] = 1;

    while (*stones)
        if (jewels_arr[*(stones++)])
            ++ans;

    return ans;
}
