#include <stdio.h>
#include <stdlib.h>


int f(int c)
{
    int x=0;
    while(c!=0){
        c=c/10;
        x++;
    }
    return x;
}


int cmp(const void*a,const void*b)
{
    int A=*(int*)a;
    int B=*(int*)b;
    if(f(A)!=f(B)){
        return f(B)-f(A);
    }else{
        return A-B;
    }
}


int main()
{
    int s[100];
    int i=0;
    while(scanf("%d",&s[i])!=EOF){
        i++;
    }
    qsort(s,i,sizeof(s[0]),cmp);
    for(int j=0;j<i;j++){
        printf("%d ",s[j]);
    }
    return 0;
}
