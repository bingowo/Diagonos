#include<stdio.h>
#define L 500
void input(int a[]){
    char s[2*L+1];
    scanf("%s",s);
    int i=0,j,k;
    while(s[i]&&s[i]!='.')i++;
    for(j=i+1,k=L+1;j<strlen(s);j++,k++)a[k]=s[j]-'0';  //获取小数部分
    for(j=i-1,k=L;j>=0;j--,k--)a[k]=s[j]-'0';     //获取整数部分
}
int compare(int a[],int b[]){
    for(int i=0;i<2*L+1;i++){
        if(a[i]>b[i])return 1;
        if(a[i]<b[i])return -1;
    }
    return 0;
}
void sub(int a[],int b[],int c[]){
    for(int i=2*L;i>=0;i--)c[i]=a[i]>=b[i]?a[i]-b[i]:a[i]-b[i]+10*(a[i-1]-(--a[i-1]));

}
int main(){
    int a[2*L+1]={0},b[2*L+1]={0},c[2*L+1]={0},flag,k=0,j=2*L,n;
    input(a);
    input(b);
    scanf("%d",&n);
    flag=compare(a,b);
    if(flag==1)sub(a,b,c);
    else sub(b,a,c);
    if(flag==-1)printf('-');
    else if(flag==0){printf("0");}
    else{
        while(c[k]==0&&k<L)k++;  //除去前置0
        if(c[L+n+1]>=5){            //考虑四舍五入
            int carry=1;
            c[L+n]=c[L+n]+carry;
            for(int i=L+n;i>=0;i--){    //进位操作
                if(c[i]>=10){c[i-1]+=1;c[i]%=10;}
                else break;
            }
        }
        else j=L+n;
        for(;k<=L;k++)printf("%d",c[k]);
        printf(".");
        k=L+1;
        for(;k<=j&&k<=L+n;k++)printf("%d",c[k]);
    }
    return 0;
}