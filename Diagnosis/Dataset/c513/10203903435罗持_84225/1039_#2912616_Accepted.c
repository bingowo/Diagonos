#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int N;
struct node
{
	int cnt;
	long long data[50];
};
struct node var[20000];
char item[50][10];
void deal(int *l,int *r)
{
	while(1)
	{
		if(strcmp(item[*l],"(") || strcmp(item[*r],")")) return;
		int t = 0;
		for(int i=*l;i<=*r;i++)
		{
			if(strcmp(item[i],"(")==0) t++;
			else if(strcmp(item[i],")")==0) t--;
			else if(t==0) return;
		}
		(*l)++;
		(*r)--;
	}
}
int isNum(char *s)
{
	for(int i=0;s[i];i++)
		if(s[i]<'0'||s[i]>'9') return 0;
	return 1;
}
int isAllNum(int l,int r)
{
	for(int i=l;i<=r;i++)
		if(!isNum(item[i])) return 0;
	return 1;
}
long long strToNum(char *s)
{
	long long res = 0;
	for(int i=0;s[i];i++)
		res = res*10 + s[i]-'0';
	return res;
}
struct node ADD(struct node n1,struct node n2)
{
	if(n1.cnt==-1) n1 = var[n1.data[0]];
	if(n2.cnt==-1) n2 = var[n2.data[0]];
	struct node tmp;
	if(n1.cnt==1)
	{
		tmp = n2;
		for(int i=0;i<n2.cnt;i++)
			tmp.data[i] += n1.data[0];
	}
	else if(n2.cnt==1)
	{
		tmp = n1;
		for(int i=0;i<n1.cnt;i++)
			tmp.data[i] += n2.data[0];
	}
	return tmp;
}
struct node SUB(struct node n1,struct node n2)
{
	if(n1.cnt==-1) n1 = var[n1.data[0]];
	if(n2.cnt==-1) n2 = var[n2.data[0]];
	struct node tmp;
	if(n1.cnt==1)
	{
		tmp = n2;
		for(int i=0;i<n2.cnt;i++)
			tmp.data[i] = n1.data[0]-tmp.data[i];
	}
	else if(n2.cnt==1)
	{
		tmp = n1;
		for(int i=0;i<n1.cnt;i++)
			tmp.data[i] -= n2.data[0];
	}
	return tmp;
}
struct node MUL(struct node n1,struct node n2)
{
	if(n1.cnt==-1) n1 = var[n1.data[0]];
	if(n2.cnt==-1) n2 = var[n2.data[0]];
	struct node tmp;
	if(n1.cnt==1)
	{
		tmp = n2;
		for(int i=0;i<n2.cnt;i++)
			tmp.data[i] *= n1.data[0];
	}
	else if(n2.cnt==1)
	{
		tmp = n1;
		for(int i=0;i<n1.cnt;i++)
			tmp.data[i] *= n2.data[0];
	}
	return tmp;
}
struct node cADD(struct node n1)
{
	int ID;
	if(n1.cnt==-1)
	{
		ID = n1.data[0];
		n1 = var[n1.data[0]];
	}
	struct node tmp = n1;
	tmp.cnt = 1;
	long long d = 0;
	for(int i=0;i<n1.cnt;i++)
		d += n1.data[i];
	tmp.data[0] = d;
	var[ID] = tmp;
	return tmp;
}
struct node cSUB(struct node n1)
{
	int ID;
	if(n1.cnt==-1)
	{
		ID = n1.data[0];
		n1 = var[n1.data[0]];
	}
	struct node tmp = n1;
	tmp.cnt = 1;
	long long d = 0;
	for(int i=n1.cnt-1;i>=0;i--)
		d = n1.data[i]-d;
	tmp.data[0] = d;
	var[ID] = tmp;
	return tmp;
}
struct node cMUL(struct node n1)
{
	int ID;
	if(n1.cnt==-1)
	{
		ID = n1.data[0];
		n1 = var[n1.data[0]];
	}
	struct node tmp = n1;
	tmp.cnt = 1;
	long long d = 1;
	for(int i=0;i<n1.cnt;i++)
		d *= n1.data[i];
	tmp.data[0] = d;
	var[ID] = tmp;
	return tmp;
}
struct node calc(int l,int r)
{
	deal(&l,&r);
	struct node tmp;
	if(isAllNum(l,r))
	{
		tmp.cnt = 0;
		for(int i=l;i<=r;i++)
			tmp.data[tmp.cnt++] = strToNum(item[i]);
		return tmp;
	}
	if(l==r)//变量名转ID cnt记为-1 
	{
		tmp.cnt = -1;
		long long d = 0;
		for(int i=0;item[l][i];i++)
			d = d*26+(item[l][i]-'a'+1);
		tmp.data[0] = d;
		return tmp;
	}
	int j=-1,t=0;
	for(int i=l;i<=r;i++)
	{
		if(strcmp(item[i],")")==0) t++;
		else if(strcmp(item[i],"(")==0) t--;
		else if(t==0 && i>l && (!strcmp(item[i],"+")||!strcmp(item[i],"-")||!strcmp(item[i],"*")||!strcmp(item[i],"=")))
		{
			j = i;
			break;
		}	
	}
	struct node op1,op2;
	if((strcmp(item[j],"=")==0))
	{
		op2 = calc(j+1,r);
		if(op2.cnt==-1) op2 = var[op2.data[0]];
		op1 = calc(l,j-1);
		var[op1.data[0]] = op2;
		return op2;
	}
	if(strcmp(item[j],"+")==0)
	{
		op2 = calc(j+1,r);
		if(op2.cnt==-1) op2 = var[op2.data[0]];
		op1 = calc(l,j-1);
		if(op1.cnt==-1) op1 = var[op1.data[0]];
		return ADD(op1,op2);
	}
	if((strcmp(item[j],"-")==0))
	{
		op2 = calc(j+1,r);
		if(op2.cnt==-1) op2 = var[op2.data[0]];
		op1 = calc(l,j-1);
		if(op1.cnt==-1) op1 = var[op1.data[0]];
		return SUB(op1,op2);
	}
	if(strcmp(item[j],"*")==0)
	{
		op2 = calc(j+1,r);
		if(op2.cnt==-1) op2 = var[op2.data[0]];
		op1 = calc(l,j-1);
		if(op1.cnt==-1) op1 = var[op1.data[0]];
		return MUL(op1,op2);
	}
	if(strcmp(item[l+1],"/")==0)
	{
		op1 = calc(l+2,r);
		if(strcmp(item[l],"+")==0) return cADD(op1);
		if(strcmp(item[l],"-")==0) return cSUB(op1);
		if(strcmp(item[l],"*")==0) return cMUL(op1);
	}

}
int main(void)
{
	scanf("%d",&N);
	getchar();
	while(N--)
	{
		char line[200] = {0};
		gets(line);
		int len = strlen(line);
		int n = -1,t = 0,flag = 0;
		for(int k=0;k<len;k++)
		{
			if(line[k]!=' ')
			{
				if(flag==0)
				{
					n++;
					t = 0;
					flag = 1;
				}
				item[n][t++] = line[k];
			}
			else
			{
				if(flag==1) item[n][t] = '\0';
				flag = 0;
			}
		}
		item[n][t] = '\0';
		struct node ans = calc(0,n);
		if(ans.cnt == -1) ans = var[ans.data[0]];
		for(int j=0;j<ans.cnt;j++)
		{
			if(j==ans.cnt-1) printf("%lld\n",ans.data[j]);
			else printf("%lld ",ans.data[j]);
		}
	}
	return 0;
} 