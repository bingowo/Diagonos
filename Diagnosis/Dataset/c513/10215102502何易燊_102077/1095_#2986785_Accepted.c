#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {int cnt; int sign; int pos[100001]; } Bigint;


void bigmul(Bigint* n,int num)
{
    if (n->sign*num>0) n->sign = 1;
    else n->sign = -1;
    num = abs(num);
    int carry = 0;
    for (int i=0;i<n->cnt;i++)
    {
        int t = carry+n->pos[i]*num;
        n->pos[i] = t%10;
        carry = t/10;
    }
    while (carry>0)
    {
        n->pos[n->cnt++] = carry%10;
        carry /= 10;
    }
}

void bigadd(Bigint* n,Bigint* m)
{
    int len = n->cnt>=m->cnt? n->cnt :m->cnt;
    if (n->sign*m->sign>0)
    {
        int len = n->cnt>=m->cnt? n->cnt :m->cnt;
        for (int i=0;i<len;i++)
        {
            n->pos[i] += m->pos[i];
            n->pos[i+1] += n->pos[i]/10;
            n->pos[i] %= 10;
        }
        n->cnt = len;
        if (n->pos[len]) n->cnt++;
    }
    else if (n->sign>0&&m->sign<0)
    {
        int len_ = len;
        while (n->pos[len_-1]==m->pos[len_-1]) len_--;
        if (n->pos[len_-1]<m->pos[len_-1])
        {
            n->sign = -1;
            n->cnt = m->cnt;
            for (int i=0;i<len;i++)
            {
                int temp = n->pos[i];
                n->pos[i] = m->pos[i];
                m->pos[i] = temp;
            }
        }
        for (int i=0;i<len;i++) 
        {
            n->pos[i] -= m->pos[i];
            while (n->pos[i]<0) {n->pos[i] += 10; n->pos[i+1]--;}
            while (!n->pos[n->cnt-1]) n->cnt--; 
        }
    }
    else if (n->sign<0&&m->sign>0)
    {
        int len_ = len;
        while (n->pos[len_-1]==m->pos[len_-1]) len_--;
        if (n->pos[len_-1]<m->pos[len_-1])
        {
            n->cnt = m->cnt;
            n->sign = 1;
            for (int i=0;i<len;i++)
            {
                int temp = n->pos[i];
                n->pos[i] = m->pos[i];
                m->pos[i] = temp;
            }
        }
        for (int i=0;i<len;i++)
        {
            n->pos[i] -= m->pos[i];
            while (n->pos[i]<0) {n->pos[i] += 10; n->pos[i+1]--;}
            while (!n->pos[n->cnt-1]) n->cnt--;
        }
    }
}

int tobinary(char s[],int num[])
{
    int copy[100001] = {};
    int k=0, p=0;
    for (int i=0;s[i];i++,k+=4)
    {
        int n = isdigit(s[i])?s[i]-'0':s[i]-'A'+10;
        for (int j=0;j<4;j++)
        {
            copy[k-j+3] = n%2;
            n /= 2;
        }
    }
    while (copy[p]==0) p++;
    for (int i=k-1,q=0;i>=p;i--) num[q++] = copy[i];
    return k-p;
}

void copy(Bigint* n,Bigint* m)
{
    m->sign = n->sign;
    memset(m->pos,0,sizeof(m->pos));
    m->cnt = n->cnt;
    for (int i=0;i<n->cnt;i++) m->pos[i] = n->pos[i];
}

int judge1(Bigint* n)
{
    for (int i=100000;i+1;i--) if (n->pos[i]) return 1;
    return 0;
}

int main()
{
    char s[10001] = {}; scanf("0x%s",s);
    if (!strcmp(s,"0")) {printf("0\n");return 0;}
    int num[100001] = {};
    int len = tobinary(s,num);
    
    Bigint one;
    one.cnt = 1; one.sign = 1;
    memset(one.pos,0,sizeof(one.pos));
    one.pos[0] = 1;

    Bigint R,I,R_,I_;
    memset(R.pos,0,sizeof(R.pos)); memset(I.pos,0,sizeof(I.pos));
    R.cnt = 0; I.cnt = 0;
    R.sign = 1; I.sign = 1;
    for (int i=len-1;i+1;i--)
    {
        copy(&R,&R_); copy(&I,&I_);
        R.sign *= -1; bigadd(&R,&I_);
        I.sign *= -1; R_.sign *= -1; bigadd(&I,&R_);
        if (num[i]) bigadd(&R,&one);
    }
    I.sign *= -1;

    if (judge1(&R)&&!judge1(&I))
    {
        if (R.sign==-1) printf("-");
        for (int i=R.cnt-1;i>=0;i--) printf("%d",R.pos[i]);
        printf("\n");
    }
    else if (!judge1(&R)&&judge1(&I))
    {
        if (I.sign==-1) printf("-");
        if (I.cnt!=1||I.pos[0]!=1)
            for (int i=I.cnt-1;i>=0;i--) printf("%d",I.pos[i]);
        printf("i\n");
    }
    else if (!judge1(&R)&&!judge1(&I)) printf("0\n");
    else
    {
        if (R.sign==-1) printf("-");
        for (int i=R.cnt-1;i>=0;i--) printf("%d",R.pos[i]);
        printf("%c",I.sign==-1?'-':'+');
        if (I.cnt!=1||I.pos[0]!=1)
            for (int i=I.cnt-1;i>=0;i--) printf("%d",I.pos[i]);
        printf("i\n");
    }

    system("pause");
    return 0;
}