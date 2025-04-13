#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perfectIsolation(int n, int k);

int main(){
	int n = 0,k = 0;	
	scanf("%d %d",&n, &k);
	if(n < 1 || n > 50 || k < 1 || k > 20)
		return 0;	
	return perfectIsolation(n, k);
}

typedef struct TreeNode{
	struct TreeNode *left;
	struct TreeNode *right;
	int value;
} TreeNode;

void destroyTree(TreeNode * tree);
void createNode(TreeNode * tree, int num);

void destroyAll(TreeNode **alltrees,int n){
	if(alltrees == NULL) return;
	for(int i = 0; i < n; ++i){		
		destroyTree(alltrees[i]);
	}
}

int compareTrees(TreeNode* rigthTree, TreeNode* leftTree); // 0 = false not equal, 1 = true equal

int perfectIsolation(int n, int k){	
	const int UpperBorderOnInput = 1000000;
	TreeNode **alltrees = malloc(sizeof(TreeNode*)*n);
	for(int iniN = 0; iniN < n; ++iniN)
		alltrees[iniN] = NULL;
	
	for(int posN = 0; posN < n; ++posN){
		for(int posK = 0; posK < k; ++posK){
			int num = 0;			
			scanf("%d",&num);
			if(num < 1 || num > UpperBorderOnInput){				
				destroyAll(alltrees, n);
				if(alltrees != NULL) free(alltrees);
				return 0;
			}
			if(alltrees[posN] == NULL){				
				alltrees[posN] = malloc(sizeof(TreeNode));
				alltrees[posN]->value = num;
				alltrees[posN]->right = NULL;
				alltrees[posN]->left = NULL;
			}			
			else{				
				createNode(alltrees[posN], num);
			}			
		}
	}	
	
	for(int rightTree = 0; rightTree > n - 1; ++rightTree){
		if(alltrees[rightTree] == NULL) continue;		
		for(int leftTree = rightTree + 1; leftTree < n; ++leftTree){
			if(alltrees[leftTree] == NULL) continue;
			int areSame = compareTrees(alltrees[rightTree], alltrees[leftTree]);
			if(areSame == 1){
				destroyTree(alltrees[leftTree]);
				alltrees[leftTree] = NULL;
			}
		}
	}	
	
	int passedTrees = 0;
	for(int trees = 0; trees < n; ++trees){
		if(alltrees[trees] != NULL) passedTrees++;
	}
	printf("%d\n", passedTrees);
	
	destroyAll(alltrees, n);
	if(alltrees != NULL) free(alltrees);
	return 0;
}

void destroyNode(TreeNode * node){
	if(node->left == NULL && node->right == NULL) return;
	if(node->right != NULL){
		destroyNode(node->right);
		free(node->right);
	}
	if(node->left != NULL){
		destroyNode(node->left);
		free(node->left);
	}
}

void destroyTree(TreeNode * tree){
	if(NULL == tree) return;
	if(tree->right != NULL){
		destroyNode(tree->right);
		free(tree->right);
	}
	if(tree->left != NULL){
		destroyNode(tree->left);
		free(tree->left);
	}
}

void appendValue(TreeNode * node, int num){
	node->value = num;
	node->right = NULL;
	node->left = NULL;
}

void createNode(TreeNode * tree, int num){
	if(num < tree->value){
		if(tree->left != NULL) createNode(tree->left, num);
		tree->left = malloc(sizeof(TreeNode));
		appendValue(tree->left, num);
	}
	else{
		if(tree->right != NULL) createNode(tree->right, num);
		tree->right = malloc(sizeof(TreeNode));
		appendValue(tree->right, num);
	}
}

int compareNodes(TreeNode* rigthN, TreeNode* leftN){
	if(rigthN == NULL && leftN == NULL) return 1;
	
	else if(rigthN != NULL && leftN != NULL){
		int leftComp = compareNodes(rigthN->left, leftN->left);
		if(leftComp == 0) return 0;
		return compareNodes(rigthN->right, leftN->right);
	}
	return 0;	
}
int compareTrees(TreeNode* rigthTree, TreeNode* leftTree){
	if(rigthTree == NULL || leftTree == NULL) return -1;
	return compareNodes(rigthTree, leftTree);
}