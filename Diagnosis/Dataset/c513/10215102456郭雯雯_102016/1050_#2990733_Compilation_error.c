#include<stdio.h>
#include<string.h>

int max(int a,int b){
    if(a>b)return a;
    return b;
}
int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s1[80],s2[80],s[80],s11[80],s21[80];
        int m;
        scanf("%s%s%s",s1,s2,s);
        strrev(s1,s11);
        if(strstr(s,s1)!=NULL&&strstr(s,s2)!=NULL)
            m=strrstr(s,s1)-strstr(s,s2);
        else m=0;
        printf("case #%d:\n",a);
        printf("%d\n",m);
        a++;
    }
}