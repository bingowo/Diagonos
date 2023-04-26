#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[100001];
unsigned int a[50001]={-1};
int main()
{
    int l,id=0,f=-1;
    scanf("%s",s);
    l=strlen(s);
    for(int i=1; i<l; i++)
    {
        if(s[i]=='x'&&s[i-1]=='0')
            {f=1;a[id]=0;}
        else
        {
            if(f==1)
            {
               if(s[i]>='a'&&s[i]<='f')
                a[id]=a[id]*16+s[i]-'a'+10;
               else if(s[i]>='0'&&s[i]<='9')
                a[id]=a[id]*16+s[i]-'0';
               else
               {
                   f=-1;
                   if(a[id]>=0)
                   id++;
               }
            }
        }
    }
    if(a[0]==-1)
        printf("-1");
    else
    {
        for(int i=0;i<=id;i++)
            printf("%u ",a[i]);
    }
    return 0;
}
