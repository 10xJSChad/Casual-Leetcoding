int 
comparator (
    int* a, 
    int* b)
{
  return *a - *b;
}

int 
numRescueBoats (
    int* people, 
    int peopleSize, 
    int limit)
{
    qsort(people, peopleSize, sizeof(int), comparator);
    int min = 0, ans = 0;
    int max = peopleSize-1;

    while (min <= max) {
        ans++;
        if (people[min] + people[max] <= limit) {
            min++;
            max--;
        } else {
            max--; 
        }
    }

    return ans;
}
