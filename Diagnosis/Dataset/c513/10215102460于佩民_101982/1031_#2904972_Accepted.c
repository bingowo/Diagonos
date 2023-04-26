#include <stdio.h>
#include <stdlib.h>

int cmp1(const void*a,const void*b){
    int m,n;
    m=*(int *)a;
    n=*(int *)b;
    return m-n;
}

int cmp2(const void*a,const void*b){
    int m,n;
    m=*(int *)a;
    n=*(int *)b;
    return n-m;
}
int main(){
    long long int sum=0;
    int Num,num,now=0,i;
    int s1[1001],s2[1001];
    scanf("%d",&Num);
    while(now<Num){
        scanf("%d",&num);
        for(i=0;i<num;i++){
            scanf("%d",&s1[i]);
        }
        for(i=0;i<num;i++){
            scanf("%d",&s2[i]);
        }
        qsort(s1, num, sizeof(int), cmp1);
        qsort(s2, num, sizeof(int), cmp2);
        for(i=0;i<num;i++){
            sum+=(s1[i]*s2[i]);
        }
        printf("case #");
        printf("%d:\n",now);
        printf("%lld\n",sum);
        now++;
        sum=0;
    }
    return 0;
}