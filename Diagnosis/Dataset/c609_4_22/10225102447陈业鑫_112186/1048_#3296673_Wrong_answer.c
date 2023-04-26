#include<stdio.h>
int main(){
    int num;
    int p_n[10] = {0};
    int cnt = 2;
    long long int ret[120] = {0,1,1};
	scanf("%d", &num);
	for(int i = 0;i<num;i++){
		scanf("%d",&p_n[i]);
	}
    for(int i = 0;i<num;i++){
        printf("case #%d:\n", i);
        while(p_n[i]>cnt){
            ret[cnt+1] = ret[cnt]+ret[cnt-1];
            cnt++;
        }
        printf("%lld\n", ret[p_n[i]]);
    }
    return 0;
}