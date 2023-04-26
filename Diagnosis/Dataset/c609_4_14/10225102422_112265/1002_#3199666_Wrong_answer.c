#include<stdio.h>
#define N 32
int main()
{
    int T;
    int s[N];
    scanf("%d",&T);
    int i=0;
    int n;
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        int j=0;
        int count;
        while(n!=0)
        {
            s[j]=n%2;
            n=n/2;
            j++;
        }
        int index;
        for(index=j-1;index>0;index--)
        {
            if(s[index]!=s[index-1])
            count=count+2;
            else if(s[index]==s[index-1])
            count=1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
    return 0;
}