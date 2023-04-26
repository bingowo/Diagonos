#include <stdio.h>

typedef struct number
{
    int value;
    int cnt;
    int seq;
} num;
int cmp1(const void *x,const void* y)
{
    num a=*(num*)x;
    num b=*(num*)y;
    return a.seq-b.seq;
}
int cmp2(const void *x,const void* y)
{
    num a=*(num*)x;
    num b=*(num*)y;
    return a.value-b.value;
}
int main()
{
    int m;
    scanf("%d\n",&m);
    int a[m+1];
    for(int i=0; i<m-1; i++) scanf("%d",&a[i]);
    scanf("%d\n",&a[m-1]);
    int n;
    scanf("%d\n",&n);
    num b[n+1];
    for(int i=0; i<n; i++) scanf("%d",&b[i].value);
    int s[1001],order[1001];
    for(int i=0; i<m; i++)
    {
        s[a[i]-1]+=1;
        order[a[i]-1]=i+1;
    }
    int count=0;
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<1000; k++)
        {
            if(b[j].value==k+1&&s[k]!=0) {b[j].cnt++;b[j].seq=order[k];count++;}
        }
    }
    num b1[count+1];
    num b2[n-count+1];
    int bb1=0,bb2=0;
    for(int i=0;i<n;i++)
    {
        if(b[i].cnt) b1[bb1++]=b[i];
        else b2[bb2++]=b[i];
    }
    qsort(b1,bb1,sizeof(num),cmp1);
    qsort(b2,bb2,sizeof(num),cmp2);
    for(int i=0;i<bb1-1;i++) printf("%d ",b1[i].value);
    for(int i=0;i<bb2-1;i++) printf("%d ",b2[i].value);
    return 0;
}
