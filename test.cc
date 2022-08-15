#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory.h>
#include <queue>

using namespace std;

class Solution {
    vector<string> table = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    std::vector<string> ans;

    void helper(int idx, string curr, const string& digits)
    {
        if (idx == digits.size())
        {
            ans.push_back(curr);
        }
        const string& str = table[digits[idx] - '2'];
        for (char ch : str)
        {
            helper(idx + 1, curr + string(1, ch), digits);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        helper(0, "", digits);
        return ans;
    }
};

int main()
{
    string s = "23";
    Solution sol;
    auto vec = sol.letterCombinations(s);
    for (string str : vec)
    {
        std::cout << str << std::endl;
    }
    return 0;
}