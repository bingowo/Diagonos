#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {char Octal[55], decimal[155];
     scanf("%s\n",&Octal);
     int len,numbers;
     char digit,temp;
     numbers = 0;
     len = strlen(Octal)-1;
     for(;len!= 1; --len) 
     {
        digit = Octal[len]-'0';
        int j = 0;
        do 
        {
           if (j < numbers)temp = digit*10 + decimal[j]-'0';
           else temp = digit*10;
           decimal[j] = temp/8 + '0';
           j++;
           digit = temp%8;
        } 
        while (digit!=0 || j < numbers);
        numbers=j;
     }
     decimal[numbers] = '\0';
     printf("case #%d:\n",&i);
     printf("0.");
     int l;
     for(l=0;l<strlen(decimal);l++)
     printf("%c",decimal[l]);
     printf("\n");
    }
    return 0;
}