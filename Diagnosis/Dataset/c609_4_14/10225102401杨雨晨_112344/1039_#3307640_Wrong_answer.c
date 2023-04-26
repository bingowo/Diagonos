#include <stdio.h>
#include <string.h>
int max(int m,int n){
    return m>n?m:n;
}
int Findleft(char *s,char*s1){
    char*p=strstr(s,s1);
    return p==0?-1:p-s;
}
int Findright(char *s,char*s1){
    char *p=s,*p1=0;
    while ((p1=strstr(p,s1))!=0)p=p1+1;
    return p-s-1;
}
int main(){
    int n,i,a,b;
    int maxdist=0;
    char s1[80],s2[80],s[80];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        a=Findleft(s,s1);
        b=Findright(s,s2);
        if (a!=-1&&b!=-1){
            maxdist=max(maxdist,b-a-strlen(s1));
            a=Findleft(s,s2);
            b=Findright(s,s1);
            maxdist=max(maxdist,b-a-strlen(s2));
        }
        printf("%d\n",maxdist);
    }
}