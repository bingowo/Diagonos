#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a,const void* b){
char *p1,*p2,*domain1,*domain2;
int j=0;
p1=*((char **)a);
p2=*((char **)b);
while(*(p1+j)!='@')j++;
domain1=p1+j+1;
j=0;
while(*(p2+j)!='@')j++;
domain2=p1+j+1;
if(!strcmp(domain1,domain2)){
    return !strcmp(p1,p2);
}
else return strcmp(domain1,domain2);
}

int main(){
int n;
char **email;
scanf("%d\n",&n);
email=(char **)malloc(n*sizeof(char *));
char s[1000001],*p;
int i,len;
for(int i=0;i<n;i++){
    scanf("%s",s);
    len=strlen(s);
    p=(char *)malloc(len+1);
    strcpy(p,s);
    *(email+i)=p;
}
qsort(email,n,sizeof(char *),cmp);
for(int i=0;i<n;i++){
    printf("%s\n",email[i]);
}
for(int i=0;i<n;i++){
p=email[i];
free(p);
}
free(email);
return 0;
}
