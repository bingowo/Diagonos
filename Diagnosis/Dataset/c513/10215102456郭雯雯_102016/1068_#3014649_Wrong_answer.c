#include<stdio.h>

int main(){
    int n,m,num[32];
    scanf("%d %d",&n,&m);
    num[0]=1;
    for(int i=1;i<31;i++)num[i]=num[i-1]*2;
    for(int i=0;i<31;i++)num[i]--;
    num[31]=2147483647;
    while(n!=-1&&m!=-1){
        int s=0;
        if(m==1)s=num[n];
        if(n==m)s=1;
        printf("%d\n",s);
        scanf("%d %d",&n,&m);
    }
}