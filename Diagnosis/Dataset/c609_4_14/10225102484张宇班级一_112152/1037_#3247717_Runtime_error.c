#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
char *n1=*(char*)a;
char *n2=*(char*)b;
int x=strlen(*n1);
int y=strlen(*n2);
return y-x;

}
int main(){
char a[1000001];
scanf("%s",a);
char b[16000][63];
int len=strlen(a);
int r=0;int c=0;
b[r][c]=a[0];
for(int i=1;i<len;i++){
    if(strstr(b[r],a[i])==NULL)
    {c++;b[r][c]=a[i];}
    else {r=r+1;c=0;}
}

qsort(b,r,sizeof(b[0]),cmp);
printf("%s",b[0]);
return 0;


}
