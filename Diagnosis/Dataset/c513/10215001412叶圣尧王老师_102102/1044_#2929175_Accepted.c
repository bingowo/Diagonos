#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int val(char n)
{
    int z;
    if(n>='0'&&n<='9')z=n-'0';
    else z=n-'a'+10;
    return z;
}

int main()
{
    char *s=malloc(sizeof(char)*100000);int a[1000],i,j;
    scanf("%s",s);i=0;int flag=-1;
    while(s[i]=='0'&&s[i+1]=='0')i++;
    for(;i<strlen(s)-1;i++)
    {
        int k=0;
        if(s[i]=='0'&&s[i+1]=='x')
        {
            i+=2;
            int val(char n);int e=-1;
            while(s[i]>='0'&&s[i]<='9'||s[i]>='a'&&s[i]<='f')
                {a[k++]=val(s[i]);i++;flag=0;e=0;}
            unsigned int big=0;
            for(j=0;j<k;j++)big=big*16+a[j];
            if(e==0)printf("%u ",big);
            i--;
        }
    }
    if(flag==-1)printf("-1");
    free(s);
}
