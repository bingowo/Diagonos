#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, N, R, s, i = 0;
    char a[33];
    cin >> T;
    while(i < T){
        i++;
        cin >> N >> R;
        if(N < 0){
            s = 0;
            N = -N;
        }
        for(int j = 0; j < 33; j++){
            a[j] = '?';
        }
        for(int k = 0; N != 0; k++){
            int r = N % R;
            N /= R;
            if(r >= 10){
                a[k] = r + '7';
            }
            else a[k] = r + '0';
        }
        if(s == 0) a[k] = '-';
        for(int j = 32; j >= 0; j--){
            if(a[j] == '?') continue;
            cout << a[j];
        }
        cout << endl;
        s = 1;
    }
    return 0;
}