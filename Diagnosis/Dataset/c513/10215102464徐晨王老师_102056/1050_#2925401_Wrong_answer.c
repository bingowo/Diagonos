#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int strstr1(char* list1,char* list2){
    int x,y=0;
    for(int i=0;i<strlen(list2);i++){
        x=0;
        for(int j=0;j<strlen(list1);j++){
            if(list1[j]!=list2[i+j])break;
            else{
                x=x+1;
            }
        }
        if(x==strlen(list1)){y=i;break;}
    }
    return y;
}


int strstr2(char* list1,char* list2){
    int x,y=0;
    for(int i=0;i<strlen(list2);i++){
        x=0;
        for(int j=0;j<strlen(list1);j++){
            if(list1[j]!=list2[i+j])break;
            else{
                x=x+1;
            }
        }
        if(x==strlen(list1)){y=i;}
    }
    return y;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){

        char s1[80],s2[80],s[80];
        scanf("%s%s%s",s1,s2,s);
        int loc1=strstr1(s1,s);
        int loc2=strstr1(s2,s);
        int a=strlen(s1);
        int b=strlen(s2);
        int c=strlen(s);
        int loc11=strstr2(s1,s);
        int loc22=strstr2(s2,s);
        int len1=abs(loc22-loc1)-a;
        if(len1<0)len1=0;
        int len2=abs(loc11-loc2)-b;
        if(len2<0)len2=0;
        int len;
        if(len1>len2)len=len1;
        else len=len2;
        if(len<0)len=0;
        if(loc1==0||loc2==0)len=0;
        printf("case #%d:\n",t);
        printf("%d\n",len);
    }
    return 0;
}