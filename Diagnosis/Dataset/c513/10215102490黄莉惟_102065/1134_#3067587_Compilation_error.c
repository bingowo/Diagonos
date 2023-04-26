#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct {
    char name[120];
    int number[100];
} STUDENT;
int comp1(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->number[1] != pb->number[1]){
		return pb->number[1] - pa->number[1];
	}else{
		return strcmp(pa->name, pb->name);
	}
}
int comp2(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->number[2] != pb->number[2]){
		return pb->number[2] - pa->number[2];
	}else{
		return strcmp(pa->name, pb->name);
	}
}
int comp3(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->number[3] != pb->number[3]){
		return pb->number[3] - pa->number[3];
	}else{
		return strcmp(pa->name, pb->name);
	}
}
void Sort1(STUDENT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp1);
}
void Sort2(STUDENT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp2);
}
void Sort3(STUDENT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp3);
}
int main(){
    int T,i,n,k;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n);
        STUDENT a[n];
        for(k=0;k<n;k++){
            scanf("%s %d %d %d",a[p].name,&a[p].number[1],&a[p].number[2],&a[p].number[3]);
        }
        printf("case #%d:\n", i);
        Sort1(a,n);
        printf("A:");
        printf("\n");
        printf("%s\n",a[0].name);
        for(int r=1;r<n;r++){
            if((a[r].number[1])==a[r-1].number[1]){
                printf("%s\n",a[r].name);
            }
        }
        Sort2(a,n);
        printf("C:");
        printf("\n");
        printf("%s\n",a[0].name);
        for(int r=1;r<n;r++){
            if((a[r].number[2])==a[r-1].number[2]){
                printf("%s\n",a[r].name);
            }
        }
        Sort3(a,n);
        printf("M:");
        printf("\n");
        printf("%s\n",a[0].name);
        for(int r=1;r<n;r++){
            if((a[r].number[3])==a[r-1].number[3]){
                printf("%s\n",a[r].name);
            }
        }
    }
}