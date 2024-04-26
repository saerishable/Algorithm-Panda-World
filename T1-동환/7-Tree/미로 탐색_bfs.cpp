#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
const int MAX = 100; // �������� �־��� �̷��� ����-���� ũ���� ������ �ش���

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 }; //Ž����
int n, m, a[MAX][MAX], visited[MAX][MAX], y, x;
// �ʿ��� ������ ��ܿ� ��� ������.
// ���� �̷��� ����, ����, �̷��� ��ǥ �� ��(0,1), �湮 ����, �ӽ� ��ǥ(����, ����)�� �ǹ��Ѵ�. 
int main() {
	cin >> n >> m;
	string temp; // �迭�� �޾ƿ��� ���� string ����.
	for (int i = 0; i < n; i++) 
	{
		cin >> temp;
		for (int j = 0; j < m; j++) 
		{
			a[i][j] = temp[j] - '0'; // ����(����)�� ������ֱ� ���� ����ŷ
		}
			temp = "";
	}
	queue<pair<int, int>> q; // bfs ������ ���� ����� q�� ������.
	visited[0][0] = 1; // ���� ������ 0,0�� ��ǥ�� �ش��Ѵ�.
	q.push({ 0, 0 }); // Ž�� ����
	while (q.size()) 
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) // ���� ���� �������� 4������ Ž����
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			// �� �κ��� ���� ��ǥ ������ ��

			if (ny < 0 || ny >= n|| nx < 0 || nx >= m) continue; // 1. �ش� ������ �̷��� ũ�⸦ �ʰ��ϴ� ���
			if (a[ny][nx] == 0) continue; // 2. �ش� ������ �����ִ� ���
			if (visited[ny][nx] != 0) continue; // 3. �� ������ �̹� Ž���� ���

			visited[ny][nx] = visited[y][x] + 1; // �ش� ������ ���� ���� �������� 1�� �� ������ ��
			q.push({ ny, nx }); // ť�� ���� �湮�� ������ ��ǥ�� ������. 
		}
	}
	cout << visited[n - 1][m - 1]; // �������� �䱸�ϴ� ���������� �ִܰŸ��� �����
	return 0;
}
