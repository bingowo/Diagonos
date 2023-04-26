#include <stdio.h>
#include <string.h>
#define N 502
void input(int *a,char *s)
{
	scanf("%s",s);
	int len=strlen(s)-1,i,j=0;
	for(i=len;i>=0;i--) a[j++]=s[i]-'0';
}
void m(int *a,int *b,int pa)
{
	int i=0,t=0;
	while(i<=pa)
	{
		a[i]-=t;
		if(a[i]<b[i])
		{
			a[i]+=10;
			t=1;
		}
		else t=0;
		b[i]=a[i]-b[i];
		i++;
		
	}
}
int main()
{
	while(1)
	{
		int a[N]={0},b[N]={0},t=1,k;
		char sa[N+1],sb[N+1];
		input(a,sa);input(b,sb);
		if(strcmp(sa,sb)>0)
		{
			k=strlen(sa)-1;
			m(a,b,k);
			for(k;b[k]==0;k--);
		}
		else if(strcmp(sa,sb)<0){
			k=strlen(sb)-1;t=-1;
			m(b,a,k);
			for(k;a[k]==0;k--);
		}
		else{
			printf("0\n");
			continue;
		}
		
		
		//for(k;k>=0;k--) printf("%d",a[k]);
		if(t==-1){
			printf("-");
			for(k;k>=0;k--) printf("%d",a[k]);
		}
		else for(k;k>=0;k--) printf("%d",b[k]);
		printf("\n");
	}
	return 0;
}