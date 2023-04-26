//#include <iostream>
//#include <cstring>
//using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare1(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p1-*p2;
}
int compare2(const void *a,const void *b)
{
    int *p1=(int *)a;
    int *p2=(int *)b;
    return *p2-*p1;
}
int main()
{
    int T;
    //cin>>T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        int a[1000],b[1000];
        //cin>>n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            //cin>>a[i];
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            //cin>>b[i];
            scanf("%d",&b[i]);
        }
        qsort(a,n,sizeof(int),compare1);
        qsort(b,n,sizeof(int),compare2);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i]*b[i];
        }
        //cout<<"case #"<<t<<":"<<endl;
        printf("case #%d:\n",t);
        //cout<<sum<<endl;
        printf("%d\n",sum);
    }
    return 0;
}