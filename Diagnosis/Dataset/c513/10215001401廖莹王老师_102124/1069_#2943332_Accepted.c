#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void reverse(char s[])
{  int c,i,j;
for(i=0,j=strlen(s)-1;i<j;i++,j--)
    c=s[i],s[i]=s[j],s[j]=c;
}
void zhuanhua(long long k,char s[1000])
{
    int i=0;
    s[0]='\0';
    for(i=0;k>0;i++){s[i]=k%10+'0';k=k/10;}
    reverse(s);
}
void huiwen(char s[10000],int count)
{
    int i,j=strlen(s);
    char s1[10000]={0};
    for(i=0;i<j;i++){s1[i]=s[j-1-i];}
    s1[i]='\0';
    if(strcmp(s,s1)==0)printf("%d %s",count,s);
    else
    {
        long long k=0;
        k=atoi(s)+atoi(s1);count++;
        zhuanhua(k,s);
        huiwen(s,count);
    }

}
int main()
{
    char s[100000]={0};
    int count=0;
    scanf("%s",s);
    huiwen(s,count);
    return 0;
}
