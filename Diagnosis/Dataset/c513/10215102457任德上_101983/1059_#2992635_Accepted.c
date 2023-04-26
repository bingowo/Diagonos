#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int GCD(int m,int n){
    int a,b,c;
    if(m>n)a=n;
    else
        a=m;
    for(b=2;b<=a;b++){
        if(m%b==0&&n%b==0)return b*GCD(m/b,n/b);
    }
    return 1;
}
int cmp(const void *a,const void *b){
    int *m1,*m2;
    m1=(int *)a;
    m2=(int *)b;
    return (*m1-*m2);
}
int main(){
    int n,s,a[1001],ans=0,ans_fz=0,ans_fm=1;
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    a[n]=100001;
    qsort(a,n,sizeof(int),cmp);
    for(int i=1;i<=n;i++){
        int c=(a[i]-a[i-1])*i;
        if(s>=c){
            s-=c;
        }
        else{
            ans=a[i-1]+s/i;
            ans_fz=s%i;
            ans_fm=i;
            break;
        }
    }
    int g=GCD(ans_fz,ans_fm);
    ans_fm/=g;
    ans_fz/=g;
    if(ans==0&&ans_fz>0){
        printf("%d/%d",ans_fz,ans_fm);
    }
    else{
        printf("%d",ans);
        if(ans_fz>0){
            printf("+%d/%d",ans_fz,ans_fm);
        }
    }
    return 0;
}