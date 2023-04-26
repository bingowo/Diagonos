#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
 { int cnt,v[101]; } BIGINT;

 void DIV2(BIGINT *n){
int carry=0,i;
if (n->v[n->cnt-1]<2){
n->cnt--;
carry=1;
}
for (i=n->cnt-1;i>=0;i--) {//eg: v[]此时是3099 实质上还是9903->4951 来回反转有点恶心
int t=10*carry+n->v[i];//从9开始9-9-0-3
n->v[i]=t/2;
carry=t%2;
}
}//v[]->4951


void MUL2ADD(BIGINT *n, int d) {
int carry=d,i;
for (i=0;i<n->cnt;i++) {
int t=carry+n->v[i]*2;
n->v[i]=t%10;
carry=t/10;
}
if (carry>0) n->v[n->cnt++]=carry;
}

int main()
{
    int T;
    scanf("%d",&T);
    int l;
    for(l=0;l<T;l++){
    printf("case #%d:\n",l);
    char line[102];
    int i;
    BIGINT n;
    scanf("%s",line);//9903转为二进制
    n.cnt=strlen(line);
    for (i=0;i<n.cnt;i++)
    n.v[i]=line[n.cnt-i-1] -'0';//v[]3099
    int s[334],cnt=0;
    while (n.cnt>0) {
    s[cnt++]=n.v[0]%2;
    DIV2(&n);//把大整数除2---v[]1594 5742 7321 816 903 451 771(1) 38(11) 91(11) 9 4 2 1 
        }//都是反着的 方便大数组除法 
      for (i=0;i<cnt;i++) MUL2ADD(&n,s[i]);//把s中的二进制转化为十进制 并放入V中 更新V
      if (n.cnt==0){
n.cnt++;
}
for (i=n.cnt-1;i>=0;i--) {
printf("%d",n.v[i]);
}
printf("\n");
    }
}
