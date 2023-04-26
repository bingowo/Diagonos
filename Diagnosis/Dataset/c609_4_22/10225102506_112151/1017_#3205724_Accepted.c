#include <stdio.h>
#include <stdlib.h>

void Asort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
               temp=a[j+1];
               a[j+1]=a[j];
               a[j]=temp;
            }
        }
    }
}

void Dsort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
               temp=a[j+1];
               a[j+1]=a[j];
               a[j]=temp;
            }
        }
    }
}

int main()
{
    char x;
    int i=0,j;
    int num[1000];
    scanf("%c",&x);
    while(scanf("%d",&num[i])!=EOF)
        i++;
    if(x=='A')
        Asort(num,i);
    if(x=='D')
        Dsort(num,i);
    printf("%d",num[0]);
    for(j=0;j<i-1;j++){
        if(num[j]!=num[j+1])
            printf(" %d",num[j+1]);
    }
    return 0;
}
