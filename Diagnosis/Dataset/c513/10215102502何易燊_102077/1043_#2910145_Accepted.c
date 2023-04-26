#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char s[])
{
    char t[101] = {};
    int index = 0;
    int cnt = 0;
    if (s[0]=='\0') return 0;
    if (strlen(s)==1) return 0;
    if (s[0]!=s[1]) t[index++] = s[0];
    else cnt++;
    for (int i=1;s[i];i++)
    {
        if (s[i]!=s[i+1]&&s[i]!=s[i-1]) t[index++] = s[i];
        else cnt++;
    }
    if (strcmp(s,t)==0) return 0;
    memset(s,0,sizeof(s));
    strcpy(s,t);
    return cnt;
}

int eliminate(char s[])
{
    int cnt = 0;
    char t[101] = {};
    //char p[101] = {};
    strcpy(t,s); //strcpy(p,s);
    int num = check(t);
    while (num!=0) {cnt += num; num = check(t);}
    return cnt;
}

void insert(char s[],int index)
{
    s[strlen(s)+1] = '\0';
    for (int i=strlen(s);i>index;i--) s[i] = s[i-1];
}

main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s[101];
        scanf("%s",s);
        int max = 0;
        for (int j=0;j<strlen(s)-1;j++)
        {
            char copy[101] = {};
            strcpy(copy,s);
            insert(copy,j);
            if (eliminate(copy)>max) max = eliminate(copy);
        }
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}