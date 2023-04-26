#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char s1[80],s2[80],s[80];
        gets(s1);
        gets(s2);
        gets(s);
        int loc1=strstr(s1,s);
        int loc2=strstr(s2,s);
        int a=strlen(s1);
        int b=strlen(s2);
        int c=strlen(s);
        char s11[80],s22[80],ss[80];
        for(int i=0;i<a;i++){
            s11[i]=s1[a-i-1];
        }
        for(int i=0;i<b;i++){
            s22[i]=s2[b-i-1];
        }
        for(int i=0;i<c;i++){
            ss[i]=s[c-i-1];
        }
        int loc11=strstr(s11,ss);
        int loc22=strstr(s22,ss);
        int len1=abs((c-loc22-b)-(loc1+a-1));
        int len2=abs((c-loc11-a)-(loc2+b-1));
        int len;
        if(len1>len2)len=len1;
        else len=len2;
        printf("%d\n",len);
    }
    return 0;
}
