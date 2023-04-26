#include <stdio.h>
#include <string.h>

int mincmp(char *s,char *t)
{
    if (s[0]=='-'&&t[0]!='-') return 1;
    else if (s[0]!='-'&&t[0]!='-')
    {
        if (strlen(s)<strlen(t)) return 1;
        else if (strlen(s)==strlen(t)&&strcmp(s,t)<0) return 1;
    }
    else if (s[0]=='-'&&t[0]=='-')
    {
        char *s_ = s+1, *t_ = t+1;
        if (strlen(s_)>strlen(t_)) return 1;
        else if (strlen(s_)==strlen(t_)&&strcmp(s_,t_)>0) return 1;
    }
    return 0;
}

int maxcmp(char *s,char *t)
{
    if (s[0]!='-'&&t[0]=='-') return 1;
    else if (s[0]!='-'&&t[0]!='-')
    {
        if (strlen(s)>strlen(t)) return 1;
        else if (strlen(s)==strlen(t)&&strcmp(s,t)>0) return 1;
    }
    else if (s[0]=='-'&&t[0]=='-')
    {
        char *s_ = s+1, *t_ = t+1;
        if (strlen(s_)<strlen(t_)) return 1;
        else if (strlen(s_)==strlen(t_)&&strcmp(s_,t_)<0) return 1;
    }
    return 0;
}

int main()
{
    int n; scanf("%d",&n);
    char temp[80] = {};
    char *p = (char*)malloc(81), *q = (char*)malloc(81);
    int sign_p = 1, sign_q = 1;
    scanf("%s",temp); strcpy(p,temp); strcpy(q,temp);
    for (int i=0;i<n-1;i++)
    {
        scanf("%s",temp);
        if (maxcmp(temp,p)) strcpy(p,temp);
        if (mincmp(temp,q)) strcpy(q,temp);
    }
    int sign_a = 1, sign_b = 1;
    if (p[0]=='-') {sign_a = -1; p++;}
    if (q[0]=='-') {sign_b = -1; q++;}
    int a[121] = {}, b[121] = {};
    int lena = 0,lenb = 0;
    for (int i=strlen(p)-1;i>=0;i--) a[lena++] = (p[i]-'0')*sign_a;
    for (int i=strlen(q)-1;i>=0;i--) b[lenb++] = (q[i]-'0')*sign_b;
    for (int i=0;i<lena;i++)
    {
        a[i] -= b[i];
        while (a[i]<0) {a[i] += 10; a[i+1]--;}
    }
    while (a[lena]==0) lena--;
    for (int i=lena;i>=0;i--) printf("%d",a[i]);
    printf("\n");
    return 0;
}