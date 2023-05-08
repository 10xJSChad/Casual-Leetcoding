int
numJewelsInStones(
    char* jewels,
    char* stones)
{
    int i = 0, ans = 0;
    char* jewels_lookup_array = \
        (char*) calloc(127, sizeof(char));
    
    for (int i = 0; jewels[i] != '\0'; ++i)
        jewels_lookup_array[jewels[i]] = jewels[i];

    for (int i = 0; stones[i] != '\0'; ++i)
        if (jewels_lookup_array[stones[i]])
            ++ans;

    return ans;
}
