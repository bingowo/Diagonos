#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d%c",&number);
    for(int i=0;i<number;i++)
    {
        char s[100];
        gets(s);
        int l=strlen(s);
        for(int j=0;j<l;j++)
        {
            if(s[j]>=65&&s[j]<=90)
            {
                s[j]=s[j]+32;
            }
        }
        int n;
        if(s[0]=='a'&&s[1]<97)
        {
        	n=0;
		}
		else if(s[0]=='t'&&s[1]=='h'&&s[2]=='e'&&s[3]<97)
		{
			n=0;
		}
		else if(s[0]=='a'&&s[1]=='n'&&s[2]<97)
		{
			n=0;
		}
		else if(s[0]=='o'&&s[1]=='f'&&s[2]<97)
		{
			n=0;
		}
		else if(s[0]=='f'&&s[1]=='o'&&s[2]=='r'&&s[3]<97)
		{
			n=0;
		}
		else if(s[0]=='a'&&s[1]=='n'&&s[2]=='d'&&s[3]<97)
		{
			n=0;
		}
		else
		{
			n=1;
		}
        for(int j=0;j<l;j++)
        {
            if(s[j]==' ')
            {
                if(s[j+1]=='a'&&s[j+2]<97)
                {
                    continue;
                }
                else if(s[j+1]=='t'&&s[j+2]=='h'&&s[j+3]=='e'&&s[j+4]<97)
                {
                    continue;
                }
                else if(s[j+1]=='o'&&s[j+2]=='f'&&s[j+3]<97)
                {
                    continue;
                }
                else if(s[j+1]=='a'&&s[j+2]=='n'&&s[j+3]<97)
                {
                    continue;
                }
                else if(s[j+1]=='f'&&s[j+2]=='o'&&s[j+3]=='r'&&s[j+4]<97)
                {
                    continue;
                }
                else if(s[j+1]=='a'&&s[j+2]=='n'&&s[j+3]=='d'&&s[j+4]<97)
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