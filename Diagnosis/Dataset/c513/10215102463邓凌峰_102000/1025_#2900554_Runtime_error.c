#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[21];
    int kinds;
}Zmc;

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;scanf("%d",&n);
        Zmc zmc[n];
        for(int j;j<n;j++){
            scanf("%s",zmc[j].s);
        }
        printf("s1\n");
        for(int j;j<n;j++){printf("%s\n",zmc[j].s);}
    }
	return 0;
}
