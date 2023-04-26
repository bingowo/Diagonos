#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 104

typedef struct {
	int hour, minute, second;
}BJTime;

void formatUTCtime(BJTime* tar, char* s) {
	int temp = (s[0] - '0') * 10  + s[1] - '0' + 8;
	tar->hour = temp % 24;
	tar->minute = (s[2] - '0') * 10 + s[3] - '0';
	tar->second = (s[4] - '0') * 10 + s[5] - '0';
}

int VerifyValue(char* gps) {
	int idx = 1, ret = gps[idx];
	while (gps[idx + 1] != '*') {
		ret ^= gps[idx + 1];
		idx++;
	}
	idx += 2;
	int sum = 0;
	for (int i = idx; i < strlen(gps); ++i) {
		sum = sum * 16; 
		if(isdigit(gps[i])) sum += gps[i] - '0';
		else sum += gps[i] - 'A' + 10;
	}
	//printf("%d %d\n", ret, sum);
	return ret == sum;
}

int isSpeGPRMC(char* gps) {
	int sign1 = strstr(gps, "$GPRMC") == NULL ? 0 : 1;
	int cnt = 0;
	for (int i = 0; i < strlen(gps); ++i) {
		if (gps[i] == ',') cnt++;
		if (cnt == 2) {
			cnt = ++i;
			break;
		}
	}
	int sign2 = gps[cnt] == 'A' ? 1 : 0;
	return sign1 & sign2;
}

int main() {
	BJTime tm;
	char t[N];
	memset(t, 0, sizeof(t));
	
	while (scanf("%s", t)) {
		if (strcmp(t, "END") == 0)break;
		if (isSpeGPRMC(t) && VerifyValue(t)) {
			char time[7] = { 0 };
			strncpy(time, t + 7, 6);
			formatUTCtime(&tm, time);
		}
		memset(t, 0, sizeof(t));
	}
	printf("%02d:%02d:%02d", tm.hour, tm.minute, tm.second);
	return 0;
}