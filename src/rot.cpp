#include<iostream>
#include<vector>
using namespace std;

template<class T> struct Val 
{
	Val(const T &t) : val_{t} { }
	bool operator<(const T& t) const {
		return first_compare_ ? val_ < t : false;
	}
	bool operator<=(const T &t) const {
		return first_compare_ ? val_ < t || val_ == t : false;
	}
	T val_;
	bool first_compare_ = true;
};

template<class T> Val<T>& operator<(T t, Val<T> &&val) {
	val.first_compare_ = (t < val.val_);
	return val;
}
template<class T> Val<T>& operator<=(T t, Val<T> &&val) {
	val.first_compare_ = (t <= val.val_);
	return val;
}
bool check_fresh(vector<vector<int>>& grid) {
	int width = grid.size(), height = grid[0].size();
	for(int i=0; i<width; i++) for(int j=0; j<height; j++) 
		if(grid[i][j] == 1) return true;
	return false;
}
bool one_minute_pass(vector<vector<int>> &grid) {
	vector<pair<int, int>> v;
	int width = grid.size(), height = grid[0].size();
	for(int i=0; i<width; i++) for(int j=0; j<height; j++) 
		if(grid[i][j] == 2) v.push_back({i, j});
	for(auto [a, b] : v) for(int i : {-1, 1}) 
	if(0 <= Val{a + i} < width &&  grid[a+i][b] == 1) grid[a+i][b] = 2;
	else if(0 <= Val{b + i} < height && grid[a][b+i] == 1) grid[a][b+i] = 2;
}

int rot(vector<vector<int>> &grid) {
	int i=0, w = grid.size(), h=grid[0].size();
	for(; check_fresh(grid) && i < w*h; i++) one_minute_pass(grid);
	return i==w*h ? -1 : i;
}
int main() {
	vector<vector<int>> grid{{2,1,1},{1,1,0},{0,1,1}};
	cout << rot(grid);
}


