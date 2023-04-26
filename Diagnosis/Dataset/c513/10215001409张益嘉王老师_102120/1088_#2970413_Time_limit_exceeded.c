#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int aa=*((int*)a);
    int bb=*((int*)b);
    return bb-aa;

}

int jud(int *b,int n)
{
    int i,re;
    for(i=0;i<n;i++)
    {
        if(b[i]!=1) return 1;
    }
    return 0;

}

void yue(int *a,int*b,int n)
{
    int k,j,nofind;
    for(k=0;k<n;k++)
        {
            if(b[k]==0) break;
            if(b[k]==1) continue;
            for(j=0;j<n;j++)
            {
                if(a[j]%b[k]==0) {a[j]=a[j]/b[k];b[k]=1;break;}
            }
        }
        /*for(j=0;j<n;j++)
        {
            printf("test yuenei:b[%d]=%d\n",j,b[j]);
        }*/
        nofind=jud(b,n);
        //printf("nofind=%d\n",nofind);
        if(nofind)
        {
            qsort(a,n,sizeof(int),cmp);
            for(j=0;j<n-2;j+=3)
            {
                a[j]=a[j]*a[j+1]*a[j+2];
                a[j+1]=1;
                a[j+2]=1;
            }
            yue(a,b,n);
        }
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        int a[50],b[50],j,k;
        memset(a,0,sizeof(int)*50);
        memset(b,0,sizeof(int)*50);
        int mx=m,nx=n;
        for(j=0;j<n;j++)
        {
            a[j]=mx--;
            //printf("test:a[%d]=%d\n",j,a[j]);
        }
        for(j=0;j<n;j++)
        {
            b[j]=nx--;
            //printf("test:b[%d]=%d\n",j,b[j]);
        }
        yue(a,b,n);

        /*for(j=0;j<n;j++)
        {
            printf("test gaihou:a[%d]=%d\n",j,a[j]);
        }*/
        unsigned long long re=1;
        for(j=0;j<n;j++)
        {
            re*=(unsigned long long)a[j];
        }
        printf("case #%d:\n",i);
        if((m==0)||(n==0)) printf("1\n");
        else printf("%llu\n",re);


    }
    return 0;
}
