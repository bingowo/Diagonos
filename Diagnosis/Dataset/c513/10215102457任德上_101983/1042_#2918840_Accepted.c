#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
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

void diff(char *d,char *left){
    int len=strlen(d),i=1;
    char c,right[17]={0};
    if(len==0);
    else{
        c=*(d+1);
        *(d+1)=0;
        strcpy(right,left);
        strcat(left,d);
        *(d+1)=c;
        printf("%s\n",left);
        diff(d+1,left);
        diff(d+1,right);
    }

}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[17],*d,left[17]={0};
        scanf("%s",s);
        qsort(s,strlen(s),1,cmp);
        d=find(s,strlen(s));
        printf("case #%d:\n",i);
        diff(d,left);
    }
    return 0;
}