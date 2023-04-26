#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//int cmp(const void*a,const void *b)
//{   return*(int*)b-*(int*)a;
//}

 int main()
 {     int n,m,i,j,k,R;
    scanf("%d %d",&n,&m);
    int*r;
    int*h;
    long long*ce;
    long long*di;
    r=(int*)malloc(n*sizeof(int));
    h=(int*)malloc(n*sizeof(int));
    ce=(long long*)malloc(n*sizeof(long long));
    di=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
      { scanf("%d %d",&r[i],&h[i]);
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
	    long long C=ce[0];
	   for(i=1;i<m;i++)//找前m个中最大r及对应侧面积 
	   { 
	    if(r[i]>R)
		 {
		   R=r[i];
		   C=ce[i];
		 }
	   }  
	   long long S=R*R;
	   for(i=0;i<m;i++) S+=ce[i];
	   long long s1=R*R+C,s2=s1; 
	   for(i=m;i<n;i++)
	   {  
	   	if(r[i]>=R&&(r[i]*r[i]+2*r[i]*h[i])>s1) s1=r[i]*r[i]+2*r[i]*h[i];
		} 
		S=S-s2+s1;
		printf("%lld\n",S);
       free(r);free(h);free(ce);free(di);
		return 0;
}