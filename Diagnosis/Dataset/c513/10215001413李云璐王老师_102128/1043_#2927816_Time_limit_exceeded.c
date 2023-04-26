#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void insertA(char*s,int k,char*b)
{
   
    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    b[i]=s[i];
    b[i]='A';
    for(i=k+2;i<=lens;i++)
    b[i]=s[i-1];
    b[i]='\0';
   
}
void insertB(char*s,int k,char*b)
{
   
    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    b[i]=s[i];
    b[i]='B';
    for(i=k+2;i<=lens;i++)
    b[i]=s[i-1];
    b[i]='\0';
    
}
void insertC(char*s,int k,char*b)
{
   
    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    b[i]=s[i];
    b[i]='C';
    for(i=k+2;i<=lens;i++)
    b[i]=s[i-1];
    b[i]='\0';
    
}

int jiancha(char*s)
{
    int len=strlen(s),k;
    for(k=1;k<len;k++)
    if(s[k]==s[k-1]) break;
    if(k==len) return 1;
    else return 0;
}

void xiaochu(char*s)
{
    char c[110];
    c[0]=s[0];
    int lens=strlen(s);
    while(jiancha(s)==0)
    {
        for(int k=1,l=1;k<lens;k++)
        {if(s[k]==s[k-1]) l--;
        if(s[k]!=s[k-1]) {c[l]=s[k];l++;}}
        strcpy(s,c);
    }
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char a[110];
        scanf("%s",a);
        int len=strlen(a),max=0;
        for(int k=0;k<len;k++)
        {
            char b[110],c[110];
            insertA(a,k,b);
            xiaochu(b);
            max=(max>(len-strlen(c)))?max:(len-strlen(c));
        }
        for(int k=0;k<len;k++)
        {
            char b[110],c[110];
            insertB(a,k,b);
            xiaochu(b);
            max=(max>(len-strlen(c)))?max:(len-strlen(c));
        }
        for(int k=0;k<len;k++)
        {
            char b[110],c[110];
            insertC(a,k,b);
            xiaochu(b);
            max=(max>(len-strlen(c)))?max:(len-strlen(c));
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
        
    }
    return 0;
}