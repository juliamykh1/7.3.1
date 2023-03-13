#include <iostream>
#include <ctime>

using namespace std;

int** createMatrix(int n);
void ChangeMatrix(int** array, int n);
int FirstLine(int** array, int n);
void PrintMatrix(int** array, int n);
void DeleteMatrix(int** array, int n);

int main()
{
    int n, ** a;
    cout << "Enter n(matrix size):";
    cin >> n;
    a = createMatrix(n);
    std::cout << "Matrix:\n";
    PrintMatrix(a, n);
    std::cout << "\nFirst line: " << FirstLine(a, n) << std::endl << std::endl;
    ChangeMatrix(a, n);
    std::cout << "Changed matrix:\n";
    PrintMatrix(a, n);
    DeleteMatrix(a, n);

    return 0;
}

int** createMatrix(int n)
{
    srand(time(NULL));
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 20 - 10;
        }
    }
    return a;
}

void ChangeMatrix(int** array, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (array[i][j] > array[k][k])
                {
                    if (i == j && i < k)
                    {
                        continue;
                    }
                    std::swap(array[i][j], array[k][k]);
                }
            }
        }
    }
}

int FirstLine(int** array, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] < 0)
            {
                count++;
            }
        }
        if (count == n)
        {
            return i + 1;
        }
        count = 0;
    }
    return -1;
}

void PrintMatrix(int** array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout.width(3);
            cout << array[i][j];
        }
        cout << endl;
    }
}

void DeleteMatrix(int** a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}