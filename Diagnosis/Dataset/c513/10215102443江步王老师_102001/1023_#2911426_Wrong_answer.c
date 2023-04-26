#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Astr
{
    char string[31];
    int value;
}str;

int strnumcmp(const void *_a, const void *_b);

int main()
{
    str s[100];
    int res;
    int flag;//flag记录是否有数字
    int i=0;
    int j;
    int n=0;//n用于记录字符串个数
    for (j=0;j<100;j++){
        s[j].value=-1;
    }
    while ( scanf("%s",s[i].string) != EOF){//保存字符串与其中的数字至s数组中
        res=0;
        flag=0;
        for (j=0;j<strlen(s[i].string);j++){//寻找并存储数字
            if (s[i].string[j] >= '0' && s[i].string[j] <= '9'){
                flag=1;
                res=res*10+s[i].string[j]-'0';
            }
        }
        if (flag){
            s[i].value=res;
        }
        i++;
        n++;
    }
    qsort(s,n,sizeof(str),strnumcmp);
    for (i=0;i<n;i++){
        printf("%s ",s[i].string);
    }
    return 0;
}

int strnumcmp(const void *_a, const void *_b)
{
    int i=0;
    str *a = (str *)_a;
    str *b = (str *)_b;
    if ((*a).value != -1 && (*b).value != -1){//a，b所指向字符串中都含有数字
        if ((*b).value < (*a).value){
            return 1;
        }
        else if((*a).value == (*b).value){//含有数字相同时，沿用原strcmp方法比较
            int len1,len2;
            len1=strlen((*a).string);
            len2=strlen((*b).string);
            while (i<len1 && i<len2){
                if ((*a).string[i] > (*b).string[i]){
                    return 1;
                }
                else if((*a).string[i] == (*b).string[i]){
                    i++;
                }
                else {
                    return -1;
                }
            }
        }
        else {
            return -1;
        }
    }
    else{//其中一个不含有数字或都不含有数字
        if ((*a).value == -1 && (*b).value != -1){
            return 1;
        }
        else if ((*a).value != -1 && (*b).value == -1){
            return -1;
        }
        else if ((*a).value == -1 && (*b).value == -1){//都不含有数字
            int len1,len2;
            len1=strlen((*a).string);
            len2=strlen((*b).string);
            while (i<len1 && i<len2){
                if ((*a).string[i] > (*b).string[i]){
                    return 1;
                }
                else if((*a).string[i] == (*b).string[i]){
                    i++;
                }
                else {
                    return -1;
                }
            }
        }
    }
}