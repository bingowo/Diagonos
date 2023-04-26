#include<stdio.h>
#define MAX 100
int main()
{
	int T,i,flag,a[MAX],cnt=0;scanf("%d\n",&T);char c;
	for(i=0;i<T;++i)
	{
		flag=1;cnt=0;
		while((c=getchar())!='\n')
		{
			if(c=='{')
			{
				if(!cnt)a[cnt++]=1;
				else if(a[cnt-1]==3)a[cnt++]=1;
				else{flag=0;break;}
			}
			else if(c=='[')
			{
				if(!cnt)a[cnt++]=2;
				else if(a[cnt-1]==1)a[cnt++]=2;
				else{flag=0;break;}
			}
			else if(c=='(')
			{
				if(!cnt)a[cnt++]=3;
				else if(a[cnt-1]==2)a[cnt++]=3;
				else{flag=0;break;}
			}
			else if(c=='}')
			{
				if(cnt&&a[cnt-1]==1)cnt--;
				else {flag=0;break;}
			}
			else if(c==']')
			{
				if(cnt&&a[cnt-1]==2)cnt--;
				else{flag=0;break;}
			}
			else if(c==')')
			{
				if(cnt&&a[cnt-1]==3)cnt--;
				else{flag=0;break;}
			}
		}
		if(flag&&!cnt)printf("YES\n");
		else
		{
			printf("NO\n");
			if(c!='\n')while((c=getchar())!='\n');
		}
	}
	return 0;
}
