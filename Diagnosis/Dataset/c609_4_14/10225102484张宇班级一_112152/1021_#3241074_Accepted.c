#include <stdio.h>
#include<stdlib.h>

int p[26];

int cmp(const void *a,const void *b)
{
    char *p1 = *(char(*)[21])a;
    char *p2 = *(char(*)[21])b;
    while(*p1&&*p2)
    {
        char c1 = (*p1);
        if(c1 >= 'a')
            c1 -= 32;
        char c2 = (*p2);
        if(c2 >= 'a')
            c2 -= 32;
        if(p[c1-'A']!=p[c2-'A'])
            return p[c1-'A']-p[c2-'A'];
        else
        {
            p1++;
            p2++;
        }
    }
    if(*p1 == 0)
        return -1;
    else
        return 1;
}

int main()
{
    char order[27];
    while(scanf("%s",order)!=EOF)
    {
        for(int i = 0;i < 26;i++)
            p[order[i]-'A'] = i;
        getchar();
        char s[100][21];
        int row = 0,column = 0;
        char c;
        while((c = getchar())!='\n')
        {
            if(c == ' ')
            {
                s[row][column] = '\0';
                row++;
                column = 0;
            }
            else
                s[row][column++] = c;
        }
        s[row][column] = '\0';
        row++;
        qsort(s,row,sizeof(s[0]),cmp);
        int i;
        for(i=0;i<row;i++)
            printf("%s ",s[i]);
        printf("\n");
    }
    return 0;
}
