#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char refer[6][4]={"eht","a","na","fo","rof","dna" };
    int T,l,cnt,p,symbol,res;
    scanf("%d",&T);getchar();
    for(int i=0;i<T;i++)
    {
        char s[101],mid[101][101];
        gets(s);l=strlen(s);cnt=0;p=0;res=0;
        for(int t=0;t<l;t++) s[t]=tolower(s[t]);
        for(int t=0;t<l;t++)
        {
            if(s[t]==' ')
            {
                symbol=1;
                while(p--) mid[cnt][p]=s[t-p-1];
                for(int m=0;m<6;m++)
                {
                    if(strcmp(mid[cnt],refer[m])==0) {symbol=0;break;}
                }
                if(symbol) res++;
                p=0;cnt++;
            }
            else if(t==l-1)
            {
                symbol=1;p++;
                while(p--) mid[cnt][p]=s[t-p];
                for(int m=0;m<6;m++)
                {
                    if(strcmp(mid[cnt],refer[m])==0) {symbol=0;break;}
                }
                if(symbol) res++;
            }
            else p++;
        }
        printf("case #%d:\n%d\n",i,res);
    }

    return 0;
}
