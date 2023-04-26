#include <stdio.h>
#include <string.h>

typedef struct{
    int v[1001];//长度2L
    int iL;//整数长度
    int fL;//小数长度
    int sign;//符号，1或-1
}BF;
void bfCountLen(BF* a);
int bfCompare(BF* a, BF* b);
void Input(BF* bf);
BF SUB(BF a, BF b, int N);
BF ADD(BF a, BF b, int N);
void output(int a[],int N);

int main(){
	BF a = {{0},0,0,1}; BF b = {{0},0,0,1};
	BF zero = {{0},1,1,1};
	Input(&a); Input(&b);
	bfCountLen(&a); bfCountLen(&b);
	int judge = bfCompare(&a, &b);
	int N; scanf("%d", &N);
	if(judge>0){
		a = SUB(a, b, N);
		a = ADD(a, zero, N);
	}
	else{
		a = SUB(b, a, N);
		a = ADD(a, zero, N);
	}
	if(judge<0){printf("-");}
	output(a.v, N);
	return 0; 
}
void bfCountLen(BF* a){
    int i = 0, L = 500;
    while(i<=L && a->v[i]==0) i++;  //跳过前置0
    if(i>L) {a->iL = 1;}   //整数部分为0
    else{
        a->iL = L - i + 1;
    }
    i = 2*L;
    while(i>L && a->v[i]==0){
        i--;
    }
    if(i==L){a->fL = 1;}
	else{
    	a->fL = i-L;		
	}
}
int bfCompare(BF* a, BF* b){
    int L = 500;
    if(a->iL > b->iL){
        return 1;//a>b
    }
    else if(a->iL < b->iL){
        return -1;
    }
    for(int i = 0; i<2*L; i++){
        if(a->v[i] > b->v[i]){
            return 1;
        }
        else if(a->v[i] < b->v[i]){
            return -1;
        }
        else{continue;}
    }
    return 0;
}
void Input(BF* bf){
    int L = 500;
    char s[L+1];
    scanf("%s",s);    
    int i=0,j,k;
    while(s[i] && s[i] != '.') i++; //定位小数点

    for(j=i-1,k=L;j>=0;j--,k--) 
         bf->v[k] = s[j] - '0';  //整数部分
    for(j=i+1,k=L+1;j<strlen(s);j++,k++) 
         bf->v[k] = s[j] - '0';   //小数部分
}
BF SUB(BF a, BF b, int N){
    int i, L=500;
    for(int i = 2*L; i > 0; i--){
        if(a.v[i] < b.v[i]){
            a.v[i] += 10 - b.v[i];
            a.v[i-1] --;
        }
        else{
            a.v[i] -= b.v[i];
        }
    }
    return a;
}
BF ADD(BF a, BF b, int N){//如果要四舍五入保留N位
    int L = 500;
    for(int i = 2*L; i > L + N; i--){
        a.v[i] += b.v[i];
        a.v[i-1] += a.v[i] / 10;//进位
        a.v[i] %= 10;
    }
    if(a.v[L+N+1] >= 5) a.v[L+N]++;//四舍五入进位
    for(int i = L+N; i > 0; i--){
        a.v[i] += b.v[i];
        a.v[i-1] += a.v[i] / 10;//进位
        a.v[i] %= 10;
    }
    return a;
}
void output(int a[],int N)//传入结构体的v
{
    int i = 0, L = 500;
    while(i<=L && a[i]==0) i++;  //跳过前置0
    if(i>L) printf("%d",0);   //整数部分为0
    else
    {
        while(i<=L) printf("%d",a[i++]); //整数部分
    }
    printf("%c",'.');
    while(i<=L+N) printf("%d",a[i++]);  //小数部分
    printf("\n");
}