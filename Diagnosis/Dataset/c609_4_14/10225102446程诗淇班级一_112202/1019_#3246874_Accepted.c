#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    int A;
    int B;
    A=*(int*)a;
    B=*(int*)b;
    int m=0;
    int n=0;
    int r,t;
    r=abs(A);
    t=abs(B);
    while(r/10!=0){
        m++;
        r=r/10;

    }
    while(t/10!=0){
        n++;
        t=t/10;

    }
    if(m!=n){
        return n-m;
    }
    else{
        if(A>B){
            return 1;
        }
        else{
            return -1;
        }
    }





}

int main()
{
    int s[1000000];
    int i=0;
    while(scanf("%d",&s[i])!=EOF){
        i++;
    }
    qsort(s,i,sizeof(s[0]),cmp);
    for(int k=0;k<i;k++){
        printf("%d ",s[k]);
    }

    return 0;
}
