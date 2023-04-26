#include<stdio.h>
#include<string.h>
#include<malloc.h>

void swap(int *a, int *b);
int cmp(char *ch, int *o, int *s, int st1, int len1, int st2, int len2);
int main()
{
    int start[100];//编号为i的单词的起始位置
    int length[100];//编号为i的单词的长度
    int index[100];//index数组储存排序第i个单词的下标
    char ch[20000];//存放当前行字符串中的所有单词
    int o[128];//当前字母的排序顺序
    int s[20000];//每个字符输出时的状态(大小写) 0--大写,1--小写
    char str[26];//用于临时储存第一行的字母顺序字符串
    char c;//暂时变量,用于取字符
    int i,j,k;
    int n=0;//n用于记录单词数
    int num=0;//num用于记录字符数
    int len=0;//len用于记录当前单词长度
    int flag=0;//flag用于储存交换状态(是否需要交换)
    while (scanf("%s",str)!=EOF){
        for (i=0;i<20000;i++){
            ch[i]=0;
        }
        for (i=0;i<26;i++){
            o['A'+i]=0;
        }
        for (i=0;i<strlen(str);i++){
            o[str[i]]=i;
        }
        while ((c=getchar()) !='\n' && c!=EOF){//取第二行的各个字符串
            if (c ==' '){
                length[n]=len;
                start[n]=num-len;
                n++;
                len=0;//重置长度
                continue;
            }
            ch[num]=c;
            if (c>='a' && c<='z'){
                s[num]=1;
            }
            else if(c>='A' && c<='Z'){
                s[num]=0;
            }
            num++;
            len++;
        }
        length[n]=len;
        start[n]=num-len;
        n++;
        //开始排序,使用index数组记录排序后顺序
        for (i=0;i<n;i++){
            index[i]=i;
        }
        for (i=0;i<n;i++){
            k=i;
            for (j=i+1;j<n;j++){
                flag=cmp(ch,o,s,start[index[k]],length[index[k]],start[index[j]],length[index[j]]);
                if (flag==-1)
                    k=j;
            }
            if (k != i){
                swap(&index[i],&index[k]);
            }
        }
        for (i=0;i<n;i++){//输出部分
            for (j=start[index[i]];j<start[index[i]]+length[index[i]];j++){
                printf("%c",ch[j]);
            }
            if (i!=n-1)
                putchar(' ');
            else
                putchar('\n');
        }
    }
}

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int cmp(char *ch, int *o, int *s, int st1, int len1, int st2, int len2)
{
    int i=0;
    int flag=0;
    char *str1 = (char *)malloc(sizeof(char)*(len1));
    char *str2 = (char *)malloc(sizeof(char)*(len2));
    for (i=0;i<len1;i++){
        str1[i]=ch[st1+i]-32*s[st1+i];
    }
    for (i=0;i<len2;i++){
        str2[i]=ch[st2+i]-32*s[st2+i];
    }
    i=0;
    while (i<len1 && i<len2){
        if (o[str1[i]]<o[str2[i]]){
            flag=1;
            free(str1);
            free(str2);
            return flag;
        }
        else if (o[str1[i]]>o[str2[i]]){
            flag=-1;
            free(str1);
            free(str2);
            return flag;
        }
        else{
            i++;
            continue;
        }
    }
    if (len1 > len2){
        flag=-1;
    }
    else if (len1 < len2){
        flag=1;
    }
    free(str1);
    free(str2);
    return flag;
}