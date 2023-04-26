#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char month[19][10] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
int cmp(const void*a,const void*b);
int main(){
//important 放在字符串数组里
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int N=0;
        scanf("%d\n",&N);
        char a[10001][20];
        for(int n=0;n<N;n++){
            gets(a[n]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        for(int n=0;n<N;n++){
            printf("%s\n",a[n]);
        }
    }
    return 0;
}
int cmp(const void*a,const void*b){
    char *s1,*s2,*p,*q,*m,*n;
    s1=(char*)a;
    s2=(char*)b;

    s1+=2,s2+=2;
    while(*s1!='2') s1++;
    while(*s2!='2') s2++;
    while(*s1 && *s2){
        if(*s1==*s2) {
            s1++;
            s2++;}
        else return *s1-*s2;
    }
    p=(char*)a;
    q=(char*)b;
    while(*p!=' ') p++;
    while(*q!=' ') q++;
    p++,q++;
    char* ch;
    int cntp=-1,cntq=-1;
    for(int o=0;o<19;o++){
        if((ch=strstr(p,month[o]))!=NULL){
            cntp=o;
            break;
        }
    }
    for(int o=0;o<19;o++){
        if((ch=strstr(q,month[o]))!=NULL){
            cntq=o;
            break;
        }
    }
    if(cntp!=cntq) return cntp-cntq;
    else{
        m=(char*)a;
        n=(char*)b;
        if((*(m+1))!='.' && (*(n+1))!='.') return *m-*n;
        else if((*(m+1))=='.' && (*(n+1))=='.') return *(m+1)-*(n+1);
        else if((*(m+1))!='.' && (*(n+1))=='.') return 1;
        else if((*(m+1))=='.' && (*(n+1))!='.') return -1;
    }

}