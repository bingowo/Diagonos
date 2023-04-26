#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define N 5000
typedef struct
{
    int cnt,v[N],sign;
}BIGINT;

typedef struct
{
    BIGINT re,im;
}COMPLEX;//复数
void SUB(BIGINT* s,BIGINT* t,BIGINT* result);
int cmp(BIGINT s,BIGINT t);
void init (COMPLEX* data,char* s)//输入的字符串解析为复数类存储
{
    int len = strlen(s); int j=len-1;
    if (s[j]=='i')
    {
        if (j==0)
        {
            data->im.v[0]=1;data->im.cnt=1;data->im.sign=1;return;
        }
        j=j-1;
        if(s[j]=='-'||s[j]=='+') data->im.v[data->im.cnt++]=1;
        else
        {
            while(j>=0&&s[j]>='0'&&s[j]<='9')
            {
                data->im.v[data->im.cnt++]=s[j--]-'0';
            }
        }
        if(j>=0)
        {
            if (s[j]=='-') data->im.sign=-1;
            j=j-1;
        }
    }
    while(j>=0&&s[j]>='0'&&s[j]<='9')
    {
        data->re.v[data->re.cnt++]=s[j--]-'0';
    }
    if(j>=0)
    {
        if(s[j]=='-')
            data->re.sign=-1;
    }
}

void print(COMPLEX* result)
{

    if (result->re.cnt!=0)
    {
        if(result->re.sign==-1)
            printf("-");
        for(int i=(result->re.cnt-1);i>=0;i--) printf("%d",result->re.v[i]);
    }
    if (result->im.cnt!=0)
    {
        if(result->im.sign==1) printf("+");
        else printf("-");

        if(result->im.cnt==1&&result->im.v[0]==1) printf("i\n");
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
BIGINT BIGMUL(BIGINT x,BIGINT y)
{
    BIGINT R={0,{0},1};
    if(x.cnt==0||y.cnt==0) return R;

    R.cnt = x.cnt+y.cnt;
    R.sign =x.sign*y.sign;
    for(int i=0;i<x.cnt;i++)
    {
        int j,t,k;
        int carry=0;
        for(j=0;j<y.cnt;j++)
        {
            t=x.v[j]*y.v[i]+carry+R.v[i+j];
            R.v[i+j] = t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry!=0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[x.cnt+y.cnt-1]==0) R.cnt--;
    return R;

}

BIGINT BIGSUB (BIGINT s,BIGINT t)
{
    BIGINT R={0,{0},1};
    if (cmp(s,t)>=0)
    {
        R.sign=1;
        SUB(&s,&t,&R);
    }
    else
    {
        R.sign=-1;
        SUB(&t,&s,&R);
    }
    return R;
}
BIGINT BIGADD(BIGINT s,BIGINT t)
{
    if(s.cnt==0) return t;
    else if(t.cnt==0) return s;
    BIGINT R={0,{0},1};
    if(s.sign*t.sign<0)
    {
        if(s.sign==-1) R=BIGSUB(t,s);
        else R=BIGSUB(s,t);
    }
    else
    {
        R.sign =s.sign;
        int i,carry=0;
        for(i=0 ;i<s.cnt&&i<t.cnt;i++)
        {
            int temp = s.v[i]+t.v[i]+carry;
            R.v[i]=temp%10;
            carry=temp/10;
        }
        while(i<t.cnt)
        {
            int temp =s.v[i]+carry;
            R.v[i++] =temp%10;
            carry = temp/10;
        }
        while (i<s.cnt)
        {
            int temp =t.v[i]+carry;
            R.v[i++]=temp%10;
            carry = temp/10;
        }
        while(carry)
        {
            R.v[i++]=carry%10;
            carry/=10;
        }
        R.cnt=i;

    }
    return R;

}

int cmp(BIGINT s,BIGINT t)
{
    int n =(s.cnt>t.cnt)?s.cnt:t.cnt;
    for(int i=n-1;i>=0;i--)
    {
        if(*(s.v+i)>*(t.v+i)) return 1;
        else if(*(s.v+i)<*(t.v+i)) return -1;
    }
    return 0;
}


void SUB(BIGINT* s,BIGINT* t,BIGINT* result)
{
    int n=(s->cnt>t->cnt)?s->cnt:t->cnt;
    result->cnt=n;
    int carry=0,i;
    for(i=0;i<n;i++)
    {
        if((*(s->v+i)+carry)<(*(t->v+i)))
        {
            *(result->v+i)=*(s->v+i)+10+carry-*(t->v+i);
            carry=-1;
        }
        else {
            *(result->v+i)=*(s->v+i)+carry-*(t->v+i);
            carry=0;
        }
    }
    for (int i=n-1;i>=0&&result->v[i]==0;i--) result->cnt--;
}






COMPLEX mul(COMPLEX a,COMPLEX b)
{
    COMPLEX result={{0,{0},1},{0,{0},1}};
    BIGINT re1=BIGMUL(a.re,b.re);
    BIGINT re2=BIGMUL(a.im,b.im);re2.sign=-re2.sign;
    BIGINT im1=BIGMUL(a.re,b.im);
    BIGINT im2=BIGMUL(a.im,b.re);
    result.re=BIGADD(re1,re2);
    result.im=BIGADD(im1,im2);
    return result;
}

void pow_Comp(COMPLEX* data,int n)
{
    COMPLEX p={{1,{1},1},{0,{0},1}};
    for(int i=1;i<=n;i++) p=mul(p,*data);
    *data=p;
//    printf("%d %d",data->im.cnt,data->re.cnt);
}








int main(void)
{
    char s[20];int n;
    scanf("%s%d",s,&n);
    COMPLEX data ={{0,{0},1},{0,{0},1}};
    init (&data,s);
    if(n==0) printf("1\n");
    else if(n==1) print(&data);
    else
    {
        pow_Comp (&data,n);
        print(&data);
    }
    return 0;

}
