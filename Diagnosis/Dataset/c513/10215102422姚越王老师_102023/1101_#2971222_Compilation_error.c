#include<stdio.h>
#include<string.h>
int ABO[8][8][8]=
{
	1,1,0,0,0,0,1,1,	1,1,0,0,0,0,1,1,	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,0,0,0,0,1,1,	1,1,0,0,0,0,1,1,
	1,1,0,0,0,0,1,1,	0,1,0,0,0,0,0,1,	1,1,1,1,1,1,0,0,	0,1,0,1,0,1,0,0,	1,1,1,1,1,1,1,1,	0,1,0,1,0,1,0,1,	1,1,0,0,0,0,1,1,	0,1,0,0,0,0,0,1,
	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,0,0,	1,1,0,0,1,1,0,0,	1,1,0,0,1,1,0,0,
	1,1,1,1,1,1,0,0,	0,1,0,1,0,1,0,0,	1,1,1,1,1,1,0,0,	0,1,0,1,0,1,0,0,	1,1,1,1,1,1,0,0,	0,1,0,1,0,1,0,0,	1,1,0,0,1,1,0,0,	0,1,0,0,0,1,0,0,
	1,1,1,1,1,1,1,1,	1,1,1,1,1,1,1,1,	1,1,1,1,1,1,0,0,	1,1,1,1,1,1,0,0,	0,0,0,0,1,1,1,1,	0,0,0,0,1,1,1,1,	0,0,0,0,1,1,1,1,	0,0,0,0,1,1,1,1,
	1,1,1,1,1,1,1,1,	0,1,0,1,0,1,0,1,    1,1,1,1,1,1,0,0,	0,1,0,1,0,1,0,0,	0,0,0,0,1,1,1,1,	0,0,0,0,0,1,0,1,	0,0,0,0,1,1,1,1,	0,0,0,0,0,1,0,1,
	1,1,0,0,0,0,1,1,	1,1,0,0,0,0,1,1,	1,1,0,0,1,1,0,0,	1,1,0,0,1,1,0,0,	0,0,0,0,1,1,1,1,	0,0,0,0,1,1,1,1,	0,0,0,0,0,0,1,1,	0,0,0,0,0,0,1,1,
	1,1,0,0,0,0,1,1,	0,1,0,0,0,0,0,1,	1,1,0,0,1,1,0,0,	0,1,0,0,0,1,0,0,	0,0,0,0,1,1,1,1,	0,0,0,0,0,1,0,1,	0,0,0,0,0,0,1,1,	0,0,0,0,0,0,0,1
};
int get_index(const char* s)
{
	if(!strcmp(s,"A+"))return 0;
	if(!strcmp(s,"A-"))return 1;
	if(!strcmp(s,"AB+"))return 2;
	if(!strcmp(s,"AB-"))return 3;
	if(!strcmp(s,"B+"))return 4;
	if(!strcmp(s,"B-"))return 5;
	if(!strcmp(s,"O+"))return 6;
	if(!strcmp(s,"O-"))return 7;
}
void print(const int* ans,int cnt)
{
	if(!cnt){printf("impossible ");return;}
    int i;printf("{");
	for(i=0;i<cnt;++i)
	{
		switch(ans[i])
		{
			case 0:{printf("A+");break;}
            case 1:{printf("A-");break;}
            case 2:{printf("AB+");break;}
            case 3:{printf("AB-");break;}
            case 4:{printf("B+");break;}
            case 5:{printf("B-");break;}
            case 6:{printf("O+");break;}
            case 7:{printf("O-");break;}
		}
        if(i!=cnt-1)printf(",");
	}
    printf("} ")
}
int main()
{
	int T;scanf("%d\n",&T);char F[10],M[10],S[10];
	for(int cas=0;cas<T;++cas)
	{
		scanf("%s %s %s",F,M,S);
		int f,m,s,i,j,k;
		if(!strcmp(S,"?"))
		{
			f=get_index(F);
			m=get_index(M);
			int ans[8],cnt=0;
			for(k=0;k<8;++k)if(ABO[f][m][k])ans[cnt++]=k;
            printf("%s %s ",F,M);print(ans,cnt);printf("\n");
		}
        else if(!strcmp(M,"?"))
        {
            f=get_index(F);
			s=get_index(S);
			int ans[8],cnt=0;
			for(j=0;j<8;++j)if(ABO[f][j][s])ans[cnt++]=j;
            printf("%s ",F);print(ans,cnt);printf("%s\n",M);
        }
        else
        {
            m=get_index(M);
			s=get_index(S);
			int ans[8],cnt=0;
			for(i=0;i<8;++i)if(ABO[i][m][s])ans[cnt++]=i;
            print(ans,cnt);printf("%s %s\n",M,S);
        }
    }
    return 0;
}