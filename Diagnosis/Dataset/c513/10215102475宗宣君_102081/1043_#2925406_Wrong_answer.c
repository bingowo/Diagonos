#include<stdio.h>
#include <string.h>
int del(char *s)
{
   int m = strlen(s),j,k = 0;
   for(j = 0;j<m;j++)
    {
        if(s[j]!=s[j-1]&&s[j]!=s[j+1]&&j!=m-1&&j!=0) s[k++] = s[j];
        else if(j==m-1&&s[j]!=s[j-1]) s[k++] = s[j];
        else if(j==0&&s[j]!=s[j+1]) s[k++] = s[j];
    }
    s[k] = '\0';
    if(m==k) return 0;
    else return m-k+del(s);
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101],a[101];
        int res = 0,k = 0,m,j;
        scanf("%s",s);
        m = strlen(s);
        res = res + del(s);
        if(res==m) res = res +1;
        else
        {for(j = 0;j<strlen(s);j++)
        {
            a[k++] = s[j];
            if(s[j-1]==s[j+1]&&j!=0&&j!=strlen(s)-1) a[k++] = s[j];

        }
        a[k]='\0';
        if(k==strlen(s)) res = 2;
        else res = res + del(a);}
        printf("case #%d:\n%d\n",i,res);

    }
    return 0;

}
