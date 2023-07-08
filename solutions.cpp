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
        if(isalpha(num)){
            processed.push_back(tolower(num));
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