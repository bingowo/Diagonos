#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",T);
    for(int cas=0;cas<T;cas++)
    {
        char oct[55],decimal[155];
        int number=0;
        scanf("%s",oct);
        int len=strlen(oct);
        for(int i=len-1;i>1;i--)
        {
            int digit=oct[i]-'0';
            int ator,j=0;
            do{
                ator=10*digit+(j<number?decimal[j]-'0':0);
                decimal[j++]=ator/8+'0';
                digit=ator%8;
            }while(digit!=0||j<number);
            number=j;
        }
        decimal[number]='\0';
        printf("case #%d:\n",cas);
        printf("0.%s\n",decimal);
    }
    return 0;
}
