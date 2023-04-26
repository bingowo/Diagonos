#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt=0;

int main()
{
    char s[21];
    memset(s,'\0',21);
    scanf("%s",s);
    int l=strlen(s);

    plus(s,l);
    printf("%d ",cnt+1);
    printf("%s",s);

    return 0;
}



void plus(char *s,int l)
{
    char s1[21];
    char s0[21];
    int flag=1;
    for(int z=0,j=l-1;j>=z;z++,j--)
    {
        if(s[j]!=s[z]) flag=0;
    }
    if(flag==1) return;
    else cnt++;

    l=strlen(s);
    int i=0;
    for(int z=0;z<l;z++)
    {
        s0[z]=s[l-z-1];
    }

    for(i=0;i<l;i++)
    {
        s[i]=s[i]+s0[i]-'0';
    }

    for(int z=l-1;z>0;z--)
    {
        if(s[z]-'0'>=10) {s[z]-=10;s[z-1]++;}
    }

    if(s[0]-'0'>=10){s[0]-=10;s1[0]='1';strcat(s1,s);strcpy(s,s1);l=l+1;}
    return plus(s,l);
}

