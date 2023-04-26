#include<stdio.h>
int main()
{
    int T,i,j,m;
    long long int r=0;
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++){
        char a[50];
        j=0;
        while((a[j]=getchar())!='\n'){
            j++;
        }
        m=1;r=0;
        for(j=j-1;j>=0;j--){
            if(a[j]=='-'){
                r=r-m;
            }
            else{
                r=r+(a[j]-'0')*m;
            }
            m=m*3;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",r);
    }
    return 0;
}
