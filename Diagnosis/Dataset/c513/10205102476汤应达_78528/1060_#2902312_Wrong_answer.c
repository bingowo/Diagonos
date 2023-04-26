#include<stdio.h>
#include<string.h>

int main()
{
    char s[101];scanf("%s",s);
    int ans=0,tmp=0,i=0;
    while (i<(int)strlen(s))
    {
        if(s[i]>='1' && s[i]<='9')
        {
            while(s[i]>='1' && s[i]<='9' && i<(int)strlen(s)) {i++,tmp++;}
            if(tmp>ans) ans=tmp;
            tmp=0;
        }
        else i++;
    }
    printf("%d",ans);

    return 0;    
}