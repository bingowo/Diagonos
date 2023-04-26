#include <stdio.h>
double time(double a,double b);



int main()
{
	double distance;
	int i;double temp;
	scanf("%lf",&distance);
	int number;
	scanf("%d",&number);
	double A[1000][2];
	double TIME[1000];
	for(i=0;i<number;i++)
	{
		scanf("%lf",&A[i][0]);
		scanf("%lf",&A[i][1]);
	}
	for(i=0;i<number;i++)
	{
		TIME[i]=time(distance-A[i][0],A[i][1]);
	}
	temp=TIME[0];
	for(i=0;i<number;i++)
	{
		if(temp<TIME[i])temp=TIME[i];
	}
	printf("%f",distance/temp);
	return 0;
 } 
 
 double time(double a,double b)
 {
 	return a/b;
 }
