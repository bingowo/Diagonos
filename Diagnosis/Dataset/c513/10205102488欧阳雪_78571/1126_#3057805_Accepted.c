#include<stdio.h>
#include<stdlib.h>
#define MAX 10001
int cmp(const void*a,const void*b)
{
	long long int c=*(long long int*)a;
	long long int d=*(long long int*)b;
	if(c>d){
		return -1;
	}
	else{
		return 1;
	}
}
void assign(int* x,long long y)//数字->数组，可以用于赋值assign(x,1);
    //是从最后一位MAX_LEN向前赋值的，可能会有前导0
{
    if(y>=0)
	{
		x[0] = 1;
	}
    else
    {
        x[0] = 0;
        y=-y;
    }
    for(int i=MAX-1;i>=1&&y;i--)
    {
        x[i] = y%10;
        y/=10;
    }
}
void print(int* x)
{
    int flag = 0;
    for(int i=1;i<MAX;i++)
    {
        if(!flag && !x[i])  continue;  //去除前导0
        flag = 1;
        printf("%d",x[i]);
    }
    if(!flag)   printf("0");
  
}
void add(int* x,int* y)
{
    int r=0;
    for(int i=MAX-1;i>=0;i--)
    {
        int tmp = x[i]+y[i]+r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	long long a[MAX]={0};
	int i=0;
	long long s=0;//记录所有数的异或之和  A^0=A,A^1=A最后一位取反 
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		s^=a[i];
	}
	if(s>0)//若所有数异或和不为0，则必无解 
	{
		printf("-1");
		return 0; 
	}
	qsort(a,n,sizeof(a[0]),cmp);//由大到小排列 
	int ans[MAX]={0};
	//ans[0]=1;//是正数 
	for(i=0;i<n-1;i++)//前n-1个数相加 ,大数相加 
	{
		int x[MAX]={0};
		assign(x,a[i]);
		add(ans,x);
	}
	print(ans);
}