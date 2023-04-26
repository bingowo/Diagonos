#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int *)a>*(int *)b?1:-1);
}
typedef struct NUM{
    int x;
}num;
int main()
{
    int n,i,sum=0; //n表示点的个数
    scanf("%d",&n);
    num m[n];
    for(i=0;i<n;i++){
        scanf("%d",&m[i].x);
    }
    qsort(m,n,sizeof(m[0]),cmp);
    for(i=0;i<n-1;i=i+2){
        sum = sum+abs(m[i].x-m[i+1].x);
    }
    printf("%d",sum);
    return 0;
}
