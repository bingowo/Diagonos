#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve();
int gcd(int up, int down);

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int t = 0; t < T; t++){
    solve();
    }

}

void solve(){
    char s[121];
    gets(s);
    int up = 0;
    int down = 0;
    for(int i = 0; s[i] != '\0'; i++){
        unsigned char ch = s[i];
        while(ch != 0){
            up = up + (ch&1);
            ch = ch >> 1;
        }
        down = down + 8;
    }
    int gcdnum = gcd(up,down);
    printf("%d/%d\n",up/gcdnum, down/gcdnum);
}

int gcd(int up, int down){
	int temp;
	while(down != 0){
		temp = up % down;
		up = down;
		down = temp;
	}
	return up;
}
