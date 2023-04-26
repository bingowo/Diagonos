#include<stdio.h>

char table[]="0123456789ABCDEFGHIJK";
void trans(int N,int R)
{
    if(N!=0)
    {if(N%R<0)
        {trans(N/R+1,R);
        putchar(table[N%R-R]);
        }
        else
        {
          trans(N/R,R);
        putchar(table[N%R]);
        }
    }

}
int main()
{
        int N,R;
        scanf("%d%d",&N,&R);
        if(N==0)
            putchar(table[0]);
        else trans(N,R);
        printf("\n");
    return 0;
}
