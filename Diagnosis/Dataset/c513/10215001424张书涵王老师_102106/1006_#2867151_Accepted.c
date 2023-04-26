#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    char c[T][50];
    for(i=0;i<T;i++)
        scanf("%s",*(c+i));
    int k,j,jieguo;
    for(k=0;k<T;k++)
    {
        jieguo=0;
        for(j=0;c[k][j];j++)
        {
            if(c[k][j]=='-')
                jieguo=jieguo*3-1;
            else
            {
                if(c[k][j]=='0')
                    jieguo=jieguo*3+0;
                else
                    jieguo=jieguo*3+1;
            }
        }
        printf("case #%d:\n%d\n",k,jieguo);
    }
}
