#include<stdio.h>
#include<string.h>

void reverse(long long *n, int num);
int main()
{
    long long n[50];//储存表达式中的各个数的数值
    long long res=0;//保存结果
    int val[128]={0};
    val['I']=1;val['V']=5;val['X']=10;val['L']=50;val['C']=100;val['D']=500;val['M']=1000;
    long long t=1;
    int i,j;
    int len=1;
    int num=0;
    char ch;
    char s[51];
    for (i=0;i<50;i++){
        n[i]=0;
    }
    scanf("%s",s);
    for (i=0;i<strlen(s)-1;i++){
        ch=s[i];
        if (ch=='('){//处理遇到的括号,t用于记录倍数
            while (s[i]=='('){
                t=t*1000;
                i++;
            }
            i--;
            continue;
        }
        else if (ch==')'){
            i=i+t-1;
            t=1;
            continue;
        }
        else if (ch == s[i+1] ){//用于处理相同字符,
            len++;
            continue;
        }
        else{
            n[num]=len*val[ch]*t;
            len=1;
            t=1;
            num++;
        }
        
    }
    reverse(n,num);
    res=n[0];
    for (j=0;j<num-1;j++){
        if (n[j] <n[j+1]){
            res=res+n[j+1];
        }
        else{
            res=res-n[j+1];
        }
    }
    printf("%lld",res);
    return 0;
}

void reverse(long long *n, int num)
{
    int i;
    long long t;
    for (i=0;i<=num/2;i++){
        t=n[i];
        n[i]=n[num-i];
        n[num-i]=t;
    }
    return;
}