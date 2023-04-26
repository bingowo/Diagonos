#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[N];
        int ans=0;
        printf("case #%d:\n",i);
        scanf("%s",s);
        char *p;
        p=s;
        while(*p++)
        {
            switch(*p)
            {
                case'0':ans=ans*3;break;
                case'-':ans=ans*3-1;break;
                case'1':ans=ans*3+1;break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}