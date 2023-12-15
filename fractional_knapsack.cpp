#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio; // value per unit weight
};

// Comparison function to sort items by ratio in descending order
bool compare(Item i1, Item i2) {
    return i1.ratio > i2.ratio;
}

void fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    int n = items.size();
    double totalValue = 0.0;

    cout << "Step\tItem\tWeight\tValue\tRatio\tFraction Taken\n";

    for (int i = 0; i < n && capacity > 0; ++i) {
        double fraction = min(1.0, static_cast<double>(capacity) / items[i].weight);
        double takenValue = fraction * items[i].value;

        cout << i + 1 << "\t" << "Item " << i + 1 << "\t" << items[i].weight << "\t" << items[i].value << "\t"
             << items[i].ratio << "\t" << fraction << "\n";

        totalValue += takenValue;
        capacity -= static_cast<int>(fraction * items[i].weight);
    }

    cout << "\nTotal Value: " << totalValue << endl;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter the weight and value for each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
        items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    cout << "\nOriginal Items:\n";
    cout << "Item\tWeight\tValue\tRatio\n";
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << "\t" << items[i].weight << "\t" << items[i].value << "\t" << items[i].ratio << "\n";
    }

    cout << "\nFractional Knapsack Solution:\n";
    fractionalKnapsack(items, capacity);

    return 0;
}
