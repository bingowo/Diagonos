#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int M, x, T, i, j, k, r, len, comlen, n, pos, numofspace, num1, num2,flag=0;
    char s[2010], ** a;
    scanf("%d", &T);getchar();
    a = (char**)malloc(2001 * sizeof(char*));
    for (i = 0;i < 2001;i++)
        a[i] = (char*)malloc(2001 * sizeof(char));
    for (x = 0;x < T;x++)
    {
        scanf("%d", &M);getchar();
        printf("case #%d:\n", x);

        s[0] = ' ';
        gets(s + 1);
        len = strlen(s);

        k = 0;
        for (i = 0;i < len;i++)
        {
            if (s[i] == ' ')
            {
                s[i] = 0;
                if (s[i + 1] != ' ' && s[i + 1] != 0)
                {
                    a[k++] = s + i + 1;
                }
            }
        }   //k：a里面有效指针的个数，也是s里面单词的个数

        comlen = 0;   //当前的这一行的长度
        n = 0;        //这一行已经塞了几个单词
        pos = 0;      //当前这一行起始单词角标
        for (i = 0;i < k;i++)        //开始给每一行填东西
        {
            if (n == 0)
            {
                pos = i;              //第一个单词在a里面的下标
                comlen = strlen(a[i]);
                n++;
            }
            else if (n > 0)
            {
                if (comlen + strlen(a[i]) + 1 <= M)        //如果还能塞
                {
                    comlen += strlen(a[i]) + 1;
                    n++;
                }
                else if ((comlen + strlen(a[i]) + 1 > M)) //再塞就溢出了,
                //也就是说，现在这个元素没塞进来，所以应该让i--，不然这个元素会被跳过
                {
                    if (i == k - 1)
                        flag = 1;
                    comlen -= n - 1;        //减去空格，得到实际的单词长度
                    numofspace = M - comlen;//空格个数
                    //现在有numofspace个空格,n-1个空格位，要均匀分配空格数
                    num1 = numofspace / (n - 1);
                    num2 = numofspace % (n - 1);
                    for (j = pos;(j - pos) < n;j++)            //最后一个不用输出空格，也不知道我考虑清楚了没有，脑袋有点糊
                    {
                        printf("%s", a[j]);
                        if ((j - pos) < ((n - 1) - num2))        //吃保底的空格位置
                            for (r = 0;r < num1;r++)
                                printf(" ");            //输出num1个空格
                        else
                            for (r = 0;r < num1 + 1;r++)
                                printf(" ");
                    }
                    printf("\n");
                    n = 0;
                    comlen = 0;
                    i--;
                }
                //前面的两个没考虑到最后一行输出，不用大于M，就有可能没法进入第二个if的输出
            }
            if (i == k - 1 && flag == 0)
            {
                comlen -= n - 1;        //减去空格，得到实际的单词长度
                for (j = pos;(j - pos) < n;j++)            //最后一个不用输出空格，也不知道我考虑清楚了没有，脑袋有点糊
                {
                    if(j-pos!=0)
                        printf(" ");
                    printf("%s", a[j]);
                }
                if(!(x==T-1))
                    printf("\n");
            }
        }
    }
    return 0;
}

//
