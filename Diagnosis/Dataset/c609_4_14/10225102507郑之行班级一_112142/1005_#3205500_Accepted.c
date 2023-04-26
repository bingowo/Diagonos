#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    char in[50];
    int out,tmp;
    for(int i=0;i<T;i++)
    {
        scanf("%s",&in);out=0;

        if (in[0]=='0' && in[1]=='\0')
            {printf("case #%d:\n0\n",i);continue;}

        for(int j=0;in[j]!='\0';j++)
        {
            if (in[j]=='-')tmp=-1;
            else tmp=in[j]-'0';
            out=out*3+tmp;
        }
        printf("case #%d:\n%d\n",i,out);
    }
    return 0;
}
