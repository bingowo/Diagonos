#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char s[121];
    int num[120];
    int len;
    int sign;
}vec;
int cmp(const void *p1,const void *p2){
    vec *a=(vec *)p1;
    vec *b=(vec *)p2;
    if(a->sign!=b->sign){
        return b->sign-a->sign;
    }
    if(a->len!=b->len){
        return a->sign*(b->len-a->len);
    }else{
        int j=a->len-1;
        while((a->num[j]==b->num[j])&&j>=0){
            j--;
        }
        if(j==-1){
            return 1;
        }
        else return a->sign*(b->num[j]-a->num[j]);
    }
}
int main() {
    int n;
    vec a[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a[i].s);
        int len = strlen(a[i].s);
        a[i].len=len;
        if(a[i].s[0]=='-'){
            a[i].sign=-1;
            a[i].len--;
        }else{
            a[i].sign=1;
        }
        int j=len-1;
        for(int m=0;m<a[i].len;m++,j--){
            a[i].num[m]=a[i].s[j]-'0';
        }
    }
    qsort(a,n,sizeof(vec),cmp);
    int m1=0,m2=n-1;
    if(a[0].sign==-a[n-1].sign){
        if(a[0].len<a[n-1].len){
            m1=n-1;
            m2=0;
        }
        int carry=0;
        int q=0;
        for(;q<a[m2].len;q++){
            a[m1].num[q]=a[0].num[q]+a[n-1].num[q]+carry;
            carry=a[m1].num[q]/10;
            a[m1].num[q]%=10;
        }
        int len2=a[m2].len;
        while(carry>0){
            a[m1].num[q]=a[m1].num[q]+carry;
            carry=a[m1].num[q]/10;
            a[m1].num[q]%=10;
            len2++;
        }
        a[m1].len=a[m1].len>len2?a[m1].len:len2;
    }else {
        if(a->sign==-1){
            m1=n-1;
            m2=0;
        }
            for (int q = 0; q < a[m2].len; q++) {
            if (a[m1].num[q] < a[m2].num[q]) {
                a[m1].num[q + 1]--;
                int q2 = q + 1;
                while (a[m1].num[q2] < 0) {
                    a[m1].num[q2 + 1]--;
                    a[m1].num[q2] += 10;
                    q2++;
                }
                a[m1].num[q] += 10;
            }
            a[m1].num[q] = a[m1].num[q] - a[m2].num[q];
        }
    }
    int t=a[m1].len-1;
    while(a[m1].num[t]==0){
        t--;
    }
    for(;t>=0;t--){
        printf("%d",a[m1].num[t]);
    }
    printf("\n");
    return 0;
}
