#include<stdio.h>
main(){
    int n;
    n=scanf("%d",&n);
    for (int i=0;i<n;i++){
        int cnt=0;int m=5;
        int a=scanf("%d",&a);
        while (a>m){
            cnt += a/m;
            m *=5;
        }
        printf("case #%d:\n",i);
        printf("%d",cnt);
    }
    return 0;
}