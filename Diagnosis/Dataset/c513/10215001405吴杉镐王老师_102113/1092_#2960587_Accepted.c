#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 100000000 //M的使用也非常巧妙
char s[1005];
int a,b,n,l;
struct node {
    long long num[1005];
    int cnt,flg;
} A;
void out(struct node x){
//    if(x.flg==-1)
//        putchar('-');
    printf("%lld",x.num[x.cnt]); //首位的正常输出即可
    for(int i=x.cnt-1;i;i--)
        printf("%08lld",x.num[i]); //尤其注意这里的08不能少 否则就可能出现由于0在末尾，位数减少的情况
    puts("");
}
void init(struct node* x,int val) {
    x->cnt=1;
    x->num[1]=val;
    if(val<0)
    {
        x->flg=-1;
        x->num[1]*=-1;
    }
    else x->flg=1;
}
void multi(struct node* x,int val) {
//    if(val<0)
//    {
//        x->flg*=-1;
//        val=-val;
//    }
    x->num[x->cnt+1]=0;
    for(int i=1; i<=x->cnt; i++) //给所有的位都要乘相同倍数
        x->num[i]*=val;
    ///
    for(int i=1; i<=x->cnt; i++)
    {
        x->num[i+1]+=x->num[i]/M;
        x->num[i]%=M;
    }
    if(x->num[x->cnt+1]>0)
        x->cnt++;
    while(x->num[x->cnt]==0 && x->cnt>1)
        x->cnt--;
    /// 标准的大整数运算的进位方法
}

int main() {
    init(&A,1);
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        int cnt=1;
        if(i>0 && s[i-1]!=s[i]) //与前面元素不等
            cnt++;
        if(s[i+1] && s[i+1]!=s[i]) //与后面元素不等
            cnt++;
        if(i>0 && s[i+1] && s[i-1]==s[i+1] && s[i-1]!=s[i] && s[i+1]!=s[i]) //前后元素相等但与自身不等
            cnt--;
        multi(&A,cnt);  //cnt的如何取值是这道题的关键
    }
    out(A);
    return 0;
}
