#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb){
    long long int a,b;
    a=*((long long int *)pa);
    b=*((long long int *)pb);
    if(a-b<0) return 1;
    else return -1;
}
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    long long int a[n];
    long long int b[n-m+1];
    int i = 0;
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long int),cmp);
    long long int q2 = 0, q1 = 0;
    i = 0;
    for(long long int k=0;k<m;k++){
        q1+=a[k];
    }
    for(long long int j=1;j<n-m+1;j++){
        for(long long int k=0;k<m;k++){
            q2+=a[j+k];
        }
        if((q2 + m*(a[i]-a[j])) > q1){
        	i = j; q1 = q2;
		}//printf("%d\n",i);
        q2=0;
    }q1 = 0;
    for(long long int k=1;k<m;k++){
        q1 += (a[i] - a[i+k]);
    }
    printf("%lld",q1);
    return 0;
}
