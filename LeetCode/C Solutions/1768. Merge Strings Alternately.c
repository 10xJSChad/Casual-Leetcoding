char* 
mergeAlternately(
    char * word1,
    char * word2)
{
    // the max length of each word is 100 so char/uint8_t
    // will work just fine, although generally you'd use
    // size_t for something like this I suppose.
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t word1_length = strlen(word1);
    uint8_t word2_length = strlen(word2);

    // allocate an extra byte for the null termination
    char* merged_string = malloc(word1_length + word2_length + 1);
    
    while (i < word1_length || i < word2_length) {
        // j++ is great here because the increment only happens
        // after the char has been assigned.
        if (i < word1_length)
            merged_string[j++] = word1[i];

        if (i < word2_length)
            merged_string[j++] = word2[i];
        ++i;
    }

    // can use calloc to not have to manually null terminate
    merged_string[j] = '\0';
    return merged_string;
}
