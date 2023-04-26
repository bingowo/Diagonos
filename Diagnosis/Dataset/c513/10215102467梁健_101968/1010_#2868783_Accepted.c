#include<stdio.h>
#include<string.h>
int main()
{
    char a[501];
    scanf("%s",a);
    printf("0001");//第一段0001；
    //第二段数字长度：
    int length=strlen(a);
    char l2[10];
    for(int i=0;i<10;i++){
        l2[i]=0;
    }
    int m=0;
    while(length>0){
        l2[m++]=length%2;
        length=length/2;
    }
    for(m=9;m>=0;m--){
        printf("%d",l2[m]);
    }
    //具体数字段。
    int len=strlen(a);
    int res=len%3,time=(len+2)/3;
    char p[4],b[7],c[10];
    for(int step=0;step<time;step++){
        for(int step1=0;step1<4;step1++){
            p[step1]=0;
        }
        for(int step2=0;step2<7;step2++){
            b[step2]=0;
        }
        for(int step3=0;step3<10;step3++){
            c[step3]=0;
        }
        int num=0,m=0;
        if(len-3*step==0||len-3*step>2){
            num=100*(a[3*step]-48)+10*(a[3*step+1]-48)+a[3*step+2]-48;
            while(num>0){
                c[m++]=num%2;
                num/=2;
            }
            m=10;
            while(m>0)printf("%d",c[(m--)-1]);
        }
        else if(len-3*step==2){
            num=10*(a[3*step])-480+a[3*step+1]-48;
            while(num>0){
                b[m++]=num%2;
                num/=2;
            }
            m=7;
            while(m>0)printf("%d",b[(m--)-1]);
        }
        else if((len-3*step)==1){
            num=a[3*step]-48;
            while(num>0){
                p[m++]=num%2;
                num/=2;
            }
            m=4;
            while(m>0)printf("%d",p[(m--)-1]);
        }
    }


    return 0;
}
