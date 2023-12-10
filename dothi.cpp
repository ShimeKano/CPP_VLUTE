#include<iostream>
using namespace std;
const int maxn = 20;
typedef int Graph[maxn][maxn];
void Initialize(Graph &g, int n, int &e)
{
 	int i, j;
	for(i=1; i<=n; i++)
 		for(j=1; j<=n; j++)
 			if (i==j) g[i][j]=1;
 			else g[i][j]=0;
		e=0;
}
//them canh
void InsertEdge(Graph &g, int n, int &e, int d1, int d2)
{
 	g[d1][d2]=1;
	g[d2][d1]=1;
	e++;
}
//xoa 1 canh
void DeleteEdge(Graph &g, int n, int &e, int d1, int d2)
{
 	g[d1][d2]=0;
	g[d2][d1]=0;
	e--;
}
//dem so canh

int CountEdge(Graph g, int n, int e, int d)
{ 
int i, dem=0;
	for(i=1; i<=n; i++)
 		if(g[d][i]==1) dem++;
	return dem-1;
}
//them 1 dinh
void InsertVertice(Graph &g, int &n, int &e, int sc)
{ int i, d;
	for(i=1; i<=n; i++)
	{
 		g[i][n+1]=0;
 		g[n+1][i]=0;
 	}
 	g[n+1][n+1]=1;
	for(i=1; i<=sc; i++)
 	{
 		cout<<"Nhap dinh noi voi dinh moi : ";
		cin>>d;
		InsertEdge(g, n, e, n+1, d);
	}
	n++;
}
//xoa 1 dinh
void DeleteVertice(Graph &g, int &n, int &e, int d)
{
	int i, j;
	e=e-CountEdge(g, n, e, d);
	for(i=d; i<=n-1; i++)
 		for(j=1; j<=n; j++)
 			g[i][j]=g[i+1][j];
	for(i=1; i<=n-1; i++)
 		for(j=d; j<=n-1; j++)
 			g[i][j]=g[i][j+1];
	for (i=1; i<=n; i++)
 	{
 		g[i][n]=0;
		g[n][i]=0;
 	}
	n--;
}
//nhap do thi
void ReadGraph(Graph &g, int n, int e)
{
	int i, d1, d2;
	for(i=1; i<=e; i++){
 		cout<<"Nhap dinh dau va dinh cuoi : ";
		cin>>d1>>d2;
		g[d1][d2]=1;
		g[d2][d1]=1;
 	}
}
//xuat do thi
void PrintGraph(Graph g, int n, int e)
{
	int i, j;
	for(i=1; i<=n; i++){
 		for(j=1; j<=n; j++)
 			cout<<g[i][j]<<'\t';
 		cout<<endl;
 	}
}
//dinh co canh noi la K
void CanhNoiK(Graph g,int n,int e, int k){
	for(int i=1;i<=n;i++)
		if(CountEdge(g,n,e,i))
			cout<<i<<'\t';
}
//nhap 1 dinh in ra canh noi voi dinh da nhap
void CanhNoiDinh(Graph g,int n,int e,int d){
	for(int i=1;i<=n;i++)
		if(g[d][i]==1)
			cout<<i<<'\t';
}
main()
{
	Graph g;
 	int n, e, d1, d2, d, sc;
 	do{
 		cout<<"Nhap so dinh cua do thi : ";
 		cin>>n;
 	}while(n<=0 || n>=maxn);
 	Initialize(g, n, e);
 	cout<<"=====DO THI VUA KHOI TAO====="<<endl;
 	PrintGraph(g, n, e);
 	cout<<"Nhap so canh cua do thi : ";
 	cin>>e;
 	ReadGraph(g, n, e);
 	cout<<"=====DO THI VUA NHAP====="<<endl;
 	PrintGraph(g, n, e);
 	cout<<endl;
 	cout<<"Nhap canh can them : ";
 	cin>>d1>>d2;
 	InsertEdge(g, n, e, d1, d2);
 	cout<<"=====DO THI SAU KHI THEM CANH====="<<endl;
 	PrintGraph(g, n, e);
 	cout<<endl;
 	cout<<"Nhap canh can xoa : ";
 	cin>>d1>>d2;
 	DeleteEdge(g, n, e, d1, d2);
 	cout<<"=====DO THI SAU KHI XOA CANH====="<<endl;
 	PrintGraph(g, n, e);
 	cout<<endl;
 	cout<<"Nhap dinh can dem so canh : ";
 	cin>>d;
 	cout<<"Dinh "<<d<<" co "<<CountEdge(g, n, e, d);
	cout<<" canh noi"<<endl;
 	cout<<"Nhap so canh noi cua dinh moi : ";
 	cin>>sc;
 	InsertVertice(g, n, e, sc);
 	cout<<"=====DO THI SAU KHI THEM DINH====="<<endl;
 	PrintGraph(g, n, e);
 	cout<<endl;
 	cout<<"Nhap dinh can xoa : ";
 	cin>>d;
 	DeleteVertice(g, n, e, d);
 	cout<<"=====DO THI SAU KHI XOA DINH====="<<endl;
 	PrintGraph(g, n, e);
}
