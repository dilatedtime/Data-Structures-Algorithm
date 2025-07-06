#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Count lowercase letters
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // If any letter appears more than once → flag = true
        int flag = 0;
        for (int j = 1; j < s.size()-1; j++)
        {
            if (freq[s[j]-'a'] > 1)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            cout << "YES"<<endl; 
        else 
            cout << "NO"<<endl;
    
    }

    return 0;
}
