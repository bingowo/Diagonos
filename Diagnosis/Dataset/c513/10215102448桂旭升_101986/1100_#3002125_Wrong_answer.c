#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int k, n, i, j = 0, l = 0, x, y, len, flag, r;
    char s[101];int a[101][2] = {0};
    scanf("%s", s); len = strlen(s);
    for(i = 0; i < len; i++){
        if(s[i] == 'U')l++;
        if(s[i] == 'D')l--;
        if(s[i] == 'L')j--;
        if(s[i] == 'R')j++;
        a[i+1][0] = j; a[i+1][1] = l;
    }
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        flag = 0;
        scanf("%d%d", &x, &y);
        if(a[len][0] == 0 && a[len][1] != 0){
            for(j = 0; j <= len; j++){
                if(x == a[j][0] && (a[j][1]-y)%a[len][1] == 0 && y*a[len][1]>=0){
                    flag = 1; printf("Yes\n"); break;
                }
            }
            if(!flag) printf("No\n");
        }
        else if(a[len][0] != 0 && a[len][1] == 0){
            for(j = 0; j <= len; j++){
                if((a[j][0] - x)%a[len][0] == 0 && y == a[j][1] && x*a[len][0]>=0){
                    flag = 1; printf("Yes\n"); break;
                }
            }
            if(!flag) printf("No\n");
        }
        else if(a[len][0] == 0 && a[len][1] == 0){
            for(j = 0; j <= len; j++){
                if(x == a[j][0] && y == a[j][1]){
                    flag = 1; printf("Yes\n"); break;
                }
            }
            if(!flag) printf("No\n");
        }
        else if(a[len][0] != 0 && a[len][1] != 0){
            for(j = 0; j <= len; j++){
                if((a[j][0] - x)%a[len][0] == 0 && (a[j][1] - y)%a[len][1] == 0 && (x - a[j][0])/a[len][0]==(y - a[j][1])/a[len][1] && y*a[len][1]>=0 && x*a[len][0]>=0){
                    flag = 1; printf("Yes\n"); break;
                }
            }
            if(!flag) printf("No\n");
        }
    }
    system("pause");
	return 0;
}