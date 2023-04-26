#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
基本思路：从最高位开始扫描，如果出现相等情况，第二个数加一，
后面用0、1交替填充
*特殊情况：加一后进位，算完之后在扫描
*/

typedef struct
{
    int cnt;
    int v[102];
}BIGINT;

void Add(BIGINT* bi,int d)
{
    int carry=1,i=d;
    for(;i<bi->cnt&&carry>0;i++)
    {
        int t=bi->v[i]+carry;
        bi->v[i]=t%10;
        carry=t/10;
    }
    if(carry>0)
        bi->v[bi->cnt]=carry,bi->cnt++;
}
int judge(BIGINT bi)
{
    for(int i=bi.cnt-1;i>0;i--)
        if(bi.v[i]==bi.v[i-1]) return i-1;
    return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[103]={0};
        int sign=0;
        BIGINT bi;
        bi.cnt=0;
        scanf("%s",s);
        for(int i=strlen(s)-1;i>=0;i--)
        {
            bi.v[bi.cnt++]=s[i]-'0';
            if(i>0&&s[i]==s[i-1]) sign=1;
        }
        if(sign==0) Add(&bi,0);
        while(judge(bi)!=-1)
        {
            if(bi.v[judge(bi)]<9)
            {
                int j;
                for(j=judge(bi)-1;j>0;)
                    bi.v[j]=0,bi.v[j-1]=1,j-=2;
                if(j==0) bi.v[0]=0;
                Add(&bi,judge(bi));
            }
            else Add(&bi,judge(bi));
        }
        printf("case #%d:\n",t);
        for(int i=bi.cnt-1;i>=0;i--)
            printf("%d",bi.v[i]);
        printf("\n");
    }
    return 0;
}