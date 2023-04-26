#include <stdio.h>

//const char *words[10] = {
//	"ZERO",
//	"ONE",
//	"TWO",
//	"THREE",
//	"FOUR",
//	"FIVE",
//	"SIX",
//	"SEVEN",
//	"EIGHT",
//	"NINE",
//};

/*
zero one two three four five six seven eight nine --- z
(zero) one two three four five six seven eight nine --- x
(zero six) one two three four five seven eight nine --- w
(zero six two) one three four five seven eight nine --- g
(zero six two eight) one three four five seven nine --- t
(zero six two eight three) one four five seven nine --- r
(zero six two eight three four) one five seven nine --- f
(zero six two eight three four five) one seven nine --- o
(zero six two eight three four five one) seven nine --- v
(zero six two eight three four five one seven) nine --- i
(zero six two eight three four five one seven nine)
*/

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t ; i ++){
		int map[26] = {0}, num[10] = {0};
		char s[30];
		scanf("%s", s);
		char *p = s;
		while(*p){
			map[*p - 'A'] += 1;
			p ++;
		}
		if(map['Z' - 'A']){
			map['E' - 'A'] -= map['Z' - 'A'];
			map['R' - 'A'] -= map['Z' - 'A'];
			map['O' - 'A'] -= map['Z' - 'A'];
			num[0] += map['Z' - 'A'];
			map['Z' - 'A'] = 0;
		} // 0
		if(map['X' - 'A']){
			map['I' - 'A'] -= map['X' - 'A'];
			map['S' - 'A'] -= map['X' - 'A'];
			num[6] += map['X' - 'A'];
			map['X' - 'A'] = 0;
		} // 6
		if(map['W' - 'A']){
			map['T' - 'A'] -= map['W' - 'A'];
			map['O' - 'A'] -= map['W' - 'A'];
			num[2] += map['W' - 'A'];
			map['W' - 'A'] = 0;
		} // 2
		if(map['G' - 'A']){
			map['E' - 'A'] -= map['G' - 'A'];
			map['I' - 'A'] -= map['G' - 'A'];
			map['H' - 'A'] -= map['G' - 'A'];
			map['T' - 'A'] -= map['G' - 'A'];
			num[8] += map['G' - 'A'];
			map['G' - 'A'] = 0;
		} // 8
		if(map['T' - 'A']){
			map['H' - 'A'] -= map['T' - 'A'];
			map['R' - 'A'] -= map['T' - 'A'];
			map['E' - 'A'] -= map['T' - 'A'] * 2;
			num[3] += map['T' - 'A'];
			map['T' - 'A'] = 0;
		} // 3
		if(map['R' - 'A']){
			map['F' - 'A'] -= map['R' - 'A'];
			map['O' - 'A'] -= map['R' - 'A'];
			map['U' - 'A'] -= map['R' - 'A'];
			num[4] += map['R' - 'A'];
			map['R' - 'A'] = 0;
		} // 8
		if(map['F' - 'A']){
			map['I' - 'A'] -= map['F' - 'A'];
			map['V' - 'A'] -= map['F' - 'A'];
			map['E' - 'A'] -= map['F' - 'A'];
			num[5] += map['F' - 'A'];
			map['F' - 'A'] = 0;
		} // 5
		if(map['O' - 'A']){
			map['N' - 'A'] -= map['O' - 'A'];
			map['E' - 'A'] -= map['O' - 'A'];
			num[1] += map['O' - 'A'];
			map['O' - 'A'] = 0; 
		} // 1
		if(map['V' - 'A']){
			map['S' - 'A'] -= map['V' - 'A'];
			map['E' - 'A'] -= map['V' - 'A'] * 2;
			map['N' - 'A'] -= map['V' - 'A'];
			num[7] += map['V' - 'A'];
			map['V' - 'A'] = 0;
		} // 7
		if(map['I' - 'A']){
			map['N' - 'A'] -= map['I' - 'A'] * 2;
			map['E' - 'A'] -= map['I' - 'A'];
			num[9] += map['I' - 'A'];
			map['I' - 'A'] = 0;
		}
		printf("case #%d:\n", i);
		for(int j = 0 ; j < 10 ; j ++){
			while(num[j] != 0){
				printf("%d", j);
				num[j] --;
			}
		}
		printf("\n");
		
	}
	
	return 0;
}