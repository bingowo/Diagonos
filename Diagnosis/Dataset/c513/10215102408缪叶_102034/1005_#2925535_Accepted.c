#include<stdio.h>
#include<string.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char octal[51],decimal[160];scanf("%s",octal);
        int l=strlen(octal)-1,numbers=0;
        for(;l!=1;l--)
        {
            int dig=octal[l]-'0',j=0,temp;
            do
            {
                if(j<numbers) temp=dig*10+decimal[j]-'0';
                else temp=dig*10;
                decimal[j++]=temp/8+'0';
                dig=temp%8;
            } while (dig || j<numbers);
            numbers=j;
        }
        decimal[numbers]='\0';
        printf("case #%d:\n0.%s\n",i,decimal);
    }

    return 0;
}
