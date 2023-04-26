#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int num[1001];
    num[0]=1;
    num[1]=1;
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        for(int i=2;i<=n;i++)num[i]=num[i-1]+num[i-2];
        printf("%d\n",num[n]);
    }
    return 0;
}