#include <stdio.h>
#include <string.h>


int main()
{
    int T,j;

    scanf("%d",&T);
    for(j=0;j<T;j++){
        long long n,result;

        scanf("%d",&n);
        if(n==0) result=0;
        if(n==1) result=1;
        if(n==2) result=1;
        if(n>2) result=count(n);



        printf("case #%d:\n",j);
        printf("%d\n",result);
    }



}

int count(int n)
{
    int *s;
    s[0]=0;s[1]=1;s[2]=1;
    int i;
    for(i=3;i<=n;i++){
        s[i]=s[i-1]+s[i-2]+s[i-3];
    }
    return s[i-1];


}