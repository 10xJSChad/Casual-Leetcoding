int 
maxProfit(
    int* prices, 
    int pricesSize)
{
    int lowest = INT_MAX;
    int max_profit = 0;

    for (int i = 0; i < pricesSize; ++i) {
        if ((prices[i] - lowest) > max_profit)
            max_profit = (prices[i] - lowest);
        
        if (prices[i] < lowest)
            lowest = prices[i];
    }

    return max_profit;
}
