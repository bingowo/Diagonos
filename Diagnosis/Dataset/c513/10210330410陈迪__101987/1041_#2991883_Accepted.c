#include <stdio.h>
#include <stdbool.h>

int main()
{
	char c, p;
    p = getchar();
    int m = 1, l = 1;
    while((c = getchar()) != '\n') {
        if(c == p) {
            l = 1;
        }else {
            l++;
            if (m < l) m = l;
        }
        p = c;
    }
    printf("%d\n", m);
	return 0;
}