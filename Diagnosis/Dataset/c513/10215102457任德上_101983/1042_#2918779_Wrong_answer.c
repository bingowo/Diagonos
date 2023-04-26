#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b){
    char *m1,*m2;
    m1=(char *)a;
    m2=(char *)b;
    return (int)(*m1-*m2);

}
char* find(char *s,int len){
    char *m,*s1,*s2;
    m=(char *)malloc((len+1)*sizeof(char));
    *m=*s;
    s2=m;
    m++;
    if(len==1){
        *m=0;
        return s2;
    }
    s1=s+1;
    while(*s1){
        if(*s1!=*(m-1)){
            *m=*s1;
            m++;
        }
        s1++;
    }
    *m=0;
    return s2;

}
void diff(char *d){
    int len=strlen(d);
    char *p,c;
    for(int i=0;i<len;i++){
        p=d+i;
        for(int m=0;m<len-i;m++){
            c=*(p+m+1);
            *(p+m+1)=0;
            printf("%s\n",p);
            *(p+m+1)=c;
        }
    }

}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[17],*d;
        scanf("%s",s);
        qsort(s,strlen(s),1,cmp);
        d=find(s,strlen(s));
        printf("case #%d:\n",i);
        diff(d);
    }
    return 0;
}