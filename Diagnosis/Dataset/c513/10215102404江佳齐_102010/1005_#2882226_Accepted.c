#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char oct[55],dec[155];
        int num=0;
        
        scanf("%s",oct);
        int len=strlen(oct)-1;
        int digit;
        for(;len!=1;--len)
        {
            digit=oct[len]-'0';
            int j=0,temp;
            do
            {
                if(j<num) temp=digit*10+dec[j]-'0';
                else temp=digit*10;
                dec[j++]=temp/8+'0';
                digit=temp%8;
            }
            while(digit || j<num);
            num=j;
        }
        dec[num]=0;
        printf("case #%d:\n",i);
        printf("0.%s\n",dec);
    }

    return 0;
}
