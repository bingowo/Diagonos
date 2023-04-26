#include<stdio.h>
#include<stdlib.h>

int cmp1(const void *a,const void *b){
    int c=*(int *)a,d=*(int *)b;
    return c-d;
}

int cmp2(const void *a,const void *b){
    int c=*(int *)a,d=*(int *)b;
    return d-c;
}

int main(){
    int t,a=0;
    scanf("%d",&n);
    while(a<t){
        int n,ans=0;
        scanf("%d",&n);
        int l1[n],l2[n];
        for(int i=0;i<n;i++)scanf("%d",&l1[i]);
        for(int i=0;i<n;i++)scanf("%d",&l2[i]);
        qsort(l1,n,sizeof(int),cmp1);
        qsort(l2,n,sizeof(int),cmp2);
        for(int i=0;i<n;i++)ans+=(l1[i]*l2[i]);
        printf("case #%d:\n%d\n",a,ans);
        a++;
    }
}