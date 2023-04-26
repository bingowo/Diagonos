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
    char *m1,*m2;
    m1=(char*)a;
    m2=(char*)b;
    return (int)(*m1-*m2);
}
int main(){
    int n,s,num1,num2,mon=0,son=0,height=0;
    scanf("%d%d",&n,&s);
    getchar();
    char *a,*b;
    a=(char *)malloc((n+1)*sizeof(char));
    for(int i=0;i<n;i++){scanf("%c",&a[i]);getchar();}
    *(a+n)=0;
    qsort(a,n,sizeof(char),cmp);
    b=a+n;
    num1=(int)(*a-'0');
    a++;
   while(*a&&s>0){
        while((*a-'0')==num1)a++;
        if(*a!=0){
        num2=*a-'0';
        int y=b-a;
        if(s>=(n-y)*(num2-num1)){s-=(n-y)*(num2-num1);height=num2;}
        else{
            int t;
            t=GCD(s,(n-y)*(num2-num1));
            mon=(n-y)*(num2-num1)/t;
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
        height=height+k+num1;
        int h=s%n;
        int t;
        t=GCD(h,n);
        mon=n/t;
        son=h/t;
   }

    if(son==0)printf("%d",height);
    else printf("%d+%d/%d",height,son,mon);
    return 0;
}
