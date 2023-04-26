#include<stdio.h>
#include<string.h>
int cmp(char a,int lena, char b, int lenb)
 {
 //前态：（句子a，a的长度，句子b， b的长度）
 //a大就返回1，a小就返回-1,相等返回0
    int max;
    if (lena < lenb)
    max = lenb;
    for(int i = 0; i < max; i++)
    {
        if(a[i] > b[i])
        return 1;
        if(a[i] < b[i])
        return -1;
    }
    return 0;
 }

int differ(char* a, int lena)//计算不同字符数
 {
    int q[21] = {0};//用于查重
    int num = 0;
    for(int i = 0; i < lena; i++)
    {
        int flag = 0;
        for(int j = 0; j < lena; j++)
        {
            if(a[i] == q[j])
            flag = 1;
        }
        if (flag == 0)
        num++;
        q[i] = a[i];
    }
     return num;
 }

int main()
 {
    int t;
    scanf("%d", &t);//共有几组问题
    int w = 0;
    while (t--)
    {
        int n;
        scanf("%d", &n);//每组有几个句子
        char a[n][21];
        int a1[n] ;//存放每个句子的不同字符数
        for (int i = 0; i < n; i++){//获取字符串
            scanf("%s", &a[i]);
            getchar();
            a1[i] = differ(a[i], strlen(a[i]));
        //记录不同字符数
    }
    for(int i = 0; i < n - 1; i++)
    {                 //i为已经排序好的数的数量
        for(int j = 0; j < n - i - 1; j++)
        {    //j为排序的下标
            if(a1[j] < a1[j+1])
             {
                 char b[21];
                 strcpy(b, a[j]);
                 strcpy(a[j], a[j+1]);
                 strcpy(a[j+1], b);
                 int t = a1[j];
                 a1[j] = a1[j+1];
                 a1[j+1] = t;
             }
        }
    }
    for (int i = 0; i < n; i++){
        a1[i] = differ(a[i], strlen(a[i]));
    }
    for(int i = 0; i < n; i++)
    {                 //i为已经排序好的数的数量
        for(int j = 0; j < n - i - 1; j++)
        { //j为排序的下标
            if(a1[j] == a1[j+1])
             {
                 if(compare(a[j], strlen(a[j]), a[j+1], strlen(a[j+1])) > 0)
                 {
                     char b[21];
                     strcpy(b, a[j]);
                     strcpy(a[j], a[j+1]);
                     strcpy(a[j+1], b);

                 }

             }
        }
    }
    printf("case #%d:\n", w);
    for(int i = 0; i < n; i++)
    {
        printf("%s\n",a[i]);
    }
    w++;

}


return 0;


}
