#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a=80,b=80,len[161]={0};

void up(char c,char L[][81],int k)
{
    int i;if(len[k]==0)a++;
    for(i=len[k];i<len[k-1];i++)L[k][i]=' ';
    L[k][i]=c;L[k][i+1]='\0';
    len[k]=len[k-1]+1;
}

void down(char c,char L[][81],int k)
{
    int i;if(len[k]==0)b--;
    for(i=len[k];i<len[k+1];i++)L[k][i]=' ';
    L[k][i]=c;L[k][i+1]='\0';
    len[k]=len[k+1]+1;
}

void stop(char c,char L[][81],int k)
{
    L[k][len[k]]=c;
    len[k]=len[k]+1;L[k][len[k]]='\0';
}

int main()
{
    char s[81];
    while(scanf("%s",s)!=EOF)
    {
        int k=80,i;
        char line[161][81];
        line[k][len[k]++]=s[0];line[k][len[k]]='\0';
        for(i=1;i<strlen(s);i++)
        {
            if(s[i]>s[i-1]){k++;up(s[i],line,k);}
            else if(s[i]<s[i-1]){k--;down(s[i],line,k);}
            else stop(s[i],line,k);
        }
        for(i=a;i>=b;i--)printf("%s\n",line[i]);
        a=80;b=80;for(i=0;i<161;i++)len[i]=0;
    }
}
