#include<stdio.h>
int time;
int turn(int n)
{
	int rn=0,d=0;
    while(n)
    {
        rn=rn*10+d;
        d=n%10;
        n/=10;
    }
    return rn;
}
int func(int n)
{
    if(n!=turn(n))
	{
		time++;
		return func(n+turn(n));

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