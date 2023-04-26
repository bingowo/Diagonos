#include<stdio.h>
#include<string.h>

int max(int a,int b){
    if(a>b)return a;
    return b;
}

char *strrstr(char *s,char *s1){
    int l=strlen(s),l1=strlen(s1);
    for(int i=l-l1;i>=0;i--){
        int m;
        for(m=0;m<l1;m++){
            if(s[i+m]!=s1[m])break;
        }
        if(m==l1)return s+i;
    }
    return NULL;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s1[80],s2[80],s[80];
        scanf("%s%s%s",s1,s2,s);
        int m,l=strlen(s),l1=strlen(s1),l2=strlen(s2);
        if(strstr(s,s1)!=NULL&&strstr(s,s2)!=NULL){
            if((strrstr(s,s1)-strstr(s,s2))>=(strrstr(s,s2)-strstr(s,s1)))
                m=(strrstr(s,s1)-strstr(s,s2))-l2;
            else m=(strrstr(s,s2)-strstr(s,s1))-l1;
        }
        else m=0;
        printf("case #%d:\n",a);
        printf("%d\n",m);
        a++;
    }
}