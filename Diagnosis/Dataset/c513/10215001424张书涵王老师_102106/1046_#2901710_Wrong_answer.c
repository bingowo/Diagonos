#include <stdio.h>
#include <stdlib.h>

int danci(char* s,int j)
{
    if(s[j]=='t'&&s[j+1]=='h'&&s[j+2]=='e'&&s[j+3]==' ')
        return 0;
    if(s[j]=='a'&&s[j+1]==' ')
        return 0;
    if(s[j]=='a'&&s[j+1]=='n'&&s[j+2]==' ')
        return 0;
    if(s[j]=='o'&&s[j+1]=='f'&&s[j+2]==' ')
        return 0;
    if(s[j]=='f'&&s[j+1]=='o'&&s[j+2]=='r'&&s[j+3]==' ')
        return 0;
    if(s[j]=='a'&&s[j+1]=='n'&&s[j+2]=='d'&&s[j+3]==' ')
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
        printf("case #%d:\n%d",i,l);
    }
}
