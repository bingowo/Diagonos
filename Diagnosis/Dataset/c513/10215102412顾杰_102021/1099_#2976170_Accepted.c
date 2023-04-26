#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{int cnt,v[334];}BIGINT;
BIGINT int2BIG(int x)
{
    BIGINT R={0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    }
    while(x>0);
    return R;
}
BIGINT ADD(BIGINT S,BIGINT T)
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
    while(i<T.cnt)
    {
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
void DIV2(BIGINT *n)
{
    int carry=0,i;
    if(n->v[n->cnt-1]<2){n->cnt--;carry=1;}
    for(i=n->cnt-1;i>=0;i--)
    {
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}
int main()
{
    char A[22223],c=0;
    A[12000]='A';A[21110]='B';A[21210]='C';A[21100]='D';A[10000]='E';A[11210]='F';A[22100]='G';A[11110]='H';
    A[11000]='I';A[12220]='J';A[21200]='K';A[12110]='L';A[22000]='M';A[21000]='N';A[22200]='O';A[12210]='P';
    A[22120]='Q';A[12100]='R';A[11100]='S';A[20000]='T';A[11200]='U';A[11120]='V';A[12200]='W';A[21120]='X';
    A[21220]='Y';A[22110]='Z';A[22222]='0';A[12222]='1';A[11222]='2';A[11122]='3';A[11112]='4';A[11111]='5';
    A[21111]='6';A[22111]='7';A[22211]='8';A[22221]='9';A[1]=' ';A[3]='.';
    int n,i,f,ans;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        f=1;ans=0;
        while(f!=-1)
        {
            switch(c)
            {
                case '\n':
                    if(f==1){printf("case #%d:\n",i);f=0;}
                    while(ans<10000&&ans)ans*=10;
                    printf("%c\n",A[ans]);
                    c=getchar();
                    ans=0;
                    f=-1;
                    break;
                case '/':
                    if(f==1){printf("case #%d:\n",i);f=0;}
                    while(ans<10000&&ans)ans*=10;
                    if(ans==0){while((c=getchar())=='/')ans++;printf("%c",A[ans]);}
                    else {printf("%c",A[ans]);c=getchar();}
                    ans=0;
                    break;
                case '.':
                    ans*=10;
                    ans++;
                    c=getchar();
                    break;

                case '-':
                    ans*=10;
                    ans+=2;
                    c=getchar();
                    break;
                default:
                    ans*=10;
                    c=getchar();

            }

        }

    }

}
