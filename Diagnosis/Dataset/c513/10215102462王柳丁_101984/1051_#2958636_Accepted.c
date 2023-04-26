#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};

int main()
{
    int T,i=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        char a[1024],res[1024];
        scanf("%s",a);
        int k=0,num=0,eve=0,record=0,j=0,bits=0;
        while(k<strlen(a))
        {
            num=a[k];
            eve=(num>>(2+bits))+(record<<(6-bits));
            res[j++]=base64_chart[eve];
            k++;
            bits+=2;
            record=num%(1<<bits);
            if(bits==6)
            {
                res[j++]=base64_chart[record];
                bits=0;record=0;
            }
        }
        if(bits==2)
        {
            res[j++]=base64_chart[record<<4];
            res[j++]='=';
            res[j++]='=';
        }
        else if(bits==4)
        {
            res[j++]=base64_chart[record<<2];
            res[j++]='=';
        }
        res[j++]='\0';
        printf("case #%d:\n",i);
        printf("%s",res);
        printf("\n");
    }
    return 0;
}
