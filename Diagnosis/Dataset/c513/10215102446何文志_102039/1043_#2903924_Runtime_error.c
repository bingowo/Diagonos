#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char s[],int index,char c)
{
    int len = strlen(s);
    for(int i = len;i>=index;i--)
    {
        s[i+1] = s[i];
    }
    s[index] = c;
}

int  eliminate(char s[],char t[])
{
    int slen = strlen(s),tlen = strlen(t);
    int i = 0,j = 0;
    while((s[i]!=0)&&(s[j]!=0))
    {
        j = i+1;
        int flag = 0;
        while(s[i]!=s[j]){i++;j++;}
        while(s[i]==s[j]){j++;}
        for(int k = i;k<j;k++)
        {
            s[k] = 0;
        }
        i = j;
    }
    int cnt = 0;
    for(int i1 = 0;i1<slen;i1++)
    {
        if(s[i1]!=0)
        {
            t[cnt++] = s[i1];
        }
    }
    return s-t;
}

int main()
{
    int T = 0;
    scanf("%d",&T);

    for(int i = 0;i<T;i++)
    {
        char s[110];memset(s,0,110*sizeof(char));
        char s1[110];memset(s1,0,110*sizeof(char));
        scanf("%s",s);
        eliminate(s,s1);
        printf("%s\n",s1);
    }

    //char s1[100] = "abcdefg";
    //insert(s1,3,'h');
    //printf("%s\n",s1);
    return 0;
}
