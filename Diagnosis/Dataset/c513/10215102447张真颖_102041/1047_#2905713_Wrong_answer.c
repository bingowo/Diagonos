#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[501]="",r[501]="";
        scanf("%s",s);
        int count=1,j=0;
        for(int i=1;i<strlen(s);i++)
        {
            if(s[i]==s[i-1]) count++;
            else if(s[i]!=s[i-1])
            {
                r[j]=count+'0';
                r[j+1]=s[i-1];
                j+=2;
                count=1;
            }
            if(i==strlen(s)-1) r[j]=count+'0',r[j+1]=s[i],j+=2;
        }
        r[j]=0;
        if(strlen(s)==1) r[0]=1+'0',r[1]=s[0],r[2]=0;
        printf("case #%d:\n%s\n",i,r);
    }
    return 0;
}