#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int strnumcmp(const void*a1,const void*a2);
int main(){
char** all;
all=(char**)malloc(sizeof(char*)*110);
char s[31];int i=0;
while(scanf("%s",s)!=EOF){
    int len=strlen(s);
    char*p=(char*)malloc(len+1);
    strcpy(p,s);
    *(all+i++)=p;
}
qsort(all,i,sizeof(char*),strnumcmp);
for(int k=0;k<i;k++){
    printf("%s%c",*(all+k),k==i-1?'\n':' ');
}
for(int j=0;j<i;j++){
    char*o=all[j];
    free(o);
}
free(all);
return 0;
}
int strnumcmp(const void*a1,const void*a2){
char*p1=*(char**)a1,*p2=*(char**)a2;
int flag1=0,flag2=0,num1=0,num2=0;
while(*p1){
    if(*p1>='0'&&*p1<='9'){flag1=1;num1=10*num1+(*p1-'0');}
    p1++;
}
while(*p2){
    if(*p2>='0'&&*p2<='9'){flag2=1;num2=10*num2+(*p2-'0');}
    p2++;
}
p1=*(char**)a1;
p2=*(char**)a2;
if(flag1!=flag2){
    return flag1-flag2;
}
else if(num1==num2){
    return strcmp(p1,p2);
}
else return num1-num2;
}