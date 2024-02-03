#include <iostream>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, char *argv[])
{
   const int size = 6;
   int arr[size];
   srand(time(0));
   for(int i = 0; i < size; i++){
        arr[i] = (rand() % 10);
   }
     std::cout << "сгенерированный случайными числами массив" << std::endl;

   for(int j = 0; j < size; j++){
       std::cout<< arr[j] << std::endl;
   }


   bool zeroFound = false;
   for(int i = 0; i < size; i++){
       if(zeroFound) {
           swap(&arr[i], &arr[i-1]);
       }
       if(arr[i] == 0)
       {
           zeroFound = true;
       }
   }
   std::cout << "массив без первого нуля" << std::endl;
   int newsize = size; //новый размер масива

   if(zeroFound) newsize = size - 1;
   for(int j = 0; j < newsize; j++){
       std::cout<< arr[j] << std::endl;
   }

   int extendedSize = newsize + (newsize/2) - 1;
   int extarray[extendedSize];
   int v = 0;
   for(int i = 0; i < size; i++){

        extarray[v] = arr[i];
        v++;
        if(i%2 == 0 && i != 0) {
            extarray[v] = arr[i-1] + 2;
            v++;
        }
   }

   std::cout << "массив расширенный" << std::endl;

   for(int j = 0; j < extendedSize; j++){
       std::cout<< extarray[j] << std::endl;
   }

    return 0;
}