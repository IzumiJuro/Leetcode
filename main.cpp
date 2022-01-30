#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> mp;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        mp[s]++;
    }
    string str;
    cin>>str;
    if (mp.find(str) != mp.end()) {
        cout<<"YES";
    }
    else {
        cout<<"No";
    }
}
