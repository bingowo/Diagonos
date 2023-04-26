#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
//char table[20]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

typedef struct Date{
    int year;
    int month;
	int day;
	char mon[8]; 
}D;
int find(char a,char b){
	if(a=='p'&& b=='o') return 1;
	if(a=='n'&& b=='o') return 2;
	if(a=='z'&& b=='i') return 3;
	if(a=='z'&& b=='o') return 4;
	if(a=='t'&& b=='z') return 5;
	if(a=='x'&& b=='u') return 6;
	if(a=='y'&& b=='o') return 7;
	if(a=='m'&& b=='o') return 8;
	if(a=='c'&& b=='h') return 9;
	if(a=='y'&& b=='a') return 10;
	if(a=='z'&& b=='a') return 11;
	if(a=='c'&& b=='e') return 12;
	if(a=='m'&& b=='a') return 13;
	if(a=='k'&& b=='a') return 14;
	if(a=='m'&& b=='u') return 15;
	if(a=='p'&& b=='a') return 16;
	if(a=='k'&& b=='o') return 17;
	if(a=='c'&& b=='u') return 18;
	if(a=='u'&& b=='a') return 19;
		
}
int  cmp(const void *aa, const void * bb){
	D a=*(D*) aa;
	D b=*(D*) bb;
    if(a.year== b.year){
    	if(a.month==b.month) return a.day-b.day;
    	else return a.month-b.month;
	}
    else return a.year-b.year;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        int n;
        scanf("%d",&n);
        D* s = (D*)malloc(sizeof(D)*(n+1));
        for(int p=0;p<n;p++){
        	s[p].day=0;
        	for(int r=0;r<8;r++){
        		s[p].mon[r]='0';
			}
			s[p].month=0;
			s[p].year=0;	
        }
        for(int j = 0; j < n; j++){
        	scanf("%d",&s[j].day);
        	char ch=getchar();
        	getchar();
        	int l=0;
        	while((ch=getchar())!=' '){
        		s[j].mon[l]=ch;
        		l++;
			}
			s[j].month=find(s[j].mon[0],s[j].mon[1]);
			scanf("%d",&s[j].year);
        }
        qsort(s,n,sizeof(D),cmp);
        for(int p=0;p<n;p++){
        	printf("%d. ",s[p].day);
        	int o=0;
        	while(s[p].mon[o]!='0'){
        		printf("%c",s[p].mon[o]);
        		o++;
			}
			printf(" %d\n",s[p].year);
		}
    }
}