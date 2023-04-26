#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char s[1000];
	scanf("%s",s);
	int a=0,b=0,c=0,len;
	len=strlen(s);
	int i=0,r,r2;
	for(i;i<len;i++)
	{
		if(s[i]=='x'&&s[i+1]=='^')
		{
			int j=0;
			r=i+4;
			for(j;j<i;j++)
			{
				a=a*10+(s[j]-'0');
			}
			if(s[0]=='x') a=1;
			if(s[0]=='-') a=-a;
			
			
		}
		else if(s[i]=='x'&&s[i+1]!='^')
		{
			r2=i+2;
			int m=r;
			if(s[r]=='x') b=1;
			for(r;r<i;r++)
			{
				b=b*10+(s[r]-'0');
			}
			
			if(s[m-1]=='-') b=-b;
		}
		
		
	}
	for(i=len-1;i>=0;i--)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='x'||(s[i]=='2'&&s[i-1]=='^')) break;
	}
	int p=1;
	if(s[i]=='-') p=-1;
	i++;
	for(i;i<len;i++) c=c*10+(s[i]-'0');
	c=c*p;
	//printf("%d\n",b);
	int s1[3]={0},s2[3]={0};
	int t,t1,d,d1,flag=0;
	for(t=1;t<=((abs(a))*1.0)/2+1;t++)
	{
		if(a%t==0) 
		{
			//printf("h\n");
			t1=a/t;
			s1[0]=t;
			s1[1]=t1;
			
		}
		for(d=1;d<=(abs(c)*1.0)/2+1||c==0;d++)
		{
			if(c==0)
			{
				s2[0]=0;
				if(b%a==0) s2[1]=b/a;
				else if(a%b==0) s2[1]=a/b;
				else s2[1]=b;
				goto ans;
			}
			if(c%d==0)
			{
				d1=c/d;
				s2[0]=d;
				s2[1]=d1;
				ans:
				if(s1[0]*s2[0]+s1[1]*s2[1]==b)
				{
					flag=1;break;
				}
				else if(s1[0]*s2[1]+s1[1]*s2[0]==b)
				{
					flag=2;break;
				}
			}
			
		}
		if(flag!=0) break;
	}
	
	printf("%d %d %d %d\n",s1[0],s1[1],s2[0],s2[1]);
	//printf("%d\n",flag);
	if(flag==1)
	{
		if(s1[0]<s1[1]) printf("%d %d %d %d\n",s1[0],s2[1],s1[1],s2[0]);
		else if(s1[0]>s1[1]) printf("%d %d %d %d\n",s1[1],s2[0],s1[0],s2[1]);
		else{
			if(s2[1]<s2[0]) printf("%d %d %d %d\n",s1[0],s2[1],s1[1],s2[0]);
			else printf("%d %d %d %d\n",s1[1],s2[0],s1[0],s2[1]);
		}
	}
	else if(flag==2)
	{
		if(s1[0]<s1[1]) printf("%d %d %d %d\n",s1[0],s2[0],s1[1],s2[1]);
		else if(s1[0]>s1[1]) printf("%d %d %d %d\n",s1[1],s2[1],s1[0],s2[0]);
		else{
			if(s2[0]<s2[1]) printf("%d %d %d %d\n",s1[0],s2[0],s1[1],s2[1]);
			else printf("%d %d %d %d\n",s1[1],s2[1],s1[0],s2[0]);
		}
	}
	else if(flag==0)
	{
		printf("No Answer!\n");
	}
	//printf("%d %d %d\n",a,b,c);
	return 0;
}