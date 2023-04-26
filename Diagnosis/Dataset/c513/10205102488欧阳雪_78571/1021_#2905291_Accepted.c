#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[28]={0};//给定字母顺序 
int n;
int sort(char a)
{
    for(n=0;n<strlen(s);n++)//找到元素在给定字母顺序表中位置
        if(a==s[n] || a==(s[n]+'a'-'A'))
            return n;
}
int cmp(const void *a,const void *b)
{
    char s1[101]={0},s2[101]={0};

    strcpy(s1,(char**)a);
    strcpy(s2,(char**)b);

    for(int i=0;s1[i]&&s2[i];i++)
    {
        if(sort(s1[i])!=sort(s2[i]))//逐个元素判断两字符串是否相等
            return sort(s1[i])>sort(s2[i])?1:-1;
    }//遇到相应两元素不等就根据元素在顺序表位置排序即停止 
    return strlen(s1)>strlen(s2)?1:-1;//若遇到abc与abcde比较
}
int main()
{
    while(scanf("%s",s)!=EOF)//每组第一行输入顺序字串S 
    {
         char t[101][101]={0};
        char c=getchar();
        int i=0,j=0;
        while((c=getchar())!='\n')//输入字符串数组
        {
            if(c!=' ')
            {
                t[i][j]=c;
                j++;
            }
            else
           {
               i++;
               j=0;}
        }
        qsort(t,i+1,sizeof(t[0]),cmp);

        for(int k=0;k<=i;k++)
            printf("%s ",t[k]);
        printf("\n");

    }
}
