#ifndef _BinaryTree_H_
#define _BinaryTree_H_
template<class T> class BinaryTree;

#include<iostream>
#include<queue>

/* 树的结点 */
template<class T> 
class TreeNode
{
public:
	TreeNode()
	{
		leftChild = NULL;
		rightChild = NULL;
	}
	T data; // 数据
	TreeNode<T> *leftChild; //左孩子
	TreeNode<T> *rightChild;//右孩子
};


/* 二叉树 */
template<class T>
class BinaryTree
{
public:
	// 可以对二叉树进行的操作
	void InOrder(); // 中序遍历
	void InOrder(TreeNode<T>* currentNode); // 中序遍历
	void PreOrder(); // 前序遍历
	void PreOrder(TreeNode<T>* currentNode);
	void PostOrder(); // 后序遍历
	void PostOrder(TreeNode<T>* currentNode); // 后序遍历
	void LevelOrder(); // 层序遍历
	void Visit(TreeNode<T>* currentNode);
public:
	TreeNode<T> *root;
};

template<class T>
void BinaryTree<T>::LevelOrder()
{
	std::queue<TreeNode<T>*> q;
	TreeNode<T>* currentNode = root;
	while(currentNode)
	{
		Visit(currentNode);
		if(currentNode->leftChild) q.push(currentNode->leftChild);
		if(currentNode->rightChild) q.push(currentNode->rightChild);
		if(q.empty()) return;
		currentNode = q.front();
		q.pop();
	};
}

template<class T>
void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
	std::cout << currentNode->data;
}

template<class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);		
}

template<class T>
void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)
{
	if (currentNode){
		InOrder(currentNode->leftChild);	
		Visit(currentNode);
		InOrder(currentNode->rightChild);	
	}
}

template<class T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T> *currentNode)
{
	if(currentNode)
	{
		Visit(currentNode);
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
	}
}


template<class T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

template<class T>
void BinaryTree<T>::PostOrder(TreeNode<T> *currentNode)
{
	if(currentNode)
	{
		PostOrder(currentNode->leftChild);
		PostOrder(currentNode->rightChild);
		Visit(currentNode);
	}
}

#endif
