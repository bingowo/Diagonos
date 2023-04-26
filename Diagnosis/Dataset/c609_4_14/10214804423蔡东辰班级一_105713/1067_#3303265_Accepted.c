#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, n, m, x;
    int j, total;//第二次上车的人数，未知
    scanf("%d%d%d%d", &a, &n, &m, &x);
	for(int j = 0; ;j++){
    	int up[n]; up[0] = a; up[1] = j;//上车数组
    	int down[n]; down[0] = 0; down[1] = j;//下车数组
    	int* each = (int*)malloc(sizeof(int) * n); 
		for(int i = 0; i<n; i++){each[i] = 0;}
		each[0] = a; each[1] = a; each[n-1] = m;
		for(int i = 2; i<n-1; i++){
    		up[i] = up[i-1] + up[i-2];
    		down[i] = up[i-1];
    		each[i] += each[i-1] + up[i] - down[i];
		}
		if(each[n-2] == m){
			printf("%d", each[x-1]);
			break;
		}
		free(each);
	}
    return 0;
}