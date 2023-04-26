#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[100001];
unsigned int a[50001];
int main()
{
    int l,id=-1,f=-1,f1=0;;
    scanf("%s",s);
    l=strlen(s);
    for(int i=1; i<l; i++)
    {
        if(f==-1)
        {if(s[i]=='x'&&s[i-1]=='0')
            {f=1;f1=0;id++;}}
        else
        {
            if(f==1)
            {
               if(s[i]>='a'&&s[i]<='f')
                {a[id]=a[id]*16+s[i]-'a'+10;f1=1;}
               else if(s[i]>='0'&&s[i]<='9')
                {a[id]=a[id]*16+s[i]-'0';f1=1;}
               else
               {
                   f=-1;
                   if(f1==0)
                   id--;
               }
            }
        }
    }
    if(id==-1)
        printf("-1");
    else
    {
        for(int i=0;i<=id;i++)
            printf("%u%c",a[i],i==id?'\n':' ');
    }
    return 0;
}
