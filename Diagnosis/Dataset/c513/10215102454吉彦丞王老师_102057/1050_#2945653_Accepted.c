#include<stdio.h>
#include<string.h>
#include<math.h>
int in(char c,char s[])
{
	int l=strlen(s);
	int t=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]!=c)
		{
			t++;
		}
	}
	if(t==l)
	{
		return -1;
	}
	else
	{
		return t;
	}
}
int length(char s1[],char s2[],char s[])
{
	int l1=strlen(s1),l2=strlen(s2),l=strlen(s);
	if(l1>l||l2>l)
	{
		return 0;
	}
	else
	{
		int start=0;
    	int n1=0,n2=0;;
    	if(l1==1&&l2==1&&(in(s1[0],s)==-1||in(s2[0],s)==-1))
    	{
    		return 0;
		}
		else
    	{
			for(int j=0;j<l;j++)
    		{
				int m=j;
        		for(int k=m;k<m+l1;k++)
        		{	
            		if(s1[k-m]==s[k])
            		{
               			start++;
            		}
            		else
            		{
                		start=0;
                		continue;
            		}
        		}
        		if(start==l1)
        		{
            		n1=m+start;
            		break;
        		}
    		}
    		int end=l-1;
    		for(int j=l-1;j>=0;j--)
    		{
				int m=j;
        		for(int k=m;k>m-l2;k--)
        		{
            		if(s2[k-m+l2-1]==s[k])
            		{
                		end--;
            		}
            		else
            		{
                		end=l-1;
                		continue;
            		}
        		}
        		if(end==l-1-l2)
        		{
            		n2=m-l2+2;
            		break;
        		}
    		}	
    		if(n2-n1<=1)
    		{
    			return 0;
			}
			else
			{
				return n2-n1-1;
			}
		}
	}
}
int cmp(char s1[],char s2[],char s[])
{
	int a=length(s1,s2,s);
	int b=length(s2,s1,s);
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s1[80],s2[80],s[80];
        scanf("%s",&s1);
        scanf("%s",&s2);
        scanf("%s",&s);
        printf("case #%d:\n",i);
		printf("%d\n",cmp(s1,s2,s));
    }
    return 0;
}