#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {

        for (int j = 0; j < Cols; j++)
        {

            cout << setw(3) << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;

    for (int j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumber][j];
    }


    return Sum;

}


void SumMatixRowsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(arr, i, Cols);
    }
}


void PrintRowsSumArray(int arrSum[3], short RowsNumber)
{

    cout << "\nThe Folowing are the sum of each row in the matrix:\n";
    for (int i = 0; i < RowsNumber; i++)
    {
        cout << "Rows " << i + 1 << " Sum = " << arrSum[i] << endl;
    }

}


int main()
{

    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "The Folowing is a 3x3 Random Matrix:\n";
    PrintMatrix(arr, 3, 3);
    SumMatixRowsInArry(arr, arrSum, 3, 3);
    PrintRowsSumArray(arrSum, 3);


    return 0;
}
