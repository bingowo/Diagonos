#include <stdio.h>

int main(){
    int k = 0;
    int loop;
    scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {


    int re=0;
    char a[1000];

        scanf("%s", a);
        int i=0;
        while (a[i])       //当读取到输入的最后一个字符之后，读取到0，跳出循环
        {
            if (a[i] >= '0' && a[i] <= '1') {

                re = re * 3 + a[i] - '0';
            }          //a[i]-'0'利用ASCII码值差值求该位的值
            else if (a[i] == 45) {

                re = re * 3 - 1;
            }          //a[i]-'a'利用ASCII码值差值求该位的值
            //a[i]-'A'利用ASCII码值差值求该位的值
            i++;       //从最高位依次往低一位遍历
        }
        printf("case #%d:\n%d\n", k++, re);
    }
}