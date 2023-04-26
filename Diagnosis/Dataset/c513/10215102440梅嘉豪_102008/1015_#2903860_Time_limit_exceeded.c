#include <stdio.h>
#include <string.h>
void read(char *p,int *q);
void add(int *a,int *b,int *c);
void out(int *p);

int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
int main()
{
    int n,a[26]={0},b[26]={0},ans[26]={0};
    char s[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        read(s,a);
        scanf("%s",s);
        read(s,b);
        for(int j=0;j<26;j++)   printf("%d",a[j]);
        printf("asdas");
        add(a,b,ans);
        printf("case #%d:\n",i);
        out(ans);
    }
}
void read(char *p,int *q)
{
    int n=strlen(p),j=25;
    for(int i=0;i<26;j++)   q[i]=0;

    for(int i=n-1;i>=0;i--)
    {
        if(p[i]!=',')   
        {
            q[j]=p[i]-'0';//把数据倒序写入数组，自动对齐
            j--;
        }
    }
}
void add(int *a,int *b,int *c)
{
    int i=25,carry=0;
    for(int i=0;i<26;i++)   c[i]=0;
    while(i>=0)
    {
        c[i]=(a[i]+b[i]+carry)%prime[i];
        carry=(a[i]+b[i]+carry)/prime[i];
        i--;
    }
    c[i]=carry;
}
void out(int *p)
{
    int i=0;
    while(!p[i])    i++;
    while(i<26)
    {
        printf("%c%c",p[i]+'0',i==25?'\n':',');
        i++;
    }
}
