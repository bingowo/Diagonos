#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long turn(char *s)
{
    long sum=0;
    for(int i=0;i<strlen(s);i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
            sum=sum+(s[i]-'0')*pow(16,strlen(s)-1-i);
        else if((s[i]>='a')&&(s[i]<='f'))
            sum=sum+(s[i]-'a'+10)*pow(16,strlen(s)-1-i);
    }
    return sum;
}
int main()
{
    char s[100001]={'\0'};
    scanf("%s",&s);
    char num[10000][50]={'\0'};
    long result[10000]={0};
    int kazu=-1;
    for(int i=0;i<strlen(s);i++)
    {
        if((s[i]=='0')&&(s[i+1]=='x')&&(((s[i+2]>='0')&&(s[i+2]<='9'))||((s[i+2]>='a')&&(s[i+2]<='f'))))
        {
            kazu++;
            i=i+2;
            int a=0;
            while(((s[i]>='0')&&(s[i]<='9'))||((s[i]>='a')&&(s[i]<='f')))
                {num[kazu][a]=s[i];
                i++;
                a++;}
        }
    }
    //printf("%s\n",num[0]);
    for(int i=0;i<kazu+1;i++)
        result[i]=turn(num[i]);
    //printf("%ld\n",result[0]);
    if(kazu==-1)
        printf("-1");
    else
    {
        for(int i=0;i<kazu;i++)
            printf("%ld ",result[i]);
        printf("%ld",result[kazu]);
    }
    return 0;
}
