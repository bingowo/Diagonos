#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
typedef struct{
    int pos;
    int ss;
}node;
typedef struct{
    int fz;
    int fm;
}fs;
void toleft(int a[],node *p,int n);
void toright(int a[],node *p,int n);
void toleft(int a[],node *p,int n){
    int left,right;
    left=p->pos;
    while(left>0){
        if(a[left-1]>a[left]){
            left-=1;break;
        }
        left--;
    }
    right=left;
    while(right<n+1){
        if(a[right+1]>a[right]){
            right+=1;break;
        }
        right++;
    }
    left=right;
    while(left>0){
        if(a[left-1]>a[left]){
            left-=1;break;
        }
        left--;
    }
    int width=right-left-1;
    while(p->ss>=width){
        for(int i=left+1;i<right;i++){
            a[i]+=1;
        }
        p->ss-=width;
        if(a[left+1]==a[left]){
            p->pos=left;
            toleft(a,p,n);
            return ;
        }
        else if(a[right-1]==a[right]){
            p->pos=right;
            toright(a,p,n);
            return ;
        }
    }
    return ;
}
void toright(int a[],node *p,int n){
    int left,right;
    right=p->pos;
    while(right<n+1){
        if(a[right+1]>a[right]){
            right+=1;break;
        }
        right++;
    }
    left=right;
    while(left>0){
        if(a[left-1]>a[left]){
            left-=1;break;
        }
        left--;
    }
    right=left;
    while(right<n+1){
        if(a[right+1]>a[right]){
            right+=1;break;
        }
        right++;
    }
    int width=right-left-1;
    while(p->ss>=width){
        for(int i=left+1;i<right;i++){
            a[i]+=1;
        }
        p->ss-=width;
        if(a[left+1]==a[left]){
            p->pos=left;
            toleft(a,p,n);
            return ;
        }
        else if(a[right-1]==a[right]){
            p->pos=right;
            toright(a,p,n);
            return ;
        }
    }
    return ;
}
int main(){
    int n,s,p;
    scanf("%d%d%d",&n,&s,&p);getchar();
    int *a=(int*)malloc(sizeof(int)*(n+2));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=1000000;a[n+1]=1000000;
    int flag=0;
    if(s%2==1){
        s-=1;
        flag=1;
    }
    node p1,p2;
    p1.ss=p2.ss=s/2;
    p1.pos=p2.pos=p;
    toleft(a,&p1,n);
    toright(a,&p2,n);
    int l1,r1,l2,r2;
    l1=p1.pos;
    while(l1>0){
        if(a[l1-1]>a[l1]){
            l1-=1;break;
        }
        l1--;
    }
    r1=l1;
    while(r1<n+1){
        if(a[r1+1]>a[r1]){
            r1+=1;break;
        }
        r1++;
    }
    l1=r1;
    while(l1>0){
        if(a[l1-1]>a[l1]){
            l1-=1;break;
        }
        l1--;
    }
    r2=p2.pos;
    while(r2<n+1){
        if(a[r2+1]>a[r2]){
            r2+=1;break;
        }
        r2++;
    }
    l2=r2;
    while(l2>0){
        if(a[l2-1]>a[l2]){
            l2-=1;break;
        }
        l2--;
    }
    r2=l2;
    while(r2<n+1){
        if(a[r2+1]>a[r2]){
            r2+=1;break;
        }
        r2++;
    }
    fs fenshu[2000]={0};
    if(l1==l2&&r1==r2){
        int width=r1-l1-1;
        s=p1.ss+p2.ss;
        if(flag)s+=1;
        while(s>=width){
            for(int i=l1+1;i<r1;i++){
                a[i]+=1;
            }
            s-=width;
            if(a[l1+1]==a[l1]||a[r1-1]==a[r1]){
                while(l1>0){
                    if(a[l1-1]>a[l1]){
                        l1-=1;break;
                    }
                    l1--;
                }
                while(r1<n+1){
                    if(a[r1+1]>a[r1]){
                        r1+=1;break;
                    }
                    r1++;
                }
                r1-=1;
                width=r1-l1-1;
            }
        }
        int g;
        if(s>0){
            g=gcd(s,width);
            s/=g;
            width/=g;
            for(int i=l1+1;i<r1;i++){
                fenshu[i].fz=s;
                fenshu[i].fm=width;
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d",a[i]);
            if(fenshu[i].fz>0){
                printf("+%d/%d",fenshu[i].fz,fenshu[i].fm);
            }
            putchar(' ');
        }
    }
    else{
        int g1,g2;
        int width=r1-l1-1;
        int fenzi=p1.ss;
        int fenmu=width;
        if(flag){
            fenzi=p1.ss*2+width;
            fenmu=width*2;
        }
        g1=gcd(fenzi,fenmu);
        fenzi/=g1;
        fenmu/=g1;
        for(int i=l1+1;i<r1;i++){
            fenshu[i].fz=fenzi;
            fenshu[i].fm=fenmu;
        }
        for(int i=1;i<r1;i++){
            printf("%d",a[i]);
            if(fenshu[i].fz){
                printf("+%d/%d",fenshu[i].fz,fenshu[i].fm);
            }
            putchar(' ');
        }
        width=r2-l2-1;
        fenzi=p2.ss;
        fenmu=width;
        if(flag){
            fenzi=p2.ss*2+width;
            fenmu=2*width;
        }
        g2=gcd(fenzi,fenmu);
        fenzi/=g2;
        fenmu/=g2;
        for(int i=l2+1;i<r2;i++){
            fenshu[i].fz=fenzi;
            fenshu[i].fm=fenmu;
        }
        for(int i=r1;i<=n;i++){
            printf("%d",a[i]);
            if(fenshu[i].fz){
                printf("+%d/%d",fenshu[i].fz,fenshu[i].fm);
            }
            putchar(' ');
        }
    }
}