#include <stdio.h>
#include <stdlib.h>

int main()
{

    int T,i=0,temp=0,res[100]={0};
    char c;
    scanf("%d",&T);
    c=getchar();
    for(i=0;i<T;i++)
        {
            while(((c=getchar())!=EOF))
            {
                if(c=='1')
                    temp=temp*3+1;
                else if(c=='-')
                    temp=temp*3-1;
                else if(c=='0')
                    temp=temp*3;
                else if(c=='\n')
                {
                    res[i]=temp;
                    temp=0;
                    break;
                }
            }
        }
    for(i=0;i<T;i++)
        {
            printf("case #%d:\n",i);
            printf("%d\n",res[i]);
        }
    return 0;
}