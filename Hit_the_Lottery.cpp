#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr = {100, 20, 10, 5, 1};
    int ans = 0;
    int i = 0;
    while(n > 0){
        if(arr[i] > n){
            i++;
        }else{
            ans++;
            n-= arr[i];
        }
    }
    cout << ans << endl;
}