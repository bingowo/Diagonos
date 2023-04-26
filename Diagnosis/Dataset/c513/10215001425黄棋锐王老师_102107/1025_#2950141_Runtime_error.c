#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
	int yi(char*s)
	{ 
		int n=0,i=0;
		int c[120]={0};
		int l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(c[s[i]]==0) 
			{
				c[s[i]]=1;
				n++;
			}
		}
		return n;
	}
 int cmp(const void*a,const void*b)
 	{   char*aa=*(char**)a;
 		char*bb=*(char**)b;
 		if(yi(aa)!=yi(bb)) return yi(bb)-yi(aa);
 		else return strcmp(aa,bb);
 	}
 	
 int main()
 {
 	 int k,T;
 	 scanf("%d",&T);
 	 for(k=0;k<T;k++)
	  {   char**p;
	       int n=0;
	       scanf("%d",&n);
	       p=(char**) malloc(n*sizeof(char*));
	       int i;
	       char s[22];
	       char *q;
	       for(i=0;i<n;i++){
	       		scanf("%s",s);
	       		strcpy(q,s);
	       		p[i]=q;
		   }
		   qsort(p,n,sizeof(char*),cmp);
 	 			printf("case #%d:\n",k);
 	 			for(i=0;i<n;i++)
				  {
 	 				printf("%s\n",p[i]);	
				  }
				  for(i=0;i<n;i++) free(p[i]);
				  free(p);
	  }
		return 0;
}