#include <stdio.h>
#include <stdlib.h>
int cmp(const void*e1,const void*e2){
int n1,n2;
n1=*((int*)e1);
n2=*((int*)e2);
return n1-n2;

}

int main()
{char a;
a=getchar();
int b[1001]={0};
int k=0;
while(scanf("%d",&b[k])!=EOF){
k++;
}
qsort(b,1001,sizeof(b[0]),cmp);
int j;
if(a=='A'){
for( j=0;j<1000;j++){
if(b[j]==0) continue;
if(b[j]==b[j+1]) continue;
printf("%d ",b[j]);
}
printf("%d",b[j]);
}else{for( j=1001;j>0;j--){
if(b[j]==0) continue;
if(b[j]==b[j-1]) continue;
printf("%d ",b[j]);
}
printf("%d",b[j]);




}
return 0;
}
