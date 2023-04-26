#include <stdio.h>
typedef struct{
	int i;
	int a[500];
}BIG;
BIG trans(int x)
{
	BIG x1={0,{0}};
	do{
		x1.a[x1.i++]=x%10;
		x/=10;
	}while(x>0);
	return x1;
}
BIG add(BIG s,BIG k)
{
	int carry=0,t=0;
	int e=0;
	for(e;e<500;e++)
	{
		s.a[e]+=carry;
		t=s.a[e]+k.a[e];
		carry=t/10;
		s.a[e]=t%10;
	}
	return s;
}
int main()
{
	int n;
	scanf("%d",&n);
	BIG m[501];
	m[1]=trans(1);
	m[2]=trans(2);
	m[3]=trans(3);
	m[4]=trans(6);
	int i;
	for(i=5;i<=n;i++)
	{
		m[i]=add(add(m[i-1],m[i-2]),m[i-4]);
	}
	//printf("%d\n",m[n].a[0]);
	int r;
	for(r=499;r>=0&&m[n].a[r]==0;r--);
	for(r;r>=0;r--) printf("%d",m[n].a[r]);
	return 0;
}