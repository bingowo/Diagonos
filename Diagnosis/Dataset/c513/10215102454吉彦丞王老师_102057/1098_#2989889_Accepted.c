#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[100];
        scanf("%s",&s);
        int l=strlen(s);
        char c[l];
        for(int j=0;j<l;j++)
        {
            c[j]='0';
        }
        int t=0;
        for(int j=0;j<l;j++)
        {
            t=j;
            int m=0;
            for(int k=t;k<t+4;k++)
            {
                if(s[k]>='A'&&s[k]<='Z')
                {
                    c[k]=s[k];
                    m++;
                    if(m>=3)
                    {
                    	break;
					}
                }
            }
            if(m>=3)
            {
            	break;
			}
        }
        for(int j=t;j<t+4;j++)
        {
            if(c[j]=='0')
            {
                c[j]=(116-(c[t]-'0')-(c[t+1]-'0')-(c[t+2]-'0')-(c[t+3]-'0'))+'0';
            }
        }
        for(int j=t-1;j>=0;j--)
        {
            c[j]=(116-(c[j+1]-'0')-(c[j+2]-'0')-(c[j+3]-'0'))+'0';
        }
        for(int j=t+4;j<l;j++)
        {
            c[j]=(116-(c[j-1]-'0')-(c[j-2]-'0')-(c[j-3]-'0'))+'0';
        }
        int R=0,B=0,Y=0,G=0;
        printf("case #%d:\n",i);
        for(int j=0;j<l;j++)
        {
        	if(c[j]=='R')
        	{
        		R++;
			}
			else if(c[j]=='B')
			{
				B++;
			}
			else if(c[j]=='Y')
			{
				Y++;
			}
			else
			{
				G++;
			}
		}
		for(int j=0;j<l;j++)
		{
			if(s[j]=='R')
			{
				R--;
			}
			else if(s[j]=='B')
			{
				B--;
			}
			else if(s[j]=='Y')
			{
				Y--;
			}
			else if(s[j]=='G')
			{
				G--;
			}
		}
		printf("%d %d %d %d\n",R,B,Y,G);
    }
    return 0;
}