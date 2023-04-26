#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 101

typedef struct BIGINT
{
    int flag,len,v[L];
};

void scan(char*s,struct BIGINT* A)
{

    A->len=strlen(s);
    for(int i=0;i<A->len-1;i++)
    {
        A->v[i] = s[A->len-1-i]-'0';
    }
    if(s[0]=='-'){ A->flag=-1;A->len--;}
    else{ A->v[A->len-1] = s[0]-'0';A->flag=1;}
}

struct BIGINT mul(struct BIGINT S, struct BIGINT T)     //两个大整数相乘
{
    struct BIGINT R= {1,S.len+T.len,{0}};
    for (int i=0; i<T.len; i++)
    {
         int t,k,j;
        int carry=0;
        for (j=0; j<S.len; j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.len+T.len-1]==0) R.len--; //最高位0不统计在一个大整数的位数中
    return R;
}

struct BIGINT int2BIG(int x)  //int convert to BIGINT
{
    struct BIGINT R= {1,0,{0}};
    do
    {
        R.v[R.len++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}


struct BIGINT powINT(struct BIGINT S,int n)
{
    struct BIGINT R=S;
    for (int i=1;i<n;i++)
        R=mul(R,S);
    return R;
}

void printI(struct BIGINT A)
{
    if(A.flag==-1)printf("-");
    for(int i=A.len-1;i>=0;i--)
        printf("%d",A.v[i]);
    printf("\n");
}

int main()
{
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int a0,n0;
        scanf("%d%d",&a0,&n0);

        if(n0==0){printf("case #%d:\n1\n",i);continue;}

        struct BIGINT a={1,1,{0}};
        a=int2BIG(a0);
        a=powINT(a,n0);

        printf("case #%d:\n",i);
        printI(a);
    }
    return 0;
}
