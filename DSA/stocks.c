

int maxProfit(int *prices, int pricesSize)
{

    int min = 100000, max = -10000;

    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }

        if (prices[i] - min > max)
        {
            max = prices[i] - min;
        }
    }

    return max;
    
}
