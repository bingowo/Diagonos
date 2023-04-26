#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[550],s2[550];
    char t[550];
    int n;
    scanf("%s %s",s1,s2);
    scanf("%d",&n);
    int len1=strlen(s1);
    int len2=strlen(s2);
    int sq1,sq2;         //用来确定小数点位置
    for(int i=0;i<len1;i++){
        if(s1[i]=='.'){
            sq1=i;
            break;
        }
        if(i==len1-1){
            sq1=len1;
        }
    }
    for(int i=0;i<len2;i++){
        if(s2[i]=='.'){
            sq2=i;
            break;
        }
        if(i==len2-1){
            sq2=len2;
        }
    }
    int m=sq1>sq2?sq1:sq2;      //最后加成的整数小数点出现的位置
    t[m]='.';
    int k=len1-1-sq1<len2-1-sq2?len1-1-sq1:len2-1-sq2;        //两个数字小数部分最少位数
    int l=len1-1-sq1>len2-1-sq2?len1-1-sq1:len2-1-sq2;        //小数部分最多位数
    if(len1-1-sq1<len2-1-sq2){
        for(int i=k+1;i<=l;i++){
            s1[sq1+i]='0';
        }
    }else{
        for(int i=k+1;i<=l;i++){
            s2[sq2+i]='0';
        }
    }                   //这里使两个小数部分等长
    int j=n;                               //j表示要补n个小数
    m=m+n;
    t[m+1]='\0';              //结果的末尾
    int jw=0;
    if(n<l){
        if(s1[sq1+n+1]+s2[sq2+n+1]>'0'*2+14){
            jw=2;                               //四舍五入
        }else if(s1[sq1+n+1]+s2[sq2+n+1]>='0'*2+5){
            jw=1;
        }
    }                               //进位
    for(;j>0;j--){
        if(j<=l){
           int gg=s1[sq1+j]+s2[sq2+j]-2*48+jw;
           jw=0;
           while(gg>=10){                //存在特殊情况9+9+2时进两位
              gg-=10;
              jw++;
           }
           t[m]=gg+'0';
        }else{                  //小数部分大于l
           t[m]='0';   //补零
        }
        m--;
    }
    sq1--;
    sq2--;        //回到小数点前一位
    m=sq1>sq2?sq1:sq2;       //回到整数部分个位
    if(sq1<0&&sq2<0&&jw==0){         //整数部分为0
        printf("0");
    }
    for(;m>=0;m--){
        if(sq1>=0&&sq2>=0){
            int gg=s1[sq1]+s2[sq2]-2*48+jw;
            jw=0;
            while(gg>=10){
               gg-=10;
               jw++;
            }
            t[m]=gg+'0';
            sq1--;
            sq2--;        //前移了
        }else if(sq1>=0){
            int gg=s1[sq1]-48+jw;
            jw=0;
            if(gg>=10){
               gg-=10;
               jw=1;
            }
            t[m]=gg+'0';
            sq1--;
        }else if(sq2>=0){
            int gg=s2[sq2]-48+jw;
            jw=0;
            if(gg>=10){
               gg-=10;
               jw=1;
            }
            t[m]=gg+'0';
            sq2--;
        }
    }
    if(jw==1){
        printf("1");
    }
    printf("%s",t);
    return 0;
}
