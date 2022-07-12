#include <iostream>
#include <cstring>
#include <climits>
#include <map>
using namespace std;

int main(){

    string s, p;
    cin >> s;
    cin >> p;
    map<int, char> m;
    int n = s.size();
    for(int i = 0; i<p.size(); i++){
        m[p[i]]++;
    }

    int c = m.size();
    int i = 0, j = 0;
    int resStart = 0, reslen = INT_MAX;
    while(j<n){
        m[s[j]]--;
        if(m[s[j]] == 0){
            c--;
        }

        if(c==0){
            while(c==0){
                if(reslen>(j-i+1)){
                    reslen = j-i+1;
                    resStart = i;
                }

                m[s[i]]++;
                if(m[s[i]] > 0){
                    c++;
                }
                i++;
            }
        }
        j++;
    }

    if(reslen == INT_MAX){
        cout << -1;
    }
    cout << s.substr(resStart, reslen);

}