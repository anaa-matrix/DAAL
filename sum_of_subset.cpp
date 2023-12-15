#include <iostream>
#include <vector>

using namespace std;

void displaySubset(const vector<int>& subset) {
    cout << "Subset: { ";
    for (int i = 0; i < subset.size(); ++i) {
        cout << subset[i];
        if (i < subset.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

void subsetSumUtil(const vector<int>& nums, vector<int>& subset, int target, int index) {
    if (target == 0) {
        displaySubset(subset);
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        if (target >= nums[i]) {
            subset.push_back(nums[i]);
            subsetSumUtil(nums, subset, target - nums[i], i + 1);
            subset.pop_back(); // Backtrack
        }
    }
}

void subsetSum(const vector<int>& nums, int target) {
    vector<int> subset;
    subsetSumUtil(nums, subset, target, 0);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    cout << "Stepwise solution for Subset Sum Problem:" << endl;
    subsetSum(nums, target);

    return 0;
}
