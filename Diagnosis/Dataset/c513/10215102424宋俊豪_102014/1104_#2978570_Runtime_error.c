#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t,i,a[130]= {0};
    char ord[7],s[1000];
    while(~scanf("%s",ord))
    {
        if(!strcmp(ord,"IN"))
        {
            scanf("%s",s);
            i=3;
            a[s[0]]=0;
            if(s[3]=='-')
            {
                i=4;
                while(s[i])
                {
                    a[s[0]]=a[s[0]]*10+s[i]-'0';
                    i++;
                }
                a[s[0]]=-a[s[0]];
            }
            else
            {
                while(s[i])
                {
                    a[s[0]]=a[s[0]]*10+s[i]-'0';
                    i++;
                }
            }

        }
        else if(!strcmp(ord,"OUT"))
        {
            scanf("%s",s);
            printf("%d\n",a[s[0]]);
        }
        else if(!strcmp(ord,"ADD"))
        {
            scanf("%s",s);
            if(s[6])
            {
                a[s[0]]=a[s[3]]+a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]+a[s[3]];
            }
        }
        else if(!strcmp(ord,"SUB"))
        {
            scanf("%s",s);
            if(s[6])
            {
                a[s[0]]=a[s[3]]-a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]-a[s[3]];
            }
        }
        else if(!strcmp(ord,"MUL"))
        {
            scanf("%s",s);
           if(s[6])
            {
                a[s[0]]=a[s[3]]*a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]*a[s[3]];
            }
        }
        else if(!strcmp(ord,"DIV"))
        {
            scanf("%s",s);
            if(s[6])
            {
                a[s[0]]=a[s[3]]/a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]/a[s[3]];
            }
        }
        else if(!strcmp(ord,"MOD"))
        {
            scanf("%s",s);
            if(s[6])
            {
                a[s[0]]=a[s[3]]%a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]%a[s[3]];
            }
        }
        else if(!strcmp(ord,"MOV"))
        {
            scanf("%s",s);
            a[s[0]]=a[s[3]];
        }
        else if(!strcmp(ord,"XCHG"))
        {
            scanf("%s",s);
            t=a[s[0]];
            a[s[0]]=a[s[3]];
            a[s[3]]=t;
        }
        else if(!strcmp(ord,"AND"))
        {
            scanf("%s",s);
            if(s[6])
            {
                a[s[0]]=a[s[3]]&a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]&a[s[3]];
            }
        }
        else if(!strcmp(ord,"OR"))
        {
            scanf("%s",s);
            if(s[6])
            {
                a[s[0]]=a[s[3]]|a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]|a[s[3]];
            }
        }
        else if(!strcmp(ord,"XOR"))
        {
            scanf("%s",s);
             if(s[6])
            {
                a[s[0]]=a[s[3]]^a[s[6]];
            }
            else{
            a[s[0]]=a[s[0]]^a[s[3]];
            }
        }
    }
    return 0;
}
