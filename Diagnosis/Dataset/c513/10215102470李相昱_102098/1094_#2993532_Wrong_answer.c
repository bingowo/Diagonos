#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char s[121];
    int num[120];
    int len;
}vec;
int cmp(const void *p1,const void *p2){
    vec *a=(vec *)p1;
    vec *b=(vec *)p2;
    if(a->len!=b->len){
        return b->len-a->len;
    }else{
        int j=a->len-1;
        while((a->num[j]==b->num[j])&&j>=0){
            j--;
        }
        if(j==-1){
            return 1;
        }
        else return b->num[j]-a->num[j];
    }
}
int main() {
    int n;
    vec a[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a[i].s);
        a[i].len = strlen(a[i].s);
        for(int j=0;j<a[i].len;j++){
            a[i].num[j]=a[i].s[a[i].len-1-j]-'0';
        }
    }
    qsort(a,n,sizeof(vec),cmp);
    for(int q=0;q<a[n-1].len;q++){
        if(a[0].num[q]<a[n-1].num[q]){
            a[0].num[q+1]--;
            int q2=q+1;
            while(a[0].num[q2]<0){
                a[0].num[q2+1]--;
                a[0].num[q2]+=10;
                q2++;
            }
            a[0].num[q]+=10;
        }
        a[0].num[q]=a[0].num[q]-a[n-1].num[q];
    }
    int t=a[0].len-1;
    while(a[0].num[t]==0){
        t--;
    }
    for(;t>=0;t--){
        printf("%d",a[0].num[t]);
    }
    printf("\n");
    return 0;
}
