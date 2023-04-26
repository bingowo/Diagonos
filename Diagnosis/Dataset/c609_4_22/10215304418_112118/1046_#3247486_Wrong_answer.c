#include <stdio.h>
#include <stdlib.h>

char c[1234];
int numc[1234][1234];

int cmp(const void* x,const void* y){
    return *(char*)x-*(char*)y;
}

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
    int ans=0;/*
    for (int j=0;j<num;j++){
        qsort(numc[j]+1,n,sizeof(int),cmp);
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<num;j++){
            printf("%d ",numc[j][i]);
        }
        printf("\n");
    }*/
    for (int j=0;j<num;j++){
        int maxn=10000000;
        for (int i=1;i<=100;i++){
            int sum=0;
            for (int k=1;k<=n;k++)
                sum+=abs(numc[j][k]-i);
            if (maxn>sum) maxn=sum;
        }
        ans+=maxn;
    }
    printf("%d\n",ans);
    return 0;
}
