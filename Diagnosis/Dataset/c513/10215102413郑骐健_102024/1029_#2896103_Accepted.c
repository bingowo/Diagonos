#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int list[26])
{
    for(int i = 0;i<26;i++)
    {
        if(list[i]!= 0)return i;
    }
    return -1;
}

int main()
{

    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 0;i < n;i++)
    {
        char s[300];
        char s2[301];
        int list[26] = {0};
        gets(s);//printf("%s\n",s);
        int point =  0;
        int point2 =0;
        for(int z = 0;z < strlen(s);z++)
        {
            if(s[z]<='Z'&&s[z]>='A')list[s[z]-'A']+=1;
            else if (s[z]==' ')continue;
            else s2[point2++] = s[z];
        }
        printf("case #%d:\n",i);
        int t = 0;
        for(int z = 0;z<strlen(s);z++)
        {
            int flag;
            if(s[z]==' ')printf(" ");
            else if(s[z]<='Z'&&s[z]>='A')
            {
                flag =check(list);
                printf("%c",flag+'A');
                list[flag]--;
            }
            else
            {
                printf("%c",s2[t]);
                t++;
            }
        }
        printf("\n");

    }
    return 0;
}
