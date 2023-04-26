#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct {
    char name[120];
    int solve;
    int number[100];
    int total;
} STUDENT;
int comp(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->total != pb->total){
		return pb->total - pa->total;
	}else{
		return strcmp(pa->name, pb->name);
	}
}
void Sort(STUDENT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp);
}

int main(){
    int t,n,m,g,i,j,k,p,sum,r;
    int b[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d",&n,&m,&g);
        STUDENT a[n];
        for(j=0;j<m;j++){
            scanf("%d",&b[j]);
        }
        for(p=0;p<n;p++){
            sum=0;
            scanf("%s %d",a[i].name,&a[i].solve);
            for(k=0;k<(a[i].solve);k++){
                scanf("%d",&a[i].number[k]);
                sum+=b[a[i].number[k]-1];
            }
            a[i].total=sum;
           printf("%d\n",a[i].total);
        }
        Sort(a,n);
        for(r=0;r<n;r++){
            printf("%d\n",a[r].total);
        }
       
    }
    return 0;
    
}