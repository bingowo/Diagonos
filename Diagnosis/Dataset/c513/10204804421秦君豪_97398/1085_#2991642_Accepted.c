#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define maxn 1000000

typedef long long int lli;

typedef struct{int cnt,v[501];}BIGINT;
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

BIGINT char2BIG(char* s,int l)
{
    BIGINT R={0,{0}};

    for (int j=l-1;j>=0;j--) R.v[R.cnt++]=s[j]-'0';
//    printf("%d",R.cnt);
    return R;
}


void minus(BIGINT a,BIGINT b)//ab相减
{
    int isnegative =0;
    if(a.cnt<b.cnt) isnegative =1;
    else if(a.cnt==b.cnt)
    {
        int i=a.cnt;
        while (a.v[i]==b.v[i])
        {
            i--;
        }
        if (a.v[i]<b.v[i]) isnegative=1;
    }
    if (isnegative==1)
    {
//        printf("oass");
        printf("-");
        minus(b,a);
    }
    else
    {
        for(int j=0;j<a.cnt;j++)
        {
            if(a.v[j]<b.v[j])
            {
                a.v[j+1]--;
                a.v[j]+=10;
            }
            a.v[j]-=b.v[j];
        }
        while(a.v[a.cnt-1]==0&&a.cnt>=1) a.cnt--;
//        printf("%d",a.cnt);
        if(a.cnt==0) printf("0\n");
        else
        {
            for(int j=a.cnt-1;j>=0;j--)
                printf("%d",a.v[j]);
            printf("\n");
        }
    }

}



int main(void)
{
    char a[501],b[501];
    while (scanf("%s%s",&a,&b)!=EOF)
    {
        int len1=strlen(a);int len2=strlen(b);
        BIGINT A=char2BIG(a,len1);
        BIGINT B=char2BIG(b,len2);
//        printf("%d\n",A.v[0]);
        minus (A,B);
    }
    return 0;

}
