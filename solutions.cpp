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
