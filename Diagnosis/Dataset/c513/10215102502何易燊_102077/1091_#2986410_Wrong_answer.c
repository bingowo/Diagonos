#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {int cnt; int pos[10001]; int sign;} Bigint;

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

void deal(Bigint* n,int num)
{
    memset(n->pos,0,sizeof(n->pos));
    if (num>0) n->sign = 1;
    else {n->sign = -1; num *= -1;}
    n->cnt = 0;
    do
    {
        n->pos[n->cnt++] = num%10;
        num /= 10;
    } while (num>0);
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
    for (int i=n->cnt;i+1;i--) if (n->pos[i]) return 1;
    return 0;
}

int main()
{
    int r = 0,c = 0,n;
    char s[50] = {}; scanf("%s %d",s,&n);
    if (!strcmp(s,"i")) {r = 0; c = 1;}
    else if (!strcmp(s,"-i")) {r = 0; c = -1;}
    else if (strchr(s,'i')&&!isdigit(*(strchr(s,'i')-1)))
    {
        if (*(strchr(s,'i')-1)=='+') c = 1;
        else c = -1;
        *(strchr(s,'i')-1) = '\0';
        sscanf(s,"%d",&r);
    }
    else 
    {
        int flag = 0; int sign = 1;
        for (int i=1;s[i];i++)
        {
            if (s[i]=='+') s[i] = ' ';
            if (s[i]=='-') {s[i] = ' '; sign = -1;}
            if (s[i]=='i') {s[i] = '\0'; flag = 1;}
        }
        if (sscanf(s,"%d %d",&r,&c)==1) if (flag) {c = r; r = 0;}
        c *= sign;
    }
    if (!n) {printf("1\n"); return 0;}

    Bigint R,I,R_,I_;
    deal(&R,r); deal(&I,c); 
    for (int i=0;i<n-1;i++)
    {
        copy(&R,&R_); copy(&I,&I_);
        bigmul(&R,r); bigmul(&I_,c);
        I_.sign *= -1; bigadd(&R,&I_);
        bigmul(&R_,c); bigmul(&I,r); bigadd(&I,&R_);
    }
    if (judge1(&R)&&!judge1(&I))
    {
        if (R.sign==-1) printf("-");
        for (int i=R.cnt-1;i>=0;i--) printf("%d",R.pos[i]);
        printf("\n");
    }
    else if (!judge1(&R)&&judge1(&I))
    {
        if (I.sign==-1) printf("-");
        if (I.cnt!=1&&I.pos[0]!=1)
            for (int i=I.cnt-1;i>=0;i--) printf("%d",I.pos[i]);
        printf("i\n");
    }
    else if (!judge1(&R)&&!judge1(&I)) printf("0\n");
    else
    {
        if (R.sign==-1) printf("-");
        for (int i=R.cnt-1;i>=0;i--) printf("%d",R.pos[i]);
        printf("%c",I.sign==-1?'-':'+');
        if (I.cnt!=1&&I.pos[0]!=1)
            for (int i=I.cnt-1;i>=0;i--) printf("%d",I.pos[i]);
        printf("i\n");
    }
    system("pause");
    return 0;
}