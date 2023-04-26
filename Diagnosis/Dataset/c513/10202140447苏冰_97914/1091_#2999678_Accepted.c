#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 5000
typedef struct{int cnt,v[N],sign;}BIGINT;
typedef struct{BIGINT re,im;}COMPLEX;
void init(COMPLEX *data,char *s)//读取一个复数
{
    int len=strlen(s);  int j=len-1;
    if(s[j]=='i')   //有虚部
    {
        if(j==0)     //特殊输入情况,没有实部，虚部为：i
        {   data->im.v[0]=1; data->im.cnt=1; data->im.sign=1;    return;   }
        j=j-1;
        if(s[j]=='-'||s[j]=='+'){  // i前面没有系数，前面为 +/-   ，如：3+i，3-i
            data->im.v[data->im.cnt++]=1;
        }
        else{     // 处理虚部的系数  234+456i, 234-456i
            while(j>=0&&s[j]>='0'&&s[j]<='9')  {  data->im.v[data->im.cnt++]=s[j--]-'0';  }
        }
        if(j>=0)   //处理虚部前面的符号，设置sign=-1或者sign=1
        {
            if(s[j]=='-')  data->im.sign=-1;
            j=j-1;
        }
    }
    while(j>=0&&s[j]>='0'&&s[j]<='9')    //有实部，处理实部的系数
       {data->re.v[data->re.cnt++]=s[j--]-'0';}
    if(j>=0) //处理实部前面的符号，设置sign=-1或者sign=1
    {
       if(s[j]=='-') data->re.sign=-1;
    }
}
void print(COMPLEX *result)//输出一个复数
{
    if(result->re.cnt!=0)    //存在实部
    {
        if(result->re.sign==-1) printf("-");
        for(int i=result->re.cnt-1;i>=0;i--) printf("%d",result->re.v[i]);
        if(result->im.cnt!=0&&result->im.sign==1) printf("+");  //存在虚部，而且虚部系数为正，输出+
    }
    if(result->im.cnt!=0)    //存在虚部
    {
        if(result->im.sign==-1) printf("-");
        if(result->im.cnt==1&&result->im.v[0]==1) printf("i\n");   //虚部系数为1，不输出1
        else
        {
            for(int i=result->im.cnt-1;i>=0;i--)
            {
                printf("%d",result->im.v[i]);
            }
            printf("i\n");
        }
    }
}
int cmp(BIGINT S,BIGINT T)//比较两个大整数
{
    int n=(S.cnt>T.cnt)?S.cnt:T.cnt;
    for(int i=n-1;i>=0;i--)
    {
        if(S.v[i]>T.v[i]) return 1;
        else if(S.v[i]<T.v[i]) return -1;
    }
    return 0;
}
void SUB(BIGINT *S,BIGINT *T,BIGINT*R)
{
    int n=(S->cnt>T->cnt)?S->cnt:T->cnt;
    R->cnt=n;
    int carry=0,i;
    for(i=0;i<n;i++)
    {
        if((*(S->v+i)+carry)<*(T->v+i))
        {
            *(R->v+i)=10+*(S->v+i)+carry-*(T->v+i);
            carry=-1;
        }
        else
        {
            *(R->v+i)=*(S->v+i)+carry-*(T->v+i);
            carry=0;
        }
    }
    for(int i=n-1;i>=0 && *(R->v+i)==0 ; i--) R->cnt--;
}
BIGINT BIGSUB(BIGINT S,BIGINT T)//大整数相减
{
    BIGINT R={0,{0},1};
    if(cmp(S,T)>=0)
    {
        R.sign=1;
        SUB(&S,&T,&R);
    }
    else
    {
        R.sign=-1;
        SUB(&T,&S,&R);
    }
    return R;
}
BIGINT BIGMUL(BIGINT S,BIGINT T)
{
    BIGINT R={0,{0},1};
    if(S.cnt==0 || T.cnt==0) return R;
    R.cnt=S.cnt+T.cnt;
    R.sign=S.sign*T.sign;
    for(int i=0;i<T.cnt;i++)
    {
        int t,k,j;
        int carry=0;
        for(j=0;j<S.cnt;j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while(carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;
    return R;
}
BIGINT BIGADD(BIGINT S,BIGINT T)
{
    if(S.cnt==0) return T;
    if(T.cnt==0) return S;
    BIGINT R= {0,{0},1};
    if(S.sign*T.sign<0)//异号相加
    {
        if(S.sign==-1) R=BIGSUB(T,S);
        else R=BIGSUB(S,T);//改成第一个数是正的，减去第二个数
    }
    else
    {
        R.sign=S.sign;
        int i,carry=0;
        for(i=0; i<S.cnt && i<T.cnt; i++)
        {
            int temp=(S.v[i]+T.v[i]+carry);
            R.v[i]=temp%10;
            carry=temp/10;
        }
        while(i<S.cnt)
        {
            int temp =S.v[i]+carry;
            R.v[i++]=temp%10;
            carry=temp/10;
        }
        while(i<T.cnt)
        {
            int temp =T.v[i]+carry;
            R.v[i++]=temp%10;
            carry=temp/10;
        }
        if(carry) R.v[i++]=carry%10;
        R.cnt=i;
    }
    return R;
}
COMPLEX mul(COMPLEX a, COMPLEX b )    //两个复数相乘：a1+b1i, a2+b2i,
{
    COMPLEX result={{0,{0},1},{0,{0},1}};
    BIGINT re1=BIGMUL(a.re,b.re);
    BIGINT re2=BIGMUL(a.im,b.im); re2.sign=-re2.sign;
    BIGINT im1=BIGMUL(a.re,b.im);
    BIGINT im2=BIGMUL(a.im,b.re);
    result.re=BIGADD(re1,re2);
    result.im=BIGADD(im1,im2);
    return result;
}
void pow_Comp(COMPLEX* data,int n)   //复数幂运算
{
    COMPLEX p={{1,{1},1},{0,{0},1}};
    for(int i=1;i<=n;i++)  p=mul(p,*data);
    *data=p;
}
int main()
{
    char s[20];
    int n;
    scanf("%s%d",s,&n);
    COMPLEX data={{0,{0},1},{0,{0},1}};
    init(&data,s);//将输入转换为复数类型
    if(n==0) printf("1\n");
    else if(n==1) print(&data);
    else
    {
        pow_Comp(&data,n);//计算复数幂,传地址，直接就进行了改变
        print(&data);
    }
    return 0;
}
