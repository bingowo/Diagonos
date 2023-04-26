#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
int main()
{
    char s[N+2];
    int count=1,cout=1;
    fgets(s,sizeof s,stdin);
    for(int i=0;s[i+1]!='\0';i++)
    {
        if (s[i]!=s[i+1]){count++;}
        else //if(s[i]==s[i+1]||(s[i]=='-'&&s[i+1]=='-')||(s[i]=='|'&&s[i+1]=='|'))
            {if (cout<count)
                 {cout=count;}
             count=1;
            }
       //printf(" %d:%d",count,cout);
    }
    if(cout<count) {cout=count;}
    printf("\n%d",cout);
}
