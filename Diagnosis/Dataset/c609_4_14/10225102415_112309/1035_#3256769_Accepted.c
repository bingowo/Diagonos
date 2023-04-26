#include <stdio.h>
#include <string.h>

// 插入字符 insert()
// 消除字符并返回消除数 cntDel()
// 判断是否需要消除 isRep() 

int isRep(char *data) {
	int len = strlen(data);
	if (len <= 1) return 0;
	for (int i = 1; i < len; i++) {
		if (data[i] == data[i-1]) return 1;
	}
	return 0;
}

int cntDel(char *data) {
	int cnt = 0;
	while (isRep(data)) {
		//printf("BEF:%d %s\n", isRep(data), data);
		char delData[120];
		int len = strlen(data);
		int j = 0;
		for (int i = 0; i < len; i++) {
			if (data[i] == data[i+1]) {
				int repNum = 1;
				for (repNum; data[i+repNum] == data[i]; repNum++);
				//printf("repNum:%d ", repNum);
				cnt += repNum;
				i += repNum - 1;
			} else {
				delData[j] = data[i];
				//printf("delData:%s\n", delData);
				j++;
			}
		}
		delData[j] = '\0';
		strcpy(data, delData); //str库函数对字符串操作，需要保证字符串完整性：'\0' 
		for (int k = j + 1; k < len + 1; k++){
			data[k] = '\0';
		}
		//printf("AFT:%d %s\n", isRep(data), data);
	}
	return cnt;
}

int insert(char *data, char c) {
//	printf("insert:%c\n", c); 
	int maxCnt = 0;
	int len = strlen(data);
	char isrData[len+2];
	for (int i = 0; i < len+1; i++) {
		int j = 0;
		for (j; j < i; j++) {
			isrData[j] = data[j];
		}
		isrData[j] = c;
		j++;
		for (j; j < len+1; j++) {
			isrData[j] = data[j-1];
		}
		isrData[j] = '\0';
//		printf("isr:%s\n", isrData);
		int cnt = cntDel(isrData);
		if (cnt > maxCnt) maxCnt = cnt;
	}
//	printf("maxCnt:%d\n", maxCnt);
	return maxCnt;
}

int solve(char *data) {
	int ret = 0;
	int ans[5];
	ans[0] = insert(data, 'A');
	ans[1] = insert(data, 'B');
	ans[2] = insert(data, 'C');
	for (int i = 0; i < 3; i++) {
		if (ret < ans[i]) ret = ans[i];
	}
//	printf("A B C - %d %d %d\n",ans[0],ans[1],ans[2]);
//	printf("solve:%d\n\n",ret);
	return ret;
	
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char data[120] = {0};
		scanf("%s", &data);
		int ret = solve(data);
		printf("case #%d:\n", i);
		printf("%d\n",ret);
	}
	return 0;
}