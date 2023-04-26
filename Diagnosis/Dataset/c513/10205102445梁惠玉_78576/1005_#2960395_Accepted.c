#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    //getchar();
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char Octal[55],decimal[155];
        scanf("%s",Octal);
        //printf("%s\n",Octal);
        int number=0;
        int len=strlen(Octal)-1;
        for(;len!=1;len--)
        {
            int digit=Octal[len]-'0';
            int j=0;
            int temp;
            do{
                if(j<number)
                {
                    temp=digit*10+decimal[j]-'0';
                }
                else{
                    temp=digit*10;
                }
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit||j<number);
            number=j;
        }
        decimal[number]='\0';
        printf("0.%s\n",decimal);


    }

    return 0;
}

