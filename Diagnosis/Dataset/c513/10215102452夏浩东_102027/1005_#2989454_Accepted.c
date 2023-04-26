#include <stdio.h>
#include <string.h>
#include <math.h> 
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++)
    {
        char L[155];
        char s[60];
        scanf("%s",s);
        int numbers = 0;
        int len = strlen(s)-1;
        for(;len!=1;--len)
        {
            int digit = s[len]-'0';
            int j=0;
            do{
                int temp=0;
                if(j<numbers)
                    temp = digit*10+L[j]-'0';
                else temp=digit*10;
                L[j++]=temp/8+'0';
                digit = temp%8;
            }while(digit!=0 || j<numbers);
            numbers = j;
        }
        L[numbers]='\0';
        printf("case #%d:\n",mm);
        printf("0.%s\n",L);
    }
    return 0;
}