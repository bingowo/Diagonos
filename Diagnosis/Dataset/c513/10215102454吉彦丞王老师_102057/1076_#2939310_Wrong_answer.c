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
        int t=0;
        if(s[0]==')'||s[0]==']'||s[0]=='}')
        {
            printf("No");
        }
        else
        {
            for(int j=0;j<l-1;j++)
            {
                if(s[j]=='(')
                {
                    if(s[j+1]=='{'||s[j+1]==')')
                    {
                        t++;
                    }
                    else
                    {
                        break;
                    }
                }
                else if(s[j]==')')
                {
                    if(s[j+1]=='}')
                    {
                        break;
                    }
                    else
                    {
                        t++;
                    }
                }
                else if(s[j]=='[')
                {
                    if(s[j+1]==']'||s[j+1]=='(')
                    {
                        t++;
                    }
                    else
                    {
                        break;
                    }
                }
                else if(s[j]==']')
                {
                    if(s[j+1]==')')
                    {
                        break;
                    }
                    else
                    {
                        t++;
                    }
                }
                else if(s[j]=='{')
                {
                    if(s[j+1]=='['||s[j+1]=='}')
                    {
                        t++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(s[j+1]==']')
                    {
                        break;
                    }
                    else
                    {
                        t++;
                    }
                }
        	}
        	if(t==l-1)
        	{
        		printf("Yes");
			}
			else
			{
				printf("No");
			}
    	}
    }
    return 0;
}