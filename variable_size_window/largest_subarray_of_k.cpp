#include <iostream>

// work only for positive numbers
using namespace std;
int main(){

    int n;
    cin >> n;
    int sum, temp = 0, ans = 0;
    cin >> sum;

    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int i = 0, j = 0;
    while(j < n){
        temp += arr[j];
        if(temp == sum){
            ans = max(ans, j - i + 1);
            j++;
        }
        else if(temp < sum){
            j++;
        }
        else if(temp > sum){
            while(temp > sum){
                temp -= arr[i];
                i++;
            }
            j++;
        }
    }
    if(temp == sum){
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return 0;
}