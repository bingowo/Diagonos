#include<string.h>
#include<stdio.h>
#define C 200
#define R 60
int compare(const int* a,const int* b)
{
    int i=0;
    if(a[0]!=b[0])return -1*a[0];
    else 
    {
        while(a[i]==b[i])i++;
        if(a[i]<b[i])return 1*a[0];
        else return -1*a[0];
    }
}
void sub(int* dest_arr,int* a,int* b)
{
    int i,j;
    memcpy(dest_arr,a,4*C);
    for(i=C-1;i>-1;--i)
    {
        if(dest_arr[i]<b[i])
        {
            j=i;
            while(dest_arr[--i]);
            dest_arr[i]--;for(++i;i<j;++i)dest_arr[i]=9;
            dest_arr[i]=10+dest_arr[i]-b[i];
        }
        else dest_arr[i]-=b[i];
    }
}
void add(int* dest_arr,int* a,int* b)
{
    int i,carry=0,tmp;
    memcpy(dest_arr,a,4*C);
    for(i=C-1;i>-1;--i)
    {
        tmp=dest_arr[i]+b[i]+carry;
        if(tmp>=10){dest_arr[i]=tmp%10;carry=tmp/10;}
        else {dest_arr[i]=tmp;carry=0;}
    }
}
void get_ans(int* dest_arr,int *a,int* b)
{
    int i,j,carry;
    if(a[0]==1&&b[0]==1)sub(dest_arr,a,b);
    else if(a[0]==1&&b[0]==-1)add(dest_arr,a,b);
    else sub(dest_arr,b,a);
}
int main()
{
    int n,i,j,k,len,ans[C]={0};scanf("%d",&n);
    char str[C];
    int a[R][C]={0};
    for(i=0;i<n;++i)
    {
        scanf("%s",str);
        len=strlen(str);
        if(str[0]=='-'){a[i][0]=-1;k=1;len--;}
        else {a[i][0]=1;k=0;}
        for(j=C-len;j<C;++j,++k)a[i][j]=str[k]-48;
    }
    int s=0,b=0;
    for(i=1;i<n;++i)
    {
        if(compare(a[i],a[s])==1)s=i;
        if(compare(a[i],a[b])==-1)b=i;
    }
    get_ans(ans,a[b],a[s]);
    for(i=0;i<C;++i)if(ans[i])break;
    for(i;i<C;++i)printf("%d",ans[i]);
    return 0;
}