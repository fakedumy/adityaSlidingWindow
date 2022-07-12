#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    int i = 0, j = 0;
    int zero_count = 0;
    int ans = 0;
    while(j<n){
        
        if(a[j] == 0){
            zero_count++;
        }
        else if(zero_count > k){
            while(a[i] == 0){
                zero_count--;
            }
            i++;
        }        
        j++;
        ans = max(ans, j-i+1);
    }
    cout << ans << endl;
}