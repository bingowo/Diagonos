#include <stdio.h>
#include <string.h>
#define MAX_N 550
int main() {
    char s1[MAX_N], s2[MAX_N]; // 存储两个浮点数的字符串
    int front1[MAX_N],front2[MAX_N],behind1[MAX_N],behind2[MAX_N],front[MAX_N],behind[MAX_N]; // 存储整数部分和小数部分的数组
    int max=MAX_N;
    for(int i=0;i<MAX_N;i++){
        front1[i]=0;
        front2[i]=0;
        behind1[i]=0;
        behind2[i]=0;
    }
    int len1, len2, len; // 两个浮点数的长度和小数部分精度
    int i, j=0, k; // 循环计数变量
    int f1=0,f2=0,b1=0,b2=0;//各段整数小数长度记录
    int maxf,maxb; 
    int carry = 0; // 进位标志
    scanf("%s%s%d", s1, s2, &len);
    len1 = strlen(s1);
    len2 = strlen(s2);
    int dot1=len1,dot2=len2; // 小数点位置，初始化时默认为整数
    // 将字符串转换为整数部分和小数部分
    for (i=0;i<len1;i++) {
        if (s1[i]=='.') {
            dot1=i;
            break;
        }
        f1++;
        front1[i]=s1[i]-'0';
    } 
    for (i=0;i<len2;i++) {
        if (s2[i]== '.') {
            dot2=i;
            break;
        }
        f2++;
        front2[i]=s2[i]-'0';
    }
    for(i=dot1+1;i<len1;i++){
        behind1[j++]=s1[i]-'0';
        b1++;
    }
    j=0;
    for(i=dot2+1;i<len2;i++){
        behind2[j++]=s2[i]-'0';
        b2++;
    }
    maxb=b1>b2?b1:b2;
    maxf=f1>f2?f1:f2;
    int flag=0;
    for(i=maxb-1;i>=0;i--){
        behind[i]=behind1[i]+behind2[i]+carry;
        if(behind[i]>9){behind[i]%=10;carry=1;}
        else carry=0;
        }//小数部分相加,ans在behind里
    for(i=dot1-1,j=dot2-1;i>=0||j>=0;i--,j--){//整数部分相加，ans在front里
       if(i>=0&&j>=0){
       front[--max]=front1[i]+front2[j]+carry;
       if(front[max]>9){front[max]%=10;carry=1;}
       else carry=0;}
       else if(i<0&&j>=0){
        while(j>=0){
            front[--max]=front2[j--]+carry;
            if(front[max]>9){front[max]%=10;carry=1;if(j<0)front[--max]=1;}
            else carry=0;
        }
       }
       else if(i>=0&&j<0){
        while(i>=0){
           front[--max]=front1[i--]+carry;
           if(front[max]>9){front[max]%=10;carry=1;if(i<0)front[--max]=1;}
           else carry=0;
        }
       }
      if(i<0&&j<0){
        if(carry==1)front[--max]=1;
       }
    }
    // 根据小数部分精度进行四舍五入，输出结果
    if(len>=maxb){
        for(i=max;i<MAX_N;i++){
        printf("%d",front[i]);    
        }
        if(dot1==0&&dot2==0){
        printf("%d",carry);
        }
        printf(".");
        for(i=0;i<maxb;i++){
        printf("%d",behind[i]);
        }
        for(i=maxb;i<len;i++){
        printf("0");
        }
    }
    int findex=MAX_N-1;
    carry=0;
    if(len<maxb)
    {      int clen=len;
           if(behind[len]>=5){
           behind[--len]+=1;
           while(behind[len]>9&&len>0){
             behind[len]%=10;
             behind[--len]+=1;
            }
            if(len==0&&behind[len]>9){
                behind[len]%=10;carry=1;
            }
            if(carry){
                front[findex]+=1;
                while(front[findex]>9){
                   front[findex]%=10;
                   front[--findex]+=1;
                }
                if(findex<max){
                    max=findex;
                }
            }
        }
        for(i=max;i<MAX_N;i++){
        printf("%d",front[i]);    
        }
        if(dot1==0&&dot2==0){
        printf("%d",carry);
        }
        printf(".");
        for(i=0;i<clen;i++){
        printf("%d",behind[i]);
        }
    }
    return 0;
}