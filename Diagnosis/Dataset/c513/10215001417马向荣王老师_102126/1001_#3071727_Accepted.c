#include<stdio.h>
int main()
{
    int t,n,r;
    scanf("%d\n",&t);
    int i,j=0;
    char arr[128];
    while(scanf("%d %d",&n,&r)!=EOF)
    {
        j=0;
        if(n<0)
        {
            printf("-");
            n=-n;
        }
        while(n!=0)
        {
            j++;
            arr[j]=n%r;
            n/=r;
        }
        for(i=j;i>0;i--)
        {
            if(arr[i]>=10)
            {
                if(i!=1) printf("%c",arr[i]+55);
                else printf("%c\n",arr[i]+55);
            }
            else
            {
                if(i!=1) printf("%d",arr[i]);
                else printf("%d\n",arr[i]);
            }
        }
    }
    return 0;
}