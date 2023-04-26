#include<stdio.h>
int count(int n)
{
    int count=0,sign=0,a;
    if(n<0){
        n=-n-1;
        sign=1;
    }
    do{
        a=n%2;
        n/=2;
        if(a==1) count++;
    }while(n!=0);
    if(sign) return 64-count;
    return count;
}
void sort(int A[],int N)
{
    int temp,x,y;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            x=count(A[i]);
            y=count(A[j]);
            if(x<y){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    for(int i=0;i<N-1;i++){
        int j=i+1;
        while(count(A[i])==count(A[j])){
            if(A[i]>A[j]){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
            j++;
        }
    }
    for(int i=0;i<N;i++){
        printf("%d ",A[i]);
    }
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    int N[T],A[T][10000];
    for(i=0;i<T;i++){
        scanf("%d",&N[i]);
        for(j=0;j<N[i];j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<T;i++){
        printf("case #%d:\n",i);
        sort(A[i],N[i]);
        printf("\n");
    }
    return 0;
}
