#include<stdio.h>
int main()
{
    char ming[26],a[100][1000];
    while(scanf("%c",&ming[0])==1)
    {
        for(int i=1;i<26;i++)
        {
            scanf("%c",&ming[i]);  //字符排序
        }
        for(int i=0;i<26;i++)
        {
            printf("%c",ming[i]);  //字符排序
        }
    }
    
}