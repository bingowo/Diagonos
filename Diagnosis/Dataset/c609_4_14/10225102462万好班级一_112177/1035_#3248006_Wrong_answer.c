#include <stdio.h>
#include <string.h>




int main(){

    char s[101];
    gets(s);unsigned int len = strlen(s);
    int max = 0;int ret = 0;int r = 0;

    for (int i = 1;s[i] != '\0'; ++i) {int z = 1;int count = 0;
        while(  (i - z >= 0)
        &&  (s[i-z] == s[i+z])
        &&  (s[i-z] != s[i-z + 1]))
        {count++;z++;}
        if(count > max){max = count;ret = i;r = z;}}//检测插入位置

    if(ret != 0){for (int i = 0;s[ret + r + i] !='\0'; ++i) {
            s[ret - r + 1 + i] = s[ret + r + i];
        }s[len - (2*r - 1)] = '\0';}//消除插入后的
    else s[len -1] = '\0';

    for (int i = 0;s[i] != '\0'; ++i) {
        printf("%c",s[i]);
    }printf("\n");

    int band;
    do
    {band = 0;
        for (int i = 0;s[i] != '\0';)
        {
            while(s[i] == '0')i++;
            int j = i + 1;
            while(s[j] == '0')j++;
            int count = 0;
            while(s[i] == s[j])
            {s[j] = '0';j++;count++;band++;}
            if(count)s[i] = '0';
            i = j;
        }
    }while(band != 0);
    s[len - (2*r - 1)] = '\0';int answer = 0;
    for (int i = 0;s[i] != '\0'; ++i) {
        if(s[i] !='0')answer++;
    }printf("%d",len - answer + 1);
}

