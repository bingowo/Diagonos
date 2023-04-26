#include <stdio.h>
#include <stdlib.h>

int danci(char* s,int j)
{
    if((s[j]=='t'||s[j]=='T')&&(s[j+1]=='h'||s[j+1]=='H')&&(s[j+2]=='e'||s[j+2]=='E')&&(s[j+3]==' '||s[j+3]==0))
        return 0;
    if((s[j]=='a'||s[j]=='A')&&(s[j+1]==' '||s[j+1]==0))
        return 0;
    if((s[j]=='a'||s[j]=='A')&&(s[j+1]=='n'||s[j+1]=='N')&&(s[j+2]==' '||s[j+2]==0))
        return 0;
    if((s[j]=='o'||s[j]=='O')&&(s[j+1]=='f'||s[j+1]=='F')&&(s[j+2]==' '||s[j+2]==0))
        return 0;
    if((s[j]=='f'||s[j]=='F')&&(s[j+1]=='o'||s[j+1]=='O')&&(s[j+2]=='r'||s[j+2]=='R')&&(s[j+3]==' '||s[j+3]==0))
        return 0;
    if((s[j]=='a'||s[j]=='A')&&(s[j+1]=='n'||s[j+1]=='N')&&(s[j+2]=='d'||s[j+2]=='D')&&(s[j+3]==' '||s[j+3]==0))
        return 0;
    return 1;
}

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[1000];
        gets(s);
        int l=0,j;
        for(j=0;s[j]!='\n'&&s[j]!=0;j++)
        {
            if(j==0)
                l=l+danci(s,j);
            else
            {
                if(s[j]==' ')
                    l=l+danci(s,j+1);
            }
        }
        printf("case #%d:\n%d\n",i,l);
    }
}