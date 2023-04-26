#include<stdio.h>
int time;
int Turn(int n)
{
	int rn=0,d=0;
    while(n)
    {
        d=n%10;
		rn=rn*10+d;
        n=n/10;
    }
    return rn;
}
int func(int n)
{
    if(n!=Turn(n))
	{
		time++;
		return func(n+Turn(n));
	}
    return n;
}
int main()
{
    int n;
    scanf("%d",&n);
	time=0;
    int ans=func(n);
	printf("%d %d",time,ans);
    return 0;
}