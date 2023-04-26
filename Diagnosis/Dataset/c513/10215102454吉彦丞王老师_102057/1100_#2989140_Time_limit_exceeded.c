#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int d(int a,int b)
{
    return abs(a)+abs(b);
}
int lastx(char s[])
{
	int l=strlen(s);
	int x=0;
	for(int i=0;i<l;i++)
    {
        if(s[i]=='R')
        {
            x++;
        }
        else if(s[i]=='L')
        {
            x--;
        }
    }
    return x;
}
int lasty(char s[])
{
	int l=strlen(s);
	int y=0;
	for(int i=0;i<l;i++)
    {
        if(s[i]=='U')
        {
            y++;
        }
        else if(s[i]=='D')
        {
            y--;
        }
    }
    return y;
}
int maxdistance(char s[])
{
    int x=0,y=0;
    int l=strlen(s);
    int length[l];
    for(int i=0;i<l;i++)
    {
        if(s[i]=='U')
        {
            y++;
        }
        else if(s[i]=='D')
        {
            y--;
        }
        else if(s[i]=='R')
        {
            x++;
        }
        else
        {
            x--;
        }
        length[i]=d(x,y);
    }
    qsort(length,l,sizeof(int),cmp);
    return length[l-1];
}
int judge(int x,int y,char s[])
{
    int d0=maxdistance(s);
    int t=0;
    int a=0,b=0;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='U')
        {
            b++;
        }
        else if(s[i]=='D')
        {
            b--;
        }
        else if(s[i]=='R')
        {
            a++;
        }
        else
        {
            a--;
        }
        if(a==x&&b==y)
        {
            t++;
        }
	}
	if(t==0)
	{
		if(d(x,y)>d0)
		{
			return -1;
		}
		else
		{
			x=x-a;
			y=y-b;
			return judge(x,y,s);
		}
	}  
    else
    {
    	return 1;
	}
}
int main()
{
    char s[101];
    scanf("%s",&s);
    int l=strlen(s);
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==0&&y==0)
        {
        	printf("Yes\n");
		}
		else
		{
			if(d(x,y)<=maxdistance(s))
			{
				if(judge(x,y,s)==1)
				{
					printf("Yes\n");
				}
				else
				{
					printf("No\n");
				}
			}
			else
			{
				if(lastx(s)*x<0||lasty(s)*y<0)
				{
					printf("No\n");
				}
				else
				{
					if(x==0)
					{
						if(y%lasty(s)==0)
						{
							printf("Yes\n");
						}
						else
						{
							if(judge(0,y%lasty(s),s)==1)
							{
								printf("Yes\n");
							}
							else
							{
								printf("No\n");
							}
						}
					}
					else if(y==0)
					{
						if(x%lastx(s)==0)
						{
							printf("Yes\n");
						}
						else
						{
							if(judge(x%lastx(s),0,s)==1)
							{
									printf("Yes\n");
							}
							else
							{
								printf("No\n");
							}
						}
					}
					else
					{
						int n=x/lastx(s);
						int m=y/lasty(s);
						int g=max(n,m);
						int t=0;
						for(int i=0;i<2*g;i++)
						{
							x=x-lastx(s);
							y=y-lasty(s);
							if(d(x,y)<maxdistance(s))
							{
								if(judge(x,y,s)==1)
								{		
									printf("Yes\n");
								}
								else
								{
								printf("No\n");
								}
								break;
							}
							else
							{
								t++;
							}
						}
						if(t==2*g)
						{
							printf("No\n");
						}
					}
				}
			}
		}
    }
    return 0;
}