#include<stdio.h>
#include<string.h>
int main()
{
	char a[42][42];
	int i=0,j=0;
	for(i=0;i<42;i++)
	{
		for(j=0;j<42;j++)
		{
			a[i][j]='.';
		}
	}
	for(i=0;i<42;i++)
	{
		a[20][i]='-';
	}
	a[20][41]='>';
	for(j=0;j<42;j++)
	{
		a[j][20]='|';
	}
	a[0][20]='^';
	
	char f[20]={0};
	while(scanf("%s",f)!=EOF)
	{
		int k=0,t=0;
		int c3=0,c2=0,c1=0,c0=0;
		int t3=0,t2=0,t1=0,t0=0;
		int flg3=1,flg2=1,flg1=1,flg0=1;
		while(f[k]!='='){
			k++;
		}
		k++;
		t=k;
		for(k;k<strlen(f);k++)
		{
			if(f[k]=='^'&&f[k+1]=='3')
			{
				t=k-2;
				if(f[t]=='+'||f[t]=='-'||f[t]=='=')
				{
					if(f[t]=='+'||f[t]=='=')
					{
						c3=1;
					}
					if(f[t]=='-')
					{
						c3=-1;
					}	
				}
				else
				{
					int cnt3=0;
					while(f[t]!='-'&&f[t]!='=')
					{
						cnt3++;
						if(cnt3==1)
						{
							t3=f[t]-'0';
						}
						if(cnt3==2)
						{
							t3+=(f[t3]-'0')*10;
						}
						t--;	
					}
					if(f[t]=='-')
					{
						flg3=-1;
					}
					c3=t3*flg3;			
				}
			}
			
			if(f[k]=='^'&&f[k+1]=='2')
			{
				t=k-2;
				if(f[t]=='+'||f[t]=='-'||f[t]=='=')
				{
					if(f[t]=='+'||f[t]=='=')
					{
						c2=1;
					}
					if(f[t]=='-')
					{
						c2=-1;
					}
				}
				else
				{
					int cnt=0;
					while(f[t]!='+'&&f[t]!='-'&&f[t]!='=')
					{
						cnt++;
						if(cnt==1)
						{
							t2=f[t]-'0';
						}
						if(cnt==2)
						{
							t2+=(f[t]-'0')*10;
						}
						t--;	
					}
					if(f[t]=='-')
					{
						flg2=-1;
					}
					c2=t2*flg2;
				}	
			}
			
			if(f[k]=='x'&&f[k+1]!='^')
			{
				t=k-1;
				if(f[t]=='+'||f[t]=='-'||f[t]=='=')
				{
					if(f[t]=='+'||f[t]=='=')
					{
						c1=1;
					}
					if(f[t]=='-')
					{
						c1=-1;
					}
				}
				else
				{
					int cnt1=0;
					while(f[t]!='+'&&f[t]!='-'&&f[t]!='=')
					{
						cnt1++;
						if(cnt1==1)
						{
							t1=f[t]-'0';
						}
						if(cnt1==2)
						{
							t1+=(f[t]-'0')*10;
						}
						t--;	
					}
					if(f[t]=='-')
					{
						flg1=-1;
					}
					c1=t1*flg1;
				}	
			}
			
			if(f[k]>='0'&&f[k]<='9'&&f[k+1]=='\0'&&f[k-1]!='^')
			{
				t=k-1;
				if(f[t]=='+'||f[t]=='-'||f[t]=='=')
				{
					if(f[t]=='+'||f[t]=='=')
					{
						c0=f[k]-'0';
					}
					if(f[t]=='-')
					{
						c0=(f[k]-'0'); 
						c0=-c0;
					}
				}
				else
				{
					c0=(f[t]-'0')*10;
					c0+=(f[t+1]-'0');
					if(f[t-1]=='-')
					{
						c0=-c0;
					}
				}
			}
		}
		
	//	printf("c3 c2 c1 c0:%d %d %d %d\n",c3,c2,c1,c0);
		
		int x,F=0;
		int cc=0;
		for(x=-20;x<=20;x++)
		{
			F=c3*x*x*x+c2*x*x+c1*x+c0;
			if(F>=-20&&F<=20)
			{
				a[20-F][20+x]='*';
				cc++;
			}
		}
	//	printf("cc:%d\n",cc);
		for(i=0;i<41;i++)
        {
		for(int j=0;j<41;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	   }
	}
}