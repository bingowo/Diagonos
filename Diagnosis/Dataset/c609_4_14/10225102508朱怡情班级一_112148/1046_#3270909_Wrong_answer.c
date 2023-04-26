#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char s[101];
    char que[101];
    int l;
}A;

int cmp(const void* a,const void* b)
{
    A x=*(A*)a;
    A y=*(A*)b;
    return x.l-y.l;
}

int main()
{
    int n;
    scanf("%d",&n);
    A a[100000];
    int len=0;
    for(int i=0;i<n;i++){
        scanf("%s",a[i].s);
        a[i].l=strlen(a[i].s);
        char temp=0;
        int k=0;
        for(int j=0;a[i].s[j];j++){
            if(temp!=a[i].s[j]){
                a[i].que[k++]=temp;
                temp=a[i].s[j];
            }
        }
        a[i].que[k]=0;
        if(len==0)len=k;
        else if(len!=k){
            printf("-1");
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<len;j++){
            if(a[i].que[j]!=a[0].que[j]){
                printf("-1");
                return 0;
            }
        }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int ans=-1;
    for(int i=a[0].l;i<=a[n-1].l;i++){
        int sum=0;
        for(int j=0;j<n;j++)sum+=abs(i-a[j].l);
        if(ans==-1)ans=sum;
        else ans=ans<sum?ans:sum;
    }
    printf("%d",ans);
    return 0;
}
