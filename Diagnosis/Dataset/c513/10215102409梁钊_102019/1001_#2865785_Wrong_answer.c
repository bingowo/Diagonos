#include<stdio.h>
int main()
{
    int T = 1 ;
    char c[50] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&T) ;
    for(int i = 0 ; i < T ; i++ ){
        int N,R ; int flag = 0 ;
        scanf("%d %d",&N,&R) ;
        if(N<0){
        	printf("-");
        	N = -N ;
		}
        int s[32]={'0'} ; int j = 0 ;
        while(N!=0){
            s[j++]= N % R ;
            N = N / R ;
    	}
        for(int k=j-1;k>=0;k--)
        	printf("%c",c[s[k]]); 
    }
}