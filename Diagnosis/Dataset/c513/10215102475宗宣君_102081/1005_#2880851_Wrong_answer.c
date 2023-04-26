#include<stdio.h>
#include<string.h>

void trans(int q)
{


    char Octal[50];
    char decimal[1000];
    scanf("%s",Octal);
    int num;
    int len = strlen(Octal) - 1;
    int Dlen = 0;

    for(; len != 1; len--)
    {
        num = Octal[len] - '0';
        int digit = 0;
        int j = 0;
        do
        {
            int temp;
            if(j < Dlen)
            {
                temp = num * 10 + decimal[j] - '0';
            }
            else
            {
                temp = num * 10;

            }
            digit = temp % 8;
            decimal[j++] = temp / 8 +'0';
            num = digit;
        }
        while(digit || j < Dlen);
        Dlen = j;
    }
    printf("case #%d:\n0.",q);
    int i;
    for(i = 0; i < Dlen; i++)
    {
        printf("%c",decimal[i]);
    }

}

int main()
{
    int total;
    scanf("%d",&total);
    int i;
    for(i = 0; i < total; i++)
    {
        trans(i);
    }
    return 0;
}
