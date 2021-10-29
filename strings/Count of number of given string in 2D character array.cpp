#include <bits/stdc++.h>
using namespace std;

int internalSearch(string needle, int row,int col, string hay[],int row_max, int col_max, int idx)
{
	int found = 0;

	if (row >= 0 && row <= row_max && col >= 0 && col <= col_max && needle[idx] == hay[row][col])
	{
		char match = needle[idx];
		idx += 1;

		hay[row][col] = 0;

		if (needle[idx] == 0)
		{
			found = 1;
		}
		else
		{
			found += internalSearch(needle, row,col + 1, hay, row_max, col_max,idx);
			found += internalSearch(needle, row, col - 1,hay, row_max, col_max,idx);
			found += internalSearch(needle, row + 1, col,hay, row_max, col_max,idx);
			found += internalSearch(needle, row - 1, col,hay, row_max, col_max,idx);
		}
		hay[row][col] = match;
	}
	return found;
}

// Function to search the string in 2d array
int searchString(string needle, int row, int col,string str[], int row_count,int col_count)
{
    int found = 0;
    int r, c;

    for (r = 0; r < row_count; ++r)
    {
    	for (c = 0; c < col_count; ++c)
    	{
    		found += internalSearch(needle, r, c, str,row_count - 1,col_count - 1, 0);
    	}
    }
    return found;
}

// Driver code
int main()
{
	string needle = "MAGIC";
	string input[] = { "BBABBM",
					"CBMBBA",
					"IBABBG",
					"GOZBBI",
					"ABBBBC",
					"MCIGAM" };

	cout << "count: " << searchString(needle, 0, 0, input,6,6) << endl;
	return 0;
}
