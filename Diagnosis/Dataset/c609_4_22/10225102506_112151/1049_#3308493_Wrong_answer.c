#include<stdio.h>
#include<string.h>
#define N 10000

int main()
{
    int len_max,i;
    char m[N],n[N],temp[N];
    while(scanf("%s%s",m,n)!=EOF){
    int a[N]={0},b[N]={0},c[N]={0};
    if(strlen(m)>strlen(n))
        len_max=strlen(m);
    else
        len_max=strlen(n);
    if(strlen(n)>strlen(m)||(strlen(m)==strlen(n)&&strcmp(n,m)>0)){
       //使被减数大于减数，长度相同时需用函数strcmp判断大小
        strcpy(temp,m);
        strcpy(m,n);
        strcpy(n,temp);
       //交换数据
        printf("-");  //结果为负
    }
    for(i=0;i<strlen(m);i++){
        a[i]=m[strlen(m)-1-i]-'0';
    }
    for(i=0;i<strlen(n);i++){
        b[i]=n[strlen(n)-1-i]-'0';
    }
    for(i=0;i<=len_max;i++){
        c[i]=a[i]-b[i];
        if(c[i]<0){
            c[i]+=10;    //向上借位
            a[i+1]--;
        }
    }
    int flag=0;
    for(i=len_max;i>=0;i--){  //逆序打印
        if(c[i])
            flag=1;
        if(flag)
            printf("%d",c[i]);
    }
    printf("\n");
    if(!flag) printf("0\n");
    } //特判！
    return 0;
}
