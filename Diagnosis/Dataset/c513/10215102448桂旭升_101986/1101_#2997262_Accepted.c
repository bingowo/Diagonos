#include <stdio.h>
#include<string.h>
char o[2] = {'+', '-'};
char sub[3] = {0};
char c1[11];
char c2[11];
char c3[11];
char s[50];
char AABBO[] = {'{','A',',','A','B',',','B',',','O','}','\0'};
char AABB[] = {'{','A',',','A','B',',','B','}','\0'};
char ABB[] = {'{','A','B',',','B','}','\0'};
char AAB[] = {'{','A',',','A','B','}','\0'};
char ABO[] = {'{','A',',','B',',','O','}','\0'};
void up(){
	if(c1[0] == '?'){
		c1[0] = '\0'; 
		if(c3[0] == 'O') {
			if(strlen(c2) != 2)strcat(c1, ABO);
			else if(strlen(c2) == 2)strcat(c1, "impossible");
		}
		else if(c3[0] == 'A' && c3[1] != 'B' ){
			if(c2[0] != 'A')strcat(c1, AAB);
			else strcat(c1, AABBO);
		}
		else if(c3[0] == 'A' && c3[1] == 'B'){
			if(c2[0] == 'O')strcat(c1, "impossible");
			else if(c2[0] == 'B')strcat(c1, AAB);
			else if(c2[0] == 'A'&&strlen(c2)==1)strcat(c1, ABB);
			else strcat(c1, AABB);
		}
		else if(c3[0] == 'B'){
			if(c2[0] != 'B'&&strlen(c2)!=2)strcat(c1, ABB);
			else strcat(c1, AABBO);
		}
	}
	if(c2[0] == '?'){
		c2[0] = '\0'; 
		if(c3[0] == 'O') {
			if(strlen(c1) != 2)strcat(c2, ABO);
			else if(strlen(c1) == 2)strcat(c2, "impossible");
		}
		else if(c3[0] == 'A' && c3[1] != 'B' ){
			if(c1[0] != 'A')strcat(c2, AAB);
			else strcat(c2, AABBO);
		}
		else if(c3[0] == 'A' && c3[1] == 'B'){
			if(c1[0] == 'O')strcat(c2, "impossible");
			else if(c1[0] == 'B')strcat(c2, AAB);
			else if(c1[0] == 'A'&&strlen(c1)==1)strcat(c2, ABB);
			else strcat(c2, AABB);
		}
		else if(c3[0] == 'B'){
			if(c1[0] != 'B'&&strlen(c1)!=2)strcat(c2, ABB);
			else strcat(c2, AABBO);
		}
	}
}
void next(){
	int len1 = strlen(c1), len2 = strlen(c2);
	c3[0] = '\0'; 
	if(len1 == 1 && len2 == 1){
		if(c1[0] == c2[0]){//printf("%s %s %c\n", c1, c2, c3[0]);
			if(c1[0] != 'O'){
				c3[0] = '{'; c3[1] = c1[0]; c3[2] = ',';
				c3[3] = 'O'; c3[4] = '}';c3[5] = '\0';
			}
			else{
				c3[0] = '{';c3[1] = c1[0];c3[2] = '}';c3[3] = '\0';
			}
		}
		else if(c1[0] != c2[0]){
			if(c1[0] != 'O' && c2[0] != 'O'){
				strcat(c3, AABBO);
			}
			else{
				c3[0] = '{'; c3[1] = (c1[0] == 'O'? c2[0]:c1[0]); c3[2] = ',';
				c3[3] = 'O';c3[4] = '}';c3[5] = '\0';
			}
		}
	}
	else if(len1 != len2){
		if(c1[0] != 'O' && c2[0] != 'O'){
			c3[0] = '{'; c3[1] = 'A'; c3[2] = ',';
			c3[3] = 'A'; c3[4] = 'B';c3[5] = ','; c3[6] = 'B';c3[7] = '}';c3[8] = '\0';
		}
		else{
			c3[0] = '{'; c3[1] = 'A'; c3[2] = ',';
			c3[3] = 'B';c3[4] = '}';c3[5] = '\0';
		}
		
	}
	else if(len1 == 2 && len2 == 2){
		c3[0] = '{'; c3[1] = 'A'; c3[2] = ',';
		c3[3] = 'A'; c3[4] = 'B';c3[5] = ',';c3[6] = 'B'; c3[7] = '}';c3[8] = '\0';
	}
}
int main(){
	int N, M, K, i, j = 0, ul = 0, ans = 0, len, con = 0, t, k, flag = 0, cnt, l = 0;
    char o1, o2, o3;
    scanf("%d", &t);gets(s);
    for(k = 0; k < t; k++){
        flag = 0; cnt = 0; l = 0;
    gets(s); len = strlen(s);
    for(i = 0; i< len; i++){
    	if(s[i] == ' '){
    		i++;break;
		}
    	c1[j++] = s[i];
	}
	c1[j] = '\0'; j = 0;
	for(; i< len; i++){
    	if(s[i] == ' '){
    		i++;break;
		}
    	c2[j++] = s[i];
	}
	c2[j] = '\0'; j = 0;
	for(; i< len; i++){
    	if(s[i] == ' '){
    		i++;break;
		}
    	c3[j++] = s[i];
	}
	c3[j] = '\0'; j = 0;
    o1 = c1[strlen(c1) - 1]; o2 = c2[strlen(c2) - 1]; o3 = c3[strlen(c3) - 1];
    if(c1[0] == '?' || c2[0] == '?'){
        if(c1[0] == '?'){
            if(o2 == '-' && o3 == '+')flag = 1;
            c2[strlen(c2) - 1] = '\0'; c3[strlen(c3) - 1] = '\0';
            up();
            if(strcmp(c1, "impossible") == 0)printf("%s", c1);
            else{
            if(flag == 0){
                for(i = 0; i < strlen(c1); i++){
                    if(c1[i] == ',' || c1[i] == '}'){
                        sub[l] = '\0'; l = 0;
                        printf("+,%s-", sub);
                    }
                    printf("%c", c1[i]);
                    if(c1[i] != ',' && c1[i] != '{')sub[l++] = c1[i];
                }
            }
            else{
                if(strlen(c1) == 3)printf("%c+", c1[1]);
                else{
                for(i = 0; i < strlen(c1); i++){
                    if(c1[i] == ',' || c1[i] == '}')printf("+");
                    printf("%c", c1[i]);
                }
                }
            }
            }
            printf(" %s%c %s%c\n", c2, o2, c3, o3);
        }
        else{
            if(c1[strlen(c1) - 1] == '-' && c3[strlen(c3) - 1] == '+')flag = 1;
            c1[strlen(c1) - 1] = '\0'; c3[strlen(c3) - 1] = '\0';
            up();
            if(strcmp(c2, "impossible") == 0)printf("%s%c %s %s%c\n", c1, o1, c2, c3, o3);
            else{
                printf("%s%c ", c1, o1);
            if(flag == 0){
                for(i = 0; i < strlen(c2); i++){
                    if(c2[i] == ',' || c2[i] == '}'){
                        sub[l] = '\0'; l = 0;
                        printf("+,%s-", sub);
                    }
                    printf("%c", c2[i]);
                    if(c2[i] != ',' && c2[i] != '{')sub[l++] = c2[i];
                }
            }
            else{
                if(strlen(c2) == 3)printf("%c+", c2[1]);
                else{
                for(i = 0; i < strlen(c2); i++){
                    if(c2[i] == ',' || c2[i] == '}')printf("+");
                    printf("%c", c2[i]);
                }
                }
            }
            printf(" %s%c\n", c3, o3);
            }
        }
    	
	}
	else{
        c1[strlen(c1) - 1] = '\0'; c2[strlen(c2) - 1] = '\0';
        if(o1 == '-' && o2 == '-')flag = 1;
		next();
        printf("%s%c %s%c ", c1, o1, c2, o2);
        if(flag == 0){
            for(i = 0; i < strlen(c3); i++){
                if(c3[i] == ',' || c3[i] == '}'){
                    sub[l] = '\0'; l = 0;
                    printf("+,%s-", sub);
                }
                printf("%c", c3[i]);
                if(c3[i] != ',' && c3[i] != '{')sub[l++] = c3[i];
            }
        }
        else{
            if(strlen(c3) == 3)printf("%c-", c3[1]);
            else{
            for(i = 0; i < strlen(c3); i++){
                if(c3[i] == ',' || c3[i] == '}')printf("-");
                printf("%c", c3[i]);
            }
            }
        }
        printf("\n");
	}
    }
    //system("pause");
	return 0;
}