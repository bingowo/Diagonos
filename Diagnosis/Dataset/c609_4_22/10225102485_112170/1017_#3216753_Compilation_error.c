#include <stdio.h>
#include <stdlib.h>
int n=0,a[100];
//升序
int compare1(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
//降序
int compare2(const void *a,const void *b){
    return *(int*)b-*(int*)a;
int main(){
    char m;//输入的A或者D
    for(int i=0;;i++){
        scanf("%d",&a[i]);
        n++;//记录输入个数
        if(getchar()=='\n')break;
    }
    if(m=='A')qsort(a,n,sizeof(int),compare1);
    if(m=='D')qsort(a,n,sizeof(int),compare2);
    int b[100];
    b[0]=a[0];
    int j=0;
    for(int i=1;i<n;i++){
        while(a[i]==b[j])i++;
        j++;
        b[j]=a[i];
    }
    for(int i=0;i<=j;i++)printf("%d ",b[i]);
    return 0;
}
