#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    int T;
    scanf("%d", &T);getchar();
    for(int i = 0; i < T; ++i) {
        char str[501];
        scanf("%s", str);
        char letters[1001];
        char *p = letters;
        for (int j = 0, l = strlen(str); j < l; ++j){
            int count = 1;
            while (str[j] == str[j+1]){
                count++;
                j++;
            }
            while(count > 255) {
                p += sprintf(p, "%d%c", 255, str[j]);
                count -= 255;
            }
            p += sprintf(p, "%d%c", count, str[j]);
        }
        printf("case #%d:\n%s\n", i, letters);
    }
    
	return 0;
}