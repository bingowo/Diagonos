#include <stdio.h>
#include <stdlib.h>
int lm;
int cmp(const void *a,const void *b)
{
    int *a0=(int**)a;
    int *b0=(int**)b;
    for(int i=0;i<lm;i++)
        if(*(a0+i)!=*(b0+i))
            return *(b0+i)-*(a0+i);
    return 0;
}
int main()
{
    int a[1000][50];
    int t,n,x,l,i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        lm=0;
        for(j=0;j<1000;j++)
            for(k=0;k<50;k++)
                a[j][k]=-1;
        for(j=0;j<n;j++){
            l=0;
            scanf("%d",&x);
            while(x!=-1){
                a[j][l]=x;
                l++;
                scanf("%d",&x);
            }
            if(l>lm)
                lm=l;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(j=0;j<n;j++)
            for(k=0;k<lm;k++){
                if(a[j][k]!=-1)
                    printf("%d",a[j][k]);
                if(k==lm-1 && a[j][k+1]==-1)
                    printf("\n");
                else
                    printf(" ");
            }
    }
    return 0;
}
