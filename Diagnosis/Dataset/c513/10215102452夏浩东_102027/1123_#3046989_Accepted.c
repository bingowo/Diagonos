#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct DNA {
    char L[21];
    int number;
};
int cmp1(const void *a,const void *b){
	struct DNA* A = (struct DNA*)a;
	struct DNA* B = (struct DNA*)b;
	return strcmp(A->L,B->L);
}
int cmp2(const void *a,const void *b){
	struct DNA* A = (struct DNA*)a;
	struct DNA* B = (struct DNA*)b;
	if(A->number != B->number) return A->number>B->number? 1:-1;
	else return strcmp(A->L,B->L);
} 
int main()
{
    int num=0;
    scanf("%d",&num);
    struct DNA* dna = (struct DNA*) malloc (num*sizeof(struct DNA)); 
    for(int j=0;j<num;j++)
    {
        scanf("%s",dna[j].L);
        dna[j].number=1;
    }
    qsort(dna,num,sizeof(struct DNA),cmp1);
    
    int len=0;
    struct DNA* dna2 = (struct DNA*) malloc (num*sizeof(struct DNA));
    strcpy(dna2[len].L,dna[0].L);
    dna2[len].number=1;
    for(int i=1;i<num;i++)
    {
    	if(strcmp(dna[i].L,dna[i-1].L)==0){
    		dna2[len].number++;
		} else {
			len++;
			strcpy(dna2[len].L,dna[i].L);
    		dna2[len].number=1;
		}
	}
    qsort(dna2,len+1,sizeof(struct DNA),cmp2);
    for(int i=0;i<=len;i++){
    	printf("%s\n",dna2[i].L);
	}
    return 0;
}