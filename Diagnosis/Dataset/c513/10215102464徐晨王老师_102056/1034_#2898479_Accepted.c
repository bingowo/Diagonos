#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double p[27];

int cmp(const void *a,const void *b){
char a1,b1;
int p1,p2;
a1=*((char *)a);
b1=*((char *)b);
if(a1>='a'&&a1<='z') p1=a1-'a'; else p1=a1-'A';
if(b1>='a'&&b1<='z') p2=b1-'a';  else p2=b1-'A';
if(p[p2]>p[p1])   return 1;
else if(fabs(p[p2]-p[p1])<1e-8)
                if(p1==p2) return b1-a1;
                else  return p1>p2;

else return -1;

}


int main(){

int T;
scanf("%d",&T);
for(int i=0;i<T;i++){

for(int j=0;j<26;j++){
    scanf("%lf",&p[j]);
}
char str[101];
scanf("%s",str);
qsort(str,strlen(str),sizeof(str[0]),cmp);
printf("case #%d:\n",i);
for(int j=0;j<strlen(str);j++){
    printf("%c",str[j]);
}
if(i<T-1)printf("\n");
}
return 0;
}
