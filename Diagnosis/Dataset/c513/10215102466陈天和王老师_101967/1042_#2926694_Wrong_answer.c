#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
typedef struct{
    char s[20];
}str;
int cmp2(const void *a,const void *b){
    str *pa=(str*)a;
    str *pb=(str*)b;
    return strcmp(pa->s,pb->s);
}
int cmp1(const void *a, const void *b)
{
    int na = *(int *)a;
    int nb = *(int *)b;
    return na - nb;
}//简单的int升序排列

int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int c,id,index=0;
        int s[20]={0};
        int map[52]={0};
        while((c=getchar())!='\n') {
            if (islower(c)) {
                id = (c - 'a') * 2 + 1;
            } else {
                id = (c - 'A') * 2;
            }
            //妙蛙，直接把大小写都放里了，而且相同字母大小写相邻而且大写在前
            if (map[id] == 0) {
                map[id] = 1;
                s[index++] = c;
            }
        }
        //现在有序数存到map里了，无重复字符的字符串存到s里了
        //接下来需要对s排序和选择和排序
        qsort(s, index, sizeof(int), cmp1);//s排成数字升序

        str data[1 << index];//类似于建立二维数组
        for(int j=0;j<(1<<index);j++){
            //由于一共1<<index（2的n次幂）种选法，所以循环这么多次，放进data里
            int p=0;
            for(int k=0;k<index;k++){
                //s长度为index，所以当然要循环到index
                if(j&(1<<k)){
                    //即j的二进制第k位为1（首位叫第0位），那就把s的第k位放进来
                    data[j-1].s[p++]=s[k];//结构体里的s和外面s不见面
                }
            }
            data[j-1].s[p]='\0';//别忘了自己弄的字符串最后补0
        }
        //二进制枚举的实现
        //现在data这个结构体数组类似于一个二维数组，每一行存放一种可能，
        // 而且由于s中本来就排好了，所以每一行自己是排好的
        //现在需要对行与行进行排序
        qsort(data,(1<<index)-1,sizeof(data[0]),cmp2);


        printf("case #%d:\n", t);
        for(int j = 0 ; j < (1 << index) - 1; j ++){
            printf("%s\n", data[j].s);
        }//输出
    }
    return 0;
}