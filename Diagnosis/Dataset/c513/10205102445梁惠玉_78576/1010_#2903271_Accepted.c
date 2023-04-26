#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transfer(int num,int bits)
{
    for(int i=bits-1;i>=0;i--)
    {
        if(num&(1<<i))
        {
            printf("1");
        }
        else{printf("0");}
    }
}

int main()
{
    char n[501];
    scanf("%s",n);
    printf("0001");
    int length=strlen(n);
    transfer(length,10);

    int flag=0;
    int temp=0;
    for(int i=0;i<length;i++)
    {
        temp=temp*10+(n[i]-'0');
        flag++;
        if(flag==3)
        {
            transfer(temp,10);
            temp=0;
            flag=0;
        }
        else if(flag==2&&i==length-1)
        {
            transfer(temp,7);
            temp=0;
            flag=0;
        }
        else if(flag==1&&i==length-1)
        {
            transfer(temp,4);
            temp=0;
            flag=0;
        }

    }
    putchar('\n');
    return 0;

}
