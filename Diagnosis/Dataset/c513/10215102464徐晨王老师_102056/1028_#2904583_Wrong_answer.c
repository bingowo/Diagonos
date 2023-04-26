#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* a,const void* b){
    int x=*(int*)a;
    int y=*(int*)b;
    return x>y;
}

int cmpD(const void* a,const void* b){
    int x=*(int*)a;
    int y=*(int*)b;
    return x<y;
}

int main(){
    char ch;
    scanf("%c",&ch);
    int data[100];
    int i=0;
    while(scanf("%d",&data[i])!=EOF){
        i=i+1;
    }
    if(ch=='A')qsort(data,i+1,sizeof(data[0]),cmpA);
    if(ch=='D')qsort(data,i+1,sizeof(data[0]),cmpD);
    //printf("%d ",data[0]);
    for(int j=1;j<i;j++){
        if(data[j]!=data[j-1])printf("%d ",data[j]);
    }
    //if(data[i]!=data[i-1])printf("%d",data[i]);
    return 0;
}