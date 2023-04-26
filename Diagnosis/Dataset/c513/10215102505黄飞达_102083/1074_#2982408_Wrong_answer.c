#include<stdio.h>
#include<string.h>
#define M 10000000007

int main(){
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        char s[105]={};
        gets(s);
        int L = strlen(s);
        int f[101][210]={1};
        for (int i=0; i<L; i++){
            int sum=0;
            for (int j=i; j<L; j++){
                sum = (sum*10+s[j]-'0')%210;
                for (int k=0; k<210; k++){
                    f[j+1][(k+sum)%210] = (f[j+1][(k+sum)%210]+f[i][k])%M;
                    if(i) f[j+1][(k+210-sum)%210] = (f[j+1][(k+210-sum)%210]+f[i][k])%M;
                }
            }
        }

        int res=0;
        for (int j=0; j<210; j++){
            if (j%2==0||j%3==0||j%5==0||j%7==0){
                res += f[L][j];
            }
        }
        printf("%d\n", res);
    }
    return 0;
}