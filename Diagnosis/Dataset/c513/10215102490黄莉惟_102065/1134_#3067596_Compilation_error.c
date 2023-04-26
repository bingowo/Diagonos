#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct {
    char name[120];
    int number[100];
    double ave[100];
} STUDENT;
int comp1(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->number[0] != pb->number[0]){
		return pb->number[0] - pa->number[0];
	}else{
		return strcmp(pa->name, pb->name);
	}
}
int comp2(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->number[1] != pb->number[1]){
		return pb->number[1] - pa->number[1];
	}else{
		return strcmp(pa->name, pb->name);
	}
}
int comp3(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->number[2] != pb->number[2]){
		return pb->number[2] - pa->number[2];
	}else{
		return strcmp(pa->name, pb->name);
	}
}
int comp4(const void *a, const void *b)
{
	STUDENT * pa = (STUDENT *)a;
	STUDENT * pb = (STUDENT *)b;
	if(pa->ave != pb->ave){
		return pb->ave - pa->ave;
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
void Sort4(STUDENT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp4);
}
int main(){
    int T,i,n,k,p;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n);
        STUDENT a[n];
        for(p=0;p<n;p++){
            scanf("%s %d %d %d",a[p].name,&a[p].number[0],&a[p].number[1],&a[p].number[2]);
            a[p].ave=int((a[p].number[0]+a[p].number[1]+a[p].number[2])/3+0.5);
        }
        printf("case #%d:\n", i);
        Sort4(a,n);
        printf("A:");
        printf("\n");
        printf("%s\n",a[0].name);
        for(int r=1;r<n;r++){
            if((a[r].ave)==a[r-1].ave){
                printf("%s\n",a[r].name);
            }
        }
        Sort1(a,n);
        printf("C:");
        printf("\n");
        printf("%s\n",a[0].name);
        for(int r=1;r<n;r++){
            if((a[r].number[0])==a[r-1].number[0]){
                printf("%s\n",a[r].name);
            }
        }
        Sort2(a,n);
        printf("M:");
        printf("\n");
        printf("%s\n",a[0].name);
        for(int r=1;r<n;r++){
            if((a[r].number[1])==a[r-1].number[1]){
                printf("%s\n",a[r].name);
            }
        }
        Sort3(a,n);
        printf("E:");
        printf("\n");
        printf("%s\n",a[0].name);
        for(int r=1;r<n;r++){
            if((a[r].number[2])==a[r-1].number[2]){
                printf("%s\n",a[r].name);
            }
        }
    }
}