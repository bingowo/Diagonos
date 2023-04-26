#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {char temp;int num;} string;
int main()
{
    int T;
    scanf ("%d",&T);
    getchar();
    for (int q=0;q<T;q++)
    {
        char c,t[27];
        int i=0,j=0;
        string s[501]={};
        while ((c=getchar())!='\n')
        {
            if (s[j].temp)
            {
                if (c==s[j].temp&&s[j].num<255)
                        s[j].num++;
                else
                {
                    j++;
                    s[j].temp=c;
                    s[j].num=1;
                }
            }
            else
            {
                s[j].temp=c;
                s[j].num=1;
            }
        }
        j++;
        printf("case #%d:\n",q);
        for (int k=0;k<j;k++)
        {
            printf("%d%c",s[k].num,s[k].temp);
        }
        printf("\n");
    }
    return 0;
}
