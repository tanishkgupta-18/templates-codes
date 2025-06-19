## Template to find the fist minimum and the second minimum in an array

```
pair<int, int> findFirstAndSecondMin(const vector<int>& nums) {
    int firstMin = INT_MAX, secondMin = INT_MAX;

    for (int num : nums) {
        if (num < firstMin) {
            secondMin = firstMin;
            firstMin = num;
        } else if (num > firstMin && num < secondMin) {
            secondMin = num;
        }
    }

    // If secondMin wasn't updated, there is no valid second minimum
    if (secondMin == INT_MAX) {
        cout << "No valid second minimum exists.\n";
        return {firstMin, -1};
    }

    return {firstMin, secondMin};
}
```