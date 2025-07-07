#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <algorithm>

using namespace std;

/**
 * Uses merge sort to sort the array while counting inversions.
 * Returns the total number of inversions in the array.
 */
long long mergeAndCount(vector<long long> &arr, int low, int high) {
    if (low == high) return 0; // single element, no inversion

    if (high - low == 1) {
        if (arr[low] > arr[high]) {
            swap(arr[low], arr[high]);
            return 1; // one inversion
        }
        return 0;
    }

    int mid = (low + high) / 2;
    long long leftInversions = mergeAndCount(arr, low, mid);
    long long rightInversions = mergeAndCount(arr, mid + 1, high);
    long long inversions = leftInversions + rightInversions;

    // Merge step while counting cross inversions
    vector<long long> merged;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] > arr[j]) {
            merged.push_back(arr[j]);
            inversions += (mid - i + 1); // all elements from i..mid form inversion with arr[j]
            j++;
        } else {
            merged.push_back(arr[i]);
            i++;
        }
    }
    while (i <= mid) merged.push_back(arr[i++]);
    while (j <= high) merged.push_back(arr[j++]);

    // Copy back to original array
    for (int k = low; k <= high; k++)
        arr[k] = merged[k - low];

    return inversions;
}

// Functor wrapper for sorting using merge sort
class Sorting {
public:
    void operator()(vector<long long> &arr, int low, int high) {
        mergeAndCount(arr, low, high);
    }
};

#endif
