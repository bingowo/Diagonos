#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int val(char n)
{
    int z;
    if(s[i]>='0'&&s[i]<='9')z=n-'0';
    else z=n-'a'+10;
    return z;
}

int main()
{
    char *s=malloc(sizeof(char)*100000);int a[100000],i,j,k1,k2;
    scanf("%s",s);i=0;int flag=-1;
    while(s[i]=='0'&&s[i+1]=='0')i++;
    for(;i<strlen(s)-1;i++)
    {
        int k=0;
        if(s[i]=='0'&&s[i+1]=='x')
        {
            i+=2;k1=i;
            while(s[i]>='0'&&s[i]<='9'||s[i]>='a'&&s[i]<='z')
                {i++;k2=i;a[k++]=val(s[i]);}
            unsigned int big=0;
            for(j=0;j<k;j++)big=big*16+a[j];
            printf("%u ",big);
            i--;flag=0;
        }
    }
    if(flag==0)printf("-1");
}