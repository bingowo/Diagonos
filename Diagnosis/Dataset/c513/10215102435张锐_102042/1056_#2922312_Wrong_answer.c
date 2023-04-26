#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *s1=(char*) a,*s2=(char*) b;
    int len1=strlen(s1),len2=strlen(s2);
    if(len1>len2) return 1;
    else return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[n][21];
    for(int i=0;i<n;i++)
    {
        scanf("%s",&s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    char ans[6001];
    scanf("%s",ans);
    int len=strlen(ans);int b=0;int i1=0;//i1是进去了发现不完全是，退出来的保险
    for(int i=0;i<len;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(s[j][0]==ans[i])
            {
                if(strlen(s[j])==1) {printf("%c ",ans[i]);b=1;}
                else
                {
                    i1=i;i++;
                    for(int k=1;k<strlen(s[j]);i++,k++)
                    {
                        if(s[j][k]==ans[i]&&k==strlen(s[j])-1) {printf("%s ",s[j]);b=1;break;}
                        else if(s[j][k]!=ans[i]) {i=i1;break;}
                    }
                }
            }
            if(b) {b=0;break;}
            if(j==0&&s[j][0]!=ans[i]) printf("%c ",ans[i]);
        }
    }
    printf("\n");
    return 0;
}
