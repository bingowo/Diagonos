//pow(A,B)的末尾N位等于pow(A的末尾N位,B)
//数组存中间结果,注意0也要乘
#include<stdio.h>
#include<string.h>
void get_base(int* base,int A,int N)
{
    int tmp[10],cnt=0,i,j=0,d;
    while(A)
    {
        tmp[cnt++]=A%10;
        A/=10;
    }
    if(cnt>=N)for(i=N-1;i>-1;--i)base[j++]=tmp[i];
    else 
    {
    	d=N-cnt;
    	for(j;j<d;++j)base[j]=0;
    	for(j;j<N;++j)
    	{
    		base[j]=tmp[cnt-j+d-1];
		}
	}
}
void mulsingle(int *a,int b,int N,int mov)
{
    int carry=0,tmp,i,d=N-mov-1;
    for(i=99;i>99-N;--i)
    {
        tmp=a[i]*b+carry;
        if(tmp>=10){a[i]=tmp%10;carry=tmp/10;}
        else {a[i]=tmp;carry=0;}
    }
    for(i-=(d-1);i<100-d;++i)a[i]=a[i+d];
    for(i;i<100;++i)a[i]=0;
    return;
}
void add(int* a,const int* b,int N)
{
    int carry=0,i,tmp;
    for(i=99;i>99-N;--i)
    {
        tmp=a[i]+b[i]+carry;
        if(tmp>=10){a[i]=tmp%10;carry=tmp/10;}
        else {a[i]=tmp;carry=0;}
    }
    return;
}
void mul(int* a,const int* base,int N)
{
    int tmp[100],ans[100],i,j,k;
    memcpy(ans,a,400);
    mulsingle(ans,base[N-1],N,N-1);
    for(i=N-2;i>-1;--i)
    {
        memcpy(tmp,a,400);
        mulsingle(tmp,base[i],N,i);
        add(ans,tmp,N);
    }
    memcpy(a,ans,400);
    return;
}
int main()
{
    int T,i,j,A,B,N;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d %d %d",&A,&B,&N);
        int a[100]={0},a_len=1;
        a[99]=1;
        int base[N];get_base(base,A,N);
        for(i=0;i<B;++i)mul(a,base,N);
        printf("case #%d:\n",cas);
        for(i=100-N;i<100;++i)printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}