#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols ; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
 
    for (int i = 0; i < Rows; i++)
    {
     
        for (int j = 0; j < Cols ; j++)
        {
           
            cout <<setw(3)<< Matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    
    srand((unsigned)time(NULL));

    int Matrix[3][3];
    FillMatrixWithRandomNumber(Matrix,3,3);
    cout << "The Folowing is a 3x3 Random Matrix:\n";
    PrintMatrix(Matrix,3,3);

}
