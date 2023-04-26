#include<stdio.h>
int main()
{
    int T;int a[100];int i;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<T;i++){
        casecase(a[i]);
    }
    return 0;
}

casecase(int n)
{
    int len[100];int a[100];int i=0;int k=0;int j;
    while(n>0){
        a[i] = n%2;
        n = n/2;
        i++;
    }
    len[0]=0;
    for(j=0;j<i;j++){
        if (a[j]!=a[j+1]){
            len[k]++;
        }
        else if(a[j]==a[j+1] && len[k]==0){
            continue;
        }
        else{
            k++;
            len[k]=1;
        }
    }
    int max=len[0];
    for (i=0;i<k;i++){
        if (max<len[i]){
            max=len[i];
        }
    }
    printf("case #%d:\n%d\n",i,max);
}