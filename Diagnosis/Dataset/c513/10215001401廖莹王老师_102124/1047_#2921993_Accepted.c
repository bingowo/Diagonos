#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char c;
    int number;
}shu;
void hanshu(int h)
{
    char s[1000];
    scanf("%s",s);
    shu p[1000];
    int count,i,j=0;
    for(i=0;s[i];i++)
    {
        count=1;p[j].c=s[i];
            for(i=i+1;s[i];i++)
            {
                if(s[i]==s[i-1])count++;
                else break;
            }
         i--;
        p[j].number=count;j++;
    }
    printf("case #%d:\n",h);
    for(i=0;i<j;i++)
    {
        if(p[i].number>255)printf("255""%c%d%c",p[i].c,p[i].number-255,p[i].c);
        else printf("%d%c",p[i].number,p[i].c);
    }
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        hanshu(h);
}
