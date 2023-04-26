#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 210
#define MOD 1000000007

int main()
{
    int T;
    scanf("%d",&T);
    for(int k=0;k<T;k++){
        char s[101];
        scanf("%s",s);
        int L = strlen(s);
        int f[101][210] = {1};
        for(int i=0;i<L;i++){
            int sum = 0;
            for(int j = i;j < L;j++){
                sum = (sum*10+s[j]-'0')%M;
                for(int w=0;w<M;w++){
                    f[j+1][(w+sum)%M]=(f[j+1][(w+sum)%M]+f[i][w])%MOD;
                    if(i)f[j+1][(w+M-sum)%M]=(f[j+1][(w+M-sum)%M]+f[i][w])%MOD;
                }
            }

        }
        int sum=0;
        for(int i=0;i<=210;i++){
            if(i%2==0||i%3==0||i%5==0||i%7==0)sum+=f[L][i];
            //printf("%d ",f[L][i]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
