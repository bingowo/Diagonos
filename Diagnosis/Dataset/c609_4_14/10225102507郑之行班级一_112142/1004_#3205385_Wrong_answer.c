#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEF";

void trans(int N,int R)
{
    if (N>0)
    {
        trans(N/R,R);
        printf("%c",table[N%R]);
    }
}

int main()
{
    int A,B,num[33],temp=0;
    char n[33];
    scanf("%d %s %d",&A,n,&B);
    for (int i=0;i<32&&n[i]!='\0';i++)
    {
        if (n[i]>='a' && n[i]<='f')
            num[i]=n[i]-'a'+10;
        else if (n[i]>='A' && n[i]<='F')
            num[i]=n[i]-'A'+10;
        else
            num[i]=n[i]-'0';

        temp = A*temp + num[i];

        //printf("num[%d]=%d\n",i,num[i]);
    }
    //printf("temp=%d\n",temp);

    trans(temp,B);

    printf("\n");
    return 0;
}
