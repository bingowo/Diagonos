#include<stdio.h>
#include<string.h>
const int ABO[4][4][4]=
{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,  1,1,1,0,  1,0,1,0,
1,1,1,1,   1,1,1,0,  0,0,1,1,  0,0,1,1, 
1,0,0,1,   1,0,1,0,  0,0,1,1,  0,0,0,1};
int ans_ABO[4];
int ans_rh[2];
const int rh[2][2][2]={1,1,1,1,1,1,0,1};
typedef struct{
	int flag1;
	int rh1;
}pair;
pair read(){
	pair a;
	char s[10],temp[10];
	scanf("%s",s);
	char *p1=s,*p2=s;
	for(;*p2!='+'&&*p2!='-'&&p2<s+strlen(s);p2++);
	memmove(temp,p1,p2-p1);
	temp[p2-p1]='\0';
	int flag=0;
	if(!strcmp(temp,"A")) flag=1;
	else if(!strcmp(temp,"B")) flag=3;
	else if(!strcmp(temp,"AB")) flag=2;
	else if(!strcmp(temp,"O")) flag=4;
	else if(!strcmp(temp,"?")) flag=0;
	a.flag1=flag;
	if(*p2=='+') a.rh1=1;
	else a.rh1=2;
	return a;
}
void pd(int a){
	if(a==1)  printf("A");
	else if(a==2) printf("AB");
	else if(a==3) printf("B");
	else printf("O"); 
}
void pd1(int a){
	if(a==1) printf("+");
	else printf("-");
} 
void print(int x,int y,int type){
	if(type==1) printf("{");
	else if(type>1) printf(",");
	if(x==1&&y==1) printf("A+");
	if(x==1&&y==2) printf("A-");
	if(x==2&&y==1) printf("AB+");
	if(x==2&&y==2) printf("AB-");
	if(x==3&&y==1) printf("B+");
	if(x==3&&y==2) printf("B-");
	if(x==4&&y==1) printf("O+");
	if(x==4&&y==2) printf("O-"); 
} 
void write(){
	int ABO=0;
	int key=0;
	int count=0;
	for(int j=0;j<4;j++){
		if(!ans_ABO[j]) count++;
	}
	for(int i=0;i<4;i++) ABO+=ans_ABO[i];
	if(ABO==0) printf("impossible");
	else if(count==1&&ans_rh[0]==0){
		printf("{O-}");
	}
	else{
		int cnt=0;
		for(int i=0;i<4;i++){
			if(ans_ABO[i]){
				cnt++;
				for(int j=0;j<2;j++){
					if(ans_rh[j]) {print(i+1,j+1,cnt);cnt++;}
				}
			}
		}
		printf("}");
	}
}
int main(){
	int chance;
	scanf("%d",&chance);
	int t;
	for(t=0;t<chance;t++){
	pair father,mother,child;
	int i,j,m1,c1,f1;
	father=read(),mother=read(),child=read();
	if(father.flag1==0){
		m1=mother.flag1-1;
		c1=child.flag1-1;
		for(i=0;i<4;i++) ans_ABO[i]=ABO[i][m1][c1];
		for(i=0;i<2;i++) ans_rh[i]=rh[i][mother.rh1-1][child.rh1-1];
		write();
		printf(" ");
		pd(mother.flag1);
		pd1(mother.rh1);
		printf(" ");
		pd(child.flag1);
		pd1(child.rh1);
		printf("\n");
	}
	if(mother.flag1==0){
		f1=father.flag1-1;
		c1=child.flag1;-1;
		for(i=0;i<4;i++) ans_ABO[i]=ABO[f1][i][c1];
		for(i=0;i<2;i++) ans_rh[i]=rh[father.rh1-1][i][child.rh1-1];
		pd(father.flag1);
		pd1(father.rh1);
		printf(" ");
		write();
		printf(" ");
		pd(child.flag1);
		pd1(child.rh1);
		printf("\n");
	}
	if(child.flag1==0){
		f1=father.flag1-1;
		m1=mother.flag1-1;
		for(i=0;i<4;i++) ans_ABO[i]=ABO[f1][m1][i];
		for(i=0;i<2;i++) ans_rh[i]=rh[father.rh1-1][mother.rh1-1][i];
		pd(father.flag1);
		pd1(father.rh1);
		printf(" ");
		pd(mother.flag1);
		pd1(mother.rh1);
		printf(" ");
		write();
		printf("\n");
	}
}
}