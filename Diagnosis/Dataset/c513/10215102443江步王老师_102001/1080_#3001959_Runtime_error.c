#include<stdio.h>
#include<string.h>
#define N 334

typedef struct a
{
    int cnt;
    int v[100];
}BIGINT;

int div2(BIGINT* n);
void power2(int* t,int j);
void mul(int* t, int n);
void add(int* a,int* b);
int main()
{
    int t;
    int i,j,k;
    scanf("%d\n",&t);

    for (i=0;i<t;++i)
    {
        BIGINT n;
        for (j=0;j<100;++j)
        {
            n.v[j]=0;
        }
        char s[101];
        scanf("%s",s);

        int len=strlen(s);
        if (strcmp(s,'0')!=0) n.cnt=len;
        else n.cnt=0;

        for (j=0;j<len;++j)
        {
            n.v[j]=s[len-1-j]-'0';
        }
        //将大整数的信息保存至变量n中

        int b_int[N]={0};
        int cnt=0;
        while (div2(&n))
        {
            b_int[cnt++]=n.v[0]%2;
        }
        //倒置二进制
        for (j=0;j<N;++j)
        {
            b_int[j]=1-b_int[j];
        }

        int res[105]={0};
        for (j=0;j<N;++j)
        {
            int t[105]={1};
            if (b_int[j])
            {
                power2(t,j);
            }
            add(res,t);
        }
        
        int pos=0;
        for (j=104;j>=0;--j)
        {
            if (res[j]!=0) 
            {
                pos=j;break;
            }
        }
        printf("case #%d:\n",i);
        for (j=pos;j>=0;--j)
        {
            printf("%d",res[j]);
        }
        putchar('\n');
    }
    return;
}

int div2(BIGINT* n)
{
    int carry=0,i;
	if (n->v[n->cnt-1]<2){
		n->cnt--;
		carry=1;
	}
	for (i=n->cnt-1;i>=0;i--) 
    {
		int t=10*carry+n->v[i];
		n->v[i]=t/2;
		carry=t%2;
    }
    return;
}

void power2(int* t,int j)
{
    for (int i=0;i<j;++i)
    {
        mul(t,2);
    }
}

void mul(int* t, int n)
{
    int temp[105]={0};

    for (int i=0;i<105-1;++i)
    {
        temp[i]+=t[i]*n;
        temp[i+1]+=temp[i]/10;
        temp[i]=temp[i]%10;
    }

    for (int i=0;i<105;++i)
    {
        t[i]=temp[i];
    }
}

void add(int* a,int* b)
{
    int carry=0;
    for (int i=0;i<105;++i)
    {
        a[i]=a[i]+b[i]+carry;
        carry=a[i]/10;
        a[i]=a[i]%10;
    }
    return;
}