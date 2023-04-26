#include <stdio.h>
#include <string.h>

int deal(char s[],int z[],int f[])
{
    char *t = strchr(s,'.');
    int fpos = 0, k = 0;
    if (t!=NULL)
    {
        for (int i=1;t[i];i++) f[k++] = t[i]-'0';
        fpos = k;
        k = 0;
        for (int i=t-s-1;i>=0;i--) z[k++] = s[i]-'0';
    }
    else for (int i=strlen(s)-1;i>=0;i--) z[k++] = s[i]-'0';
    return fpos;
}

int main()
{
    char s[501],t[501];
    int save;
    scanf("%s %s %d",s,t,&save);
    int za[501] = {},zb[502] = {};
    int fa[501] = {},fb[502] = {};
    int fapos = deal(s,za,fa); 
    int fbpos = deal(t,zb,fb);
    int max = (fapos>fbpos)?fapos:fbpos;
    int carry = 0;
    for (int i=max;i>0;i--)
    {
        fa[i] += fb[i];
        fa[i-1] += fa[i]/10;
        fa[i] %= 10;
    }
    fa[0] += fb[0]; carry += fa[0]/10; fa[0] %= 10;
    if (fa[save]>=5) fa[save-1]++;
    for (int i=save-1;i>0;i--) {fa[i-1] += fa[i]/10; fa[i] %= 10;}
    if (fa[0]>=10) {carry += fa[0]/10; fa[0] %= 10;}
    za[0] += carry;
    for (int i=0;i<501;i++)
    {
        za[i] += zb[i];
        za[i+1] += za[i]/10;
        za[i] %= 10;
    }
    int index = 500;
    while (za[index]==0&&index) index--;
    for (int i=index;i>=0;i--) printf("%d",za[i]);
    printf(".");
    for (int i=0;i<save;i++) printf("%d",fa[i]);
    return 0;
}