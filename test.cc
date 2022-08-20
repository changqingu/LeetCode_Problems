#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::vector<vector<int>> ans;
        int min_diff = 10000000;
        for (int i = 0; i != arr.size() - 1; ++i)
        {
            if (arr[i+1] - arr[i] > min_diff)
            {
                continue;
            }
            else if (arr[i+1] - arr[i] < min_diff)
            {
                min_diff = arr[i+1] - arr[i];
                ans.clear();
                vector<int> vec = {arr[i], arr[i+1]};
                ans.emplace_back(vec);
            }
            else
            {
                ans.emplace_back(arr[i], arr[i+1]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec = {2,1,4,3};
    sol.minimumAbsDifference(vec);
    return 0;
}