#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int ans=0;
        char c=getchar();
        while((c=getchar())!='\n')
        {
            if(c=='1')
            {
                ans=ans*3+1;

            }
            if(c=='0')
            {
                ans=ans*3+0;

            }
            if(c=='-')
            {
                ans=ans*3-1;

            }
        }
        printf("case #%d:\n%d\n",i,ans); 
    }
    return 0;
}
