#include<stdio.h>
#include<string.h>
long long m[51];
int main()
{
    memset(m,0,sizeof(m));
    m[0]=0;
    m[1]=1;
    m[2]=2;
    m[3]=4;
    m[4]=8;
    for(int i=5;i<51;i++){
        m[i]=m[i-1]+m[i-2]+m[i-3]+m[i-4];
    }
    int n,num;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        printf("case #%d:\n%lld\n",num,m[num]);
    }
}