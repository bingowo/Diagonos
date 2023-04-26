#include <stdio.h>
#include <stdlib.h>
 int bit(unsigned x){
 	 int k;
 	 for(k=0;x!=0;x=x&(x-1))
 	 	 k++;
	return k;
}
 int cmp(const void*a,const void*b){
 	return *(unsigned*)a-*(unsigned*)b;
 }

void Sort(unsigned *p, unsigned n){
	int i,j,k,l,t;
	unsigned m;
	qsort(p,n,sizeof(unsigned),cmp);      
	 for(j=0;j<n;j++){ k=j;
	 	for(l=j+1;l<n;l++){
	 		if(bit(p[k])<bit(p[l])||bit(p[k])==bit(p[l])&&p[k]>p[l]) k=l; 
		 }
		 if(k!=j){m=p[j];
		        p[j]=p[k];
		        p[k]=m;  }
	 }
	 }
int main()
{ unsigned n,i,a[1000];  scanf("%u",&n);
  for (i=0;i<n;i++) scanf("%u",a+i);   Sort(a,n);
  for (i=0;i<n;i++) printf("%u%c",a[i],i!=n-1?' ':'\n');
  return 0;
}