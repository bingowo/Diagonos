#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double f[1234];
int a[1234];
char st[1234];

int cmp(const void *st1,const void *st2){
    char x=*(char*)st1;
    char y=*(char*)st2;
    int f1=0;
    int f2=0;
    if (x>='A' && x<='Z') {
        f1=1;
        x=x-'A'+'a';
    }
    if (y>='A' && y<='Z') {
        f2=1;
        y=y-'A'+'a';
    }
    if (x==y) return f1-f2;
    else if (f[y-'a'+1]==f[x-'a'+1]) return x-y;
    else if (f[y-'a'+1]-f[x-'a'+1]<0) return -1;
    else return 1;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        for (int i=1;i<=26;i++){
            scanf("%lf",&f[i]);
        }
        scanf("%s",st);
        qsort(st,strlen(st),sizeof(char),cmp);
        printf("%s\n",st);
    }
    return 0;
}
