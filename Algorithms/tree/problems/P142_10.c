#include <stdio.h>
#include <stdlib.h>
#include "treenode/treenode.h"

int i = 1;
void K_pre_travel(TreeNode* root, int k, int* ret){
	if(i == k)
		*ret = root->val;
	++i;
	if(root->left) 
		K_pre_travel(root->left, k, ret);
	if(root->right) 
		K_pre_travel(root->right, k, ret);	
}

int whdk(TreeNode* root, int k){
	if(root == NULL)
		return -1;
	if(i == k)
		return root->val;
	++i;
	int ret = whdk(root->left, k);
	if(ret != -1)
		return ret;
	ret = whdk(root->right, k);
	return ret;
}
int main(){
	TreeNode* root = CreateNode(1);	
	root->left = CreateNode(2);
	root->right = CreateNode(3);
	root->left->right = CreateNode(4);
	root->right->left = CreateNode(5);
	root->right->right = CreateNode(6);

	preorder_traversal(root);
	printf("\n");

	printf("k is %d\n", whdk(root, 4));
	
	return 0;
}
