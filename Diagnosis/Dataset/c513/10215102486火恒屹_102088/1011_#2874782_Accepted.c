#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* turntobin(char* c)
{
    char *a=(char*)malloc(400*sizeof(char));
    int k=0;
    for(int i=2;i<strlen(c);i++)
    {
        if(c[i]=='0')
        {a[k]='0';a[k+1]='0';a[k+2]='0';a[k+3]='0';k=k+4;}
        else if(c[i]=='1')
        {a[k]='0';a[k+1]='0';a[k+2]='0';a[k+3]='1';k=k+4;}
        else if(c[i]=='2')
        {a[k]='0';a[k+1]='0';a[k+2]='1';a[k+3]='0';k=k+4;}
        else if(c[i]=='3')
        {a[k]='0';a[k+1]='0';a[k+2]='1';a[k+3]='1';k=k+4;}
        else if(c[i]=='4')
        {a[k]='0';a[k+1]='1';a[k+2]='0';a[k+3]='0';k=k+4;}
        else if(c[i]=='5')
        {a[k]='0';a[k+1]='1';a[k+2]='0';a[k+3]='1';k=k+4;}
        else if(c[i]=='6')
        {a[k]='0';a[k+1]='1';a[k+2]='1';a[k+3]='0';k=k+4;}
        else if(c[i]=='7')
        {a[k]='0';a[k+1]='1';a[k+2]='1';a[k+3]='1';k=k+4;}
        else if(c[i]=='8')
        {a[k]='1';a[k+1]='0';a[k+2]='0';a[k+3]='0';k=k+4;}
        else if(c[i]=='9')
        {a[k]='1';a[k+1]='0';a[k+2]='0';a[k+3]='1';k=k+4;}
        else if(c[i]=='A')
        {a[k]='1';a[k+1]='0';a[k+2]='1';a[k+3]='0';k=k+4;}
        else if(c[i]=='B')
        {a[k]='1';a[k+1]='0';a[k+2]='1';a[k+3]='1';k=k+4;}
        else if(c[i]=='C')
        {a[k]='1';a[k+1]='1';a[k+2]='0';a[k+3]='0';k=k+4;}
        else if(c[i]=='D')
        {a[k]='1';a[k+1]='1';a[k+2]='0';a[k+3]='1';k=k+4;}
        else if(c[i]=='E')
        {a[k]='1';a[k+1]='1';a[k+2]='1';a[k+3]='0';k=k+4;}
        else if(c[i]=='F')
        {a[k]='1';a[k+1]='1';a[k+2]='1';a[k+3]='1';k=k+4;}
    }
    return a;
}
int main()
{
    char c[100]={'0'};
    scanf("%s",&c);
    char *a=turntobin(c);
    long long real=0;
    long long com=0;
    for(int i=0;i<strlen(a);i++)
    {
        long long tmpt=real;
        real=-real-com;
        com=tmpt-com;
        real=real+a[i]-'0';
    }
    free(a);
    if(com==0)
        printf("%lld",real);
    else if((real==0)&&(com==1))
        printf("i");
    else if((real==0)&&(com==-1))
        printf("-i");
    else if((real==0)&&(com!=0))
        printf("%lldi",com);
    else if((com>0)&&(com!=1))
        printf("%lld+%lldi",real,com);
    else if((com>0)&&(com==1))
        printf("%lld+i",real);
    else if((com<0)&&(com!=-1))
        printf("%lld%lldi",real,com);
    else
        printf("%lld-i",real);
    return 0;
}
