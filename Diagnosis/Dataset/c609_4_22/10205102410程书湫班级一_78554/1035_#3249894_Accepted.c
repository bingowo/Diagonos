#include <stdio.h>
#include <string.h>

void insert(char ch,int i,char *s,char *t)
{
    strncpy(t,s,i);
    t[i]=ch;t[i+1]='\0';
    strcat(t,s+i);
}

int count_delchar(char *t)
{
    char result[103];
    int s_len=strlen(t),r_len=0;
    int del_char=0;
    if(s_len==0) return 0;
    int i=0;
    while(i<s_len)
    {
        int j=i+1;
        while(t[i]==t[j]) j++;
        if(j-i>1)
        {del_char=del_char+j-i;i=j;}
        else 
        {result[r_len++]=t[i];i=i+1;}
    }
    result[r_len]='\0';
    if(s_len==r_len) return 0;
    else return del_char+count_delchar(result);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        int Max_number=0;
        for(int i=0;i<=len;i++)
        {
            char t[102];
            int ans;
            for(char ch='A';ch<='C';ch++)
            {
                insert(ch,i,s,t);
                ans=count_delchar(t);
                if(ans>Max_number) Max_number=ans;
            }
            
        }
        printf("case #%d:\n",cas);
        printf("%d\n",Max_number);
    }
    return 0;
}