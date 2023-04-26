#include <stdio.h>
#include <stdlib.h>


int manage(long long a)
{
    int length=1;
    int count=1;
    int l=0;
    int s[100000];
    s[0]=0;
    while(a>0){
        s[l++]=a%2;
        a/=2;
    }
    for(int i=0;i<l-1;i++)
    {
        if(s[i]==s[i+1]) length=1;
        else length++;
        count=count>length?count:length;
    }
    return count;
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
