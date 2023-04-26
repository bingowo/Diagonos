#include<stdio.h>
#include<string.h>
int main()
{
	char question[500];
	scanf("%s",&question);
	int l=strlen(question);
	char answer[10];
	if(l%3==0)
	{
		int n=l/3;
		char s[n][10];
		int x=0;
		for(int i=0;i<n;i++)
		{
			int x=(question[3*i]-'0')*100+(question[3*i+1]-'0')*10+(question[3*i+2]-'0');
			int t=9;
    		while(x>0)
    		{
        		s[i][t]=x%2+'0';
        		x=x/2;
        		t--;
    		}
    		for(int k=0;k<t+1;k++)
    		{
    			s[i][k]='0';
			}
		}
		int t1=9;
		while(l>0)
		{
			answer[t1]=l%2+'0';
			l=l/2;
			t1--;
		}
		for(int q=0;q<t1+1;q++)
		{
			answer[q]='0';
		}
		printf("0001");
		for(int k=0;k<10;k++)
		{
			printf("%c",answer[k]);
		}
		for(int j=0;j<n;j++)
		{
			printf("%s",s[j]);
		}
	}
	else if(l%3==1)
	{
		int n=(l-1)/3;
		char s[n][10];
		int x=0;
		for(int i=0;i<n;i++)
		{
			int x=(question[3*i]-'0')*100+(question[3*i+1]-'0')*10+(question[3*i+2]-'0');
			int t=9;
    		while(x>0)
    		{
        		s[i][t]=x%2+'0';
        		x=x/2;
        		t--;
    		}
    		for(int k=0;k<t+1;k++)
    		{
    			s[i][k]='0';
			}
		}
		char s1[4];
		int n1=question[l-1]-'0';
		int t2=3;
		while(n1>0)
		{
			s1[t2]=n1%2+'0';
			n1=n1/2;
			t2--;
		}
		for(int j=0;j<t2+1;j++)
		{
			s1[j]='0';
		}
		int t1=9;
		while(l>0)
		{
			answer[t1]=l%2+'0';
			l=l/2;
			t1--;
		}
		for(int q=0;q<t1+1;q++)
		{
			answer[q]='0';
		}
		printf("0001");
		for(int q=0;q<8;q++)
		{
			printf("%c",answer[q]);
		}
		for(int q1=0;q1<n;q1++)
		{
			printf("%s",s[q1]);
		}
		for(int q2=0;q2<4;q2++)
		{
			printf("%c",s1[q2]);
		}
	}
	else
	{
		int n=(l-2)/3;
		char s[n][10];
		int x=0;
		for(int i=0;i<n;i++)
		{
			int x=(question[3*i]-'0')*100+(question[3*i+1]-'0')*10+(question[3*i+2]-'0');
			int t=9;
    		while(x>0)
    		{
        		s[i][t]=x%2+'0';
        		x=x/2;
        		t--;
    		}
    		for(int k=0;k<t+1;k++)
    		{
    			s[i][k]='0';
			}
		}
		char s1[7];
		int y=(question[l-2]-'0')*10+(question[l-1]-'0');
		int t2=6;
		while(y>0)
		{
			s1[t2]=y%2+'0';
			y=y/2;
			t2--;
		}
		for(int q=0;q<t2+1;q++)
		{
			s1[q]='0';
		}
		int t1=9;
		while(l>0)
		{
			answer[t1]=l%2+'0';
			l=l/2;
			t1--;
		}
		for(int q=0;q<t1+1;q++)
		{
			answer[q]='0';
		}
		printf("0001");
		printf("%s",answer);
		for(int q1=0;q1<n;q1++)
		{
			printf("%s",s[q1]);
		}
		for(int q2=0;q2<7;q2++)
		{
			printf("%c",s1[q2]);
		}
	}
	return 0;
}