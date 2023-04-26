#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 int main()
 {     int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    long long*r;
    long long*h;//*************使用同一类型数据，减少运算时数据转换造成的错误
    long long*ce;
    r=( long long*)malloc(n*sizeof( long long));
    h=( long long*)malloc(n*sizeof( long long));
    ce=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
      { scanf("%lld %lld",&r[i],&h[i]);
	        ce[i]=2*r[i]*h[i];
       }
       for(i=0;i<n;i++)//按侧面积从大到小排序 
       {  k=i;
       	for(j=k+1;j<n;j++){
       		if(ce[j]>ce[k]) k=j;
		   }
		   if(k!=i)
		   {
		   	 long long t;
		   	 t=ce[i];ce[i]=ce[k];ce[k]=t;//侧面积和r,h对应 
		   	 j=r[i];r[i]=r[k];r[k]=j;
		   	 j=h[i];h[i]=h[k];h[k]=j;
		   }
	   }
	    long long R=r[0];
	    long long C=ce[m-1];//前m个中最小的侧面积 
	   for(i=1;i<m;i++)//找前m个中最大半径 
	   { 
	    if(r[i]>R)
		 {
		   R=r[i];
		 }
	   }  
	   long long S=R*R;
	   for(i=0;i<m;i++) S+=ce[i];//先取前m个的总面积 
	   long long s1=R*R+C,s2=s1; 
	   for(i=m;i<n;i++)
	   //如果后面有r>R并且总面积大于前m个的最小侧面积加R^2，
	   //就把最小侧面积的换成半径r的 ，换掉后总面积增大 
	   {  
	   	if(r[i]>R&&(r[i]*r[i]+2*r[i]*h[i])>s1) s1=r[i]*r[i]+2*r[i]*h[i];
		} 
		S=S-s2+s1;
		printf("%lld\n",S);
       free(r);free(h);free(ce);
		return 0;
}