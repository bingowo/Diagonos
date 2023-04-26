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
        int num[255];num[0]=-1;
        int l=strlen(s),m=1,n=0;
        for(int i=0;i<l;i++)
            if(!isalpha(s[i]))num[m++]=i;
        if(isalpha(s[l-1]))num[m++]=l;
        for(int i=0;i<m-1;i++){
            if(num[i+1]-num[i]>1)
                strncpy(w[n++].c,s+num[i]+1,num[i+1]-num[i]-1);
        }
        qsort(w,m,sizeof(struct word),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<m-1;i++){
            if(strcmp(w[i].c,w[i+1].c)!=0)printf("%s ",w[i].c);
        }
        printf("%s",w[m-1].c);
        printf("\n");
        a++;
    }
    return 0;
}