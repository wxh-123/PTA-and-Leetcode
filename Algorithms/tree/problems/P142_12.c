#include <stdio.h>
#include <stdlib.h>
#include "treenode/treenode.h"

int st[10];
int top = 0;
void pare(TreeNode* root, int x){
	if(root->val == x){
		while(top>0)
			printf("%d\n", st[--top]);
		exit(0);//直接退出程序		
	}
	st[top++] = root->val;
	if(root->left) pare(root->left, x);
	if(root->right) pare(root->right, x);
	--top;//回溯的方法
}

int main(){
	TreeNode* root = CreateNode(1);	
	root->left = CreateNode(2);
	root->right = CreateNode(3);
	root->left->right = CreateNode(4);
	root->right->left = CreateNode(5);
	root->right->right = CreateNode(6);
	
	pare(root, 6);
	printf("\n");
	
	return 0;
}
