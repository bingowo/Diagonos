#include <stdio.h>
#include <string.h>
int main()
{
    int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++)
    {
        char s[100];
        int i, n, tmp, ans[140]={0}, j;
        scanf("%s",s);
        int l=strlen(s);
        for(i=0, tmp=0, j=0; i<l; i++)
        {
            if(tmp==0)
            {
                ans[j++]=s[i]/4;
                ans[j]=(s[i]%4)*16;
            }
            else if(tmp==1)
            {
                ans[j++]+=s[i]/16;
                ans[j]=(s[i]%16)*4;
            }
            else
            {
                ans[j++]+=s[i]/64;
                ans[j++]=s[i]%64;
            }
            tmp=(++tmp)%3;
        }
        if(j%4) for(j++; j%4!=0; j++) ans[j]=64;
        printf("case #%d:\n",I);
        for(i=0; i<j; i++)
        {
            if(ans[i]<26) printf("%c",'A'+ans[i]);
            else if(ans[i]<52) printf("%c",'a'+ans[i]-26);
            else if(ans[i]<62) printf("%c",'0'+ans[i]-52);
            else if(ans[i]==62) printf("+");
            else if(ans[i]==63) printf("/");
            else printf("=");
        }
        printf("\n");
    }
    return 0;
}