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
    i++;
    for(;i<=lens;i++)
    b[i]=s[i-1];
    b[i]='\0';

}//在s[k]后插入A放在b里面
void insertB(char*s,int k,char*b)
{

    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    b[i]=s[i];
    b[i]='B';
    i++;
    for(;i<=lens;i++)
    b[i]=s[i-1];
    b[i]='\0';

}//在s[k]后插入B放在b里面
void insertC(char*s,int k,char*b)
{

    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    b[i]=s[i];
    b[i]='C';
    i++;
    for(;i<=lens;i++)
    b[i]=s[i-1];
    b[i]='\0';

}//在s[k]后插入C放在b里面


void xiaochu(char*s)
{
    char c[110];
    int lens=strlen(s);
    int jiancha(char*s)
{
    int len=strlen(s),k;
    if(len<=1) return 1;
    if(len>1)
    {for(k=1;k<len;k++)
    if(s[k]==s[k-1]) break;
    if(k==len) return 1;
    else return 0;}
}//检查s里面有没有重复字母

    while(jiancha(s)==0)
    {
        int l=0;
        for(int k=0;k<lens-1;k++)
        {if(s[k]==s[k+1]) {while(s[k]==s[k+1]&&k<lens-1) k++;}
        else {c[l]=s[k];l++;}
        k++;}
        strcpy(s,c);
    }//消除
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a[110];
        scanf("%s",a);
        int len=strlen(a),max=0;
        for(int k=0;k<len;k++)
        {
            char b[110];
            insertA(a,k,b);
            xiaochu(b);
            max=(max>(len-strlen(b)))?max:(len-strlen(b));
        }//插A
        for(int k=0;k<len;k++)
        {
            char b[110];
            insertB(a,k,b);
            xiaochu(b);
            max=(max>(len-strlen(b)))?max:(len-strlen(b));
        }//插B
        for(int k=0;k<len;k++)
        {
            char b[110];
            insertC(a,k,b);
            xiaochu(b);
            max=(max>(len-strlen(b)))?max:(len-strlen(b));
        }//插C
        printf("case #%d:\n",i);
        printf("%d\n",max);

    }
    return 0;
}
