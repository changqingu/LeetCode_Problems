#include <iostream>
#include <vector>
#include <string>

        #include <memory.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> res;
        res.reserve(size / 2);
        int *label = new int[size];
        memset(label, 0, size);
        for (int val : nums)
        {
            label[val - 1] = 1;
        }
        for (int i = 0; i != size; ++i)
        {
            if (label[i] == 0)
            {
                res.push_back(i+1);
            }
        }
        delete[] label;
        return res;
    }
};


int main()
{
  std::vector<int> nums = { 4,3,2,7,8,2,3,1 };
  std::vector<int> temp(1000, 9);
  Solution sol;
  std::cout << sol.findDisappearedNumbers(nums)[0] << "\n";
  return 0;
}