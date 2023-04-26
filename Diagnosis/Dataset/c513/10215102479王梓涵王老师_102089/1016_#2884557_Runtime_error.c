#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int N,R;
	scanf("%d %d",&N,&R);
	char res[100]={'\0'};
	if (N==0) printf("0");
	int i=0;
	while(N!=0)
	{
		int tmp=N%R;
		N=N/R;
		if(tmp<0)
		{
			tmp-=R;
			N++;
		}
		if(abs(tmp)>=0 && abs(tmp)<=9) res[i]=abs(tmp)+'0';
		else res[i]=abs(tmp)-10+'A';
		i++;
	}
	for(i=strlen(res)-1;1>=0;i++)
	{
		printf("%c",res[i]);
	}
}