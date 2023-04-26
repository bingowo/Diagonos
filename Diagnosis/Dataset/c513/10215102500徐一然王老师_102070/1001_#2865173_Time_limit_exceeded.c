#include<stdio.h>

int main()
{
    int num,x1,x2,y,i=0,sign=1;
    char c;
    scanf("%d",&num);
    while (num--)
    {
        i=0;
        int L[1000];
        char S[1000];
        scanf("%d %d",&x1,&y);
        if(x1<0)
        {
            x1=-x1;
            sign=-1;
        }
        while(x1)
        {
            if(y<=10)
            {
                x2=x1%y;
                x1=x1/y;
                L[i++]=x2;
            }
            else if(11<=y&&y<=32)
            {
                x2=x1%y;
                c='A'+x2-10;
                x1=x1/y;
                if(x2>=10)
                {
                    S[i++]=c;
                }
                else
                {
                    S[i++]='0'+x2;
                }

            }
        }
        if(sign==-1)
        {
            printf("-");
        }
        if(y<=10)
        {
            while(i--)
            {
                printf("%d",L[i]);
            }
            printf("\n");
        }
        else if(11<=y&&y<=32)
        {
            while(i--)
            {
                printf("%c",S[i]);
            }
            printf("\n");
        }
    }
}

