#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse(char*s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    char s[100001]={0};
    unsigned int a[100001]={0};
    gets(s);
    int i,p=0;
    for(i=0;s[i];i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            char s1[100001]={0};
            int j=0;
            for(i=i+2;s[i];i++)
            {
                if((s[i]<='9'&&s[i]>='0')||(s[i]<='f'&&s[i]>='a'))
                {
                    if(s[i]=='0'&&s[i+1]=='x'&&((s[i+2]<='9'&&s[i+2]>='0')||(s[i+2]>='a'&&s[i+2]<='f')))
                        break;
                    else
                        s1[j++]=s[i];
                }
                else
                    break;
            }
            if(s[i-1]!='x')
            {
                reverse(s1);
                for(j=0;s1[j];j++)
                {
                    if(s1[j]<='9'&&s1[j]>='0')
                        a[p]=a[p]+(s1[j]-'0')*pow(16,j);
                    else
                        a[p]=a[p]+(s1[j]-87)*pow(16,j);
                }
                p++;
            }
        }
    }
    if(p==0)
        printf("-1");
    else
    {
        for(i=0;i<p;i++)
            printf("%u ",a[i]);
    }
}