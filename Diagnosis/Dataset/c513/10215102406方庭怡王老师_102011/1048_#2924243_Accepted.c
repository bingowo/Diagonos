#include<stdio.h>
#include<string.h>

#define INPUTMAX 120
#define NMAX 51
#define MAXTIME 101
int main(void)
{
	char input_1[INPUTMAX],input_2[INPUTMAX];
	while((scanf("%s %s",input_1,input_2))!=EOF)
	{
		int time[MAXTIME]={0},
		n1[NMAX]={0},
		n2[NMAX]={0},
		i,coe,exp,pro,sig;
		int length_n1=strlen(input_1),length_n2=strlen(input_2);
		for(i=0,coe=0,pro=0,sig=1,exp=1;i<length_n1;i++)
		{
			if(input_1[i]=='x' && pro!=0)
			{
				n1[0]=0;
				n1[1]=coe;
				pro=1;
			}
			else if(input_1[i]=='x' &&pro==0)
			{
				if(input_1[i+1]=='^')
				{
					coe=1*sig;
					pro=1;
				}
				else
				{
					coe=1*sig;
					n1[1]=coe;
					pro=1;	
				}
			}
			else if(input_1[i]=='^')
				continue;
			else if(pro!=1 && input_1[i]=='+')
			{
				sig=1;
			}
			else if(pro==1 && input_1[i]=='+')
			{
				pro=0;
				sig=1;
			}
			else if(pro!=1 && input_1[i]=='-')
			{
				sig=-1;
			}
			else if(pro==1 &&input_1[i]=='-')
			{
				pro=0;
				sig=-1;
			}
			else if(pro==1)
			{
				exp=0;
				while(input_1[i]>='0' && input_1[i]<='9')
				{
					exp+=input_1[i]-'0';
					if(input_1[i+1]>='0' && input_1[i+1]<='9')
					{
						exp*=10;
						i++;
					}
					else 
						break;
				}
				n1[exp]=coe;
				n1[1]=0;
				n1[0]=0;
			}
			else if(pro==0)
			{
				coe=0;
				while(input_1[i]>='0'&&input_1[i]<='9')
				{
					coe+=input_1[i] - '0';
					if(input_1[i+1] >= '0' && input_1[i+1]<='9')
					{
						coe*=10;
						i++;
					}
					else
						break;
				}
				coe*=sig;
				n1[0]=coe;
				pro=2;
			}
		}
		for(i=0,coe=0,pro=0,sig=1,exp=1;i<length_n2;i++)
		{
			if(input_2[i]=='x' && pro!=0)
			{
				n2[0]=0;
				n2[1]=coe;
				pro=1;
			}
			else if(input_2[i]=='x' &&pro==0)
			{
				if(input_2[i+1]=='^')
				{
					coe=1*sig;
					pro=1;
				}
				else
				{
					coe=1*sig;
					n2[1]=coe;
					pro=1;	
				}
			}
			else if(input_2[i]=='^')
				continue;
			else if(pro!=1 && input_2[i]=='+')
			{
				sig=1;
			}
			else if(pro==1 && input_2[i]=='+')
			{
				pro=0;
				sig=1;
			}
			else if(pro!=1 && input_2[i]=='-')
			{
				sig=-1;
			}
			else if(pro==1 &&input_2[i]=='-')
			{
				pro=0;
				sig=-1;
			}
			else if(pro==1)
			{
				exp=0;
				while(input_2[i]>='0' && input_2[i]<='9')
				{
					exp+=input_2[i]-'0';
					if(input_2[i+1]>='0' && input_2[i+1]<='9')
					{
						exp*=10;
						i++;
					}
					else 
						break;
				}
				n2[exp]=coe;
				n2[1]=0;
				n2[0]=0;
			}
			else if(pro==0)
			{
				coe=0;
				while(input_2[i]>='0'&&input_2[i]<='9')
				{
					coe+=input_2[i] - '0';
					if(input_2[i+1] >= '0' && input_2[i+1]<='9')
					{
						coe*=10;
						i++;
					}
					else
						break;
				}
				coe*=sig;
				n2[0]=coe;
				pro=2;
			}
		}
		int ans[MAXTIME],cnt=0;
		for(int i=0;i<NMAX;i++)
		{
			for(int j=0;j<NMAX;j++)
			{
				time[i+j]+=n1[i]*n2[j];
			}
		}
		for(int i=100;i>=0;i--)
		{
			if(time[i])
			{
				ans[cnt++]=time[i];
				
			}
		}
		for(int i=0;i<cnt-1;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[cnt-1]);
	}
	return 0;
}