#include <iostream>
using namespace std;

const int MaxSize=10;

int arr[MaxSize][MaxSize]; //起始的邻接矩阵
int dist[MaxSize][MaxSize]; //保存每对结点之间的最短路径


int numNode=0;

//创建邻接矩阵
void createArr()
{
	cin>>numNode;
	for(int i=0;i<numNode;++i)
		for(int j=0;j<numNode;++j)
			cin>>arr[i][j];
}


//求出每对结点之间的最短路径
void allPath()
{
	//初始化dist数组
	for(int i=0;i<numNode;++i)
		for(int j=0;j<numNode;++j)
			dist[i][j]=arr[i][j];

	//迭代：对于结点k，若i直接到j的距离大于i经过k再到j的距离和时，
	//则改写i到j的距离
	for(int k=0;k<numNode;++k)
		for(int i=0;i<numNode;++i)
			for(int j=0;j<numNode;++j)
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
}


int main()
{
	createArr();

	allPath();
}