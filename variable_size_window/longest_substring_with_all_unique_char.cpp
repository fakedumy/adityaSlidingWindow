#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> m;
    int i = 0, j = 0, ans = 0;

    while (j < s.size())
    {
        m[s[j]]++;

        if (m.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }

        else if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}