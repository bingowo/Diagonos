#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,a[128]={0};
    char ord[5],s[15];
    while(~scanf("%s",ord))
    {
        if(!strcmp(ord,"IN"))
        {
            scanf("%s",s);
            i=3;a[s[0]]=0;
            if(s[3]=='-')
            {   i=4;
                while(s[i])
            {a[s[0]]=a[s[0]]*10+s[i]-'0';i++;}
               a[s[0]]=-a[s[0]];
            }
            else
            {
                while(s[i])
            {a[s[0]]=a[s[0]]*10+s[i]-'0';i++;}
            }

        }
        else if(!strcmp(ord,"OUT"))
        {   scanf("%s",s);
            printf("%d\n",a[s[0]]);
        }
        else if(!strcmp(ord,"ADD"))
        {   scanf("%s",s);
        a[s[0]]=a[s[0]]+a[s[3]];}
        else if(!strcmp(ord,"SUB"))
        {   scanf("%s",s);
        a[s[0]]=a[s[0]]-a[s[3]];}
         else if(!strcmp(ord,"MUL"))
        {   scanf("%s",s);
        a[s[0]]=a[s[0]]*a[s[3]];}
        else if(!strcmp(ord,"DIV"))
        {   scanf("%s",s);
        a[s[0]]=a[s[0]]/a[s[3]];}
    }
    return 0;
}
