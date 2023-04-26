#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void* a,const void* b)
{  
    int ua=*(int*)a;
    int ub=*(int*)b;
    return ua<ub?-1:1;
}

void Sort(int *a,int n)
{
    qsort(a,n,sizeof(int),cmp);
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int T;
    scanf("%d",&T);
    int i,j,m,n,k,t;
    for(i=0;i<T;i++){
        int N;  
        scanf("%d",&N);
		int a[N];
        for(j=0;j<N;j++){
            scanf("%d",&a[j]);
        }
		Sort(a,N);
		int sum=0;
		int b[1000];
    	b[0]=a[0];
    	int j=1;
    	for(t=1;t<N;t++){
        	if(a[t]!=a[t-1]){
           	 	b[j]=a[t];
            	j++;
        	}
    	}
    	b[j]='\0';
//		for (k=0;k<j;k++) printf("%d%c",b[k],k!=j-1?' ':'\n');
		for(m=0;m<j-1;m++){
			for(n=m+1;n<j;n++){
				if(gcd(b[m],b[n])==1){
					sum++;
				}
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",sum);
    }  
}