#include <stdio.h>
#include <stdlib.h>

int main()
{

    int T,i=0,temp=0;
    char c;
    scanf("%d",&T);
    c=getchar();
    for(i=0;i<T;i++)
        {
            temp=0;
            while(((c=getchar())!='\n'))
            {
                if(c=='1')
                    temp=temp*3+1;
                else if(c=='-')
                    temp=temp*3-1;
                else if(c=='0')
                    temp=temp*3;
            }
            printf("case #%d:\n",i);
            printf("%d\n",temp);
        }
    return 0;
}