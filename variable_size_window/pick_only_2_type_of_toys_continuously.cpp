/*Example - 
    "aabbcc", k = 3
    There are substrings with exactly 3 unique characters
    {"aabbcc" , "abbcc" , "aabbc" , "abbc" }
    Max is "aabbcc" with length 6.
*/
// https://leetcode.com/problems/fruit-into-baskets/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k = 2, j = 0, i = 0;
    unordered_map<char,int> m;
    int ans = 0;
    while(j<s.size()){
        m[s[j]]++;
        if(m.size() < k){
            j++;
        }
        else if(m.size() == k){
            ans = max(ans, j-i+1);
            j++;
        }
        else if(m.size() > k){
            while(m.size() > k){
                m[s[i]]--;
                if(m[s[i]] == 0){
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