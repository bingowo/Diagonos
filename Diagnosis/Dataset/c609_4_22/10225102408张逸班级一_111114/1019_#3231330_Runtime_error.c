#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*a1,const void* a2){
    int num1=0,num2=0;int p1=*(int*)a1,p2=*(int*)a2;
    while(p1){
        p1/=10;
        num1++;
    }    
    while(p2){
        p2/=10;
        num2++;
    }
    if(num1!=num2){
        return num2-num1;
    }
    else return *(int*)a1-*(int*)a2;
}
int main(){
    int i[100000];
    int j=0;
    while(scanf("%d",&i[j])!=EOF){
        j++;
    }
    qsort(i,j+1,sizeof(i[0]),cmp);
    for(int k=0;k<j;k++){
        printf("%d ",i[k]);
    }
    return 0;
}