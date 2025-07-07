#ifndef CLOSEST_SOLVER_HPP
#define CLOSEST_SOLVER_HPP

#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>
#include <iostream>

using namespace std;

/**
 * Uses divide and conquer to find the closest pair of points in 2D space.
 * Returns the lexicographically smallest pair in case of ties.
 */
class ClosestSolver {
private:
    vector<pair<long long, long long>> points;
    map<pair<long long, long long>, int> indexMap; // to maintain input order
    vector<pair<long long, long long>> sortedByX;

    // Returns squared Euclidean distance to avoid floating point errors
    long long squaredDistance(const pair<long long, long long> &p1, const pair<long long, long long> &p2) {
        long long dx = p1.first - p2.first;
        long long dy = p1.second - p2.second;
        return dx * dx + dy * dy;
    }

    // Ensures output order aligns with input order
    void orderByInputOrder(vector<pair<long long, long long>> &pairList) {
        if (indexMap[pairList[0]] > indexMap[pairList[1]])
            swap(pairList[0], pairList[1]);
    }

    /**
     * Recursive function to find the closest pair using divide and conquer.
     */
    vector<pair<long long, long long>> findClosest(int low, int high) {
        if (low == high) {
            return {sortedByX[low], sortedByX[high], {LLONG_MAX, 0}};
        }

        if (high - low == 1) {
            return {sortedByX[low], sortedByX[high], {squaredDistance(sortedByX[low], sortedByX[high]), 0}};
        }

        int mid = (low + high) / 2;
        auto leftPair = findClosest(low, mid);
        auto rightPair = findClosest(mid + 1, high);

        vector<pair<long long, long long>> bestPair = (leftPair[2].first <= rightPair[2].first) ? leftPair : rightPair;
        if (leftPair[2].first == rightPair[2].first)
            orderByInputOrder(bestPair);

        // Build strip within d of mid x-coordinate
        vector<pair<long long, long long>> strip;
        long long d = sqrt(bestPair[2].first) + 1;
        for (int i = low; i <= high; i++)
            if (abs(sortedByX[i].first - sortedByX[mid].first) < d)
                strip.push_back(sortedByX[i]);

        // Sort strip by y-coordinate
        sort(strip.begin(), strip.end(), [](const auto &a, const auto &b) {
            return a.second < b.second;
        });

        // Check pairs in the strip to improve result
        for (size_t i = 0; i < strip.size(); i++) {
            for (size_t j = i + 1; j < strip.size() && j < i + 10; j++) {
                long long dist = squaredDistance(strip[i], strip[j]);
                if (dist < bestPair[2].first) {
                    bestPair = {strip[i], strip[j], {dist, 0}};
                }
            }
        }

        orderByInputOrder(bestPair);
        return bestPair;
    }

public:
    ClosestSolver(const vector<pair<long long, long long>> &pts) : points(pts) {
        for (int i = 0; i < points.size(); i++)
            indexMap[points[i]] = i;
        sortedByX = points;
        sort(sortedByX.begin(), sortedByX.end());
    }

    // Calls the recursive solver and prints the closest pair
    void solveAndPrint() {
        auto result = findClosest(0, sortedByX.size() - 1);
        cout << result[0].first << " " << result[0].second << " "
             << result[1].first << " " << result[1].second << endl;
    }
};

#endif
