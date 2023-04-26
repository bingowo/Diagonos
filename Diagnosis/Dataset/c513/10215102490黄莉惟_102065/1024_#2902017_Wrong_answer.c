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
    int t,n,m,g,i,j,k,p,sum,r,num;
    int b[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        num=0;
        scanf("%d %d %d",&n,&m,&g);
        STUDENT a[n];
        for(j=0;j<m;j++){
            scanf("%d",&b[j]);
        }
        for(p=0;p<n;p++){
            sum=0;
            scanf("%s %d",a[p].name,&a[p].solve);
            for(k=0;k<(a[p].solve);k++){
                scanf("%d",&a[p].number[k]);
                sum+=b[a[p].number[k]-1];
            }
            a[p].total=sum;
        }
        printf("case #%d:\n", i);
        Sort(a,n);
        for(r=0;r<n;r++){
            if((a[r].total)>=g){
                num++;
            }
        }
        printf("%d",num);
        for(r=0;r<n;r++){
            if((a[r].total)>=g){
                printf("%s %d\n",a[r].name,a[r].total);
            }
        }
       
    }
    return 0;
    
}