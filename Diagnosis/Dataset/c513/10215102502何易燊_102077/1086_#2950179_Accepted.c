#include <stdio.h>
#include <string.h>

void deal(char s[],int f[])
{
    char *p = strchr(s,'.');
    if (p==NULL)
        for (int i=strlen(s)-1,k=0;i>=0;i--,k++) f[501-k] = s[i]-'0';
    else
    {
        for (int i=1,k=0;p[i];i++,k++) f[501+k+1] = p[i]-'0';
        for (int i=p-s-1,k=0;i>=0;i--,k++) f[501-k] = s[i]-'0';
    }
}

int swap(int *a, int *b)
{
    int i = 0;
    while (a[i]==b[i]) i++;
    if (a[i]<b[i]) return 1;
    return 0;
}

int main()
{
    char s[502] = {}, t[502] = {};     
    int save;
    scanf("%s %s %d",s,t,&save);
    int fa[1002] = {}, fb[1002] = {};  // set index=501 as dot.
    deal(s,fa); deal(t,fb);
    if (swap(fa,fb))
    {
        for (int i=0;i<1002;i++) {fa[i]^=fb[i]; fb[i]^=fa[i]; fa[i]^=fb[i];}
        printf("-");
    }
    for (int i=1001;i>=0;i--)
    {
        fa[i] -= fb[i];
        while (fa[i]<0) {fa[i] += 10; fa[i-1]--;}
    }
    if (fa[501+save+1]>=5) fa[501+save]++;
    for (int i=501+save;i>=0;i--) {fa[i-1] += fa[i]/10; fa[i] %= 10;}
    int pos = 0;
    while (fa[pos]==0&&pos<501) pos++;
    for (int i=pos;i<502;i++) printf("%d",fa[i]);
    printf(".");
    for (int i=502;i<502+save;i++) printf("%d",fa[i]);
    printf("\n");
    return 0;
}