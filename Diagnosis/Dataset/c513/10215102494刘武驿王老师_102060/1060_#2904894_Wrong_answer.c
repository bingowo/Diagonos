#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[200];
    scanf("%s",s);
    int j,max=0,test=1;
    for(int i=0;i<strlen(s);i++)
    {
        if((s[i]=='0'&&isalpha(s[i-1]))||test==0)
        {
            test=0;
            if(s[i+1]!='0') test=1;
            continue;
        }
        if(s[i]<='9'&&s[i]>='0')
        {
            j=0;
            while(s[i+j]<='9'&&s[i+j]>=1) j++;
            if(j>max) max=j;
        }
    }
    printf("%d",max);
}