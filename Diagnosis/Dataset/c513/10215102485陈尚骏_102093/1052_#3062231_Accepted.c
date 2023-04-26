#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int tab[30],num[11];
int main()
{
    int T;
    scanf("%d",&T);
    char s[256];
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int tmp=0;
        int len=strlen(s);
        for(int j=0;j<len;j++)
        {
            tab[s[j]-'A']++;
        }
        tmp=tab['Z'-'A'];
        tab['O'-'A']-=tmp;
        tab['R'-'A']-=tmp;
        num[0]=tmp;
        tmp=tab['X'-'A'];
        tab['S'-'A']-=tmp;
        tab['I'-'A']-=tmp;
        num[6]=tmp;
        tmp=tab['S'-'A'];
        tab['V'-'A']-=tmp;
        num[7]=tmp;
        tmp=tab['V'-'A'];
        tab['I'-'A']-=tmp;
        tab['F'-'A']-=tmp;
        num[5]=tmp;
        tmp=tab['F'-'A'];
        tab['R'-'A']-=tmp;
        tab['O'-'A']-=tmp;
        num[4]=tmp;
        tmp=tab['W'-'A'];
        tab['O'-'A']-=tmp;
        num[2]=tmp;
        tmp=tab['G'-'A'];
        tab['I'-'A']-=tmp;
        num[8]=tmp;
        num[1]=tab['O'-'A'];
        num[9]=tab['I'-'A'];
        num[3]=tab['R'-'A'];
        printf("case #%d:\n",i);
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<num[j];k++)
            {
                printf("%d",j);
            }
        }
        printf("\n");
        memset(tab,0,sizeof(tab));
        memset(num,0,sizeof(num));
    }
    return 0;
}
