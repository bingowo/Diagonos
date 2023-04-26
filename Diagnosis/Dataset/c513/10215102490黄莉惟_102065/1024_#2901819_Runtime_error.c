#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct {
    char name[12];
    int solve;
    int number[100];
} STUDENT;
int main(){
    int t,n,m,g,i,j,k;
    int b[1000];
    scanf("%d",&t);
    STUDENT a[n];
    for(i=0;i<t;i++){
        scanf("%d %d %d",&n,&m,&g);
        for(j=0;j<m;j++){
            scanf("%d",&b[j]);
        }
        for(j=0;j<n;j++){
            scanf("%s %d",a[i].name,a[i].solve);
            for(k=0;k<(a[i].solve);k++){
                scanf("%d",a[i].number[k]);
            }
        }
    }
    
}