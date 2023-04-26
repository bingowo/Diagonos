#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(){
    int T;
    scanf("%d",&T);
    int l=0;
    while(T-->0){
    
        
        int n,m;
        scanf("%d %d",&n,&m);
        int d=n*(n+1)/2;
        int a[1000];
        int b[m][2];
        int c[d+1];
        for(int i=1;i<n*(n+1)/2;i++) c[i]=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d %d",&b[i][0],&b[i][1]);
        //for(int i=0;i<n;i++) printf("%d",a[i]);
        //for(int i=0;i<m;i++) printf("%d %d",b[i][0],b[i][1]);
        int i=0,j=0,k=0,sum=0;
        for(i=0;i<n;i++){
            for(j=i;j<n;j++,sum++){
                for(k=i;k<=j;k++) c[sum]+=a[k];
            }
        }
        qsort(c,sum,sizeof(c[0]),cmp);
        //for(int i=0;i<sum;i++) printf("%d",c[i]);
        printf("case #%d:\n",l++);
        for(int i=0;i<m;i++){
            int sum=0;
            int j=b[i][0],k=b[i][1];
            for(;j<=k;j++){
                sum+=c[j-1];
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}