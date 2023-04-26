#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num = 0;

int check(char s[])
{
    int i = 1;
    if (s[0]==s[1]) return 0;
    if (s[0]=='\0') return -1;
    while (s[i]!=s[i+1]&&s[i+1]) i++;
    if (i==strlen(s)-1) return -1;
    else return i;
}

int check2(char s[])
{
    for (int i=0;s[i+2];i++) if (s[i]==s[i+2]&&s[i]!=s[i+1]) return 1;
    return 0;
}

main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s[101];
        scanf("%s",s);
        int judge = check2(s);
        while (check(s)!=-1)
        {
            int index = check(s);
            int cnt = 0;
            for (int j=index;s[j]==s[index];j++) cnt++;
            num += cnt;
            for (int j=index+cnt;s[j-1];j++) s[j-cnt] = s[j];
        }
        if (s[0]=='\0') num++;
        else if (judge) num += 4;
        else num += 2;
        printf("case #%d:\n%d\n",i,num);
        num = 0;
    }
    system("pause");
    return 0;
}