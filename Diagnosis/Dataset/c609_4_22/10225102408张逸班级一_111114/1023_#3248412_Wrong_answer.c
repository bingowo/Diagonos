#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a1,const void*a2){
    char*p1=*(char**)a1,*p2=*(char**)a2;
    int len1=strlen(p1)-1,len2=strlen(p2)-1;
    int num1,num2,num3,num4;
    int ans1=10*(*(p1+len1-1)-'0')+(*(p1+len1)-'0');
    int ans2=10*(*(p2+len2-1)-'0')+(*(p2+len2)-'0');
    if(ans1!=ans2)
      return ans1-ans2;
    if(strstr(p1,"pop"))num1=1;
    else if(strstr(p1,"no"))num1=2;
    else if(strstr(p1,"zip"))num1=3;
    else if(strstr(p1,"zotz"))num1=4;
    else if(strstr(p1,"tzec"))num1=5;
    else if(strstr(p1,"xul"))num1=6;
    else if(strstr(p1,"yoxkin"))num1=7;
    else if(strstr(p1,"mol"))num1=8;
    else if(strstr(p1,"chen"))num1=9;
    else if(strstr(p1,"yax"))num1=10;
    else if(strstr(p1,"zac"))num1=11;
    else if(strstr(p1,"ceh"))num1=12;
    else if(strstr(p1,"mac"))num1=13;
    else if(strstr(p1,"kankin"))num1=14;
    else if(strstr(p1,"muan"))num1=15;
    else if(strstr(p1,"pax"))num1=16;
    else if(strstr(p1,"koyab"))num1=17;
    else if(strstr(p1,"cumhu"))num1=18;
    else if(strstr(p1,"uayet"))num1=19;
    if(strstr(p2,"pop"))num2=1;
    else if(strstr(p2,"no"))num2=2;
    else if(strstr(p2,"zip"))num2=3;
    else if(strstr(p2,"zotz"))num2=4;
    else if(strstr(p2,"tzec"))num2=5;
    else if(strstr(p2,"xul"))num2=6;
    else if(strstr(p2,"yoxkin"))num2=7;
    else if(strstr(p2,"mol"))num2=8;
    else if(strstr(p2,"chen"))num2=9;
    else if(strstr(p2,"yax"))num2=10;
    else if(strstr(p2,"zac"))num2=11;
    else if(strstr(p2,"ceh"))num2=12;
    else if(strstr(p2,"mac"))num2=13;
    else if(strstr(p2,"kankin"))num2=14;
    else if(strstr(p2,"muan"))num2=15;
    else if(strstr(p2,"pax"))num2=16;
    else if(strstr(p2,"koyab"))num2=17;
    else if(strstr(p2,"cumhu"))num2=18;
    else if(strstr(p2,"uayet"))num2=19;
    if(num1!=num2)return num1-num2;
    if(*(p1+1)!='.')num3=10+*(p1+1)-'0';
    else num3=*(p1)-'0';
    if(*(p2+1)!='.')num4=10+*(p2+1)-'0';
    else num4=*(p2)-'0';
    return num3-num4;
}
int main(){
 int t;
 scanf("%d",&t);
 for(int i=0;i<t;i++){
  int a;
  scanf("%d",&a);
  char cc;
  cc=getchar();
  char**p=(char**)malloc(a*sizeof(char*));
  for(int j=0;j<a;j++){
    char s[20];
    gets(s);
    char*o=(char*)malloc(strlen(s)+1);
    strcpy(o,s);
    *(p+j)=o;
    
  }
  qsort(p,a,sizeof(char*),cmp);
  for(int i=0;i<a;i++){
    printf("case #%d:\n",i);
    printf("%s\n",*(p+i));}
  for(int i=0;i<a;i++){
    char*d=*(p+i);
    free(d);
  }
  free(p);
 }
 return 0;
}