#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void domain(char *s,char *t){
 int i=0;
 s+=7;
 while(*s!='/') t[i++]=*s++; //t[i]=0;
}
void address(char *s,char t[]){
 s+=7;
 int i=0;
 while(*s!='/') s++;
 while(*s) t[i++]=*s++;
 t[i]='\0';

}

int cmp(const void *a,const void *b){
 char *s1=(char*)a,*s2=(char*)b;
 char t1[301],t2[301];

 domain(s1,t1);domain(s2,t2);
 int r=strcmp(t1,t2);
 if(r!=0) return r;
 char x1[301],x2[302];
 address(s1,x1);
 address(s2,x2);
 if (strcmp(x1,x2)<0){
    return -1;
 }
 else return 1;

}



int main(){
 char s[301];
 char a[100][301];
 int m=0,n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++){
  scanf("%s",s);
  if(s[4]!='s') strcpy(a[m++],s);
 }


 qsort(a,m,sizeof(a[0]),cmp);
 for(i=0;i<m;i++)
 printf("%s\n",a[i]);
 return 0;
}
