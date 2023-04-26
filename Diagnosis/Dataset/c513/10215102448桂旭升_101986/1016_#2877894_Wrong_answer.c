#include <stdio.h>
#include <string.h>
char s[21] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
int a[100] = {0};
int main()
{
    int m, n, t, k, i = 0;
	scanf("%d %d", &m, &n);
    while(m != 0){
            k = m % n;
            t = m / n;
            if(k < 0){
                k -= n;
                t++;
            }
            m = t;
            a[i++] = k;
        }
        i--;
	for(;i >= 0; i--){
		printf("%d", a[i]);
	}
    return 0;

}