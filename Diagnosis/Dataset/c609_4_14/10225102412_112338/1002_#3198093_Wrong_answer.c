#include<stdio.h>
int main()
{
    int T,n;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d",&n);
        printf("case #%d:\n%d\n",i,casecase(n));
    }
    return 0;
}

int casecase(int n)
{
    int len=1;int a[100];int i=0;
    while(n>0){
        a[i] = n%2;
        n = n/2;
        i++;
    }
    for(int j=0;j<i;j++){
        if (a[j]!=a[j+1]){
            len++;
        }
    }
    return len;
}