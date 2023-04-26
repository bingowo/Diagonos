#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0){
	    double a=n*log10(n);
	    int b=(int)a;
	    a-=b;
	    int ans=(int)pow(10.0,a);
	    printf("%d\n",ans);
	    scanf("%d",&n);
	}
}