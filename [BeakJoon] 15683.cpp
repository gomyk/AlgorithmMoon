#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// 1~5 Ä«¸Þ¶ó 
int N, M;
int map[10][10];
int area[10][10];
int move_x[4] = { 0,1,0,-1 };
int move_y[4] = { -1,0,1,0 };
int result = INT_MAX;
struct dat {
	int y;
	int x;
	int type;
};
vector<dat> cctv;
bool isValid(int y, int x) {
	if (y >= 1 && y <= N) {
		if (x >= 1 && x <= M) {
			return true;
		}
	}
	return false;
}
void fill_one_direc(int y,int x, int direc) {
	while (isValid(y, x)) {
		if (map[y][x] == 6) {
			break;
		}
		else {
			area[y][x]++;
			y += move_y[direc];
			x += move_x[direc];
		}
	}
}
void remove_one_direc(int y, int x, int direc) {
	while (isValid(y, x)) {
		if (map[y][x] == 6) {
			break;
		}
		else {
			area[y][x]--;
			y += move_y[direc];
			x += move_x[direc];
		}
	}
}

void fill(dat tv, int direc) {
	int y = tv.y;
	int x = tv.x;
	switch (tv.type) {
	case 1: {
		fill_one_direc(y, x, direc);
		break;
	}
	case 2: {
		fill_one_direc(y, x, direc);
		fill_one_direc(y, x, (direc + 2) % 4);
		break;
	}
	case 3: {
		fill_one_direc(y, x, direc);
		fill_one_direc(y, x, (direc + 1) % 4);
		break;
	}
	case 4: {
		fill_one_direc(y, x, direc);
		fill_one_direc(y, x, (direc + 1) % 4);
		fill_one_direc(y, x, (direc + 2) % 4);
		break;
	}
	case 5: {
		fill_one_direc(y, x, direc);
		fill_one_direc(y, x, (direc + 1) % 4);
		fill_one_direc(y, x, (direc + 2) % 4);
		fill_one_direc(y, x, (direc + 3) % 4);
		break;
	}
	}
}
void remove(dat tv, int direc) {
	int y = tv.y;
	int x = tv.x;
	switch (tv.type) {
	case 1: {
		remove_one_direc(y, x, direc);
		break;
	}
	case 2: {
		remove_one_direc(y, x, direc);
		remove_one_direc(y, x, (direc + 2) % 4);
		break;
	}
	case 3: {
		remove_one_direc(y, x, direc);
		remove_one_direc(y, x, (direc + 1) % 4);
		break;
	}
	case 4: {
		remove_one_direc(y, x, direc);
		remove_one_direc(y, x, (direc + 1) % 4);
		remove_one_direc(y, x, (direc + 2) % 4);
		break;
	}
	case 5: {
		remove_one_direc(y, x, direc);
		remove_one_direc(y, x, (direc + 1) % 4);
		remove_one_direc(y, x, (direc + 2) % 4);
		remove_one_direc(y, x, (direc + 3) % 4);
		break;
	}
	}
}
void back_track(int index) {
	if (index == cctv.size()) {
		int blank = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!area[i][j]) {
					blank++;
				}
			}
		}
		result = min(result, blank);
		//calc_min
		return;
	}
	for (int i = 0; i < 4; i++) {
		fill(cctv[index], i);
		back_track(index + 1);
		remove(cctv[index], i);
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			area[i][j] = 0;
		}
	}
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv.push_back({ i, j ,map[i][j]});
			}
			else if (map[i][j] == 6) {
				area[i][j] = 1;
			}
		}
	}
	back_track(0);

	cout << result << endl;
}