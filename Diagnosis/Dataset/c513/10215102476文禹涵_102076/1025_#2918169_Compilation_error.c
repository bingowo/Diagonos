#include<stdio.h>
#define N 105


int main(){
    int A=0, B=0;
    int a[N]={0};
    int tot=0, nf=0;
    scanf("%d%d", &A, &B);
    // 特判 A / B = 0
    if(A == 0){#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char l[21];
    int num;
    int alb[26];
}con;
int cmp(const void *p1,const void *p2){
    con *a= (con*)p1;
    con *b= (con*)p2;
    if(a->num < b->num){
        return 1;
    }else if(a->num > b->num){
        return -1;
    }else{
        return strcmp(a->l,b->l);
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        con a[n];
        for(int j=0;j<n;j++){
            a[j].num =0;
            for(int q=0;q<26;q++){
                a[j].alb[q] = 0;
            }
            scanf("%s",a[j].l);
            for(int p=0;p< strlen(a[j].l);p++){
                if(a[j].alb[a[j].l[p]-'A']==0){
                    a[j].num ++;
                }
                a[j].alb[a[j].l[p]-'A']=1;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int c=0;c<n;c++){
            printf("%s\n",a[c].l);
        }
    }
    return 0;
}
        puts("0");
        return 0;
    }
    
    // A变为3进制
    while(A){
        a[++tot] = A % 3;
        A /= 3;
    }
    // 看小数点位数
    while(B){
        nf++;
        B /= 3;
    }
    nf--;
    
    // 使第2和第3步的全1序列相同
    tot++;
    // 将得到的三进制数与全1序列按 三进制记数系统的规则 相加
    int tmp = 0;
    tot = (tot >= (nf + 1) ? tot : (nf + 1));
    for(int i = 1; i <= tot; i++){
        a[i] = a[i] + 1 + tmp;
        tmp = a[i] / 3;
        a[i] %= 3;
    }
    if(tmp) a[++tot] = tmp;
    // 将第2步得到的序列与全1序列按位独立相减
    for(int i = 1; i <= tot; i++){
        a[i] = a[i] - 1;
        if(a[i] == -1) a[i] = 2;
    }
    // 去掉前导0和小数末尾的0
    int L = 1, R = tot;
    for(int i = 1; i <= tot && i <= nf; i++){
        if(a[i] == 0) L++;
        else break;
    }
    for(int i = tot; i >= L && i > nf + 1; i--){
        if(a[i] == 0) R--;
        else break;
    }
    // 输出
    for(int i = R; i >= L; i--){
        if(i == nf) printf(".");
        printf("%d", a[i]);
    }
    puts("");
    return 0;
}
