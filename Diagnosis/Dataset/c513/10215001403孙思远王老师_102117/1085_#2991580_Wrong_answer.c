#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char aa[500],bb[500];
    while(scanf("%s%s",aa,bb)!=EOF)
    {
        int i,c,n,a[500]={0},b[500]={0},s[500]={0};
        for(i=0;i<(strlen(aa)+1)/2;i++)
        {
            c=aa[i]-'0';
            a[i]=aa[strlen(aa)-1-i]-'0';
            a[strlen(aa)-1-i]=c;
        }
        for(i=0;i<(strlen(bb)+1)/2;i++)
        {
            c=bb[i]-'0';
            b[i]=bb[strlen(bb)-1-i]-'0';
            b[strlen(bb)-1-i]=c;
        }
        for(i=0;i<500;i++)
            s[i]=a[i]-b[i];
        for(i=499;i>=0;i--)
        {
            if(s[i]!=0)
            {
                n=i;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(s[i]<0)
            {
                s[i+1]--;
                s[i]+=10;
            }
        }
        if(s[n]<0)
        {
            s[n]*=-1;
            printf("-");
        }
        if(n==1&&s[n]==0)
            printf("0");
        for(i=n;i>=0;i--)
        {
            if(s[i]!=0)
                break;
        }
        for(;i>=0;i--)
            printf("%d",s[i]);
        printf("\n");
    }
    return 0;
}
