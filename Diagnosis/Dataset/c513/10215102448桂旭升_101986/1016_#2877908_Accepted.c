#include <stdio.h>
#include <string.h>
char s[21] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
char a[100] = {'\0'};
int main()
{
    int m, n, t, k, i = 0;
	scanf("%d %d", &m, &n);
	if(m == 0)printf("0");
	else if(m < 0 && m > n)printf("%c", s[-1 * m]);
	else{

    	while(m != 0){
            k = m % n;
            t = m / n;
            if(k < 0){
                k -= n;
                t++;
            }
            m = t;
            a[i++] = s[k];
        }
        i--;
		for(;i >= 0; i--){
			printf("%c", a[i]);
		}	
	}
    return 0;

}