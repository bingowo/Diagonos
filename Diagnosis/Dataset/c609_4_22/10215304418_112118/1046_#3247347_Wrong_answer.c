#include <stdio.h>
#include <stdlib.h>

char c[1234];
int numc[1234][1234];

int main()
{
    int n;
    scanf("%d",&n);
    int num;
    for (int i=1;i<=n;i++){
        char st[1234];
        scanf("%s",st);
        if (i==1){
            num=0;
            for (int j=0;j<strlen(st);j++){
                if (j==0 || st[j]!=st[j-1]){
                    c[num]=st[j];
                    numc[num][1]=1;
                    num++;
                }
                else{
                    numc[num-1][1]++;
                }
            }
        }
        else{
            int k=0;
            numc[0][i]=0;
            for (int j=0;j<strlen(st);j++){
                if (st[j]==c[k]){
                    numc[k][i]++;
                }
                else{
                    if (numc[k][i]==0 || c[k+1]!=st[j]) {
                        printf("-1\n");
                        return 0;
                    }
                    else{
                        k++;
                        numc[k][i]=1;
                    }
                }
            }
            if (k<num-1) {
                printf("-1\n");
                return 0;
            }
        }
    }
    int ans=0;
    for (int j=0;j<num;j++){
        int maxn=2147483647;
        for (int i=1;i<=n;i++){
            num=0;
            for (int k=1;k<=n;k++)
                num+=abs(numc[j][i]-numc[j][k]);
            if (num<maxn) {
                maxn=num;
            }
        }
        ans+=maxn;
    }
    printf("%d\n",ans);
    return 0;
}
