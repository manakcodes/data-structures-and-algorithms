#include <iostream>
using namespace std;

int main()
{
    int rows = 3;
    int cols = 4;

    int **arr = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    int x = 10;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = (x += 10);
        }
    }

    cout << "rows : " << rows << endl;
    cout << "cols : " << cols << endl;
    cout << "2D array : " << endl
         << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
