#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[1000];
        scanf("%s",s);
        int len=strlen(s);
        printf("case #%d:\n",i);
        for(int j=0;j<len;j++)
        {
            int num=0;
            for(int k=j;k<len;k++)
            {
                if(s[k]==s[j]) num++;
                if(s[k]!=s[j])
                {
                    while(num>255)
                    {
                        printf("255%c",s[j]);
                        num-=255;j+=255;
                    }
                    if(num<=255&&num>0) {printf("%d%c",num,s[j]);j=j+num-1;num=0;break;}
                    else if(num==0) break;
                }
            }
            if(num!=0) {printf("%d%c",num,s[j]);j=len-1;}
        }
        printf("\n");
    }
    return 0;
}
