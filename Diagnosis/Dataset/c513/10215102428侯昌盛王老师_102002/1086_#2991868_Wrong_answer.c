#include <stdio.h>
#include <string.h>
#define N 500
void input(int *a,char *s)
{
	scanf("%s",s);
	int i,len=strlen(s),n,j;
	for(i=0;s[i]!='.'&&i<len;i++);
	for(n=N,j=i-1;j>=0;n--,j--) a[n]=s[j]-'0';
	for(n=N+1,j=i+1;j<len;n++,j++) a[n]=s[j]-'0';
}
void m(int *a,int *b,int d)
{
	int i,carry=0;
	for(i=2*N;i>N+d;i--)
	{
		a[i]-=carry;
		if(a[i]<b[i])
		{
			a[i]+=10;
			carry=1;
			b[i]=a[i]-b[i];
		}
		else{
			b[i]=a[i]-b[i];carry=0;
		}
	}
	if(b[i+1]>=5) b[i]--;
	//printf("%d\n",b[i+1]);
	for(i=N+d;i>=0;i--)
	{
		a[i]-=carry;
		if(a[i]<b[i])
		{
			a[i]+=10;
			carry=1;
			b[i]=a[i]-b[i];
		}
		else{
			b[i]=a[i]-b[i];carry=0;
		}
	}

}
int main()
{
	char sa[2*N+1],sb[2*N+1];
	int a[2*N+1]={0},b[2*N+1]={0};
	input(a,sa);input(b,sb);
	int d;
	scanf("%d",&d);
	if(strcmp(sa,sb)>=0)
	{
		m(a,b,d);
		int k;
		for(k=0;b[k]==0&&k<=N;k++);
		if(k==N+1) printf("0");
		for(k;k<=N;k++) printf("%d",b[k]);
		printf(".");
		for(k;k<=N+d;k++) printf("%d",b[k]);
	}
	else
	{
		m(b,a,d);
		printf("-");
		int k;
		for(k=0;a[k]==0&&k<=N;k++);
		if(k==N+1) printf("0");
		for(k;k<=N;k++) printf("%d",a[k]);
		printf(".");
		for(k;k<=N+d;k++) printf("%d",a[k]);
	}
	
	//printf("%d\n",b[d+N]);
	
	
	printf("\n");
	return 0;
	
}