#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[100];
        gets(s);
        int l=strlen(s);
        for(int j=0;j<l;j++)
        {
            if(s[i]>=65&&s[i]<=90)
            {
                s[i]=s[i]+32;
            }
        }
        int n=1;
        for(int j=0;j<l;j++)
        {
            if(s[j]==' ')
            {
                if(s[j+1]=='a'&&s[j+2]==' ')
                {
                    continue;
                }
                else if(s[j+1]=='t'&&s[j+2]=='h'&&s[j+3]=='e'&&s[j+4]==' ')
                {
                    continue;
                }
                else if(s[j+1]=='o'&&s[j+2]=='f'&&s[j+3]==' ')
                {
                    continue;
                }
                else if(s[j+1]=='a'&&s[j+2]=='n'&&s[j+3]==' ')
                {
                    continue;
                }
                else if(s[j+1]=='f'&&s[j+2]=='o'&&s[j+3]=='r'&&s[j+4]==' ')
                {
                    continue;
                }
                else if(s[j+1]=='a'&&s[j+2]=='n'&&s[j+3]=='d'&&s[j+4]==' ')
                {
                    continue;
                }
                else
                {
                    n++;
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",n);
    }
    return 0;
}