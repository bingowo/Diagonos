#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double b[26];
int co(int n1,int n2,char s1,char s2){
    char c1,c2;
    c1=tolower(s1);
    c2=tolower(s2);
    if(fabs(b[n1]-b[n2])<1e-7){
        if(c1==c2){
            if(s1>s2)return -1;
            return 1;
        }
        if(c1>c2)return 1;
        return -1;
    }
    if((b[n1]-b[n2])>1e-7)return -1;
    return 1;
}
int cmp(const void *a,const void *b){
    char *s1,*s2,c1,c2;
    s1=(char *)a;
    s2=(char *)b;
    c1=*s1;
    c2=*s2;
    c1=tolower(c1);
    c2=tolower(c2);
    int n1,n2;
    n1=(int)(c1-'a');
    n2=(int)(c2-'a');
    return co(n1,n2,*s1,*s2);

}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        double a[26];
        int n=0;
        char s1[101],c;
        for(int m=0;m<26;m++)scanf("%lf",&a[m]);
        for(int m=0;m<26;m++)b[m]=a[m];
        c=getchar();
        gets(s1);
        qsort(s1,strlen(s1),sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,s1);
    }

}