#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[110];
    scanf("%s",s);
    int i=0,count1=0,m=0;

    for(i=0;s[i];i++)
    {
        if(i==0 && s[i]=='0'){for(i=0;s[i]=='0';i++)m=0;i=i-1;}
        else if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z'))
        {
            if(s[i+1]=='0'){for(i=i+1;s[i]=='0';i++)m=0;i=i-1;}
            else m=0;
        }
        else if(s[i]>='0'&& s[i]<='9')m++;
        if(count1<=m)count1=m;
    }
    printf("%d",count1);
    return 0;
}
