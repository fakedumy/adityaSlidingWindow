/*Example - 
    "aabbcc", k = 3
    There are substrings with exactly 3 unique characters
    {"aabbcc" , "abbcc" , "aabbc" , "abbc" }
    Max is "aabbcc" with length 6.
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;
int longestKSubstr(string s, int k) {
   // your code here
    int i=0,j=0,flag=0;
    int mx=INT_MIN;
    unordered_map<char,int>mp;
    while(j<s.length()){
        mp[s[j]]++;
        if(mp.size()==k){
            flag=1;
            mx=max(mx,j-i+1);
            
        }
        else{
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            
        }
        j++;
    }
    if(flag==1){
        return mx;
    }
    else{
        return -1;
    }
}


int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << longestKSubstr(s, k) << endl;
    return 0;
}