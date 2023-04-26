#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int ABO[4][4][4]=//******************      A,AB,B,O==0,1,2,3
{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,    //A
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,  //AB
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1,  //B
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1}; //O

int read(char*s)
{   int flag=0;
	if(strcmp(s,"A")==0) flag=1;
	else if(strcmp(s,"AB")==0) flag=2;
	else if(strcmp(s,"B")==0) flag=3;
	else if(strcmp(s,"O")==0) flag=4;
	else if(strcmp(s,"?")==0) flag=0; 
	return flag-1;
}
void put(int k)
{
	if(k==0) putchar('A');
	else if(k==1) putchar('A'),putchar('B');
	else if(k==2) putchar('B');
	else if(k==3) putchar('O');
} 
void match(int a,int b,int k,char*fa,char*mo,char*ki)
{   int j,t[5],d=0;
	for(j=0;j<5;j++) t[j]=-1;
	if(a==-1)
	{  for(j=0;j<4;j++) 
	      if(ABO[j][b][k]==1) t[d++]=j;//存在就记录这个血型 
	    if(d==0) printf("impossible %s %s",mo,ki);
	    else { 
	    	printf("{");
	    	for(j=0;j<d;j++) 
			{
			  put(t[j]);
			  printf("%c",((j+1)<d)?',':'}');
		    }
		    printf(" ");
		    printf("%s %s",mo,ki);
		}
	}
	else if(b==-1)
	{for(j=0;j<4;j++) 
	      if(ABO[a][j][k]==1) t[d++]=j;//存在就记录这个血型 
	    if(d==0) printf("%s impossible %s",fa,ki);
	    else { 
	    	printf("%s",fa);
	    	printf(" ");
	    	printf("{");
	    	for(j=0;j<d;j++) 
			{
			  put(t[j]);
			  printf("%c",((j+1)<d)?',':'}');
		    }
		    printf(" ");
		    printf("%s",ki);
		}
		
	}
	else if(k==-1)
	{for(j=0;j<4;j++) 
	      if(ABO[a][b][j]==1) t[d++]=j;//存在就记录这个血型 
	      printf("%s %s",fa,mo);
	      printf(" ");
	    	printf("{");
	    	for(j=0;j<d;j++) 
			{
			  put(t[j]);
			  printf("%c",((j+1)<d)?',':'}');
		    }
	}
}
 int main()
 {    char fa[50]={'\0'};
 	  char mo[50]={'\0'};
 	  char ki[50]={'\0'};
 	  scanf("%s %s %s",fa,mo,ki);
 	  match(read(fa),read(mo),read(ki),fa,mo,ki);
		return 0;
}