#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &email)
    {
        unordered_set<string> st;
        auto find = [&](string s)
        {
            string curr = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '.')
                {
                    continue;
                }
                if (s[i] == '+')
                {
                    break;
                }
                if (s[i] == '@')
                {
                    break;
                }
                curr.push_back(s[i]);
            }
            curr += s.substr(s.find('@'));
            return curr;
        };
        for (auto it : email)
        {
            string s = find(it);
            cout << s << endl;
            st.insert(s);
        }
        return st.size();
    }
};