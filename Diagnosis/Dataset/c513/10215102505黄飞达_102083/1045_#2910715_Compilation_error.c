#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
const int M = 1001, N = 101;
int main(){
    int n;
    scanf("%d ", &n);
    char s[M][N];//+00
    for (int i = 0; i < n; i++){
        gets(s[i]);
    }
    ll count = 0;
    char mode[N];
    ll numarr[M][N] = {0};
    int index = 0;
    for (int i = 0; i < strlen(s[0]); i++){
        if (s[0][i]==s[0][i+1]){
            mode[index++] = s[0][i];
            while (i+1<strlen(s[0]) && s[0][i]==s[0][i+1]) i++;
        }
    }
    for (int i = 0; i < n; i++) {
        index=0;
        for (int j = 0; j < strlen(s[i]); j++){
            if (mode[index]==s[i][j]){
                numarr[i][index]++;
            }
            else if (j>=1 && mode[index]==s[i][j-1]){
                index++;
                j--;
            }
            else {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    for (int i = 0; i < index+1; i++){
        double mean_num = 0;
        int j = 0;
        for (j = 0; j < n; j++){
            mean_num += numarr[j][i];
        }
        mean_num /= n;
        if (mean_num - (int)mean_num>=0.5) mean_num = (int)mean_num+1;
        else mean_num = (int)mean_num;
        for (j = 0; j < n; j++){
            ll temp = numarr[j][i] - mean_num;
            count += temp < 0 ? -temp : temp;
        }
    }
    printf("%lld\n", count);
    return 0;
}