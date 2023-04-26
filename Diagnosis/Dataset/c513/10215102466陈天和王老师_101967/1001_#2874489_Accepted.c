#include <stdio.h>
#include <stdlib.h>
int f(int n,int r);
int main()
{
    int num;
    int j;
    int rec=100;
    scanf("%d",&num);

    int a[100][2];//这玩意万一比一百多咋整，这种未知总数的输入，如何接受呢，数组可以定义为a[n]吗
    for(int i=0;i<num;i++){
        scanf("%d %d", &a[i][0],&a[i][1]);
    }
    //input
    for(int i=0;i<num;i++) {
        char str[100];//这玩意万一比一百多咋整，这种未知总数的输入，如何接受呢，数组可以定义为a[n]吗

        if(a[i][0]>0){rec=1;}
        if(a[i][0]<0){
            rec=0;
            a[i][0]=-a[i][0];
        }//process sgn

        for (j = 0; a[i][0] != 0; j++) {
            if (a[i][0] % a[i][1] < 10) { str[j] = '0' + (a[i][0] % a[i][1]); }//把数字放在字符型里当然得用asc转换一下
            else { str[j] = 'A' + a[i][0] % a[i][1] - 10; }
            a[i][0] = a[i][0] / a[i][1];
        }

        if(rec==0){printf("-");}

        for(int k=j-1;k>=0;k--){
            printf("%c",str[k]);
        }
        printf("\n");
    }
    return 0;

}
//多次循环中如果用同一个变量或者数组，那么有时需要考虑这一次循环造成的改变会不会影响下一次循环！！！！

//一些debugg后发现的问题
// 变量交给时数据类型由整形变成字符型但是没管
// 注意正负号了吗

