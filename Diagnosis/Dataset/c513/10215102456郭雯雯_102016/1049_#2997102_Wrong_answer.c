#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct word{
    char c[100];int l;
};

int cmp(const void *a,const void *b){
    struct word *w1=(struct word *)a,*w2=(struct word *)b;
    return strcmp(w1->c,w2->c);
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    char s[501];
    gets(s);
    while(a<t){
        gets(s);
        struct word w[251];
        int l=strlen(s),m=0,n=-1;
        for(int i=0;i<l;i++){
            if(!isalpha(s[i])){
                strncpy(w[m].c,s+n+1,i-n-1);
                w[m].c[i-n-1]='\0';
                m++;
                n=i;
            }
        }
        if(n<l-1){
            strncpy(w[m].c,s+n+1,l-n-1);
            w[m].c[l-n-1]='\0';
            m++;
        }
        qsort(w,m,sizeof(struct word),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<m-1;i++){
            if(strcmp(w[i].c,w[i+1].c)!=0)printf("%s ",w[i].c);
        }
        printf("\n");
        a++;
    }
}