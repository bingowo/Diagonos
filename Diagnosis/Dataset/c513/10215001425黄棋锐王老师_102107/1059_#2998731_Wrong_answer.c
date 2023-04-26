#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int GCD(int x,int y)
{ int r;
	r=x%y;
	if(r==0) return y;
	else GCD(y,r);
}
int main()
{  int  va[1005]={0};
   int  s;
   int i,n;
   scanf("%d %d",&n,&s);
   for(i=0;i<n;i++) scanf("%d",&va[i]);
   int min=va[0],max=va[0];
   for(i=1;i<n;i++)
   {if(va[i]>max) max=va[i];
   	if(va[i]<min) min=va[i];
   }
	int h[1002]={0};//记录各海拔高度个数 
	for(i=0;i<n;i++) h[va[i]]++;
	int in=min,zi=0,mu=0,r=0,sum=0;
	for(i=min;i<=max&&s>0;i++)
	{   if(h[i]==0) continue;
		sum+=h[i];
	    if(s>=sum) 
		{
		   in++;
		   s-=sum;
	    }
		else
	 {    zi=s;
	 	  mu=sum;
	 	  int r=GCD(zi,mu);
		  zi/=r;
		  mu/=r;
		  s=0;	
		}
	}
	if(zi==0) printf("%d",in);
	else if(in==0) printf("%d/%d",zi,mu); 
	else printf("%d+%d/%d",in,zi,mu);
	
	return 0;
	 
}

