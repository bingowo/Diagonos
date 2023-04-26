#include <stdio.h>
#include <string.h>
struct person{
  int abo,rh;  
};
const int ABO[4][4][4]=
{{{1,0,0,1},{1,1,1,0},{1,1,1,1},{1,0,0,1}},
{{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,0,1,0}},
{{1,1,1,1},{1,1,1,0},{0,0,1,1},{0,0,1,1}}, 
{{1,0,0,1},{1,0,1,0},{0,0,1,1},{0,0,0,1}}};
const int RH[2][2][2]={
  {{1,1},{1,1}},
  {{1,1},{0,1}}
};
struct person read()
{
    char s[10];
    struct person flag;
    flag.abo=-1;
	flag.rh=-1; 
    scanf("%s",s);
    if(strcmp(s,"A+")==0) {flag.abo=0;flag.rh=0;}
    else if(strcmp(s,"AB+")==0) {flag.abo=1;flag.rh=0;}
    else if(strcmp(s,"B+")==0) {flag.abo=2;flag.rh=0;}
    else if(strcmp(s,"O+")==0) {flag.abo=3;flag.rh=0;}
    else if(strcmp(s,"A-")==0) {flag.abo=0;flag.rh=1;}
    else if(strcmp(s,"AB-")==0) {flag.abo=1;flag.rh=1;}
    else if(strcmp(s,"B-")==0) {flag.abo=2;flag.rh=1;}
    else if(strcmp(s,"O-")==0) {flag.abo=3;flag.rh=1;}
    return flag;
}
void write(struct person p)
{
    if(p.abo==0) printf("A");
    else if(p.abo==1) printf("AB");
    else if(p.abo==2) printf("B");
    else if(p.abo==3) printf("O");
    
    if(p.rh==0) printf("+");
    else if(p.rh==1) printf("-");
}
void print(struct person* L,int len)
{
	if(len==0) printf("impossible");
	else {
		if(len>1) printf("{");
		for(int i=0;i<len;i++)
		{
			if(i==len-1) write(L[i]);
			else {
				write(L[i]);
				printf(",");
			}
		}
		if(len>1) printf("}");
	}
}
int main()
{
	int cnt=0;
	scanf("%d",&cnt);
	for(int mm=0;mm<cnt;mm++){
    struct person father,mother,child;
    father = read();
    mother = read();
    child = read();
    struct person temp[8];
    int k=0;
    if(father.abo==-1){
        for(int i=0;i<4;i++)
        {
        	for(int j=0;j<2;j++)
        	{
        		if(ABO[i][mother.abo][child.abo]==1 
					&& RH[j][mother.rh][child.rh]==1){
					temp[k].abo=i;
					temp[k].rh =j;
					k++;
				}
			}
		}
		print(temp,k);
		printf(" ");
		write(mother);
		printf(" ");
		write(child); 
    }
    else if(mother.abo==-1){
        write(father);
        printf(" ");
        for(int i=0;i<4;i++)
        {
        	for(int j=0;j<2;j++)
        	{
        		if(ABO[father.abo][i][child.abo]==1 
					&& RH[father.rh][j][child.rh]==1){
					temp[k].abo=i;
					temp[k].rh =j;
					k++;
				}
			}
		}
		print(temp,k);
		printf(" ");
		write(child);
    }
    else if(child.abo==-1){
        write(father);
		printf(" ");
		write(mother);
		printf(" "); 
		for(int i=0;i<4;i++)
        {
        	for(int j=0;j<2;j++)
        	{
        		if(ABO[father.abo][mother.abo][i]==1 
					&& RH[father.rh][mother.rh][j]==1){
					temp[k].abo=i;
					temp[k].rh =j;
					k++;
				}
			}
		}
		print(temp,k);
    }
    printf("\n");
}
    return 0;
}