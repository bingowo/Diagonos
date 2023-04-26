#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define N 27
typedef struct Node{
	struct Node *son[N];//×Ó½ÚµãÒ²ÊÇNodeÐÍ½á¹¹Ìå 
	int isword;
}Trie;
Trie *NewNode()
{
	Trie *root=(Trie*)malloc(sizeof(Trie));
	for(int i=0;i<N;i++)root->son[i]=NULL;
	root->isword=0;
	return root;
}
void insert(Trie *root,char *s)
{
	Trie *node=root;
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		int x=s[i]-'a';if(s[i]=='-')x=26;
		if(node->son[x]==NULL)node->son[x]=NewNode();
		node=node->son[x];
	}
	node->isword=1;
}
int n,len,flag,sig[5005];
char chr[5005];
int search(Trie *root,int pos,int L)
{
	Trie *node=root;
	int x=chr[pos]-'a';if(chr[pos]=='-')x=26;
	if(node->son[x]==NULL)return 0;
	node=node->son[x];
	if(L==1)
	{
		if(node->isword)return 1;
		return 0;
	}
	return search(node,pos+1,L-1);
}
int main()
{
	int L=0;
	char s[15];
	scanf("%d",&n);
	memset(sig,0,sizeof(sig));
	Trie *root=NewNode();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);insert(root,s);
		if(strlen(s)>L)L=strlen(s);
	}
	scanf("%s",chr);
	len=strlen(chr);
	int x=0;
	while(x<len)
	{
		int k=L;
		while(1)
		{
			if(k==1||search(root,x,k))break;
			k--;
		}
		sig[x+k-1]=1;x+=k;
	}
	for(int i=0;i<len;i++)
	{
		printf("%c",chr[i]);
		if(sig[i])printf(" ");
	}
	return 0;
} 