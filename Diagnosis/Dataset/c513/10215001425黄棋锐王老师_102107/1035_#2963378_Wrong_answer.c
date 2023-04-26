#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 int main()
 {     int n,m,i,j,k,R;
    scanf("%d %d\n",&n,&m);
    int*r;
    int*h;
    long long*ce;
    long long*di;
    r=(int*)malloc(n*sizeof(int));
    h=(int*)malloc(n*sizeof(int));
    ce=(long long*)malloc(n*sizeof(long long));
    di=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
      { scanf("%d %d\n",&r[i],&h[i]);
	        ce[i]=2*r[i]*h[i];
	        di[i]=r[i]*r[i];
       }
       for(i=0;i<n;i++)//按侧面积从大到小排序 
       {  k=i;
       	for(j=k;j<n;j++){
       		if(ce[j]>ce[k]) k=j;
		   }
		   if(k!=i)
		   {
		   	 long long t;
		   	 t=ce[i];ce[i]=ce[k];ce[k]=t;//侧面积和r对应 
		   	 j=r[i];r[i]=r[k];r[k]=j;
		   }
	   }
	    R=r[0];
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
       free(r);free(h);free(ce);free(di);
		return 0;
}