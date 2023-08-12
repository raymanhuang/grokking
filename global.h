//
// Created by imara on 2023-07-07.
//

#ifndef GROKKING_GLOBAL_H
#define GROKKING_GLOBAL_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <map>

using namespace std;
class Solution{
    public:
    string reverseVowels(string s);
    bool isPalindrome(string s);
    bool isAnagram(std::string s, std::string t);
    int shortestDistance(vector<string>& words, string word1, string word2);
    int numGoodPairs(std::vector<int>& nums);
    vector<int> search(const vector<int> &arr, int targetSum);
    int remove(vector<int> &arr);
    vector<int> makeSquares(vector<int> &arr);
};

#endif //GROKKING_GLOBAL_H
