#include <stdio.h>
#include<math.h>
  long long poww (int x,int y){
  	long long res=1;
  	for(int i=0;i<y;i++){
  		res=res*x;
	  }
  	return res;
  }
int main()
{int T;
scanf("%d",&T);
for(int v=0;v<T;v++){
	int i,a,b,n;
	long long int last = 1;
	scanf("%d %d %d",&a,&b,&n);
	printf("case #%d:\n",v);
	for( i=1;i<b+1;i++ )
	{
		last = last*a % poww(10,n);
	}
	if(last==0) {
	for(int k=0;k<n;k++) printf("0");
	printf("\n");}
	else printf("%d\n",last);}
    return 0;
}