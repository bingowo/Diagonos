#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int compar(const void *a,const void *b);
int number(char* str){
    int i,sum=-1,flag=0;
    unsigned long int len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            if(sum==-1)sum++;
            sum=sum*10+str[i]-'0';
            flag=1;
        }
    }
    return sum;
}
double p[27];
int main(){
    char str[100][31];
    int count=0;
    while(scanf("%s",str[count])!=EOF)count++;
    qsort(str,count,sizeof(str[0]),compar);
    for(int i=0;i<count-1;i++)printf("%s ",str[i]);
    printf("%s\n",str[count-1]);
    return 0;
}


int compar(const void*a,const void*b){
    int s1,s2;
    char* str1,*str2;
    str1=(char*)a;
    str2=(char*)b;
    s1=number(str1);
    s2=number(str2);
    if(s1==s2)return strcmp(str1,str2);
    else{
        if(s1>s2)return 1;
        else return -1;
    }
}
