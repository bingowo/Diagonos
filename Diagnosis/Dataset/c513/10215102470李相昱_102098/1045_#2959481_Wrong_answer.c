#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char s[101];
    char alb[101];
    int num[100];
}vec;
int sign=0;
int cmp(const void *p1,const void *p2){
    vec a = *(vec*)p1;
    vec b = *(vec*)p2;
    return a.num[sign] - b.num[sign];
}
int main() {
    int n;
    scanf("%d",&n);
    vec a[n];
    int flag=0;
    int times=0;
    int p=1;
    for(int i=0;i<n;i++){
        scanf("%s",a[i].s);
        a[i].alb[0] = a[i].s[0];
        if(i>=1){
            if(a[i].alb[0]!=a[i-1].alb[0]){
                flag=1;
                break;
            }
        }
        int num =1;
        p=1;
        for(int j=1;j<strlen(a[i].s);j++){
            if(a[i].s[j] == a[i].s[j-1]){
                num++;
            } else{

                a[i].alb[p] = a[i].s[j];
                a[i].num[p-1] = num;
                a[i].num[p] =1;
                if(i>=1){
                    if(a[i].alb[p]!=a[i-1].alb[p]){
                        flag=1;
                        break;
                    }
                }
                num =1;
                p++;
            }

        }
        a[i].alb[p]=0;
        if(num>1){
            a[i].num[p-1] = num;
        }
        if(i>=1){
            if(strlen(a[i].alb)!= strlen(a[i-1].alb)){
                flag=0;
                break;
            }
        }
    }
    if(flag){
        printf("-1");
    } else{
        int times1 =0;
        for(int m=0;m<p;m++){
            sign=m;
            qsort(a,n,sizeof(vec),cmp);
            for(int t=0;t<n;t++){
                times = times + abs(a[t].num[sign]-a[n/2].num[sign]);
            }
            if(n%2==0){
                for(int t=0;t<n;t++){
                    times1 = times1 + abs(a[t].num[sign]-a[n/2-1].num[sign]);
                }
            }
        }
        if(times1){
            times = times1>times?times:times1;
        }
        printf("%d",times);
    }
    return 0;
}