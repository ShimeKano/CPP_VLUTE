#include <iostream>
using namespace std;
//Khai bao
typedef int Info;
struct BST_Node
{ 	Info Key;
	BST_Node* Left;
	BST_Node* Right;
};
typedef BST_Node* BST_Type; 
//Khoi tao cay
BST_Type Initialize(BST_Type &BTree) 
{  	
  BTree = NULL; 
  return  BTree; 
} 
//Tim kiem 1 nut
BST_Type BST_Searching(BST_Type BST_Tree, Info SearchData) 
{  	BST_Type  CurNode = BST_Tree; 
	while(CurNode !=NULL && CurNode->Key != SearchData) 
		{  	
			if (CurNode->Key > SearchData) 
				CurNode = CurNode->Left; 
			else 
				CurNode = CurNode->Right; 
		} 
	return (CurNode); 
} 
//Tao moi 1 nut
BST_Type  Create_Node(Info  NewData) 
{  	
    BST_Type  BTnode = new  BST_Node; 
	  if (BTnode != NULL) 
	  {  	
       	BTnode->Left = NULL; 
  	    BTnode->Right = NULL; 
	    BTnode->Key = NewData; 
      } 
   return BTnode; 
} 
//Them 1 nut
void BST_Add_Node(BST_Type  &BST_Tree, Info  NewData) 
{  	
	if(BST_Tree == NULL){
		Create_Node(NewData);
	}
	else //BST != NULL
		if(BST_Tree->Key == NewData) return;
		else
			if(BST_Tree->Key > NewData)
				BST_Add_Node(BST_Tree->Left, NewData);
			else
				BST_Add_Node(BST_Tree->Right, NewData);
} 

//Nhap cay
void Read_Tree(BST_Type  &BST_Tree)
{
    Info X;
    cin>>X;
    if(X!=0)
        {
            BST_Type BST;
            BST = Create_Node(X);
            BST_Tree = BST;
            cout<<"Nhap con trai cua "<<X<<" : ";
            Read_Tree(BST_Tree->Left);
            cout<<"Nhap con phai cua "<<X<<" : ";
            Read_Tree(BST_Tree->Right);
        }
    else BST_Tree=NULL;
}
//Duyet cay theo cach LNR
void  LRootR_Travelling(BST_Type  BST_Tree) 
{	
	if (BST_Tree == NULL) 			
		return; 
	LRootR_Travelling (BST_Tree->Left); 
	cout << BST_Tree->Key << '\t'; 
	LRootR_Travelling (BST_Tree->Right); 
}
////xoa 1 nut(the mang,viet choi thui dung dom)
int Delete_Node_SB(BST_Type &BST, Info DelData)
{
	BST_Type DelNode = BST;
	BST_Type PrDelNode = NULL;
	int OnTheLeft = 0;
	while(DelNode != NULL){
		if(DelNode->Key == DelData)
			break;
		PrDelNode = DelNode;
		if(DelNode->Key > DelData){
			DelNode = DelNode->Left;
			OnTheLeft = 1;
		}
		else // (DelNode->Key < DelData)
		{
			DelNode = DelNode->Right;
			OnTheLeft = 0;
		}
	}
	if(DelNode == NULL) // Khong co nut de huy
		return 0;
	if(PrDelNode == NULL){ // DelNode la nut goc
 		if(DelNode->Left == NULL && DelNode->Right == NULL)
			BST = NULL;
 		else
			if(DelNode->Left == NULL){
// DelNode co 1 cay con phai
				BST = BST->Right; 
				DelNode->Right = NULL;
			}
			else
				if(DelNode->Right == NULL){
// DelNode co 1 cay con trai
					BST = BST->Left;
					DelNode->Left = NULL;
				}
		}
// DelNode khong la nut goc		
	else{ 
 		if(DelNode->Left==NULL && DelNode->Right==NULL)
			if(OnTheLeft == 1)
				PrDelNode->Left = NULL;
			else
				PrDelNode->Right = NULL;
 		else
			if(DelNode->Left == NULL){
// DelNode co 1 cay con phai
				if(OnTheLeft == 1)
					PrDelNode->Left = DelNode->Right;
				else
					PrDelNode->Right = DelNode->Right;
				DelNode->Right = NULL;
			}
			else
				if(DelNode->Right == NULL){
// DelNode co 1 cay con trai
					if(OnTheLeft == 1)
 						PrDelNode->Left = DelNode->Left;
					else
 						PrDelNode->Right = DelNode->Left;
					DelNode->Left = NULL; 
				}
	}
// DelNode co hai cay con
	if(DelNode->Left!=NULL && DelNode->Right!=NULL)
	{
		BST_Type MLNode = DelNode->Right;
		BST_Type PrMLNode = DelNode;
		while(MLNode->Left != NULL){
			PrMLNode = MLNode;
			MLNode = MLNode->Left;
		}
		DelNode->Key = MLNode->Key;
		if(PrMLNode == DelNode)
			PrMLNode->Right = MLNode->Right;
		else
			PrMLNode->Left = MLNode->Right;
		MLNode->Right = NULL;
		DelNode = MLNode;
	}
	delete DelNode;
	return 1;
}
//in tu goc toi K
void RoottoK(BST_Type BST_Tree, Info K){
	if(BST_Tree !=NULL){
		cout<<BST_Tree->Key<<'\t';
		if(BST_Tree->Key<K)
			RoottoK(BST_Tree->Right,K);
		else
			RoottoK(BST_Tree->Left,K);
	}		
}
//in tu k toi goc
void KtoRoot(BST_Type BST_Tree,Info K){
	if(BST_Tree !=NULL){		
		if(BST_Tree->Key<K)
			KtoRoot(BST_Tree->Right,K);
		else
			KtoRoot(BST_Tree->Left,K);
		cout<<BST_Tree->Key<<'\t';	
	}		
}
//in tu goc toi max
void RoottoMax(BST_Type BST_Tree){
	if(BST_Tree !=NULL){
		cout<<BST_Tree->Key<<'\t';
		RoottoMax(BST_Tree->Right);
	}
}
//in tu min toi goc
void MintoRoot(BST_Type BST_Tree){
	if(BST_Tree !=NULL){		
		RoottoMax(BST_Tree->Left);
		cout<<BST_Tree->Key<<'\t';
	}
}
//in tu min toi max(chi di het lk trai va lk phai(^))
void MintoMax(BST_Type BST_Tree){
	MintoRoot(BST_Tree);
	RoottoMax(BST_Tree->Right);
}
//in nut > K
void InnutlonhonK(BST_Type BST_Tree,Info K){
	if(BST_Tree!=NULL){
		if(BST_Tree->Key==K)
		LRootR_Travelling(BST_Tree->Right);
		else if(BST_Tree->Key<K)
			InnutlonhonK(BST_Tree->Right,K);
		else{
			InnutlonhonK(BST_Tree->Left,K);
			cout<<BST_Tree->Key<<'\t';
			LRootR_Travelling(BST_Tree->Right);
		}
	}
}
main()
{
  	BST_Type BST;
  	cout<<"=====NHAP CAY NHI PHAN TIM KIEM====="<<endl;
  	Initialize(BST);
  	Read_Tree(BST);
  	cout<<"=====CAY NHI PHAN TIM KIEM DA NHAP====="<<endl;
  	LRootR_Travelling(BST);
  	cout<<endl;
  	int del;
  	cout<<"Nhap nut can xoa: "<<endl;
  	cin>>del;
  	cout<<"Sau khi xoa: "<<Delete_Node_SB(BST, del)<<endl;
	LRootR_Travelling(BST);
	cout<<endl;
	int K;
	cout<<"Nhap moc can in: ";
	cin>>K;
	cout<<"Cay khi in tu nut goc toi moc da nhap la: "<<endl;
	RoottoK(BST,K);
	LRootR_Travelling(BST);
	cout<<endl;
	
}
