#include<stdio.h>
#include<string.h>

int max(int a,int b){
    if(a>b)return a;
    return b;
}

char *strrstr(char *s,char *s1){
    int l=strlen(s),l1=strlen(s1);
    for(int i=l-l1;i>=0;i--){
        for(int m=0;m<l1;m++){
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
        int m,l=strlen(s);
        scanf("%s%s%s",s1,s2,s);
        if(strstr(s,s1)!=NULL&&strstr(s,s2)!=NULL)
            m=max(abs(strrstr(s,s1)-strstr(s,s2)),abs(strrstr(s,s2)-strstr(s,s1)));
        else m=0;
        printf("case #%d:\n",a);
        printf("%d\n",m);
        a++;
    }
}