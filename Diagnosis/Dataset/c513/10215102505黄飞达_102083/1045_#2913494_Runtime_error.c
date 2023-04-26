#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define M 1001
#define N 101

int cmp(const void*a, const void* b){
    return *(ll*)a < *(ll*)b ? -1 : 1;
}

int func(ll arr[M][N], int i, int n){
    ll temparr[M] = {0};
    for (int j = 0; j < n; j++){
        temparr[j] = arr[j][i];
    }
    qsort(temparr, n, sizeof(ll), cmp);
    return temparr[n/2];
}

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
    int index = 0, lastindex=0;
    for (int i = 0; i < strlen(s[0]); i++){
        mode[index++] = s[0][i];
        while (i+1<strlen(s[0]) && s[0][i]==s[0][i+1]) i++;
    }
    for (int i = 0; i < n; i++) {
        index=0;
        int j = 0;
        for (j = 0; j < strlen(s[i]); j++){
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
        if (index < lastindex) {
            printf("-1\n");
            return 0;
        }
        lastindex = index;

    }
    
    for (int i = 0; i < index+1; i++){
        int num = func(numarr, i, n);
        for (int j = 0; j < n; j++){
            ll temp = numarr[j][i] - num;
            count += temp < 0 ? -temp : temp;
        }
    }
    printf("%lld\n", count);
    return 0;
}