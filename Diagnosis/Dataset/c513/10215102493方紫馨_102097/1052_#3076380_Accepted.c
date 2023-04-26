#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		char s[21];
		int num[30]={0};
		int ret[10]={0},n;
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++){
			num[s[i]-'A']++;
		}
		//8
		n=num['G'-'A']; 
		if(n!=0){
			ret[8]=n;
			num['E'-'A']-=n;
			num['I'-'A']-=n;
			num['G'-'A']-=n;
			num['H'-'A']-=n;
			num['T'-'A']-=n;
		}
		//0
		n=num['Z'-'A'];
		if(n!=0){
			ret[0]=n;
			num['Z'-'A']-=n;
			num['E'-'A']-=n;
			num['R'-'A']-=n;
			num['O'-'A']-=n;
		}
		//2
		n=num['W'-'A'];
		if(n!=0){
			ret[2]=n;
			num['T'-'A']-=n;
			num['W'-'A']-=n;
			num['O'-'A']-=n;
		}
		//4
		n=num['U'-'A'];
		if(n!=0){
			ret[4]=n;
			num['F'-'A']-=n;
			num['O'-'A']-=n;
			num['U'-'A']-=n;
			num['R'-'A']-=n;
		}
		//1
		n=num['O'-'A'];
		if(n!=0){
			ret[1]=n;
			num['O'-'A']-=n;
			num['N'-'A']-=n;
			num['E'-'A']-=n;
		}
		//3
		n=num['T'-'A'];
		if(n!=0){
			ret[3]=n;
			num['T'-'A']-=n;
			num['H'-'A']-=n;
			num['R'-'A']-=n;			
			num['E'-'A']-=n+n;		
		}
		//6
		n=num['X'-'A'];
		if(n!=0){
			ret[6]=n;
			num['S'-'A']-=n;
			num['I'-'A']-=n;
			num['X'-'A']-=n;
		}
		//7
		n=num['S'-'A'];
		if(n!=0){
			ret[7]=n;
			num['S'-'A']-=n;
			num['E'-'A']-=n+n;
			num['V'-'A']-=n;			
			num['N'-'A']-=n;		
		}
		//5
		n=num['F'-'A'];
		if(n!=0){
			ret[5]=n;
			num['F'-'A']-=n;
			num['I'-'A']-=n;
			num['V'-'A']-=n;			
			num['E'-'A']-=n;		
		}
		//9
		n=num['I'-'A'];
		if(n!=0){
			ret[9]=n;
			num['N'-'A']-=n;
			num['I'-'A']-=n;
			num['N'-'A']-=n;			
			num['E'-'A']-=n;		
		}
		printf("case #%d:\n",k);
		for(int i=0;i<10;i++){
			for(int j=0;j<ret[i];j++){
				printf("%d",i);
			}
		}
		printf("\n");
	}
	
	return 0;
 } 
 
/*	0		ZERO		Z
	1		ONE			O
	2		TWO			W
	3		THREE		T
	4		FOUR		U
	5		FIVE		F
	6		SIX			X
	7		SEVEN		S
	8		EIGHT		G
	9		NINE		I
	*/