#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
char *n1=*(char**)a;
char *n2=*(char**)b;
int x=strlen(*n1);
int y=strlen(*n2);
return y-x;

}
int main(){
char a[1000001];
scanf("%c",a);
char b[100001][100001];
int len=strlen(a);
int r=0;int c=0;
for(int i=0;i<len;i++){
    if(strstr(b[r],a[i])==NULL)
    {b[r][c]=a[i];c++;}
    else r=r+1;c=0;
}
int out[100001];
qsort(b,r,sizeof(b[0]),cmp);
printf("%s",b[0]);
return 0;


}