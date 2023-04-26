#include<stdio.h>
int len(int n){
    int a[40],b[40],j=0,k=0,m,length=1;
    while(n){
        a[j]=(n%2);
        n/=2;
        j++;
        m++;
    }
    for(k=0,j=m-1;k<m,j>=0;k++,j--){
        b[k]=a[j];
    }
    for(k=0;k<m;k++){
        if(b[k]==b[k+1]) length++;
    }
}
int main()
{
    int T;
    scanf("%d\n",&T);
    int n[10],i=0;
    for(i=0;i<T;i++){
        scanf("%d\n",n[i]);
    };
    for(i=0;i<T;i++){
        printf("case #%d:%d\n",);
    };
    return 0;
}