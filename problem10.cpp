#include <iostream>
#include <vector>
using namespace std;

int kthElementUtil(const vector<int>& arr1, const vector<int>& arr2, int m, int n, int k) {
    if (m == 0)
        return arr2[k - 1];
    if (n == 0)
        return arr1[k - 1];
    if (k == 1)
        return min(arr1[0], arr2[0]);

    int i = min(k / 2, m), j = min(k / 2, n);
    if (arr1[i - 1] < arr2[j - 1]) {
        vector<int> newArr1(arr1.begin() + i, arr1.end());
        return kthElementUtil(newArr1, arr2, m - i, n, k - i);
    }
    else {
        vector<int> newArr2(arr2.begin() + j, arr2.end());
        return kthElementUtil(arr1, newArr2, m, n - j, k - j);
    }
}

int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int m = arr1.size(), n = arr2.size();
    return kthElementUtil(arr1, arr2, m, n, k);
}

int main() {
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int k = 5;
    cout << kthElement(arr1, arr2, k) << endl;

    vector<int> arr3 = { 100, 112, 256, 349, 770 };
    vector<int> arr4 = { 72, 86, 113, 119, 265, 445, 892 };
    k = 7;
    cout << kthElement(arr3, arr4, k) << endl;

    return 0;
}
