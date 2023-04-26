#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char dayin[65];
void reverse(char s[])
{  int c,i,j;
for(i=0,j=strlen(s)-1;i<j;i++,j--)
    c=s[i],s[i]=s[j],s[j]=c;}
void zhuanhua(char t[4])
{
    int i,j,d=0;
    char er[100]={0};
   for(i=0;t[i];i++)
    {   d=t[i];
        char m[9]={0};
        for(j=0;d>0;j++)
        {m[j]=d%2+'0';d=d/2;}
        if(j<8){for(j=j;j<8;j++)m[j]='0'+0;}
        reverse(m);
        strcat(er,m);
    }
    int k=strlen(er);
    while(k%6!=0){er[k]='0'+0;k++;}
    for(i=0;i<k;i=i+6)
    {
        int g=0,u=0;
        for(u=0;u<6;u++)g=g*2+er[i+u]-'0';
        printf("%c",dayin[g]);
    }
    if(k/6<4)
    {
        for(i=k/6;i<4;i++)printf("=");
    }
}
void jisuan(int h)
{
    int i=0;
    for(i=0;i<26;i++)dayin[i]='A'+i;
    for(i=26;i<52;i++)dayin[i]='a'+i-26;
    for(i=52;i<62;i++)dayin[i]='0'+i-52;
    dayin[62]='+';dayin[63]='/';dayin[64]='\0';
    char s[110]={0};
    scanf("%s",s);
    printf("case #%d:\n",h);
    for(i=0;s[i];i=i+3)
    {
        char t[4]={0};
        t[0]=s[i];t[1]=s[i+1];t[2]=s[i+2];t[3]='\0';
        zhuanhua(t);
    }
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
