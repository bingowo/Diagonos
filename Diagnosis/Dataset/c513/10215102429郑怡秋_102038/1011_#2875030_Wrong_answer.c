#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
	getchar();
	getchar(); 
	char A[100];
	int B[500];
	scanf("%s",A);
	int j=0,l=strlen(A);
	int k=0;
	while(j<l)
	{
		int x;
		if(isdigit(A[j])) x=A[j]-'0';
		else x=A[j]-'A'+10;
		int m=4;
		for(int q=0;q<m;q++,k++)
		{
			B[k]=(x>>(m-q-1))&1;
		}
		j++;
	}
	long long a=0,b=0,aa;
	int i=0,r;
	while(i<k)
	{
		r=B[i];
		aa=a;
		a=r-aa-b;
		b=aa-b;
		i++;
	}
	if(a==0) printf("%lldi",b);
	else if(b==0) printf("%lld",a);
	else if(b==1) printf("%lld+i",a);
	else if(a>0&&b>0 ||(a<0&&b>0)) printf("%lld+%lldi",a,b);
	else if(a<0&&b<0 ||(a>0&&b<0)) printf("%lld%lldi",a,b);
	
	return 0;
}