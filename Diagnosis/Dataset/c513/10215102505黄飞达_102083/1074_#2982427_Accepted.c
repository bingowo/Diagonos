#include<stdio.h>
#include<string.h>
#define M 1000000007
#define ll long long

int main(){
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        char s[105]={};
        gets(s);
        int L = strlen(s);
        ll f[101][210]={1};
        for (int i=0; i<L; i++){
            ll sum=0;
            for (int j=i; j<L; j++){
                sum = (sum*10+s[j]-'0')%210;
                for (int k=0; k<210; k++){
                    f[j+1][(k+sum)%210] = (f[j+1][(k+sum)%210]+f[i][k])%M;
                    if(i) f[j+1][(k+210-sum)%210] = (f[j+1][(k+210-sum)%210]+f[i][k])%M;
                }
            }
        }
        ll res=0;
        for (int j=0; j<210; j++){
            if (j%2==0||j%3==0||j%5==0||j%7==0){
                res = (res+f[L][j])%M;
            }
        }
        printf("%lld\n", res%M);
    }
    return 0;
}