#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        char octal[55]={0},decimal[155]={0};
        scanf("%s",octal);
        int numbers=0,i=strlen(octal)-1;
        for( ;i!=1;i--)
        {
            int digit=octal[i]-'0';
            int j=0;
            int temp;
            do
            {
                if(j<numbers)
                {
                    temp=digit*10+decimal[j]-'0';
                }
                else
                {
                    temp=digit*10;
                }
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit!=0||j<numbers);
            numbers=j;
        }
        decimal[numbers]='\0';
        printf("case #%d:\n0.%s\n",Case,decimal);
    }
    return 0;
}
