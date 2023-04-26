#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 101

typedef struct BIGINT
{
    int flag,len,v[L];
};

struct BIGINT Zero={1,0,{0}};
struct BIGINT One={1,1,{1}};

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

void add(struct BIGINT* A,struct BIGINT* B)
{
    int carry=0,cnt=0;
    do{
        A->v[cnt] = A->v[cnt] + B->v[cnt] + carry;
        carry = A->v[cnt]/10;
        A->v[cnt] %= 10;
        cnt++;
    }while(cnt< A->len);
    if(carry!=0)
    {
        A->len++;
        A->v[cnt]=carry;
    }
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

/*int DIV(struct BIGINT *S, int t)
{
    int carry=0;
    struct BIGINT R= {1,S->len,{0}};
    if (S->v[S->len-1]<t)R.len--,carry=S->v[S->len-1];
    for(int i=R.len-1;i>=0;i++)
    {
        int u=10*carry+ S->v[i];
        R.v[i]=u/t;
        carry=u%t;
    }
    *S=R;
    return carry;
}

void mod(struct BIGINT *S, int t)
{
    int rem = DIV(S,t);
    struct BIGINT INT1 = {1,1,{1}};
    if(rem<0){rem+=(-1*t);add(S,&INT1);}

    //if( *S != C ) mod (S,t);

    printf("%d",rem);
}*/

void DIV2(struct BIGINT *n)
{
    int carry=0;
    if (n->v[n->len-1]<2)n->len--,carry=1;
    for (int i=n->len-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
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
    char s[L];
    struct BIGINT a={1,1,{0}};//b={1,1,{0}};
    scanf("%s",s);scan(s,&a);
    //printI(a);
    //scanf("%s",s);scan(s,&b);
    int bin[400]={0},cnt=0;
    while(a.len>0)
    {
        int temp=a.v[0]%2;

        bin[cnt++]=temp;
        DIV2(&a);

        if(a.flag==-1 && temp)
        {
            if (a.len==0){a.len++;a.v[0]=1;}
            else add(&a,&One);
        }
        a.flag*=-1;
    }

    for (int i=cnt-1;i>=0;i--)
        printf("%d",bin[i]);
    printf("\n");
    //printI(a);
    return 0;
}
