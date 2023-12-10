#include <iostream>
using namespace std;
typedef int Info;
//khai bao
struct BinT_Node 
{ 
	Info Key; 
	BinT_Node* Left; //con trai
	BinT_Node* Right; //con phai
}; 
typedef BinT_Node* BinT_Type;
//khoi tao
void Initialize(BinT_Type &BTree) 
{ 
 	BTree = NULL;
}
//tao 1 nut
BinT_Type Create_Node(Info NewData) 
{ 
 	BinT_Type BTnode = new BinT_Node; 
 	if(BTnode != NULL) 
 	{ 
 		BTnode->Left = NULL; 
 		BTnode->Right = NULL; 
 		BTnode->Key = NewData; 
	} 
	return BTnode; 
} 
//them nut trai nhat
void Add_Left(BinT_Type &BTree, Info NewData) 
{ 
	BinT_Type NewNode = Create_Node(NewData); 
	if(BTree == NULL) 
		BTree = NewNode;
	else{
		BinT_Type Lnode = BTree; 
		while(Lnode->Left != NULL) 
				Lnode = Lnode->Left; 
			Lnode->Left = NewNode; 
	} 
}
//them nut phai nhat
void Add_Right(BinT_Type &BTree, Info NewData) 
{ 
	BinT_Type NewNode = Create_Node(NewData); 
	if(BTree == NULL) 
		BTree = NewNode;
	else{
		BinT_Type Rnode = BTree; 
		while(Rnode->Right != NULL) 
				Rnode = Rnode->Right; 
			Rnode->Right = NewNode; 
	} 
}
//duyet cay L-N-R(trao doi vi tri cac cau lenh se ra kieu duyet cay khac)
void LRootR_Traverse(BinT_Type BTree) 
{ if(BTree == NULL) 
return; 
	LRootR_Traverse(BTree->Left); //left
	cout<<BTree->Key<<'\t';//nut
	LRootR_Traverse(BTree->Right); //right
}
//tinh chieu cao cay
int Tree_Height(BinT_Type BTree) 
{ 
	if(BTree == NULL) 
		return 0; 
	int HTL = Tree_Height(BTree->Left); 
	int HTR = Tree_Height(BTree->Right); 
	if(HTL > HTR) 
		return HTL + 1; 
	else
		return HTR + 1; 
}
//dem so nut tren cay
int Count_Node(BinT_Type BTree) 
{
	if(BTree == NULL) return 0;
	int NNL = Count_Node(BTree->Left);
	int NNR = Count_Node(BTree->Right);
	return(NNL + NNR + 1); 
}
//nhap cay
void Read_Tree(BinT_Type &BTree)
{ 	Info X;
 	cin>>X;
 	if(X!=0){
 		BinT_Type BT;
 		BT = Create_Node(X);
 		BTree = BT;
 		cout<<"Nhap con trai cua "<<X<<" : ";
 		Read_Tree(BTree->Left);
 		cout<<"Nhap con phai cua "<<X<<" : ";
 		Read_Tree(BTree->Right);
 	}
 	else BTree=NULL;
}
//in cac nut la
void Inla(BinT_Type BTree){
	if(BTree !=NULL)
		if(BTree->Left == NULL && BTree->Right == NULL)
			cout<<BTree->Key<<'\t';
		else{
			Inla(BTree->Left);
			Inla(BTree->Right);
		}	
}
//in con trai cua cay
void Intrai(BinT_Type BTree){
	if(BTree!=NULL){
		if(Btree->Left!=NULL)
			cout<<BTree->Left->Key<<'\t';
		Intrai(BTree->Left);
		Intrai(BTree->Right);
	}
}
//dem nut bat 2
int DemB2(BinT_Type BTree){
	if(Btree==NULL) return 0;
	if(BTree->Left!=NULL && BTree->Right!=NULL)
		return 1 + DemB2(BTree->Left) + DemB2(BTree->Right);
	else
		return DemB2(BTree->Left) + DemB2(BTree->Right);
}
//tim max
Info Max(Info a,Info b,Info c){
	Info t;
	if(a>b) t=a;
	else t=b;
	if(c>t) t=c;
	return t;
}
Info NutMax(BinT_Type Btree){
	if(BTree==NULL)return 0;
	else return Max(BTree->Key,NutMax(BTree->Left), NutMax(BTree->Right));
}
//in nut mut K
void InMucK(BinT_T)
//????/////????////?/??///????//??/???//////?///
main()
{ 	BinT_Type BT;
 	cout<<"=====NHAP CAY NHI PHAN====="<<endl;
 	Initialize(BT);
 	Read_Tree(BT);
 	cout<<"=====IN CAY NHI PHAN THEO CACH LNR====="<<endl;
 	LRootR_Traverse(BT);
 	cout<<endl;
 	Info X;
 	cout<<"Ban muon them vao nut trai nhat la bao nhieu: ";
 	cin>>X;
 	Add_Left(BT, X);
 	cout<<"==CAY NHI PHAN SAU KHI THEM NUT TRAI=="<<endl;
 	LRootR_Traverse(BT);
 	cout<<'\n';
 	cout<<"Ban muon them vao nut phai nhat la bao nhieu: ";
 	cin>>X;
 	Add_Right(BT, X);
 	cout<<"==CAY NHI PHAN SAU KHI THEM NUT PHAI=="<<endl;
 	LRootR_Traverse(BT);
 	cout<<"\nChieu cao cua cay la: "<<Tree_Height(BT);
 	cout<<"\nCay co "<<Count_Node(BT)<<" nut"<<endl;
}

