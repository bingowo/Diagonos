#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a1,const void*a2);
int p[26];
int main(){
char s[27];
while(scanf("%s",s)!=EOF){
char cc;
cc=getchar();
 for(int i=0;i<26;i++){
    p[s[i]-'A']=i;
 }
 char c[100][21];
 int first=0,second=0;
 char a;
 a=getchar();
 while(a!='\n'){
    c[first][second++]=a;
    a=getchar();
    if(a==' '){c[first][second]='\0';first++;second=0; a=getchar();}
 }
  if(a=='\n')c[first][second]='\0';
  qsort(c,++first,sizeof(c[0]),cmp);
  if(first==1){
    printf("%s\n",c[0]);
  }
  else {for(int i=0;i<first-1;i++){
    printf("%s ",c[i]);
  }
  printf("%s\n",c[first-1]);
}
}
return 0;
}
int cmp(const void*a1,const void*a2){
char*p1,*p2,cha1,cha2;
p1=*(char(*)[21])a1;p2=*(char(*)[21])a2;
while(*p1&&*p2){
    cha1=(*p1)>='a'?*p1-32:*p1;
    cha2=(*p2)>='a'?*p2-32:*p2;
    if(p[cha1-'A']!=p[cha2-'A'])
        return p[cha1-'A']-p[cha2-'A'];
    else{p1++;p2++;}
}
if(*p1==0){return -1;}
else return 1;
}

