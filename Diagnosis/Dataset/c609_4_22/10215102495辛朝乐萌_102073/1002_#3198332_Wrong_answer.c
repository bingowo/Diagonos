#include <stdio.h>
#include <stdlib.h>


int manage(long long a)
{
    int length=0;
    int l=0;
    int s[1000];
    while(a>0){
        s[l++]=a%2;
        a/=2;
    }
    for(int i=0;i<l;i++)
    {
        if(s[i]!=s[i+1]) length++;
        else length=0;
    }
    return length;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long a;
        scanf("%lld",&a);
        int res=manage(a);
        printf("case #%d:\n%d\n",i,res);

    }
}

