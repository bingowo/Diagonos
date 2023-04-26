#include<stdio.h>
typedef struct{
    int v;
    int fz;
    int fm;
}Number;
int GCD(int m,int n){
    int a,b;
    if(m>n)a=n;
    else
        a=m;
    for(b=2;b<=a;b++){
        if(m%b==0&&n%b==0)return b*GCD(m/b,n/b);
    }
    return 1;
}
void pour(Number* a,Number s,int n,int p){
    if(s.fz==0)s.fm=1;
    int left_p,right_p,left_v=0,right_v=0,v,left,right;
    for(int i=p-1,flag=0;i>=0;i--){
        if(a[i].v<a[p].v&&flag==0){left=i,flag=1;}
        else if(a[i].v==a[p].v&&flag==1){
            left_p=i;
            break;
        }
        else if(a[i].v>a[p].v){
            left_p=i;
            break;
        }
        left_v+=a[p].v-a[i].v;
    }
    for(int i=p+1,flag=0;i<=n+1;i++){
        if(a[i].v<a[p].v&&flag==0){flag=1,right=i;}
        else if(a[i].v==a[p].v&&flag==1){
            right_p=i;
            break;
        }
        else if(a[i].v>a[p].v){
            right_p=i;
            break;
        }
        right_v+=a[p].v-a[i].v;
    }
    v=right_v+left_v;
    if(v==0){
        int min=a[left_p].v>a[right_p].v?a[right_p].v:a[left_p].v;
        int s1;
        s1=(min-a[p].v)*(right_p-left_p-1);
        if(s.v>=s1){
            s.v-=s1;
            int t=min-a[p].v;
            for(int i=left_p+1;i<right_p;i++)a[i].v+=t;
            if(s.v>0||s.fz>0)pour(a,s,n,p);
        }
        else{
            int m=right_p-left_p-1;
            s.fz=s.v*s.fm+s.fz;
            s.fm*=m;
            s.v=s.fz/s.fm;
            s.fz=s.fz%s.fm;
            int g=GCD(s.fz,s.fm);
            s.fz/=g;
            s.fm/=g;
            for(int i=left_p+1;i<right_p;i++){
                a[i].v+=s.v;
                if(s.fm==a[i].fm)a[i].fz+=s.fz;
                else{
                    a[i].fz*=s.fm;
                    s.fz*=a[i].fm;
                    a[i].fz+=s.fz;
                    a[i].fm*=s.fm;
                }

            }
            return;
        }
    }
    else if(s.v>=v){
        s.v-=v;
        for(int i=left_p+1;i<right_p;i++){
            a[i].v=a[p].v;
        }
        if(s.v>0||s.fz>0)pour(a,s,n,p);
    }
    else{
        Number half;
        half.v=s.v/2,half.fz=s.fz*2+(s.v%2)*s.fm,half.fm=s.fm*2;
        if(half.v>=left_v&&left_v!=0){
            for(int i=left_p+1;i<p;i++){
                a[i].v=a[p].v;
            }
            s.v-=2*left_v;
            Number s1;
            s1.v=left_v,s1.fz=0,s1.fm=1;
            pour(a,s1,n,right);
            pour(a,s,n,p);
        }
        else if(half.v>=left_v&&left_v==0){
            pour(a,s,n,right);
        }
        else if(half.v>=right_v&&right_v!=0){
            for(int i=p+1;i<right_p;i++){
                a[i].v=a[p].v;
            }
            s.v-=2*right_v;
            Number s1;
            s1.v=right_v,s1.fz=0,s1.fm=1;
            pour(a,s1,n,left);
            pour(a,s,n,p);
        }
        else if(half.v>=right_v&&right_v==0){
            pour(a,s,n,left);
        }
        else{
            pour(a,half,n,left);
            pour(a,half,n,right);
        }
    }
}
int main(){
    int n,s,p;
    Number a[100];
    scanf("%d%d%d",&n,&s,&p);
    a[n+1].v=100001,a[n+1].fz=0,a[n+1].fm=1;
    a[0].v=100001,a[0].fz=0,a[0].fm=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].fz=0;
        a[i].fm=1;
    }
    Number s1;
    s1.v=s,s1.fz=0,s1.fm=1;
    pour(a,s1,n,p);
    for(int i=1;i<=n;i++){
        if(a[i].fz>=a[i].fm){
            a[i].v+=a[i].fz/a[i].fm;
            a[i].fz%=a[i].fm;
        }

    }
    for (int i = 1; i <= n; i++){
        if (a[i].v == 0 && a[i].fz > 0){
            printf("%d/%d", a[i].fz, a[i].fm);
        }
        else
        {
            printf("%d", a[i].v);
            if (a[i].fz > 0)
                printf("+%d/%d", a[i].fz, a[i].fm);
        }
        printf("%c",(i==n) ? '\n':' ');
    }
    return 0;
}
