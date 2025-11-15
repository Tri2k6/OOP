#include "Function.h"

void GroupStudent(const list<pair<string,int>>& L) {
    map<int,int> mp;
    for (const auto &it : L) {
        mp[it.second]++;
    }

    vector<pair<int,int>> v;

    for (auto it = mp.rbegin();it != mp.rend();it++) {
        v.push_back(*it);
    }

    sort(v.begin(), v.end(), [&] (pair<int,int> a , pair<int,int> b) {
        return a.second > b.second;
    });

    for (auto it : v) {
        cout << "GPA " << it.first << ": " << it.second << " students.\n";
    }
}