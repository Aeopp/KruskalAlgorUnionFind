#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

void myswap(int*a,int*b)
{
	*a ^= *b;
	*b ^=*a;
	*a ^= *b;
};

void quicksort(int left,int right,
	int arr[])
{
	int pivot = left;
	int low = pivot;
	int high = left + 1;

	if(left<right)
	{
		for (; high <= right; high++)
		{
			if(arr[high] <arr[pivot])
			{
				low++;
				myswap(&arr[low], &arr[high]);
				pivot = low;
			}

			quicksort(left,pivot-1,arr); 
			quicksort(pivot+1,right,arr); 

		}
	}
	
	
}

namespace Kruskal
{
	
// 싸이클 테이블
	int parent[] = { 0,1,2,3,4,5,6,7,8,9 };
	// 해당 값들은 코스트
	int edge[] = { 11,5,8,15,17,4,20,25,10,30 };
	// 모든 정점의 부모는 처음 시작시 자기 자신으로 설정.
	// 인덱스가 부모 노드를 묻는 Key 배열의 값이 부모노드를 나타내는 Val
	void initparent(int arr[], int size/*not index input size */)
	{
		for (int i = 0; i < size; ++i)
			arr[i] = i;
	}
	int getparent(int arr[], int val)
	{
		// 부모가 자기 자신이라면 즉 아직 연결된 정점이 하나도 없는 상태.
		if (arr[val] == val) return val;
		return arr[val] = getparent(arr, arr[val]);
	}
	void Test(int arr[], int lhs, int rhs, int size)
	{
		for (int i = 0; i < size; ++i) cout << i << " 의 최상위 부모 : " << arr[i] << endl;
	}
	void cycleprint(int arr[], int lhs, int rhs)
	{
		if (arr[lhs] == arr[rhs]) cout << "연결되어있습니다.";
		else cout << "연결 안 되어 있습니다.";
	}
	// 사이클이 발생했는지 검사
	bool iscycle(int arr[], int lhs, int rhs)
	{
		int lhsparent = getparent(arr, lhs);
		int rhsparent = getparent(arr, rhs);
		// ver 과 newparent 를 연결
	// 둘의 부모중 작은 숫자가 최상위 루트가 된다
		bool bcycle = lhsparent == rhsparent;
		if (bcycle) return;
		else if (bcycle == false)
		{
			arr[lhs] = arr[rhs] = lhs < rhs ? lhs : rhs;
		};

	};
	// 간선의 배열을 오름차순으로 소팅
// 저 비용의 코스트의 간선에서부터 연결을 시도
// 연결이후의 최상위 부모가 동일하다면 교집합 ( 싸이클 발생 연결 실패)
// 최상위 부모가 동일하지 않다면 연결 진행
// 간선의 수 = 버텍스 - 1;  <- 해당 조건을 만족한다면 스팬트리의 완성
	void KruskalFunc(int edges[],int size)
	{
		
	}
};


//void edge(int arr[],int lhs,int rhs)
//{
//}
//struct node
//{
//public:
//	string name;
//	node* parent = this;
//	inline bool operator==(const node& rhs) { return &rhs == this; };
//	node(const string& pname) :name(pname),parent(this){};
//	inline node* getparent()
//	{
//	/*	if (getparent() == this)return this;
//		return parent->getparent();*/
//	}
//};
//struct edge
//{
//	node* first;
//	node* end;
//	int cost;
//	edge( node* const lhs,  node* const pfrom, const int pcost) :
//		end(lhs), first(pfrom), cost(pcost) {};
//	
//	inline bool operator==(edge* rhs)const
//	{
//		return rhs == this;
//		/*return rhs.first == first &&
//			rhs.end == end &&
//			rhs.cost == cost;*/
//	};
//};
//
//class Algor
//{
//public:
//	static void EdgeSort(std::vector<edge*>&ESort)
//	{
//		static int FinalCost = 0;
//		
//		sort(ESort.begin(), ESort.end(),
//	[](edge*&lhs,edge*&rhs)->bool
//		{
//			return lhs->cost < rhs->cost;
//		});
//		// 배열 소팅 완료
//		for(auto&E:ESort)
//		{
//				
//		}
//	}
//};

int main()
{
	/*node* A = new node("A");
	node* B = new node("B");
	node* C = new node("C");
	node* D = new node("D");
	node* E = new node("E");
	node* F = new node("F");
	node* G = new node("G");
	
	edge AB(A, B, 10);
	edge BD(B, D, 25);
	edge DE(D, E, 22);
	edge EF(E, F, 12);
	edge FG(F, G, 16);
	edge GA(G, A, 28);
	edge DC(D, C, 24);
	edge CE(C, E, 18);
	edge CG(C, G, 14);

	std::vector<node*> nodes = { A,B,C,D,E,F,G };
	std::vector<edge*> edges = { &AB,&BD,&DE,&EF,&FG,&GA,&DC,&CE,&CG };

	
	*/
	//Kruskal::initparent(Kruskal::parent, 10);
	//int test[] = { 3,5,1,2,4 };
	//quicksort(0, 4 , test);
	//for (auto&e : test)cout << e << endl;
}




