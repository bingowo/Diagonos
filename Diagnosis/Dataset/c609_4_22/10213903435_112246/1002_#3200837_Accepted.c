#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i=0;
    int arr[10],cnt[10];
    scanf("%d",&t);
    while(i<t)scanf("%d",arr+(i++));    //连续输入t个数字
    for(i=0;i<t;i++)
    {
        cnt[i]=0;
        int temp_cnt=1,n=*(arr+i);      
        int temp_n=n%2;     
        /*将二进制中表示的第一位的值赋值给temp_n，
        后续利用temp_n判断b_i是否等于b_(i+1)*/
        n/=2;
        do
        {

           if(n%2!=temp_n&&n>1){temp_cnt++;temp_n=n%2;} 
           //如果b_(i+1)不等于b_i且
           else if(n%2!=temp_n&&n<=1&&temp_cnt>=cnt[i]){temp_cnt++;cnt[i]=n?temp_cnt:temp_cnt-1;}
           /*如果b_(i+1)等于b_i，且b_(i+1)为二进制表示中的首位1或者前置0，则循环结束，
           将最长的长度赋值给cnt[i]*/
           else if(n%2==temp_n&&temp_cnt<cnt[i])continue;
           /*如果b_i等于b_(i+1,且此时非重复二进制串的长度不超过先前统计的长度，则进入下一次循环*/
           else if(n%2==temp_n&&temp_cnt>=cnt[i]){cnt[i]=temp_cnt;temp_cnt=1;continue;}
           /*如果b_i等于b_(i+1)，并且此时长度超过了先前的长度，
           则将此时的长度赋值给cnt[i]，并继续判断*/
        }while(n/=2);
    }
    int k=0;
    while(k<t)
    {
        printf("case #%d:\n%d\n",k,cnt[k]);
        k++;
    }//输出结果
    return 0;
}
