#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void input(char*s,int*s1)
{
    int len=strlen(s),i,l;
    for(i=len-1,l=0;i>=0;i--)
    {
        while(s[i]!=0) {s1[l]=s[i]%2;s[i]/=2;l++;}
    }//l是s1中数字的个数
    for(i=0;i<l/2;i++)
    {
        int c;
        c=s1[i];
        s1[i]=s1[l-i-1];
        s1[l-i-1]=c;
    }//调换顺序
    for(;l<10000000;l++)
    s1[l]=0;
    
}
void shu(char*s,int l)
{
    int len=strlen(s),i;
    l=0;
    for(i=len-1,l=0;i>=0;i--)
    {
        while(s[i]!=0) {l++;s[i]/=2;}
    }
   
}

void chuli(int*s1,int*s2,int l)
{
    int k=0;
    for(int i=0;i<(l/6+1);i++)
    {
        for(int o=0;o<6;o++,k++)
        s2[i]=s2[i]*2+s1[k];
    }
}

void fanyi(int*s2,char*s3,int l)
{
    int l2=l/6+1;//l2是s2中数字的个数
    char d[65]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
    'O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h',
    'i','j','k','l','m','n','o','p','p','q','r','s','t','u','v','w','x','y','z',
    '0','1','2','3','4','5','6','7','8','9','+','/'};
    int i;
    for(i=0;i<l2;i++)
    for(int k=0;k<63;k++)
    if(s2[i]==d[k]) s3[i]=k;
    s3[i]='\0';
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char s[110],s3[1110];
        scanf("%s",s);
        int len=strlen(s),l;
        int s1[48*len]={0},s2[l/6+100]={0};
        input(s,s1);
        shu(s,l);
        chuli(s1,s2,l);
        fanyi(s2,s3,l);
        printf("case #%d:\n",i);
        printf("%s\n",s3);
    }
    return 0;
}