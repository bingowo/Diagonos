#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void erase(vector<string> &lines) {
void erase(char (*lines)[200], int lineCnt) {
	int state = 0;
//    for(auto &i:lines) {
//    	for (size_t j = 0; j < i.size(); j++) {
	for (int i = 0; i < lineCnt; i++) {
		size_t i_size = strlen(lines[i]);
		for (size_t j = 0; j < i_size; j++) {
    		if (state == 0) {
    			if (lines[i][j] == '/') state = 1;
    			else if (lines[i][j] == '\'') state = 6; 
    			else if (lines[i][j] == '"') state = 5;
			} else if (state == 1) {
    			if (lines[i][j] == '/') state = 4;
    			else if (lines[i][j] == '*') state = 2; 
//    			else { state = 0; cout << i[j-1]; }
				else { state = 0; printf("%c", lines[i][j-1]); }
			} else if (state == 2) {
    			if (lines[i][j] == '*') state = 3;
			} else if (state == 3) {
    			if (lines[i][j] == '/' && j != 0) state = 0; 
    			else if (lines[i][j] == '*') state = 3; 
    			else state = 2;
			} else if (state == 5) {
    			if (lines[i][j] == '"') state = 0;
    			else if (lines[i][j] == '\\') state = 8; 
			} else if (state == 6) {
				if (lines[i][j] == '\'') state = 0;
				else if (lines[i][j] == '\\') state = 7; 
			} else if (state == 7) {
				state = 6;
			} else if (state == 8) {
				state = 5;
			}
			if (state == 0 && lines[i][j] == '/' && lines[i][j-1] == '*');
			else if (state == 0 || state == 5 || state == 6 || state == 7 || state == 8)
//				cout << i[j];
				printf("%c", lines[i][j]);
		}
		if (state == 4) state = 0;
//		if (state != 2 && state != 3) cout << endl;
		if (state != 2 && state != 3) printf("\n");
	}
}
    
    
int main() {
	char lines[200][200];
	int lineCnt = 0;
	while (gets(lines[lineCnt++]));
	lineCnt--;
	erase(lines, lineCnt);
    return 0;
}