#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
    int height=1;
    int v=width*height;
    if(s>v){
        s-=v;
        for(int i=left+1;i<right;i++){
            a[i]+=height;
        }
    }
    else{
        return s;
    }
    if(s>0)toleft(a,s,left+1,n);
    else return s;
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
    int height=1;
    int v=width*height;
    if(s>v){
        s-=v;
        for(int i=left+1;i<right;i++){
            a[i]+=height;
        }
    }
    else{
        return s;
    }
    if(s>0)toright(a,s,left+1,n);
    else return s;
}
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    int n,s,p;
    scanf("%d%d%d",&n,&s,&p);getchar();
    int *a=(int*)malloc(sizeof(int)*(n+2));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[0]=1001;a[n+1]=1001;
    int s1=toleft(a,s/2,p,n);
    int s2=toright(a,s-s/2,p,n);
    int l1,r1,l2,r2;
    l1=p;
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
    r2=p;
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
    if(l1==l2&&r1==r2){
        int width=r1-l1-1;
        s=s1+s2;
        if(s%width==0){
            for(int i=l1+1;i<r1;i++){
                a[i]+=s/width;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
        putchar(' ');
    }
}