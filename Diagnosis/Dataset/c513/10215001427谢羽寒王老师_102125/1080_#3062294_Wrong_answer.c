#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int cnt,v[101]; } BIGINT;   //cnt存放位数 v存放每一位数字

void chu2(BIGINT *n){         //做一次除以2的除法 一位一位除
	int carry=0,i;
	if (n->v[n->cnt-1]<2){ //判断最高位是否小于2 如果小于2 跳过最高位 才做除法运算
	    n->v[n->cnt-1]=0;     //最高位改掉（除后最高位为0
		n->cnt--;
		carry=1;               //最高位小于2 只有可能是1
	}
	for (i=n->cnt-1;i>=0;i--) {
		int t=10*carry+n->v[i];
		n->v[i]=t/2;
		carry=t%2;
	}
}



void cheng2(BIGINT *n, int d) {
	int carry=d,i;
	for (i=0;i<n->cnt;i++) {          //这个cnt是多少？
		int t=carry+n->v[i]*2;       //最开始的时候这个n.v在之前的过程中已经被除尽 为0了
		n->v[i]=t%10;
		carry=t/10;
	}
	if (carry>0) n->v[n->cnt++]=carry;           //10进1位
}



int main()
{
    int k,T;


    scanf("%d",&T);

    for(k=0;k<T;k++){
        char line[102];
        int i;
        BIGINT n;
        memset(n.v,0,sizeof(int));              //清零
        scanf("%s",line);                       //用字符类型 输入 转成 整形数组
        n.cnt=strlen(line);

        for (i=0;i<n.cnt;i++){
            n.v[i]=line[n.cnt-i-1] -'0';}      //记住！ps 顺便调换了顺序 让个位摆在前面


        int s[334],cnt=0;
        while (n.cnt>0) {                     //十进制转二进制 得到一个倒放的二进制（个位在0下标的地方存放
                                                //s 存放334位二进制 n.v 存放的是101十进制
            s[cnt++]=n.v[0]%2;               //除末位先得到二进制结果 下一行再做真的整个数的除法
            chu2(&n);
                }


        for (i=0;i<cnt;i++) cheng2(&n,s[i]);       //二进制变成十进制 存在 n.v

        printf("case #%d:\n",k);


            if (n.cnt==0){
                n.cnt++;                              //0的情况？
                            }
        for (i=n.cnt-1;i>=0;i--) {
                printf("%d\n",n.v[i]);
                }




    }


}