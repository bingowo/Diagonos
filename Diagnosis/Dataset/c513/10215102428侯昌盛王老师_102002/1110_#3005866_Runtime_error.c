#include <stdio.h>
#include <string.h>
int main()
{
	char s[81],p;
	scanf("%s",s);
	int sumx=0,suma=0;
	int mid[81]={0};
	int len=strlen(s),i;
	for(i=0;s[i]!='=';i++)
	{
		
		if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
		{
		
			p=s[i];
			if(i==0||s[i-1]=='+') sumx+=1;
			else if(s[i-1]=='-') sumx-=1;
			else{
				int k=i;
				while(k!=0&&s[k]!='+'&&s[k]!='-')
				{
					k--;
					mid[k]=1;
				}
				
				int m,res=0;
				if(k==0&&s[k]!='-') m=0;
				else m=k+1;
			
				for(m;m<i;m++) res=res*10+(s[m]-'0');
			
				if((k==0&&s[k]!='-')||s[k]=='+') sumx+=res;
				else if(s[k]=='-') sumx-=res;
				
			}
			
		}
		
		
	}

	for(i=0;s[i]!='=';i++)
	{
		int w,res=0;
		if(s[i]>='0'&&s[i]<='9'&&mid[i]==0)
		{
		
			
			w=i;
			while(s[i]!='+'&&s[i]!='-'&&s[i]!='=')
			{
				
				res=res*10+(s[i]-'0');
			
				i++;
			}
		}
		if(w==0||s[w-1]=='+') suma-=res;
		else suma+=res;
		if(s[i]=='=') break; 
	}

	int r=i;
	for(i;i<len;i++)
	{
		if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
		{
			
			p=s[i];
			if(s[i-1]=='='||s[i-1]=='+') sumx-=1;
			else if(s[i-1]=='-') sumx+=1;
			else{
				int k=i;
				while(s[k]!='='&&s[k]!='+'&&s[k]!='-')
				{
					k--;
					mid[k]=1;
				}
				int m=k+1,res=0;
				for(m;m<i;m++) res=res*10+(s[m]-'0');
				if(k==0||s[k]=='+') sumx-=res;
				else if(s[k]=='-') sumx+=res;
				
			}
		}
	}
	for(i=r;i<len;i++)
	{
		int res=0,w;
		if(s[i]>='0'&&s[i]<='9'&&mid[i]==0)
		{
			w=i;
			while(s[i]!='+'&&s[i]!='-'&&i<len)
			{
				res=res*10+(s[i]-'0');
				
				i++;
			}
		} 
		if(s[w-1]=='='||s[w-1]=='+') suma+=res;
		else suma-=res;
		if(i==len) break;
	}
	
	double ans;
	ans=suma*1.0/sumx;
	printf("%.3lf\n",ans);

	return 0;
	
}