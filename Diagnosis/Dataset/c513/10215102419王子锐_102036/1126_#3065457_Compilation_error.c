#include <stdio.h>
#include<stdlib.h>
#define LL long long
#define N 100
typedef struct { int cnt,v[N];}BIGINT;
BIGINT int2BIG(long long x)//int转换成BIGINT
{
BIGINT R = {0,{0}};
do
{
R.v[R.cnt++]=x%10;
x/=10;
}while(x>0);
return R;
}
BIGINT ADD(BIGINT S, BIGINT T) //两个大整数相加
{
BIGINT R={0};
int i,carry=0;
for(i=0;i<S.cnt&&i<T.cnt;i++)
{
int temp=(S.v[i]+T.v[i]+carry);
R.v[i]=temp%10;
carry=temp/10;
}
while(i<S.cnt)
{
int temp=S.v[i]+carry;
R.v[i++]=temp%10;
carry=temp/10;
}
while(i<T.cnt){
int temp=T.v[i]+carry;
R.v[i++]=temp%10;
carry=temp/10;
}
if(carry)
{
R.v[i++]=carry%10;
}
R.cnt=i;
return R;
}
int cmp(const void* a,const void* b)
{
return *(int*)a-*(int*)b;
}
int main(){
int n;scanf("%d",&n);
LL a[10000],res=0;
for(int i=0;i<n;i++){
scanf("%lld",&a[i]);
res=res^a[i];//计算所有数据的异或运算
}
if(res!=0){printf("-1\n");return 0;}//整数异或结果不为0，没有满足条件的分组
qsort(a,n,sizeof(a[0]),cmp);
//最小的数单独一组，其它数一组
BIGINT ans={0,{0}};
for(int i=1;i<n;i++)
{
ans=ADD(ans,int2BIG(a[i]));}
for(int i=ans.cnt-l;i>=0;i--)
printf("%d",ans.v[i]);
printf("\n");
return 0;
}