#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for (auto p : m) 
          if(s.insert(p.second).second != 1)
            return false;

        return true;
    }
};
