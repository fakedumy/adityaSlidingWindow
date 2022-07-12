/*
Input : n = 5, arr[] = {-8, 2, 3, -6, 10}, k = 2
Output : -8 0 -6 -6
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k; // Size of subarray
    cin >> k;
    int i=0, j=0;
    vector<int> ans;
    queue<int> q;
    while(j<n){
        if(j-i+1 < k){
            if(arr[j] < 0){
                q.push(arr[j]);
            }
            j++;
        }
        else{
            if(arr[j] < 0){
                q.push(arr[j]);
            }
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(q.front());
            }
            if(arr[i] == q.front()){
                q.pop();
            }
            i++;
            j++;
        }
    }

    for(int l = 0; l < ans.size(); l++){
        cout << ans[l] << " "; 
    }
}