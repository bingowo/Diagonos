#include<stdio.h>
#include<string.h>
#include<math.h>
long long int zhishu(int n)
{
    long long int t=1;
    for(int i=0;i<n;i++)
    {
        t=t*10;
    }
    return t;
}
long long int change(char s[],int be,int ed)
{
    long long int t=0;
    if(be<=ed)
    {
    	for(int i=be;i<=ed;i++)
    	{
        	t=t+(s[i]-'0')*zhishu(ed-i);
    	}
    }
    else
    {
    	t=t+1;
	}
    return t;
}
int main()
{
    char s[40];
    long long int a,b;
    scanf("%s",s);
    int l=strlen(s);
    int t=0;
    int sign,be;
    if(s[0]=='-')
    {
        sign=-1;
        be=1;
    }
    else
    {
        sign=1;
        be=0;
    }
    for(int i=0;i<l;i++){
       if(s[i]=='+'||s[i]=='-')
       {
           t=i;
       }
    }
    if(t>0)
    {
        if(s[t]=='+')
        {
            a=change(s,be,t-1)*sign;
            b=change(s,t+1,l-2);
        }
        else
        {
            a=change(s,be,t-1)*sign;
            b=-change(s,t+1,l-2);
        }
    }
    else
    {
        if(s[l-1]=='i')
        {
            a=0;
            b=change(s,be,l-2)*sign;
        }
        else
        {
            a=change(s,be,l-1)*sign;
            b=0;
        }
    }
    char c[200];
    int n=0;
    if(abs(a)+abs(b)==0)
    {
    	printf("0");
	}
    while(llabs(a)+llabs(b)!=0)
    {
    	int r;
    	if((a+b)%2==0)
    	{
    		r=0;
		}
		else
		{
			r=1;
		}
		c[n]=r+'0';
		n++;
		int m=a-r;
		int n=b;
		a=(n-m)/2;
		b=-(n+m)/2;
	}
	for(int i=n-1;i>=0;i--)
	{
		printf("%c",c[i]);
	}
	return 0;
}