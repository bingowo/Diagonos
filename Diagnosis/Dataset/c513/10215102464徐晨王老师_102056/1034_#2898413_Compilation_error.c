#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(){
int T;
scanf("%d",&T;
for(int i=0;i<T;j++){
double p[27];
for(int j=0;j<26;j++){
    scanf("%lf",&p[j]);
}
char str[101];
scanf("%s",str);
qsort(str,strlen(str),sizeof(str[0]),cmp);
printf("case #%d:",i);
for(int j=0;j<26;j++){
    printf("%lf",p[j]);
}
if(i<T-1)printf("\n");
}    
return 0;    
    
}