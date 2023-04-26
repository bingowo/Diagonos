#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 5000

typedef struct 
{ 
    int cnt, v[N], sign;
} BIGINT ;

typedef struct 
{
    BIGINT re,im;
} COMPLEX ;

BIGINT BIGMUL(BIGINT S , BIGINT T)  //两个大整数相乘
{
    BIGINT R= {0,{0},1};
    if(S.cnt==0 || T.cnt==0) return R;
    R.cnt=S.cnt+T.cnt;
    R.sign=S.sign*T.sign;
    for (int i=0 ; i<T.cnt ; i++)
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
    if(R.v[S.cnt+T.cnt-1]==0) R.cnt--; //最高位0不统计在一个大整数的位数中
    return R;
}

void SUB(BIGINT *S , BIGINT *T , BIGINT *result) //大数减小数
{
 int n=(S->cnt>T->cnt) ?S->cnt : T->cnt;
 result->cnt=n ;
 int carry=0,i;
 for(i=0 ; i<n ; i++)
 {
     if((*(S->v+i)+carry)<(*(T->v+i)))
     {
         *(result->v+i)=10+*(S->v+i)+carry-*(T->v+i);
         carry=-1;
     }
     else
     {
         *(result->v+i)=*(S->v+i)+carry-*(T->v+i);
         carry=0;
     }
 }
 for(int i=n-1;i>=0&& !result->v[i];i--) result->cnt--;
}

int cmp(BIGINT S,BIGINT T) //两个大整数的比较
{
    int n=(S.cnt>T.cnt)?S.cnt:T.cnt;
    for(int i=n-1;i>=0;i--)
    if(*(S.v+i)>*(T.v+i)) return 1;
    else if(*(S.v+i)<*(T.v+i)) return -1;
    return 0;
}

BIGINT BIGSUB (BIGINT S , BIGINT T)
{
    BIGINT R={0 , {0} , 1} ;
    if(cmp(S,T)>=0)
    {
        R.sign=1 ;
        SUB(&S , &T , &R) ;
    }
    else
    {
        R.sign=-1 ;
        SUB(&T , &S , &R) ;
    }
    return R ;
}

BIGINT BIGADD (BIGINT S , BIGINT T) //两个大整数相加
{
 if(S.cnt==0) return T ;
 if(T.cnt==0) return S ;
 BIGINT R= {0,{0},1} ;
 if(S.sign*T.sign<0) //两个异号相加

 {
 if(S.sign==-1) R=BIGSUB (T , S) ; //调整为第一个数为正，减第二个数

 else R=BIGSUB (S , T) ;
 }
 else //两个同号相加

  {
 R.sign=S.sign ;
 int i , carry=0 ;
 for (i =0 ; i <S.cnt&&i <T.cnt ; i ++)
 {
 int temp= (S.v[i] +T.v[i] +carry) ;
 R.v[i]=temp%10 ;
 carry=temp/10 ;
 }
 while (i<S.cnt)
 {
 int temp=S.v[i] +carry ;
 R.v[i++]=temp%10 ;
 carry=temp/10 ;  }
 while (i<T.cnt)
 {
 int temp=T.v[i]+carry ;
 R.v[i++]=temp%10 ;
 carry=temp/10 ;
 }
 if(carry)
{
 R.v[i++]=carry%10 ;
 }
 R.cnt=i ;
 }
 return R ;
}

COMPLEX mul (COMPLEX a , COMPLEX b )
{
 COMPLEX result={ {0 , {0} , 1} , {0 , {0} , 1} } ;
 BIGINT re1=BIGMUL (a.re ,b.re) ;
 BIGINT re2=BIGMUL (a.im ,b.im) ; re2.sign=-re2.sign;
 BIGINT im1=BIGMUL (a.re ,b.im) ;
 BIGINT im2=BIGMUL (a.im ,b.re) ;
 result.re=BIGADD ( re1 ,re2) ;
 result.im=BIGADD (im1 ,im2) ;
 return result ;
}

void init(COMPLEX *data , char *s)
{
 int len=strlen(s) ;
 int j=len-1;
 if(s[j]=='i')
 {
 if(j==0)
 {
 data->im.v[0]=1 ; data->im.cnt=1 ; data->im.sign=1 ;
 return ;
}
 j=j-1 ;
 if(s[j] =='-'||s[j]=='+') {
 data->im.v[data->im.cnt++]=1 ;
 }
else{
while (j>=0&&s[j]>='0'&&s[j]<='9')
 {data->im.v[data->im.cnt++]=s[j--]-'0'; }
 }
if(j>=0)
 {
 if(s[j]=='-')data->im.sign=-1;
 j=j-1;
 }
 }
 while(j>=0&&s[j]>='0'&&s[j]<='9')
{data->re.v[data->re.cnt++]=s[j--]-'0'; }
 if(j>=0)
  {
 if(s[j] =='-' ) data->re.sign=-1 ;
 }
}

void pow_Comp (COMPLEX* data , int n)
{
 COMPLEX p={ {1 , {1} , 1} , {0 , {0} , 1} } ;
 for (int i=1 ; i<=n ; i++)
 p=mul(p , *data) ;
 *data=p ;
}

void print (COMPLEX * result)
{
 if(result->re.cnt!=0) //存在实部

 {
 if( result->re.sign==-1) printf("-") ;
 for (int i=result->re.cnt-1 ; i >=0 ; i--) printf("%d",result->re.v[i]) ;
 if( result->im.cnt!=0&&result->im.sign==1) printf("+") ; //存在虚部，而且虚部系数为正，输出+

 }
 if( result->im.cnt!=0) //存在虚部

 {
 if( result->im.sign==-1) printf("-") ;
 if( result->im.cnt==1&&result->im.v[0]==1) printf("i\n") ; //虚部系数为1，不输出 1

 else

 {
 for (int i=result->im.cnt-1 ; i>=0 ; i--)
 {
 printf("%d",result->im.v[i] ) ;
 }
 printf("i\n") ;
 }
 }
}

int main()
{
 char s[20] ; int n ; scanf("%s%d",s,&n) ;
 COMPLEX data={ {0 , {0} , 1} , {0 , {0} , 1} } ;
 init (&data,s) ;
 if(n==0) printf("1\n") ;
 else if(n==1) print (&data) ;
 else {pow_Comp (&data,n) ; print(&data) ; }
 return 0 ;
}
