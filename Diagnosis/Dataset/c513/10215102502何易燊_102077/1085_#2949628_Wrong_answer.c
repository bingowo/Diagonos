#include <stdio.h>
#include <string.h>

int main()
{
    char s[501],t[501];
    while (scanf("%s %s",s,t)!=EOF)
    {
        char *p,*q;
        if (strlen(t)>strlen(s)) 
        {
            printf("-");
            p = t; q = s;
        }
        else if (*t>*s)
        {
            printf("-");
            p = t; q = s;
        }
        else {p = s; q = t;}
        int a[501] = {}, b[501] = {};
        int lena = 0,lenb = 0;
        for (int i=strlen(s)-1;i>=0;i--) a[lena++] = p[i]-'0';
        for (int i=strlen(t)-1;i>=0;i--) b[lenb++] = '0'-q[i];
        int max = (lena>lenb)?lena:lenb;
        for (int i=0;i<max;i++)
        {
            a[i] += b[i];
            while (a[i]<0) {a[i] += 10; a[i+1]--;}
        }
        while (a[max]==0&&max) max--;
        for (int i=max;i>=0;i--) printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}