#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int count;
    char ch;
}CHAR;

int transfer(CHAR etab[],char s[])
{
    int c=1,t=0;
    for(int i=1;i<strlen(s);i++)
    {
        if(s[i]==s[i-1])
        {
            c++;
        }
        else if(s[i]!=s[i-1])
        {
            etab[t].ch=s[i-1];
            etab[t].count=c;
            c=1;
            t++;
        }
        if(i==strlen(s)-1)
        {
            etab[t].ch=s[i];
            etab[t].count=c;
            c=1;
            t++;
        }
    }
    if(strlen(s)==1) etab[0].ch=s[0],etab[0].count=1,t=1;
    return t;
}


CHAR tab[100000][101]={0};
int main()
{
    int n=0;
    scanf("%d",&n);
    int sign=-1,chkind=0;
    for(int i=0;i<n;i++)
    {
        char s[101]={0};
        scanf("%s",s);
        int t=transfer(tab[i],s);
        if(i==0) chkind=t;
        else if(chkind!=t){sign=0;break;}

    }

    int step=0;
    if(sign)
    {
        for(int j=0;j<chkind;j++)
        {
            char ch=tab[0][j].ch;
            int maxc=tab[0][j].count,minc=tab[0][j].count;
            for(int i=0;i<n;i++)
            {
                if(tab[i][j].ch!=ch){sign=0;break;}
                else
                {
                    if(maxc<tab[i][j].count) maxc=tab[i][j].count;
                    if(minc>tab[i][j].count) minc=tab[i][j].count;
                }
            }
            if(sign==0) break;
            else
            {
                int medium=(maxc+minc)/2;
                for(int i=0;i<n;i++)
                    step+=abs(tab[i][j].count-medium);
            }
        }
    }
    if(sign==0) printf("-1");
    else printf("%d",step);
    return 0;
}