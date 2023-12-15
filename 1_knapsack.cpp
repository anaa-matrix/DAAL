#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    int dp[n + 1][maxWeight + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int maxProfit = dp[n][maxWeight];

    vector<int> selectedItems(n, 0);
    int i = n, j = maxWeight;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            selectedItems[i - 1] = 1;
            j -= weight[i - 1];
        }
        i--;
    }

    cout << "Items selected (1 for taken, 0 for not taken): ";
    for (int item : selectedItems)
    {
        cout << item << " ";
    }
    cout << endl;

    return maxProfit;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> weight;
    vector<int> value;
    cout << "Enter elements (weight, value): ";
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        weight.push_back(a);
        value.push_back(b);
    }
    int maxWeight;
    cout << "Enter the maximum weight capacity: ";
    cin >> maxWeight;
    int cost = knapsack(weight, value, n, maxWeight);
    cout << "The maximum profit is: " << cost << endl;
    return 0;
}