#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
    char ele[25];	
} DNA;

typedef struct {
    char name[25];
    int num;
} DA;
int cmp1(const void* a,const void* b)
{  
    DNA * pa = (DNA *)a;
	DNA * pb = (DNA *)b;
	return strcmp(pa->ele, pb->ele);
}


int cmp2(const void *a, const void *b)
{
	DA * pa = (DA *)a;
	DA * pb = (DA *)b;
	if(pa->num != pb->num){
		return pa->num - pb->num;
	}else{
		return strcmp(pa->name, pb->name);
	}
}

int main(){
    int n,i;
    scanf("%d",&n);
	DNA s[n];
    for(i=0;i<n;i++){      
        scanf("%s",s[i].ele);
    }
    qsort(s,n,sizeof(s[0]),cmp1);
	strcpy(a[0].name,s[0].ele);
	a[0].num=1;
	i=1;
	 for(i=1;i<n;i++){
    	if(strcmp(s[i].ele,s[i-1].ele)!=0){
    		strcpy(a[k].name,s[i].ele);
    		a[k].num=1;
    		k++;
		}else{	
    		a[k-1].num++;
		}		
	}
	qsort(a,k,sizeof(a[0]),cmp2);
	for(i=0;i<k;i++){
        printf("%s\n",a[i].name);
    }
    return 0;
}