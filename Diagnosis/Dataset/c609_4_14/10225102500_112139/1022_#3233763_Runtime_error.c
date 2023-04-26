#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mail{
char* name;
char* realm;
};
typedef struct mail Mail;
char a[1000000]={0};

int cmp(const void*e1,const void* e2){
Mail m;
Mail n;
m=*(Mail*) e1;
n=*(Mail*) e2;
char* p;
char* q;
char* s;
char* t;
p=m.name;
q=n.name;
s=m.realm;
t=n.realm;
int r;
r=strcmp(p,q);
if(r!=0) return r;
else return -strcmp(s,t);


}





int main()
{int n;
scanf("%d",&n);
getchar();
Mail* b=(Mail*)malloc(n*sizeof(Mail));
int len=0;
for(int i=0;i<n;i++){
        char c;

     int   flag=0;
        b[i].name=a+len;
        int j=0;
while((c=getchar())!='@'){
(b[i].name)[j]=c;
j++;
len++;
}
if((c=getchar())=='@'){
(b[i].name)[j]=0;
len++;
}
b[i].realm=a+len;
j=0;
while((c=getchar())!='\n'&&(c=getchar())!=EOF){
(b[i].realm)[j]=c;
j++;
len++;
}
(b[i].realm)[j]=0;
len++;
}
qsort(b,n,sizeof(b[0]),cmp);
for(int i=0;i<n;i++){
printf("%s@%s\n",b[i].name,b[i].realm) ;




}
free(b);

return 0;











}



