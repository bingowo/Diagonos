#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a1,const void*a2);
int p[26];
int main()
{
  char s[27];
  while(scanf("%s",s)!=EOF){
  char cc;
  cc=getchar();
  for(int i=0;i<26;i++)p[s[i]-'A']=i;
  int num=0,k=0;
  char c[100][21];
  char a;
  a=getchar();
  while(a!='\n'){
    c[num][k++]=a;
    a=getchar();
    if(a==' ')
    {c[num++][k]='\0'; k=0;a=getchar();}
     }
  if(a=='\n')c[num][k]='\0';
  qsort(c,++num,sizeof(c[0]),cmp);
  if(num==1){printf("%s\n",c[0]);}
  else{
  for(int i=0;i<num-1;i++){
    printf("%s ",c[i]);
  }
  printf("%s\n",c[num-1]);
  }}
   return 0;
}
int cmp(const void*a1,const void*a2){
char*p1,*p2,cha1,cha2;
p1=*(char(*)[21])a1;
p2=*(char(*)[21])a2;
while(*p1&&*p2){
    cha1=*p1;
    cha2=*p2;
    if(cha1>='a'){cha1-=32;}
    if(cha2>='a'){cha2-=32;}
    if(p[cha2-'A']!=p[cha1-'A']){
        return p[cha1-'A']-p[cha2-'A'];
    }
    else{p1++;p2++;}
}
if(*p1==0){
    return -1;
}
else return 1;
}

