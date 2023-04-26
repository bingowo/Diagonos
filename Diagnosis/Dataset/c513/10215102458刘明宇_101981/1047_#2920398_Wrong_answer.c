#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        char s[1000];
        scanf("%s",s);
        char *p = s;
        int list[1000];//存放各个字符的出现次数
        char list1[1000];//存放每一个字符
        memset(list,0,sizeof(list));//全化为0 ac
        int i = 0;
        while(*p){
            int num = 1;//初始出现次数为1
            char *p1 = p+1;//定住p指针，移动p1指针
            while(*p1 == *p){ //如果两个指针指向的元素相同
                num++; //出现次数+1
                p1++; //p1指针向后移动一位
            }
            list1[i] = *p;
            p += (num);//指针p向后移动，移动位数为出现次数
            list[i] = num;//list来统计对应元素出现的次数

            i++;//i向后移动
        }
        //int *p0 = list;
        //int len = 0;
        //while(*p0 != 0){
        //    len++;
        //    p0++;
        //} //计算list的长度
        //printf("MY LEN IS %d\n",len);
        printf("case #%d:\n",cnt);
        for(int j = 0;j < i;j++){
            printf("%d%c",list[j],list1[j]); //依次打印出list的元素
        }
        printf("\n");
        cnt++;
    }
}