#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		char s[21];
		int m[128]={0},d[10]={0};
		int j=0,len;
		scanf("%s",s);
		len=strlen(s);
		 for(;j<len;j++){m[s[j]]++; }
		  while(m['Z']--!=0){m['E']--;m['R']--;m['O']--;d[0]++;}
          while(m['W']--!=0){m['T']--;m['O']--;d[2]++;}
          while(m['U']--!=0){m['F']--;m['O']--;m['R']--;d[4]++;}
          while(m['G']--!=0){ m['I']--;m['E']--;m['H']--;m['T']--;d[8]++;}
          while(m['H']--!=0){m['T']--;m['R']--;m['E']-=2;d[3]++;}
          while(m['X']--!=0){m['S']--;m['I']--;d[6]++;}
          while(m['F']--!=0){m['I']--;m['V']--;m['E']--;d[5]++;}
          while(m['V']--!=0){m['S']--;m['N']--;m['E']-=2;d[7]++;}
          while(m['I']--!=0){m['N']-=2;m['E']--;d[9]++;}
          d[1]=m['O'];
          printf("case #%d:\n",v);
          for(int i=0;i<d[0];i++) printf("0");
          for(int i=0;i<d[1];i++) printf("1");
          for(int i=0;i<d[2];i++) printf("2");
          for(int i=0;i<d[3];i++) printf("3");
          for(int i=0;i<d[4];i++) printf("4");
          for(int i=0;i<d[5];i++) printf("5");
          for(int i=0;i<d[6];i++) printf("6");
          for(int i=0;i<d[7];i++) printf("7");
          for(int i=0;i<d[8];i++) printf("8");
          for(int i=0;i<d[9];i++) printf("9");
          printf("\n");
        }
return 0;
        }
 
