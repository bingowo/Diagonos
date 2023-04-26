#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int numfd(const char*);
    int strnumcmp(const void*,const void*);

    char **s = (char **)malloc(sizeof(char *)*100);
    int n = 0;
    char tmp[31];
    for(int i=0;scanf("%s",tmp) != EOF;i++){
        *(s+i) = (char*)malloc(strlen(tmp));
        strcpy(*(s+i),tmp);
        n++;
    }
    qsort(s,n,sizeof(char*),strnumcmp);
    for(int i=0;i<n;i++){
        printf("%s ",*(s+i));
    }
    for(int i=0;i<n;i++){
        free(*(s+i));
    }
    free(s);

    return 0;
}
int numfd(const char*s)
{
    int l = strlen(s);
    int res = 0,flag = 0;
    for(int i=0;i<l;i++){
        if(s[i] < '0' || s[i] >'9') continue;
        else{
            if(!flag) flag = 1;
                res *= 10;
                res += s[i] - '0';
            }
    }
    if(flag) return res;
    else return -1;
}
int strnumcmp(const void*a,const void*b)
{
    char *pa,*pb;
    pa = *(char **)a;
    pb = *(char **)b;
    int numa,numb;
    numa = numfd(pa);
    numb = numfd(pb);
    if(numa == -1 && numb == -1) return strcmp(pa,pb);
    else if(numa != -1 && numb == -1) return 1;
    else if(numa == -1 && numb != -1) return -1;
    else return numa - numb;
}
