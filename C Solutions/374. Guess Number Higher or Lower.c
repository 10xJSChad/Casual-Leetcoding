int guessNumber(int n){
    long min = 1;
    long max = n;
    while(min <= max){
        long mid = (min + max) / 2;
        int result = guess(mid);
        if(result == -1) max = mid - 1;
        else if(result == 1) min = mid + 1;
        else return mid;
    }
	return min;
}
