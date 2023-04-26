#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode* Tree;
typedef struct ANode* Address;
struct ANode{
	char *username;
	char *host;
};
struct TNode{
	Address item;
	Tree left;
	Tree right;
};

void split(char s1[], char s2[], char s[])
{
	char *po = s, *p = s;
	for(; *p != '@'; p++);
	memmove(s1, po, p - po);
	s1[p - po] = '\0';
	po = p;
	for(; *p; p ++);
	memmove(s2, po, p - po);
	s2[p - po] = '\0';
}

int cmp(Address a, Address b)
{
	if(strcmp(a->host, b->host) != 0){
		return strcmp(a->host, b->host);
	}else{
		return strcmp(b->username, a->username);
	}
}

Address CreateAddress(char s[])
{
	Address temp = (Address)malloc(sizeof(struct ANode));
	char s1[1000000], s2[1000000];
	split(s1, s2, s);
	temp->username = (char *)malloc(strlen(s1) + 1);
	temp->host = (char *)malloc(strlen(s2) + 1);
	strcpy(temp->username, s1);
	strcpy(temp->host, s2);
	return temp;
}

Tree CreateTree(char s[])
{
	Tree temp;
	temp = (Tree)malloc(sizeof(struct TNode));
	temp->item = CreateAddress(s);
	temp->left = NULL, temp->right = NULL;
	return temp;
}

Tree Insert(Tree t, Address a)
{
	int c;
	if(!t){
		t = (Tree)malloc(sizeof(struct TNode));
		t->item = a;
		t->left = NULL, t->right = NULL;
	}else{
		if((c = cmp(a, t->item)) < 0){
			t->left = Insert(t->left, a);
		}else if(c > 0){
			t->right = Insert(t->right, a);
		}else{
			t->left = Insert(t->left, a);
		} 
	}
	return t;
}

void PrintTree(Tree t)
{
	if(t){
		PrintTree(t->left);
		printf("%s%s\n", t->item->username, t->item->host);
		PrintTree(t->right);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	char s[1000001];
	scanf("%s", s);
	Tree words = CreateTree(s);
	for(int i = 1; i < n ; i ++){
		scanf("%s", s);
		Address temp = CreateAddress(s);
		words = Insert(words, temp);
	}
	PrintTree(words);	
	return 0;
}