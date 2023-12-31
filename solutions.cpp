//
// Created by imara on 2023-07-07.
//
#include "global.h"

using namespace std;

string Solution::reverseVowels(string s){
    vector<int> vowels_s;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for(char num : s){
        if(vowels.find(num) != vowels.end()){
            vowels_s.push_back(num);
        }
    }
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        char temp = vowels_s[left];
        vowels_s[left] = vowels_s[right];
        vowels_s[right] = temp;
        left++;
        right--;
    }
    int i = 0;
    int v_i = 0;
    for(char num : s){
        if(vowels.find(num) != vowels.end()){
            s[i] = vowels_s[v_i];
            v_i++;
        }
        i++;
    }
    return s;
}

bool Solution::isPalindrome(string s){
    vector<char> processed;
    for(char num : s){
        if(isalpha(num) || (num >= 48 && num <= 57)){
            if(isalpha(num)){
            processed.push_back(tolower(num));
        }else{
                processed.push_back(num);
            }
        }
    }
    int left = 0;
    int right = processed.size() - 1;
    for(char num : processed){
        cout << num << " ";
    }
    while(left < right){
        if(processed[left] != processed[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
//typically using all the original letters exactly once.

bool Solution::isAnagram(std::string s, std::string t){
    unordered_set<char> s_;
    unordered_set<char> t_;

    for(char num : s){
        s_.insert(num);
    }

    for(char num : t){
        t_.insert(num);
    }

    if(s_.size() != t_.size() || s.size() != t.size()){
        return false;
    }

    for(char num : s_){
        if(t_.find(num) == t_.end()){
            return false;
        }
    }
    return true;
}

//Given an array of strings words and two different strings that already exist in the array word1 and word2,
//return the shortest distance between these two words in the list.
//Input: words = ["a", "c", "d", "b", "a"], word1 = "a", word2 = "b"
//Output: 1
//Explanation: The shortest distance between "a" and "b" is 1 word. Please note that "a" appeared twice.
int Solution::shortestDistance(vector<string>& words, string word1, string word2){
    vector<int> index1;
    vector<int> index2;
    int index = 0;
    for(string num : words){
        if(num == word1){
            index1.push_back(index);
        }
        if(num == word2){
            index2.push_back(index);
        }
        index++;
    }
    int sd;
    int sdt;
    sd = abs(index1[0] - index2[0]);
    int i = 0;
    for(int num1 : index1){
        int j = 0;
        for(int num2 : index2){
            sdt = abs(index1[i] - index2[j]);
            if(sdt < sd){
                sd = sdt;
            }
            j++;
        }
        i++;
    }
    return sd;
}

//Given an array of integers nums, return the number of good pairs.
//
//A pair (i, j) is called good if nums[i] == nums[j] and i < j.
//Input: nums = [1,2,3,1,1,3]
//Output: 4
//Explanation: There are 4 good pairs, here are the indices: (0,3), (0,4), (3,4), (2,5).
int Solution::numGoodPairs(std::vector<int>& nums){
    int gp = 0;
    map<int, int> m;
    int i = 0;
    for(int num : nums){
        if(m.find(num) != m.end()){
            m.insert(make_pair(num, 1));
        }else{
            m[num]+=1;
        }
    }
    for(const auto& pair : m){
        int p = 0;
        for(int i = 1; i < pair.second; i++){
            p += i;
        }
        gp += p;
    }
    return gp;
}

//Given an array of numbers sorted in ascending order and a target sum,
//find a pair in the array whose sum is equal to the given target.
//
//Write a function to return the indices of the two numbers (i.e. the pair)
//such that they add up to the given target.
vector<int> Solution::search(const vector<int> &arr, int targetSum) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;
    while(left < right){
        if(arr[left] + arr[right] == targetSum){
            break;
        }else if(arr[left] + arr[right] < targetSum){
            left++;
        }else{
            right--;
        }
    }
    vector<int> answer;
    answer.push_back(left);
    answer.push_back(right);

    return answer;
}
//
//Given an array of sorted numbers, remove all duplicate number instances from
//it in-place, such that each element appears only once. The relative order
//of the elements should be kept the same and you should not use any extra
//space so that the solution has a space complexity of O(1)
//
//Move all the unique elements at the beginning of the array
//and after moving return the length of the subarray that has no duplicate in it.
int Solution::remove(vector<int> &arr){
  int k = 1;
  for(int i = 0; i < arr.size() - 1; i++){
      if(arr[i] != arr[i+1]){
          arr[k] = arr[i+1];
          k+=1;
      }
  }
  return k;
}

//Given a sorted array, create a new array containing squares of all
//the numbers of the input array in the sorted order.
vector<int> Solution::makeSquares(vector<int> &arr){
    vector<int> squares(arr.size());
    int right = arr.size() - 1;
    int left = 0;
    int i = arr.size() - 1;
    while(right >= left) {
        int sR = arr[right] * arr[right];
        int sL = arr[left] * arr[left];
        if(sR >= sL) {
            squares[i] = sR;
            right--;
        } else {
            squares[i] = sL;
            left++;
        }
        i--;
    }
    return squares;
}