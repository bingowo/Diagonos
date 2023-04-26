#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void *b)
{
    int* x=(int*)a;
    int* y=(int*)b;
    return x-y;           //把a中小的排在前面

}
int GCD(int m,int n)//最大公约数

{  int t,r;
    if(m<n)
    {
        t=m;
        m=n;
        n=t;
    }


    r=m%n;
    if(r==0)
        {return n;}
    else
    {
        GCD(n,r);          //递归 看高代
    }

}

int main()
{
    int n,s,i;
    scanf("%d %d",&n,&s);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x=0,y=0; //分子分母
    while(s>0){
        qsort(a,n,sizeof(int),cmp);
        int cnt=1;
        for(i=1;i<n;i++){
            if(a[i]==a[i-1]){cnt++;continue;}       //看看此时的最低高度a有几个
            else{ break;}
        }

        if(s>=cnt){
            s=s-cnt;
            for(i=0;i<cnt;i++){
                a[i]+=1;
            }

        }
        else{
            
            int r;
            r=GCD(s,cnt);
            if(r!=1){x=s/r;y=cnt/r;}
            else {x=s;y=cnt;}
            s=0;
        }


    }

    printf("%d",a[0]);
    if(x!=0){printf("+%d/%d",x,y);}
    return 0;
}