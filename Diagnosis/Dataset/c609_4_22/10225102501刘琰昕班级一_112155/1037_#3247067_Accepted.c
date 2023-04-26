#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//48-57数字，65-90大写字母，97-122小写字母
char table[123]={0};

int main()
{
    char *s;int n=0;
    s=(char *)malloc(1000001*sizeof(char));
    while((s[n]=getchar())!='\n')n++;
    int maxpos1=0,maxpos2=0,pos1=0,pos2=0;
    for(int i=0;i<n;i++)
    {
        if(!table[s[i]])
        {
            table[s[i]]=1;
            pos2++;
        }
        else
        {
            if((maxpos2-maxpos1)<(pos2-pos1))
                {maxpos2=pos2,maxpos1=pos1;}
            while(s[pos1]!=s[pos2])
            {
                table[s[pos1]]=0;
                pos1++;
            };
            pos1++;pos2++;
        }
    }
    if((maxpos2-maxpos1)<(pos2-pos1))
        {maxpos2=pos2;maxpos1=pos1;}
    for(int i=maxpos1;i<maxpos2;i++)
        putchar(s[i]);
    return 0;
}
