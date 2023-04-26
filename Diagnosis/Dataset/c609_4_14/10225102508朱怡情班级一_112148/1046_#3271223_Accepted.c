#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char s[101];
    char que[101];
    int l[101];
}A;

int main()
{
    int n;
    scanf("%d",&n);
    A a[100000];
    int len=0;
    for(int i=0;i<n;i++){
        scanf("%s",a[i].s);
        char temp=0;
        int k=0,m=-1;
        for(int j=0;a[i].s[j];j++){
            if(temp!=a[i].s[j]){
                m++;
                a[i].que[k++]=temp;
                temp=a[i].s[j];
                a[i].l[m]=1;
            }
            else a[i].l[m]++;
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
    int ans=0;
    for(int i=0;i<len;i++){
        int temp=-1;
        for(int j=1;j<=100;j++){
            int sum=0;
            for(int k=0;k<n;k++)
                sum+=abs(j-a[k].l[i]);
            if(temp==-1)temp=sum;
            else temp=temp<sum?temp:sum;
        }
        ans+=temp;
    }
    printf("%d",ans);
    return 0;
}