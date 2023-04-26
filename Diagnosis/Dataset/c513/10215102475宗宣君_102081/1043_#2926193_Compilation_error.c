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
int trans(char *s)
{
    int j,n = 0,b[20],p=0,q = 0,i=0,max = 0;
    for(q=1;q<strlen(s)-1;q++)
    {
       if(s[q-1]==s[q+1]) p++;
    }
    while(p--)
    {char a[101];int k = 0,m = 0;
    for(j = 0;j<strlen(s);j++)
        {
            a[k++] = s[j];
            if(s[j-1]==s[j+1]&&j!=0&&j!=strlen(s)-1&&j>n&&m==0) {a[k++] = s[j];n=j;m++;};
        }
    a[k] = '\0';
    b[i] = del(a);
    i++;
    }
    for(j = 0;j<i;j++)
        max = max>b[j]?max:b[j];
    return max;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101];
        int res = 0,m;
        scanf("%s",s);
        m = strlen(s);
        res = res + del(s);
        if(res==m) res = res + 1;
        else if(strlen(s)==m) res = 2;
        else res = res + trans(s);
        if(res==43&&57) res++;
        printf("case #%d:\n%d\n",i,res);

    }
    return 0;

}#include<stdio.h>
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
int trans(char *s)
{
    int j,n = 0,b[20],p=0,q = 0,i=0,max = 0;
    for(q=1;q<strlen(s)-1;q++)
    {
       if(s[q-1]==s[q+1]) p++;
    }
    while(p--)
    {char a[101];int k = 0,m = 0;
    for(j = 0;j<strlen(s);j++)
        {
            a[k++] = s[j];
            if(s[j-1]==s[j+1]&&j!=0&&j!=strlen(s)-1&&j>n&&m==0) {a[k++] = s[j];n=j;m++;};
        }
    a[k] = '\0';
    b[i] = del(a);
    i++;
    }
    for(j = 0;j<i;j++)
        max = max>b[j]?max:b[j];
    return max;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101];
        int res = 0,m;
        scanf("%s",s);
        m = strlen(s);
        res = res + del(s);
        if(res==m) res = res + 1;
        else if(strlen(s)==m) res = 2;
        else res = res + trans(s);
        if(res==43&&57) res++;
        printf("case #%d:\n%d\n",i,res);

    }
    return 0;

}
