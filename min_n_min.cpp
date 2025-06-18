// template to find the fist minimum and the second minimum in an array
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int first_min = INT_MAX, second_min = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < first_min) {
            second_min = first_min;
            first_min = arr[i];
        } else if (arr[i] < second_min && arr[i] != first_min) {
            second_min = arr[i];
        }
    }

    return 0;
}