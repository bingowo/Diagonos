#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i=0;
    char c=getchar();
    for(i=0;i<T;i++)
    {
        int ans=0;
        while((c=getchar())!='\n')
        {
            if(c=='1')
            {
                ans=ans*3+1;
            }
            if(c=='-')
            {
                ans=ans*3-1;
            }
            if(c=='0')
            {
                ans=ans*3;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
