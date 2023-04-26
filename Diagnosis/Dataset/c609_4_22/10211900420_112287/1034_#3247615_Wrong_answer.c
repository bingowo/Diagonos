#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
unsigned int pow(unsigned int x,unsigned int y)
{
    unsigned int i,pai=1;
    for(i=0;i<y;i++)
    {
        pai=pai*x;
    }
    return pai;
}
char ox[17]="0123456789abcdef";
int main()
{
    unsigned int i,ord,sum;
    char si[3]="0x";
    char* pch;
    char* pch2;
    char *x,*y;
    x=(char*)malloc(100001*sizeof(char));
    y=(char*)malloc(100001*sizeof(char));
    scanf("%s",x);
    pch=strstr(x,si);
    if(pch!=NULL)
    {
        while(pch!=NULL)
        {
            sum=0;
            pch2=strstr(pch+2,si);
            if(pch2==NULL)
                pch2=pch+strlen(x);
            strncpy(y,pch+2,pch2-2-pch);
            y[pch2-pch]='\0';
            for(i=0;i<strlen(y);i++)
            {
                if(strchr(ox,y[i])==NULL)
                    y[i]='\0';
            }
            for(i=0;i<strlen(y);i++)
            {
                ord=strchr(ox,y[i])-strchr(ox,'0');
                sum=sum+ord*pow(16,strlen(y)-i-1);
            }
            if(sum!=0)
                printf("%u ",sum);
            pch=strstr(pch+2,si);
        }
    }
    else
        printf("-1");
    free(y);
    free(x);
    return 0;
}
