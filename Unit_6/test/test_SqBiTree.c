/*************************************************************************
	> File Name: test_SqBiTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 22 Aug 2018 08:26:13 PM CST
 *************************************************************************/


#ifndef MAIN
#define MAIN

#include "../src/SqBiTree.c"

int main(int argc,char **argv){

	SqBiTree T;
	SqElemType_Bt *e = "ABCDEF#G#HI#J";
	printf("\n----------测试CreateBiTree_Sq()------------\n");
	if(CreateBiTree_Sq(T,e,13)){
		printf("\n----------测试PreOrderTraverse()------------\n");
		PreOrderTraverse(T,visitByChar,0);
		printf("\n----------测试InOrderTraverse()------------\n");
		InOrderTraverse(T,visitByChar,0);
		printf("\n----------测试PostOrderTraverse()------------\n");
		PostOrderTraverse(T,visitByChar,0);
		printf("\n----------测试LevelOrderTraverse()------------\n");
		LevelOrderTraverse(T,visitByChar);

		printf("\n----------测试BiTreeEmpty_Sq()------------\n");
		BiTreeEmpty_Sq(T) == TRUE?printf("该二叉树为空树\n"):printf("该二叉树不为空树\n");
	
		printf("\n----------测试BiTreeDepth_Sq()------------\n");
		printf("该二叉树的深度为:%d\n",BiTreeDepth_Sq(T));
	
		printf("\n----------测试Assign_Sq()------------\n");
		Assign_Sq(T,T[0],'a');
		printf("\n----------测试PreOrderTraverse()------------\n");
		PreOrderTraverse(T,visitByChar,0);
		printf("\n----------测试InOrderTraverse()------------\n");
		InOrderTraverse(T,visitByChar,0);
		printf("\n----------测试PostOrderTraverse()------------\n");
		PostOrderTraverse(T,visitByChar,0);
		printf("\n----------测试LevelOrderTraverse()------------\n");
		LevelOrderTraverse(T,visitByChar);
	
		
		printf("\n----------测试Parent_Sq()------------\n");
		printf("\n根节点的父节点：");
		visitByChar(Parent_Sq(T,Root_Sq(T)));
		printf("\n第三节点的父节点：");
		visitByChar(Parent_Sq(T,T[2]));

		printf("\n----------测试LeftChild_Sq()------------\n");
		printf("\n根节点的左孩子节点：");
		visitByChar(LeftChild_Sq(T,Root_Sq(T)));
		printf("\n第三节点的左孩子节点：");
		visitByChar(LeftChild_Sq(T,T[2]));

		printf("\n----------测试RightChild_Sq()------------\n");
		printf("\n根节点的右孩子节点：");
		visitByChar(RightChild_Sq(T,Root_Sq(T)));
		printf("\n第三节点的右孩子节点：");
		visitByChar(RightChild_Sq(T,T[2]));

		printf("\n----------测试LeftSibling_Sq()------------\n");
		printf("\n根节点的左兄弟节点：");
		visitByChar(LeftSibling_Sq(T,Root_Sq(T)));
		printf("\n第三节点的左兄弟节点：");
		visitByChar(LeftSibling_Sq(T,T[2]));

		printf("\n----------测试RightSibling_Sq()------------\n");
		printf("\n根节点的右兄弟节点：");
		visitByChar(RightSibling_Sq(T,Root_Sq(T)));
		printf("\n第二节点的右兄弟节点：");
		visitByChar(RightSibling_Sq(T,T[1]));

		printf("\n----------测试DestroyBiTree_Sq()------------\n");
		DestroyBiTree_Sq(T);
		printf("\n----------测试PreOrderTraverse()------------\n");
		PreOrderTraverse(T,visitByChar,0);
		printf("\n----------测试InOrderTraverse()------------\n");
		InOrderTraverse(T,visitByChar,0);
		printf("\n----------测试PostOrderTraverse()------------\n");
		PostOrderTraverse(T,visitByChar,0);
		printf("\n----------测试LevelOrderTraverse()------------\n");
		LevelOrderTraverse(T,visitByChar);
	}
	
	return 0;
}

#endif 
