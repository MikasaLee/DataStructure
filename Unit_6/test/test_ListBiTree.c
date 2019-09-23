/*************************************************************************
	> File Name: test_ListBiTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 02 Oct 2018 06:39:57 PM CST
 ************************************************************************/


#ifndef MAIN
#define MAIN

#include "../src/ListBiTree.c"

int main(int argc,char **argv){
	LBiTree T = NULL;
	ListElemType_Bt *e = "ABCDEF#G#HI#J";
	printf("\n----------测试CreateBiTree_L()------------\n");
	if(CreateBiTree_L(&T,e,0,13)){
		printf("\n----------测试PreOrderTraverse()------------\n");
		PreOrderTraverse(T,visitByChar);
		printf("\n----------测试InOrderTraverse()------------\n");
		InOrderTraverse(T,visitByChar);
		printf("\n----------测试PostOrderTraverse()------------\n");
		PostOrderTraverse(T,visitByChar);
		printf("\n----------测试LevelOrderTraverse()------------\n");
		LevelOrderTraverse(T,visitByChar);

		printf("\n----------测试BiTreeEmpty_L()------------\n");
		BiTreeEmpty_L(T) == TRUE?printf("该二叉树为空树\n"):printf("该二叉树不为空树\n");
	
		printf("\n----------测试BiTreeDepth_L()------------\n");
		printf("该二叉树的深度为:%d\n",BiTreeDepth_L(T));
	
		printf("\n----------测试Assign_L()------------\n");
		Assign_L(T,'a');
		printf("\n----------测试PreOrderTraverse()------------\n");
		PreOrderTraverse(T,visitByChar);
		printf("\n----------测试InOrderTraverse()------------\n");
		InOrderTraverse(T,visitByChar);
		printf("\n----------测试PostOrderTraverse()------------\n");
		PostOrderTraverse(T,visitByChar);
		printf("\n----------测试LevelOrderTraverse()------------\n");
		LevelOrderTraverse(T,visitByChar);
	
		
		printf("\n----------测试Parent_L()------------\n");
		printf("\n根节点的父节点：");
		visitByChar(Parent_L(T,Root_L(T)));
		printf("\n第三节点的父节点：");
		visitByChar(Parent_L(T,T -> rchild));

		printf("\n----------测试LeftChild_L()------------\n");
		printf("\n根节点的左孩子节点：");
		visitByChar(LeftChild_L(Root_L(T)));
		printf("\n第三节点的左孩子节点：");
		visitByChar(LeftChild_L(T -> rchild));

		printf("\n----------测试RightChild_L()------------\n");
		printf("\n根节点的右孩子节点：");
		visitByChar(RightChild_L(Root_L(T)));
		printf("\n第三节点的右孩子节点：");
		visitByChar(RightChild_L(T -> rchild));

		printf("\n----------测试LeftSibling_L()------------\n");
		printf("\n根节点的左兄弟节点：");
		visitByChar(LeftSibling_L(T,Root_L(T)));
		printf("\n第三节点的左兄弟节点：");
		visitByChar(LeftSibling_L(T,T -> rchild));

		printf("\n----------测试RightSibling_L()------------\n");
		printf("\n根节点的右兄弟节点：");
		visitByChar(RightSibling_L(T,Root_L(T)));
		printf("\n第二节点的右兄弟节点：");
		visitByChar(RightSibling_L(T,T -> lchild));

		printf("\n----------测试DestroyBiTree_L()------------\n");
		DestroyBiTree_L(&T);
		printf("\n----------测试PreOrderTraverse()------------\n");
		PreOrderTraverse(T,visitByChar);
		printf("\n----------测试InOrderTraverse()------------\n");
		InOrderTraverse(T,visitByChar);
		printf("\n----------测试PostOrderTraverse()------------\n");
		PostOrderTraverse(T,visitByChar);
		printf("\n----------测试LevelOrderTraverse()------------\n");
		LevelOrderTraverse(T,visitByChar);
	}
	
	return 0;
}

#endif
