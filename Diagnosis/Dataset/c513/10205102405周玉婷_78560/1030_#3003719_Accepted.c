#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char s[21];
    int len;
    }  Num;
typedef long long int lli;
lli atolli(char s[],int len)
{
    int flag=0;
    lli temp=0;
    if(s[0]=='-') flag=1;
    for(int i=flag; i<len; i++)//霍纳规则
    {
        temp=temp*10+s[i]-'0';
    }
    if(flag==1) temp=-temp;
    return temp;
}

int cmp(const void* a,const void*b)
{
    Num pa=* (Num*)a;
    Num pb=* (Num*)b;
    char aa,bb;
    aa=pa.s[0]=='-'?pa.s[1]:pa.s[0];
    bb=pb.s[0]=='-'?pb.s[1]:pb.s[0];
    if(aa==bb)
    {
     return atolli(pa.s,pa.len)>atolli(pb.s,pb.len)?1:-1;   
    }
    else return aa<bb?1:-1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; j++)
    {
        int n;
        scanf("%d",&n);
        Num * p=(Num *)malloc(sizeof(Num)*n);
        for(int i=0; i<n; i++)
        {
            scanf("%s",p[i].s);
            p[i].len=strlen(p[i].s);
        }
        qsort(p,n,sizeof(Num),cmp);
        printf("case #%d:\n",j);
        for(int i=0; i<n; i++)
        {
            printf("%s%c",p[i].s,i==n-1?'\n':' ');
        }
    }
    return 0;
}