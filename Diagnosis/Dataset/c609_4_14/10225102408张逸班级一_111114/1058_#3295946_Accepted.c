#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{int cnt,v[101];}BIGINT;//结构体放位数及每一位的值
void DIV2(BIGINT*n){
int carry=0;
if(n->v[n->cnt-1]<2)n->cnt--,carry=1;//商的数位比被除数少一位
for(int i=n->cnt-1;i>=0;i--){
    int t=10*carry+n->v[i];
    n->v[i]=t/2;
    carry=t%2;
}
}
void ADD1(BIGINT *n){
int carry=0,i=1;
n->v[0]=n->v[0]+1;carry=n->v[0]/10;n->v[0]=n->v[0]%10;
while(carry!=0&&i<n->cnt){
    n->v[i]+=carry;carry=n->v[i]/10;n->v[i]=n->v[i]%10;i++;//模拟进位
}
if(carry!=0){n->v[i]=carry;n->cnt++;}//位数增加一位
}

int main()
{   char s[120];
    scanf("%s",s);int sign=1;
    BIGINT n={0,{0}};
    int len=strlen(s)-1;
    for(int i=len;i>=1;i--)n.v[n.cnt++]=s[i]-'0';//存放各数位，输入
    if(s[0]=='-'){sign=-1;}           //负数首位符号位特判
    else{n.v[n.cnt++]=s[0]-'0';} //正数首位数字位继续输入存储，cnt逐渐增加到最大位数的值,v[0]是个位
    int bin[400]={0},cnt=0;
    while(n.cnt>0){
        int temp=n.v[0]%2;
        bin[cnt++]=temp;
        DIV2(&n);
        if(sign==-1&&temp){
            if(n.cnt==0){n.cnt++;n.v[0]=1;}
            else ADD1(&n);
        }
        sign=-sign;
    }
    for(int i=cnt-1;i>=0;i--){
        printf("%d",bin[i]);
    }
    return 0;
}