#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
PROBLEM: Best Time to Buy and Sell Stock
- You are given an array prices where prices[i] is the price of a given stock on the ith day.
- You want to maximize your profit by choosing a single day to buy one stock
  and choosing a different day in the future to sell that stock.
- Return the maximum profit you can achieve from this transaction.
- If you cannot achieve any profit, return 0.

ALGORITHM EXPLANATION:
The key insight is that we want to buy at the lowest price we've seen so far
and sell at the current price to maximize profit.

1. Keep track of minimum price seen so far (mini)
2. For each day, calculate potential profit if we sell today (current_price - mini)
3. Update maximum profit if current profit is better
4. Update minimum price if current price is lower

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - only using constant extra space
*/

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int profit = 0;    // Maximum profit we can achieve
        int mini = arr[0]; // Minimum price seen so far (best day to buy)

        for (int i = 1; i < arr.size(); i++)
        {
            // Calculate profit if we sell today
            int val = arr[i] - mini;

            // Update maximum profit
            profit = max(profit, val);

            // Update minimum price (better buying opportunity)
            mini = min(mini, arr[i]);
        }
        return profit;
    }
};

// Helper function to test the solution
void testMaxProfit(vector<int> prices, string testName)
{
    Solution sol;
    int result = sol.maxProfit(prices);

    cout << "\n"
         << testName << ":" << endl;
    cout << "Prices: [";
    for (int i = 0; i < prices.size(); i++)
    {
        cout << prices[i];
        if (i < prices.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    cout << "Maximum Profit: " << result << endl;

    // Find the actual buy and sell days for demonstration
    int mini = prices[0], buyDay = 0, sellDay = 0, maxProfit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - mini > maxProfit)
        {
            maxProfit = prices[i] - mini;
            sellDay = i;
            // Find the buy day
            for (int j = 0; j < i; j++)
            {
                if (prices[j] == mini)
                {
                    buyDay = j;
                    break;
                }
            }
        }
        if (prices[i] < mini)
        {
            mini = prices[i];
        }
    }

    if (result > 0)
    {
        cout << "Buy on day " << buyDay << " (price: " << prices[buyDay]
             << "), Sell on day " << sellDay << " (price: " << prices[sellDay] << ")" << endl;
    }
    else
    {
        cout << "No profitable transaction possible" << endl;
    }
}

int main()
{
    cout << "=== Best Time to Buy and Sell Stock ===" << endl;

    // Test Case 1: Normal case with profit
    testMaxProfit({7, 1, 5, 3, 6, 4}, "Test Case 1");

    // Test Case 2: Decreasing prices (no profit)
    testMaxProfit({7, 6, 4, 3, 1}, "Test Case 2");

    // Test Case 3: Single element
    testMaxProfit({5}, "Test Case 3");

    // Test Case 4: Two elements
    testMaxProfit({1, 5}, "Test Case 4");

    // Test Case 5: All same prices
    testMaxProfit({3, 3, 3, 3}, "Test Case 5");

    // Test Case 6: Increasing prices
    testMaxProfit({1, 2, 3, 4, 5}, "Test Case 6");

    cout << "\n=== Step-by-step explanation for [7, 1, 5, 3, 6, 4] ===" << endl;
    vector<int> example = {7, 1, 5, 3, 6, 4};
    int profit = 0, mini = example[0];

    cout << "Initial: profit = 0, mini = " << mini << endl;

    for (int i = 1; i < example.size(); i++)
    {
        int val = example[i] - mini;
        cout << "Day " << i << ": price = " << example[i]
             << ", profit if sell today = " << example[i] << " - " << mini << " = " << val;

        profit = max(profit, val);
        mini = min(mini, example[i]);

        cout << " → profit = " << profit << ", mini = " << mini << endl;
    }

    return 0;
}
