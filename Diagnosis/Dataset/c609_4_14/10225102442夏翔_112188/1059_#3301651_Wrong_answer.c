//1059
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *a, const void *b){
    char *s1=*(char**)a, *s2=*(char**)b;
    int flag1=1, flag2=1, zhengshu1[110], zhengshu2[110], len1=0, len2=0;
    memset(zhengshu1, 0, sizeof(zhengshu1));
    memset(zhengshu2, 0, sizeof(zhengshu2));
    if(s1[0]=='-') flag1 = -1; //比大小
    if(s2[0]=='-') flag2 = -1;
    if(flag1==-1 && flag2==1) return -1;
    else if(flag1==1 && flag2==-1) return 1;
    int len;
    if(!strchr(s1, '.')) //读整数1
        len = strlen(s1);
    else
        len = strchr(s1, '.')-s1;
    for(int i=0; i<len; i++){
        if(s1[i]>='0' && s1[i]<='9')
            zhengshu1[len1++] = s1[i];
    }
    if(!strchr(s2, '.'))//读整数2 
        len = strlen(s2);
    else
        len = strchr(s2, '.')-s2;
    for(int i=0; i<len; i++){
        if(s2[i]>='0' && s2[i]<='9')
            zhengshu2[len2++] = s2[i];
    }
    if(len1>len2){ //比大小
        if(flag1==1) return 1;
        else return -1; 
    }else if(len1<len2){
        if(flag1==1) return -1;
        else return 1; 
    }else{
        for(int i=0; i<len1; i++){
            if(zhengshu1[i]>zhengshu2[i]){
                if(flag1==1) return 1;
                else return -1;
            }else if(zhengshu1[i]<zhengshu2[i]){
                if(flag1==1) return -1;
                else return 1;
            }
        }
    }
    int xiaoshu1[110], xiaoshu2[110], len3=0, len4=0;
    memset(xiaoshu1, 0, sizeof(xiaoshu1));
    memset(xiaoshu2, 0, sizeof(xiaoshu2));
    if(strchr(s1, '.')){ //读小数1
        for(int i=strchr(s1, '.')-s1+1; i<strlen(s1); i++){
            if(s1[i]>='0' && s1[i]<='9')
                xiaoshu1[len3++] = s1[i];
        }
    }
    if(strchr(s2, '.')){ //读小数1
        for(int i=strchr(s2, '.')-s2+1; i<strlen(s2); i++){
            if(s2[i]>='0' && s2[i]<='9')
                xiaoshu2[len4++] = s2[i];
        }
    }
    len = (len3>len4)? len3: len4;
    for(int i=0; i<len; i++){  //比大小
        if(xiaoshu1[i]>xiaoshu2[i]){
            if(flag1==1) return 1;
            else return -1;
        }else if(xiaoshu1[i]<xiaoshu2[i]){
            if(flag1==1) return 1;
            else return -1;
        }
    }
    return 0;
}
int main(){ 
    int n;
    scanf("%d", &n);
    char **s;
    s = (char**)malloc(sizeof(char*)*n);
    for(int i=0; i<n; i++){
        s[i] = (char*)malloc(sizeof(char)*110);
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(s[0]), cmp1);
    for(int i=0; i<n; i++) printf("%s\n", s[i]);
    for(int i=0; i<n; i++) free(s[i]);
    free(s);
    return 0;
}