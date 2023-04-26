#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void A();
void D();
int sortA(const void * a, const void * b);
int sortD(const void * a, const void * b);
int search(int arr[],int i,int n);
int main() {
    char method;
	scanf("%c",&method);
	if(method == 'A'){
        A();
	}else{
        D();
	}
	return 0;
}
void A() {
    int arr[101];
    int i;
    int n = 0;//array number
    int *a = arr;
    char c;
	while(c != '\n'){
            scanf("%d",&i);
            scanf("%c",&c);
        if(search(arr,i,n)){
            *a = i;
            a++;
            n++;
        }
	}//input number
	qsort(arr,n,4,sortA);
	int index = 0;
    while(index < n){
    printf("%d ",arr[index]);
    index++;
    }
}
void D(){
    int arr[101];
    int i;
    int n = 0;//array number
    int *a = arr;
    char c;
	while(c != '\n'){
            scanf("%d",&i);
            scanf("%c",&c);
        if(search(arr,i,n)){
            *a = i;
            a++;
            n++;
        }
	}//input number
	qsort(arr,n,4,sortD);
	int index = 0;
    while(index < n){
    printf("%d ",arr[index]);
    index++;
    }
}

int search(int arr[],int i,int n){
    int index = 0;
    while(index < n){
        if(arr[index] == i) return 0;
        index++;
    }
    return 1;
}

int sortA(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );

}
int sortD(const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}
