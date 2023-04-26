#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void f1(int n,int *ka,int *ky)
{  int i,j,k1a=1,k2a=0,k1y=1,k2y=1,ta,ty,sa=2,sy=0;//k1-上车的系数，k2-下车的系数 
    if(n==1||n==2)*ka=1,*ky=0;
    else if(n==3) *ka=2,*ky=0;
    else if (n>3)
   {  for(i=4;i<=n;i++)
   		{  sa+=k2a;
   		   sy+=k2y;
		   ta=k1a;
		    ty=k1y;
		   k1a=k1a+k2a;
		   k1y=k1y+k2y;
   			k2a=ta;
			k2y=ty;   	
		}     
   	    *ka=sa;*ky=sy;
   }
}
int main()
{    int a,n,m,x,y,ant;//y-第二站上下人数 
	int ka=0,ky=0;
	scanf("%d %d %d %d",&a,&n,&m,&x);
	 f1(n-1,&ka,&ky);//系数只算到倒数第二站 
	y=(m-ka*a)/ky;
	 f1(x,&ka,&ky);
	ant=ka*a+ky*y;
	printf("%d",ant);
	return 0;
}
 
