#include <stdio.h>
#include <string.h>
char L[2000][1000];
int C[2000];
int Input()
{
    char s[2001]; int k=0;
    gets(s);
    int begin=0,end=0;
    for(int i=0;i<(int)strlen(s);i++){
        if(s[i]==' ' && end==begin){
            end++;
            begin++;
        } else {
            if(s[i+1]==' '||s[i+1]=='\0'){
                for(int j=begin;j<=end;j++) L[k][j-begin]=s[j];
                L[k][end-begin+1]='\0';
                C[k++] = end-begin+1; 
                end+=2;
                begin=end;
                i++;
            } else {
            	end++;
    		}
        }
    }
    return k;
}
void func1(int begin,int end,int N)
{
    char res[70];
    int NL[100];
    int num=end-begin,block=N,k=0,q=num-1;
    for(int i=begin;i<=end;i++) block-=C[i];
    for(int i=0;i<num;i++) NL[i]=0;
    while(block!=0){
        NL[q--]+=1;
        block--;
        if(q==-1) q=num-1;
    }
    for(int i=begin;i<=end;i++){
        for(int j=0;L[i][j]!='\0';j++) res[k++] = L[i][j];
        if(i!=end){ for(int j=0;j<NL[i-begin];j++) res[k++] = ' ';}
    }
    for(int i=0;i<k;i++){
        printf("%c",res[i]);
    }
    printf("\n");
}
void func2(int begin,int end)
{
	char res[70]; int k=0;
	for(int i=begin;i<=end;i++){
        for(int j=0;L[i][j]!='\0';j++) res[k++] = L[i][j];
        if(i!=end) res[k++]=' '; 
    }
    for(int i=0;i<k;i++){
        printf("%c",res[i]);
    }
    printf("\n");
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++)
    {
        int N=0; char c;
        scanf("%d%c",&N,&c);
        printf("case #%d:\n",mm);
        int num = Input();
        int begin=0,end=0,count=0;
        for(int i=0;i<num;i++){
            if(count+C[end]>N){
                func1(begin,end-1,N);
                count=0;
                begin=end;
            } 
        	count+=C[end]+1;
            end++;
        }
        func2(begin,end-1);
    }
    return 0;
}