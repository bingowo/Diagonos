#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct {
    char name[12];
    int solve;
    int number[100];
    int total;
} STUDENT;
long long comp(int *s1,int *s2){
    STUDENT v1=*(STUDENT*)s1;
    STUDENT v2=*(STUDENT*)s2;
    int sum1,sum2;
    sum1=v1.total;
    sum2=v2.total;
    if(sum1==sum2){
        return strcmp(v1.name,v2.name);
    }else{
        return sum2-sum1;
    }
    
}
void Sort(STUDENT *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp);
}

int main(){
    int t,n,m,g,i,j,k,p,sum;
    int b[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d",&n,&m,&g);
        STUDENT a[n];
        for(j=0;j<m;j++){
            scanf("%d",&b[j]);
        }
        for(p=0;p<n;p++){
            sum=0;
            scanf("%s %d",a[i].name,&a[i].solve);
            for(k=0;k<(a[i].solve);k++){
                scanf("%d",&a[i].number[k]);
                sum+=b[a[i].number[k]-1];
            }
            a[i].total=sum;
            printf("%d\n",a[i].total);
        }
       
    }
    return 0;
    
}