#include<stdio.h>
#include<string.h>
#include<math.h>
int change(char s[])
{
    int t=0;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        t=(t+(s[i]-'0'))*10;
    }
    return t/10;
}
int test(int a,int b,int c)
{
	if(b*b-4*a*c<0)
	{
		return -1;
	}
	else
	{
		int re=b*b-4*a*c;
		int t=0;
		for(int i=0;i<=re;i++)
		{
			if(i*i==re)
			{
				t=i;
			}
		}
		if(t>=0)
		{
			return t;
		}
		else
		{
			return -1;
		}
	}
}
int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	else
	{
		return a;
	}
}
int eliminate(int a,int b)
{
	int t=1;
	if(a*b==0)
	{
		t=a+b;
	}
	else
	{
		for(int i=1;i<=min(abs(a),abs(b));i++)
		{
			if(a%i==0&&b%i==0)
			{
				if(t<i)
				{
					t=i;
				}
			}
		}
	}
	return t;
}
int main()
{
    char s[20];
    scanf("%s",s);
	int l=strlen(s);
    char s1[l];
    char s2[l];
    char s3[l];
    int a,b,c;
    int key1=0,key2=0,key3=0;
    int choose,sign,sign2,sign3;
    if(s[0]=='-')
    {
        sign=-1;
        choose=1;
    }
    else
    {
        sign=1;
        choose=0;
    }
    for(int i=choose;i<l;i++)
    {
        if(s[i]=='x'&&s[i+1]=='^')
        {
            key1++;
            int m=i;
            if(m==choose)
            {
                a=sign;
            }
            else
            {
                for(int j=choose;j<m;j++)
                {
                    s1[j-choose]=s[j];
                }
                s1[m-choose]='\0';
                a=change(s1)*sign;
            }
        }
        if(s[i]=='^'&&s[i+1]=='2')
        {
            int x=0;
            int m=i+2;
            for(int j=m+1;j<l;j++)
            {
                if(s[j]=='x')
                {
                    x=j;
                }
            }
            if(x==0)
            {
                b=0;
                sign3=s[m]=='+'?1:-1;
                for(int j=m+1;j<l;j++)
                {
                	s3[j-m-1]=s[j];
				}
				s3[l-m-1]='\0';
				c=change(s3)*sign3;
            }
            else 
            {
                sign2=s[m]=='+'?1:-1;
                if(x==m+1)
                {
                    b=sign2;
                }
                else
                {
                    for(int j=m+1;j<x;j++)
                    {
                        s2[j-m-1]=s[j];
                    }
                    s2[x-m-1]='\0';
                    b=change(s2)*sign2;
                }
                if(x==l-1)
                {
                    c=0;
                }
                else
                {
                    sign3=s[x+1]=='+'?1:-1;
                    for(int j=x+2;j<l;j++)
                    {
                        s3[j-x-2]=s[j];
                    }
                    s3[l-x-2]='\0';
                    c=change(s3)*sign3;
                }
            }
        }
    }
    if(test(a,b,c)==-1)
    {
    	printf("No Answer!");
	}
	else
	{
		int re1=2*a,re2=b+test(a,b,c),re3=2*a,re4=b-test(a,b,c);
		int d1=eliminate(re1,re2);
		int d2=eliminate(re3,re4);
		re1=re1/d1;
		re2=re2/d1;
		re3=re3/d2;
		re4=re4/d2;
		if(re1<re3)
		{
			printf("%d %d %d %d",re1,re2,re3,re4);
		}
		else if(re1==re3)
		{
			if(re2<=re4)
			{
				printf("%d %d %d %d",re1,re2,re3,re4);
			}
			else
			{
				printf("%d %d %d %d",re3,re4,re1,re2);
			}
		}
		else
		{
			printf("%d %d %d %d",re3,re4,re1,re2);
		}
	}
    return 0;
}