#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*a1,const void*a2){
    return *(int*)a1-*(int*)a2;
}
int cmp2(const void*a1,const void*a2){
    return *(int*)a2-*(int*)a1;
}
int main(){
    char a;
    int num[100];int i=0;
    scanf("%c",&a);
    if(a=='A'){
        while(scanf("%d",&num[i])!=EOF){
            i++;
        }
        qsort(num,i,sizeof(num[0]),cmp1);
    }
    else{
        while(scanf("%d",&num[i])!=EOF){
            i++;
        }
        qsort(num,i,sizeof(num[0]),cmp2);
    }
    for(int j=0;j<i-1;j++){
        if(num[j]!=num[j+1])
            printf("%d ",num[j]);
        }
        printf("%d",num[i-1]);

    return 0;
}
