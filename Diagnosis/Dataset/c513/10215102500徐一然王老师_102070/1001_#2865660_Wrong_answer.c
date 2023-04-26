#include<stdio.h>

int main()
{
    int num,x2,y,i=0,sign=1;
    int x1,x3;
    char c;
    scanf("%d",&num);
    while (num--)
    {
        i=0;
        int L[100];
        char S[100];
        scanf("%d %d",&x1,&y);
        if(x1<0)
        {
            x1=-x1;
            sign=-1;
        }
        x3=x1;
        while(x1)
        {
            if(y<=10)
            {
                x2=x1%y;
                x1=x1/y;
                L[i++]=x2;
            }
            else if(11<=y&&y<=36)
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
        if(y<=10&&x3)
        {
            while(i--)
            {
                printf("%d",L[i]);
            }
            printf("\n");
        }
        else if(11<=y&&y<=36&&x3)
        {
            while(i--)
            {
                printf("%c",S[i]);
            }
            printf("\n");
        }
        if(x3==0)
        {
            printf("0\n");
        }
    }
}