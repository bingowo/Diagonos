#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f(char* t)
{
    char t1[110];        //用于存储修改后的字符串
    t1[0]=t[0];
    int m=0;             //修改后数组的索引
    int g=0;              //判断这个元素是不是第一次出现
    for(int i=1;i<strlen(t);i++){
        if(t[i]==t1[m]){
           g=1;
           continue;
        }else{
           if(g==0){
              m++;
              t1[m]=t[i];
           }else{
              t1[m]=t[i];
              g=0;
           }

        }
    }
    if(g==1){           //t1最后一个元素是重复元素不要
        for(int i=0;i<m;i++){
            t[i]=t1[i];
        }
        t[m]='\0';

    }else{
        for(int i=0;i<m+1;i++){
            t[i]=t1[i];
        }
        t[m+1]='\0';
    }
}

int pd(char*  t)            //用来判断有无重复元素
{
    int x=0;
    int y=strlen(t);
    for(int i=0;i<y-1;i++){
        if(t[i]==t[i+1]){
            x=1;
            break;
        }
        if(i==strlen(t)-2){
            x=0;              //到末尾了都没发现 无重复元素 返回0
        }
    }
    return x;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[110];
        scanf("%s",s);
        int len=strlen(s);
        int Max=0;               //删除最多的元素
        s[len]='g';                //随便赋一个 反正会变
        s[len+1]='\0';
        for(int i=0;i<=len;i++){
            char s1[len+1];                         //赋值得到一个新的新字符串 是加一个元素过后的 void函数直接对这个字符串进行处理
            strcpy(s1,s);
            for(int j=len;j>i;j--){
                s1[j]=s1[j-1];                    //len位置是空出来的 用来增加一个字符i是增加的位置  i后面的元素全都向后移一位 恰好够放
            }
            s1[i]='A';
            int x=1;
            while(x==1){                                //一直while 直到无重复元素结束掉 此时x被赋值为0
                x=pd(s1);
                if(x==1){
                    f(s1);
                }
            }
            int y=len+1-strlen(s1);
            if(y>Max){
                Max=y;
            }
        }
        for(int i=0;i<=len;i++){
            char s1[len+1];                         //赋值得到一个新的新字符串 是加一个元素过后的 void函数直接对这个字符串进行处理
            strcpy(s1,s);
            for(int j=len;j>=i;j--){
                s1[j]=s1[j-1];                    //len位置是空出来的 用来增加一个字符i是增加的位置  i后面的元素全都向后移一位 恰好够放
            }
            s1[i]='B';
            int x=1;
            while(x){                                //一直while 直到无重复元素结束掉 此时x被赋值为0
                x=pd(s1);
                if(x==1){
                    f(s1);
                }
            }
            int y=len+1-strlen(s1);
            if(y>Max){
                Max=y;
            }
        }
        for(int i=0;i<=len;i++){
            char s1[len+1];                         //赋值得到一个新的新字符串 是加一个元素过后的 void函数直接对这个字符串进行处理
            strcpy(s1,s);
            for(int j=len;j>=i;j--){
                s1[j]=s1[j-1];                    //len位置是空出来的 用来增加一个字符i是增加的位置  i后面的元素全都向后移一位 恰好够放
            }
            s1[i]='C';
            int x=1;
            while(x){                                //一直while 直到无重复元素结束掉 此时x被赋值为0
                x=pd(s1);
                if(x==1){
                    f(s1);
                }
            }
            int y=len+1-strlen(s1);
            if(y>Max){
                Max=y;
            }
        }
        printf("case #%d:\n%d\n",i,Max);

    }
    return 0;
}
