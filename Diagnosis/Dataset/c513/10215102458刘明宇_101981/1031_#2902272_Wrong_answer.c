#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp1(const void *a,const void *b){
    int *p1,*p2;
    p1 = (int *)a;
    p2 = (int *)b;
    return *p1 - *p2;
}

int cmp2(const void *a,const void *b){
    int *p1,*p2;
    p1 = (int *)a;
    p2 = (int *)b;
    return *p2 - *p1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        int n;
        scanf("%d",&n);
        int s1[1001],s2[1001];
        for(int i=0;i<n;i++){
            scanf("%d",&s1[i]);
        }
        for(int j=0;j<n;j++){
            scanf("%d",&s2[j]);
        }
        qsort(s1,n,sizeof(s1[0]),cmp1);
        qsort(s2,n,sizeof(s2[0]),cmp2);
        //for(int i =0;i<n;i++){
        //    printf("%d ",s1[i]);
        //}
        //printf("\n");
        //for(int i = 0;i < n;i++){
        //    printf("%d ",s2[i]);
        //}
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += s1[i] * s2[i];
        }
        printf("case #%d:\n",cnt);
        printf("%d",sum);
        cnt++;
    }
}