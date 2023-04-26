#include<stdio.h>
#include<stdlib.h>
#define N 1000001

typedef struct{
	int num;
	int numl;
}NUM;

int cmp(const void *p1,const void *p2);

int main(void)
{
    NUM *data = (NUM*)malloc(sizeof(NUM)*N);
    int i = 0;
    int temp;
    
    do{
    	scanf("%d",&data[i].num);
    	data[i].numl = 1, temp = data[i].num;
    	while(temp){
    		temp /= 10;
    		data[i].numl++;
		}
		i++;
	}while(getchar() != '\n');
	
	qsort(data,i,sizeof(NUM),cmp);
	
	for(int v = 0; v < i; v++){
		printf("%d ",data[v].num);
	}
    
    free(data);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    NUM a = *(NUM*)p1;
    NUM b = *(NUM*)p2;

    if(a.numl != b.numl) return b.numl > a.numl?1:a.numl > b.numl?-1:0;
    else return a.num > b.num?1:a.num < b.num?-1:0;
}