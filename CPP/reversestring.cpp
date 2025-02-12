#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> st;
        int itr = 0;
        string temp = "";
        while (itr < s.length())
        {
            if (s[itr] == ' ')
            {
                if (temp.length() > 0)
                {
                    st.push_back(temp);
                }
                temp = "";
            }
            else
            {
                temp = temp + s[itr];
            }
            itr++;
        }
        if (temp.length() > 0)
        {
            st.push_back(temp);
        }
        string res = "";
        for (int i = st.size() - 1; i >= 0; i--)
        {
            res+=st[i];
            if(i!=0){
                res+=" ";
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}