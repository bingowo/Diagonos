#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct data{
    char qian[100];
    int flag;
    char hou[100];
    int zhengfu;
    char zong[99999];
}Data;

int cmp(const void *a,const void *b)
{
    Data *m,*n;
    m=(Data *)a;
    n=(Data *)b;
    if (m->zhengfu==n->zhengfu){
        if (!strcmp(m->qian,n->qian)){
            if (m->flag==n->flag){
                return strcmp(m->hou,n->hou);
            }
            else{
                if (m->flag>0) return 1;
                else return 0;
            }
        }
        else return strcmp(m->qian,n->qian);
    }
    else{
        if (m->zhengfu>0) return 1;
        else return 0;
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    Data m[t];
    char s[99999];
    char ss[99999];
    for (int i = 0; i < t; ++i) {
        scanf("%s",s);
        for (int j = 0; j < strlen(s); ++j) {
            m[i].zong[j]=s[j];
        }
        if (s[0]=='-') m[i].zhengfu=-1;
        else m[i].zhengfu=1;
        int qianshu=0,houshu=0,zhongjian=0;
        if (strchr(s,'.')) {
            m[i].flag=1;
            for (int j = 0; j < strlen(s); ++j) {
                while (s[j]!='.') {
                    zhongjian++;
                    if (s[i] == '-' || s[i] == '+') continue;
                    else m[i].qian[qianshu++] = s[j];
                }
            }
            for (int j = zhongjian+1; j < strlen(s); ++j) {
                m[i].hou[houshu++]=s[j];
            }
        }
        else {
            m[i].flag=0;
            for (int j = 0; j < strlen(s); ++j) {
                m[i].qian[qianshu++]=s[j];
            }
        }
    }
    qsort(m,t, sizeof(m[0]),cmp);
    for (int i = 0; i < t; ++i) {
        printf("%s",m[i].zong);
    }
    return 0;
}