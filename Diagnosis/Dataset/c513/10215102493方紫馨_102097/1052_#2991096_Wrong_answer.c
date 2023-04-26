#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);	
	for(int i=0;i<T;i++){
		int alph[26] = {0};
		printf("case #%d:\n",i);
		char s[21];
		scanf("%s",s);
		int num[10] = {0},n;
		for(int i=0;i<strlen(s);i++){
			alph[s[i]-'A'] ++;
		}
		//0
		n = alph['Z'-'A'];
		if(n > 0){
			num[0] += n;
			alph['Z'-'A'] -=n;
			alph['E'-'A'] -=n;
			alph['R'-'A'] -=n;
			alph['O'-'A'] -=n;
		}
		//6
		n = alph['X'-'A'];
		if(n > 0){
			num[6] += n;
			alph['S'-'A'] -= n;
			alph['I'-'A'] -= n;
			alph['X'-'A'] -= n;
		}
		//2
		n = alph['W'-'A'];
		if(n > 0){
			num[2] += n;
			alph['T'-'A'] -=n;
			alph['W'-'A'] -=n;
			alph['O'-'A'] -=n;
		}
		//7
		n = alph['V'-'A'];
		if(n > 0){
			num[7] += n;
			alph['S'-'A'] -=n;
			alph['E'-'A'] -=n;
			alph['V'-'A'] -=n;
			alph['E'-'A'] -=n;
			alph['N'-'A'] -=n;
		}
		//4
		n = alph['U'-'A'];
		if(n > 0){
			num[4] += n;
			alph['F'-'A'] -=n;
			alph['O'-'A'] -=n;
			alph['U'-'A'] -=n;
			alph['R'-'A'] -=n;
		}
		//8
		n = alph['G'-'A'];
		if(n > 0){
			num[8] += n;
			alph['E'-'A'] -=n;
			alph['I'-'A'] -=n;
			alph['G'-'A'] -=n;
			alph['H'-'A'] -=n;
			alph['T'-'A'] -=n;
		}
		//3
		n = alph['H'-'A'];
		if(n > 0){
			num[3] += n;
			alph['T'-'A'] -=n;
			alph['H'-'A'] -=n;
			alph['R'-'A'] -=n;
			alph['E'-'A'] -=n;
			alph['E'-'A'] -=n;
		}
		//5
		n = alph['F'-'A'];
		if(n > 0){
			num[5] += n;
			alph['F'-'A'] -=n;
			alph['I'-'A'] -=n;
			alph['V'-'A'] -=n;
			alph['E'-'A'] -=n;
		}
		//9
		n = alph['I'-'A'];
		if(n > 0){
			num[9] += n;
			alph['N'-'A'] -=n;
			alph['I'-'A'] -=n;
			alph['N'-'A'] -=n;
			alph['E'-'A'] -=n;
		}
		//1
		n = alph['N'-'A'];
		if(n > 0){
			num[1] += n;
			alph['O'-'A'] -=n;
			alph['N'-'A'] -=n;
			alph['E'-'A'] -=n;
		}
		for(int i=0;i<10;i++){
			while(num[i]>0){
				printf("%d",i);
				num[i]--;
			}
				
		}
		printf("\n");
		
	}
	
	return 0;
}

//one two three four five six seven eight nine zero
//e 3 5 7 9 0
//f 4 5			\ 5
//g 8			\ 8
//h 2 3 8		\ 3
//i 5 6 8 9		\ 9
//n 1 7 9
//o 1 2 4 0
//r 3 0			\ 0
//s 6 7			\ 6
//t 2 3 8		\
//u 4			\ 4
//v 7			\ 7
//w 2			\ 2
//x 6			\ 6
//z 0 			\ 0

