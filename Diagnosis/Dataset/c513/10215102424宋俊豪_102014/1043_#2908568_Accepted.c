#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[105],s1[105],b[105];
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int f(char t[])
{
    int i=0;
    while(i<strlen(t)-1)
    {
        if(t[i]==t[i+1])
            return 1;
        i++;
    }
    return -1;
}
int slo(char t[])
{
    int id=0,i=0;
    char a[105];
    memset(a,0,sizeof(a));
    int l=strlen(t);
    while(i<l-1)
    {
        if(t[i]==t[i+1]&&i+1<l)
        {
            int j=i;
            while(t[j]==t[j+1]&&j<l-1)j++;
            i=j+1;
        }
        else
        {
            a[id++]=t[i];
            i++;
        }
    }
    if(t[l-1]!=t[l-2])
        a[id++]=t[l-1];
    if(f(a)==1&&a[0]!='\0')
        return slo(a);
    else
        return id;
}

int main()
{
    int n,l,maxn,cnt;
    char c;
    scanf("%d",&n);getchar();
    for(int i=0; i<n; i++)
    {   memset(b,0,sizeof(b));
        gets(s);
        l=strlen(s);
        maxn=0;
        strcpy(b,s);
        for(int q=l; q>0; q--)
                    b[q]=b[q-1];
        cnt=slo(b);
        maxn=max(l-cnt+1,maxn);

        for(int j=0; j<l-1; j++)
        {   strcpy(b,s);
            if(b[j]!=b[j+1])
            {
                for(int q=l; q>j+1; q--)
                    b[q]=b[q-1];
                b[l+1]='\0';
                cnt=slo(b);
                maxn=max(l-cnt+1,maxn);
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",maxn);
    }
    return 0;
}