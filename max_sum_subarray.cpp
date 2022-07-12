/*Input  : n = 4, arr[] = {100, 200, 300, 400}
         k = 2
Output : 700
*/
#include<iostream>
using namespace std;
int main(){


    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k; // size of subarray
    cin >> k;
    int i = 0, j = 0, sum = 0, ans = INT16_MIN;
    while(j<n){

        if(j-i+1 < k){
            sum += arr[j];
            j++;
        }
        else if(j-i+1 == k){
            sum += arr[j];
            ans = max(ans, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    cout << ans <<endl;
    return 0;
}