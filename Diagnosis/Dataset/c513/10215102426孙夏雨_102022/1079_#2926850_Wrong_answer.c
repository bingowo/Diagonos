#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if(*p1>*p2) return 1;
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0,m=0;
        scanf("%d %d",&n,&m);
        int* p0=(int* )malloc(n*sizeof(int));
        for(int i=0;i<n;i++) scanf("%d",(p0+i));
        int* p=(int* )malloc((n*(n+1)/2)*sizeof(int));
        int len=1,sum=0,num=0;
        while(len<=n){
            for(int j=0;j<len;j++) sum+=*(p0+j);
            *(p+num)=sum;
            num++;
            for(int k=len;k<n;k++){
                sum=sum+(*(p0+k))-(*(p0+k-len));
                *(p+num)=sum;
                num++;
            }
            len++;
            sum=0;
        }
        qsort(p,num,sizeof(int),cmp);
        printf("case #%d:\n",t);
        for(int ii=0;ii<m;ii++){
            int beg=0,end=0,ans=0;
            scanf("%d %d",&beg,&end);
            for(int kk=beg-1;kk<end;kk++) ans+=(*(p+kk));
            printf("%d\n",ans);
        }
    }
    return 0;
}
