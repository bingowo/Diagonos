#include<stdio.h>
#include<stdlib.h>
int cmpA(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int cmpD(const void *a,const void *b){
    return (*(int *)b-*(int *)a);
}

int main(){
    char alpha;
    scanf("%c",&alpha);
    int num[100];
    int k=0;
    while(scanf("%d",&num[k])!=EOF){
        k++;
    }
    if(k==1)
        printf("%d",num[0]);
    else if(alpha=='A'){
        qsort(num,k,sizeof(num[0]),cmpA);
        printf("%d ",num[0]);
        for(int i=1;i<k;i++){
            if(num[i]!=num[i-1]&&i!=k-1)
                printf("%d ",num[i]);
            if(num[i]!=num[i-1]&&i==k-1)
                printf("%d",num[k-1]);
        }
    }
    else if(alpha=='D'){
        qsort(num,k,sizeof(num[0]),cmpD);
        printf("%d ",num[0]);
        for(int i=1;i<k;i++){
            if(num[i]!=num[i-1]&&i!=k-1)
                printf("%d ",num[i]);
            if(num[i]!=num[i-1]&&i==k-1)
                printf("%d",num[k-1]);
        }
    }
    return 0;
}
