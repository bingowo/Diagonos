#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int p1,p2;
int toleft(int a[],int s,int p,int n){
    int left,right;
    left=p;
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
    if(s>=width){
        for(int i=left+1;i<right;i++){
            a[i]+=1;
        }
        s-=width;
        if(a[left+1]>=a[left]||a[right-1]==a[right]){
            p1=left+1;
            toleft(a,s,p1,n);
            return ;}
    }
    return s;
}
int toright(int a[],int s,int p,int n){
    int left,right;
    right=p;
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
    while(s>=width){
        for(int i=left+1;i<right;i++){
            a[i]+=1;
        }
        s-=width;
        if(a[left+1]==a[left]||a[right-1]==a[right]){
            p2=left+1;
            toleft(a,s,left+1,n);
            return ;}
    }
    return s;
}
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
typedef struct{
    int fenzi;
    int fenmu;
}fs;
int main(){
    int n,s,p;
    scanf("%d%d%d",&n,&s,&p);getchar();
    int *a=(int*)malloc(sizeof(int)*(n+2));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int flag=0;
    if(s%2==1){
        s-=1;flag=1;
    }
    fs fenshu[1000]={0};
    a[0]=1001;a[n+1]=1001;
    int s1=toleft(a,s/2,p,n);
    int s2=toright(a,s-s/2,p,n);
    if(flag){
        int left,right;
        left=right=p;
        while(left>0){
            if(a[left-1]>a[left]){
                left-=1;break;
            }
            left--;
        }
        fenshu[left+1].fenzi=1,fenshu[left+1].fenmu=2;
        while(right<n+1){
            if(a[right+1]>a[right]){
                right+=1;break;
            }
            right++;
        }
        fenshu[right-1].fenzi=1,fenshu[right-1].fenmu=2;
    }
    int l1,r1,l2,r2;
    l1=p1;
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
    r2=p2;
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
    if(l1==l2&&r1==r2){
        int width=r1-l1-1;
        s=s1+s2;
        while(s>=width){
            for(int i=l1+1;i<r1;i++){
                a[i]+=1;
            }
            s-=width;
        }
        if(s>0){
            int g=gcd(s,width);
            for(int i=l1+1;i<r1;i++){
                fenshu[i].fenzi=s;
                fenshu[i].fenmu=width;
            }
            for(int i=1;i<=n;i++){
                printf("%d",a[i]);
                if(fenshu[i].fenzi){
                    printf("+%d/%d",fenshu[i].fenzi/g,fenshu[i].fenmu/g);
                }
                putchar(' ');
            }
        }
        else{
            for(int i=1;i<=n;i++){
                printf("%d",a[i]);
                if(fenshu[i].fenzi){
                    printf("+%d/%d",fenshu[i].fenzi,fenshu[i].fenmu);
                }
                putchar(' ');
            }
        }
    }
    else{
        int width=r1-l1-1;
        int g1,g2;
        if(s1>0){
            g1=gcd(width,s1);
            for(int i=l1+1;i<r1;i++){
                fenshu[i].fenzi=s1;
                fenshu[i].fenmu=width;
            }
        }
        for(int i=1;i<r1;i++){
            printf("%d",a[i]);
            if(fenshu[i].fenzi){
                printf("+%d/%d",fenshu[i].fenzi/g1,fenshu[i].fenmu/g1);
            }
            putchar(' ');
        }
        width=r2-l2-1;
        if(s2>0){
            g2=gcd(width,s2);
            for(int i=l2=1;i<r2;i++){
                fenshu[i].fenzi=s2;
                fenshu[i].fenmu=width;
            }
        }
        for(int i=r1;i<=n;i++){
            printf("%d",a[i]);
            if(fenshu[i].fenzi){
                printf("+%d/%d",fenshu[i].fenzi/g2,fenshu[i].fenmu/g2);
            }
            putchar(' ');
        }
    }
}