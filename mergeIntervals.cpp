#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    cout << "Enter the intervals in the format [start, end]:" << endl;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, end});
    }

    vector<vector<int>> merged = sol.merge(intervals);

    cout << "Merged Intervals:" << endl;
    for (int i = 0; i < merged.size(); i++) {
        cout << "[" << merged[i][0] << ", " << merged[i][1] << "]";
        if (i != merged.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
