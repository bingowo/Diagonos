#include <stdio.h>
#include <stdlib.h>


int cmp(const void*a,const void*b)
{
    int A=*(int*)a;
    int B=*(int*)b;
    return A-B;
}

int main()
{
    int n;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    int y=0;
    for(int j=0;j<(n-1);j=j+2){
        y=y+s[j+1]-s[j];
    }
    printf("%d",y);
    return 0;
}
