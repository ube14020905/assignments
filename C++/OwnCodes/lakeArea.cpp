#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<char>> &grid, int r, int c)
{
	if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 'W')
	{
		return 0;
	}
	int area = 1;
	grid[r][c] = 'L';
	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			area += dfs(grid, r + dr, c + dc);
		}
	}
	return area;
}

int lakeArea(vector<vector<char>> &grid, int row, int col)
{
	return dfs(grid, row, col);
}

int main()
{
	int test_cases;
	cin >> test_cases;
	for (int t = 0; t < test_cases; t++)
	{
		vector<vector<char>> grid;
		string line;
		int n;
		cin>>n;
		while (n!=0)
		{
			cin>>line;
			grid.push_back(vector<char>(line.begin(), line.end()));
			n--;
		}

		int queries;
		cin >> queries;

		for (int q = 0; q < queries; q++)
		{
			int row, col;
			cin >> row >> col;
			cout << lakeArea(grid, row - 1, col - 1) << endl;
		}

		if (t < test_cases - 1)
		{
			cout << endl;
		}
	}

	return 0;
}
