#include<stdio.h>
#include<stdlib.h>
int tongji(long long int m)
{
    int i,x,k=0;
	for(i=0;i<64;i++)
	{
		x=(m>>i)&1;
		if(x==1)
			k++;
	}
	return k;
}  //ojbk
long long int comp(const void*p1,const void*p2)
{
    long long int x;
    long long int n1,n2;
    n1=*(long long int*)p1;
    n2=*(long long int*)p2;
    x=tongji(n1)-tongji(n2);
    if(x!=0)
    {
        return -x;
    }
    else
    {
        if((n1-n2)<0)
            x=-1;
        else
            x=1;
        return x;
    }
}


int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int t,k;
        long long int m;
        scanf("%d",&t);
        long long int a[t],b[t],c[t];
        for(int tt=0;tt<t;tt++)
        {
            scanf("%lld",&a[tt]);
            m=a[tt];
            int sz=sizeof(a)/sizeof(a[0]);
            if(tt==t-1)
            {
                qsort(a,sz,sizeof(a[0]),comp);
                printf("case #%d:\n",i);
                for(int ttt=0;ttt<t;ttt++)
                {
            
                    printf("%lld ",a[ttt]);
                }
                printf("\n");
            }
            
            
            
            
            
        }   //保存所有数字
    }
    
}