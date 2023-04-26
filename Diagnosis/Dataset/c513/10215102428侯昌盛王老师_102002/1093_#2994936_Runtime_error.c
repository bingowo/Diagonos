#include <stdio.h>
#include <string.h>
int h(int *a,int n);
int add(int *a,int n);
void m(int*a,int n)
{
	
	int i,carry=0,last9;
	for(i=0;i<n;i++)
	{
		if(a[i]>=9){
			a[i]=a[i]+1;
			carry=a[i]/10;
			a[i+1]+=carry;
			a[i]=a[i]%10;
			last9=i;
		}
	}
	if(a[n]!=0) n++;

	
	//printf("%d %d\n",a[0],a[1]);
	for(last9;last9>=0;last9--) a[last9]=0; 
	
	if(a[n]!=0) n++;
	while((add(a,n)==0)||(h(a,n)==0))
	{
		int t=0,k=0;
		a[k]++;
		//printf("%d\n",a[k]);
		while(a[k]==10)
		{
			t=a[k]/10;
			a[k+1]+=t;
			a[k]%=10;
			k++;
		}
		if(a[n]!=0) n++;

	}
}
int h(int *a,int n)
{
	int i=0;
	for(i;i<n;i++)
	{
		if(a[i]==9) return 0;
		
	}
	return 1;
}
int add(int *a,int n)
{
	int i=0,sum=0;
	for(i;i<n;i++) sum+=a[i];
	return sum%9;
}
int main()
{
	char s[101];
	scanf("%s",s);
	int a[150]={0};
	int len=strlen(s),i;
	int k0=len-1;
	for(i=0;i<len;i++) a[i]=s[k0--]-'0';
	int t=0,k=0;
	a[k]++;
	while(a[k]==10)
	{
		t=a[k]/10;
		a[k+1]+=t;
		a[k]%=10;
		k++;
	}
	if(a[len]!=0) m(a,len+1);
	else m(a,len);
	int e=149;
	for(e;a[e]==0;e--);
	for(e;e>=0;e--) printf("%d",a[e]);
	printf("\n");
	return 0;
}