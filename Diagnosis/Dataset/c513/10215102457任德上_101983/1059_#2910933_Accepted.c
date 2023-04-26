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
    int n,s,num1,num2,mon=0,son=0,height=0;
    scanf("%d%d",&n,&s);
    getchar();
    int *a,*b;
    a=(int *)malloc((n)*sizeof(int));
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}
    qsort(a,n,sizeof(int),cmp);
    b=a+n;
    num1=*a;
    a++;
   while(b>a&&s>0){
        while((*a)==num1)a++;
        if(b>a){
        num2=*a;
        int y=b-a;
        if(s>=(n-y)*(num2-num1)){s-=(n-y)*(num2-num1);height=num2;}
        else{
            int t;
            t=GCD(s,n-y);
            mon=(n-y)/t;
            son=s/t;
            s=0;
            height=num1;
        }
        num1=num2;
        }
        else break;
   }
   if(s>0){
        int k=s/n;
        height=height>num1?height:num1;
        height=height+k;
        int h=s%n;
        int t;
        t=GCD(h,n);
        mon=n/t;
        son=h/t;
   }
   while(mon<=son&&son!=0){height++;son-=mon;}
    if(son==0)printf("%d",height);
    else if(height==0)printf("%d/%d",son,mon);
    else printf("%d+%d/%d",height,son,mon);
    return 0;
}