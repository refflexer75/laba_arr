#include <iostream>
using namespace std;
const int numberOfStrings = 4;
const int numberOfCols = 3;


void selectionSort(int (*arr)[numberOfStrings][numberOfCols], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            int left = (*arr)[j][2];
            int right =(*arr)[min_idx][2]; 
            if (left < right)
                min_idx = j;
        }
        if (min_idx != i) {
            cout << "now swapping string № " << (*arr)[min_idx][0] << " and " << (*arr)[i][0] << "\n";
            for(int el = 0; el < numberOfCols; el++) swap((*arr)[min_idx][el], (*arr)[i][el]);
        }
    }
}


int main(int argc, char *argv[])
{


    int arr[numberOfStrings][numberOfCols] = {{1,2,8},
                                              {2,2,6},
                                              {3,2,9},
                                              {4,2,2}};
    selectionSort(&arr, numberOfStrings);

    for(int i =0; i < numberOfStrings; i++)
    {
        for(int j = 0; j < numberOfCols; j++) cout << arr[i][j];
        cout << endl;
    }
    return 0;
}