#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct maya{
int day;
int year;
char month[7];
} Maya ;
char key[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet",};
int value(const void *e){
char* p;
p=(char*) e;
int k;
for(k=0;k<19;k++){
if(strcmp(e,key[k])==0){
break;
}

}
return k;
}


int cmp(const void *e1,const void *e2){
Maya m,n;
m=*(Maya *)e1;
n=*(Maya *)e2;
if(m.year!=n.year) return m.year-n.year;
else if(value(m.month)!=value(n.month)) return value(m.month)-value(n.month);
else if(m.day!=n.day) return m.day-n.day;
else return 0;

}

int main(){
int t;
scanf("%d",&t);
for(int i=0;i<t;i++){
int n;
scanf("%d",&n) ;
Maya* a;
a=(Maya *)malloc(n*sizeof(Maya));

for(int j=0;j<n;j++){

scanf("%d%. %s %d",&a[j].day,a[j].month,&a[j].year);

}
qsort(a,n,sizeof(Maya),cmp);
printf("case #%d\n",i);
for(int j=0;j<n;j++){
printf("%d. %s %d\n",a[j].day,a[j].month,a[j].year);
}
free(a);
}
return 0;



}
