#include <stdio.h>
#include <string.h>

int cal(char c);

int
main()
{
    int questions;
    char c[121] = {'\0'};
    long length;
    int count = 0;
    int num1,num2;
    
    scanf("%d",&questions);
    getchar();
    for (int i=0; i<questions; i++)
    {
        count = 0;
        gets(c);
        length = strlen(c);
        for (int i=0; i<length; i++)
        {
            count += cal(*(c+i));
        }
        num1 = count;
        num2 = length*8;
        for (int i=num1;i>1 ; i--)
        {
            if ((num1%i==0 && num2%i==0))
            {
                num1 /= i;
                num2 /= i;
            }
        }
        printf("%d/%d\n",num1,num2);
    }

    
    return 0;
}


int
cal(char c)
{
    int count = 0;
    
    for (int i=0; i<8; i++)
    {
        if ((c>>i)&1)   count++;
    }
    
    return count;
}