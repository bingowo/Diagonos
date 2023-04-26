#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data{
    char s[21];
    char alpha[26];
    int num;
};
int cmp(const void *a,const void *b){
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    int len1=strlen(d1.s);
    for(int i=0;i<len1;i++){
            if(d1.alpha[d1.s[i]-'A']==0){
                d1.alpha[d1.s[i]-'A']=1;
                d1.num++;
            }
    }
    int len2=strlen(d2.s);
    for(int i=0;i<len2;i++){
            if(d2.alpha[d2.s[i]-'A']==0){
                d2.alpha[d2.s[i]-'A']=1;
                d2.num++;
            }
    }
    if(d2.num!=d1.num){
        return d2.num-d1.num;
    }
    else{
        return strcmp(d1.s,d2.s);
    }



}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++){
        struct data p[1000];
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%s",p[j].s);

        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",cas);
        for(i=0;i<n;i++){
            printf("%s\n",p[i].s);
        }
    }

    return 0;
}
