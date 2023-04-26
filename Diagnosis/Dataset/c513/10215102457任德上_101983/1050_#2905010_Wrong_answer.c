

#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[81],s1[81],s2[81];
        scanf("%s%s%s",s1,s2,s);
        int max1,max2;
        char *m1,*m2,*m;
        m1=strstr(s,s1);
        m=s;
        while(strstr(m,s2)!=NULL){
            m2=strstr(m,s2);
            m=m2+1;
        }
        if(m1!=NULL&&m2!=NULL&&m1!=m2)max1=m2-m1-strlen(s1);
        else max1=0;
        m1=strstr(s,s2);
        m=s;
        while(strstr(m,s1)!=NULL){
            m2=strstr(m,s1);
            m=m2+1;
        }
        if(m1!=NULL&&m2!=NULL&m1!=m2) max2=m2-m1-strlen(s2);
        else max1=0;
        max2=m2-m1-strlen(s2);
        int max=max1>max2?max1:max2;
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}