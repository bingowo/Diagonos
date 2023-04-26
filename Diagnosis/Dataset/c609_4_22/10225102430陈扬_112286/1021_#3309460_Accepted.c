#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char alp[27];
int strscmp(char *s1, char *s2){ //针对某一个字符串alp的排序函数
    int count=0;
    char temp1, temp2;
    while(s1[count]!='\0'&&s2[count]!='\0'){
        temp1 = s1[count];
        if((int)temp1>=97&&(int)temp1<=122)
            temp1 -= 32;
        temp2 = s2[count];
        if((int)temp2>=97&&(int)temp2<=122)
            temp2 -= 32;
        if(temp1==temp2) count++;
        else if(strchr(alp, temp1)>strchr(alp, temp2))
            return 1;
        else return -1;
    }
    if(s1[count]=='\0'&&s2[count]=='\0') return 0;
    if(s1[count]=='\0') return -1;
    if(s2[count]=='\0') return 1;
}
int cmp1(const void *a, const void *b){
    return strscmp(*(char**)a, *(char**)b);
}
int main(){
    char **s, c;
    int count=0, sum=0;//记录位数，字符串总数
    while(scanf("%s", alp)!=EOF){    
        s = (char**)malloc(sizeof(char*)*100);
        count = 0;
        sum = 0;
        s[sum] = (char*)malloc(sizeof(char)*21);
        getchar();
        scanf("%c", &c);
        while(c!='\n'){   
            if(c!=' ')
                s[sum][count++] = c;
            else{
                s[sum][count] = '\0';
                sum++;
                s[sum] = (char*)malloc(sizeof(char)*21);
                count = 0;
            }
            scanf("%c", &c);
        }
        s[sum][count] = '\0';
        sum++;
        qsort(s,sum,sizeof(s[0]),cmp1);
        for(int i=0; i<sum-1; i++) printf("%s ", s[i]);
        printf("%s\n", s[sum-1]);
        for(int i=0; i<sum; i++) free(s[i]);
        free(s);
    }
    return 0;
}