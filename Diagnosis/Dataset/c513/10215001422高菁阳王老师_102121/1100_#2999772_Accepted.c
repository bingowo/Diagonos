#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct point{
	int a,b;
};
int sol(int t,int r){
	if(t==0&&r!=0) return -2;
	if(t==0&&r==0) return -1;
	if(r%t!=0||r/t<0) return -2;
	return r/t;
}
int main(int argc, char *argv[]) {
	struct point pos[200];
	char s[200];
	int q,j,a,b,m1,m2,flag;
	scanf("%s",s);
	int len=strlen(s);
	pos[0].a=0;pos[0].b=0;
for(int i=1;i<=len;i++){
      switch(s[i-1]){
	case'U':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b+1;break;
	case'D':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b-1;break;
	case'L':pos[i].a=pos[i-1].a-1;pos[i].b=pos[i-1].b;break;
	case'R':pos[i].a=pos[i-1].a+1;pos[i].b=pos[i-1].b;break;
   }
}
     scanf("%d",&q);
     for(int i=0;i<q;i++){
     	scanf("%d %d",&a,&b);
     	flag=0;
     	for(j=0;j<=len;j++){
     		m1=sol(pos[len].a,a-pos[j].a);
     		m2=sol(pos[len].b,b-pos[j].b);
     		if(m1==-2||m2==-2) continue;
     		if(m1==-1||m2==-1||m1==m2){
     			flag=1;break;
			 }
		 }if(flag) printf("Yes\n");
		 else printf("No\n");
	 }
     
	return 0;
}