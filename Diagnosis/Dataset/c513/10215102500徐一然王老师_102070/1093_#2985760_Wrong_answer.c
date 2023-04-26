#include <stdio.h>
typedef struct{int cnt,v[500];} BIGINT;

BIGINT INPUT()
{
    BIGINT A={0,{0}};
    char c;
    while((c=getchar())!=EOF&&c!='\n')
    {
        A.v[A.cnt++]=c-'0';
    }
    return A;
}

int SUM(BIGINT R)
{
    int sum=0;
    for(int i=0;i<R.cnt;i++)
    {
        sum=sum+R.v[i];
    }
    if(sum%9==0)
        return 1;
    else return -1;
}

int PD(BIGINT R)
{
    for(int i=0;i<R.cnt;i++)
    {
        if(R.v[i]==9)return 1;
    }
    return -1;
}

BIGINT ADD(BIGINT R)
{
    BIGINT C={0,{0}};
    for(int i=R.cnt-1;i>=0;i--)
    {
        if(i==R.cnt-1&&i!=0)
        {
            R.v[i]++;
        }
        if(i==0)
        {
            if(R.v[i]>=10)
            {
                R.v[i]=R.v[i]-10;
                R.v[i-1]++;
                C.v[i+1]=R.v[i];
                C.v[0]==1;
            }
            else
            C.v[i+1]=R.v[i];
        }
        else
        {
            if(R.v[i]>=10)
            {
                R.v[i]=R.v[i]-10;
                R.v[i-1]++;
            }
            C.v[i+1]=R.v[i];
        }

    }
    C.cnt=R.cnt+1;
    return C;
}

int main()
{
    int i=0;
    BIGINT R;
    R=INPUT();
    R=ADD(R);
    while(1)
    {
        if(SUM(R)==-1&&PD(R)==-1)break;
        else{R=ADD(R);}
    }
    for(i;i<R.cnt;i++)
    {
        if(R.v[i]!=0)break;
    }
    for(i;i<R.cnt;i++)
    {
        printf("%d",R.v[i]);
    }
}
