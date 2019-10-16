#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;
vector<int> stackData;
int G[6][6] = { {0,1,1,0,0,0},
					{0,0,0,1,1,0},
					{1,0,0,0,0,0},
					{0,0,0,0,1,1},
					{0,1,0,0,0,1},
					{0,0,0,1,1,0} };
int DFS(int i, int j){
	
	if (stackData.size()==0) {
		stackData.push_back(i);
	}

	if (G[i][j]==0) {
		j = j + 1;
		
		if (j > 5) {
			
			if (stackData.size() == 1) {
				return -1;
			}
			cout << stackData[stackData.size() - 1];
		
			stackData.pop_back();
			j = 0;
			i = stackData[stackData.size() - 1];
			
			return DFS(i, j);
		}else{
		
		return DFS(i, j);
		}
	}
	else if (G[i][j]==1) {
	
		for (int k = 0; k < 6; k++) {
			
			G[k][j] = 0;
		}
	
		stackData.push_back(j);
	
		i = j;
		j = 0;
		
	
		return DFS(i, j);
	}

}
int main(){
	
	
	DFS(0,0);


	system("pause");
	return 0;
}