#include <iostream>
#include <cstdlib>
using namespace std;

int HiIndexMinNeg(const int a[], int n);

int main()
{
   int i;
   int a11[] = {0};
   int a12[] = {-1};
   int a21[] = {0, 1};
   int a22[] = {0, -1};
   int a23[] = {-1, 2};
   int a24[] = {1, -2};
   int a25[] = {-1, -2};
   int a26[] = {-2, -1};
   int a27[] = {-1, -1};
   int a31[] = {1, 2, 3};
   int a32[] = {-1, 2, 3};
   int a33[] = {1, -2, 3};
   int a34[] = {1, 2, -3};
   int a35[] = {-1, -2, 3};
   int a36[] = {-1, -2, -3};
   int a37[] = {-1, -2, -1};
   int a38[] = {-1, -1, -1};
   int a39[] = {-2, -1, -3};
   int a1001[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int a1002[] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int a1003[] = {0, 1, 2, 3, 4, -5, 6, 7, 8, 9};
   int a1004[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, -9};
   int a1005[] = {-1, 1, 2, 3, 4, -5, 6, 7, 8, -9};
   int a1006[] = {-9, 1, 2, 3, 4, -5, 6, 7, 8, -1};
   int a1007[] = {-1, 1, 2, 3, 4, -9, 6, 7, 8, -5};
   int a1008[] = {-5, 1, 2, 3, 4, -1, 6, 7, 8, -9};
   int a1009[] = {-5, 1, 2, 3, 4, -9, 6, 7, 8, -1};
   int a1010[] = {-1, 1, 2, 3, 4, -1, 6, 7, 8, -1};
   int a1011[] = {-1, 1, -2, 3, -1, 5, -2, 7, -2, 9};
   int a1012[] = {0, -1, 2, 3, -2, 5, 6, -4, 8, -3};
   int a1013[] = {0, -1, 2, -1, 4, -2, 6, -2, 8, -2};
   int a1014[] = {-5, 1, -9, 3, -5, -5, 6, 7, -9, -9};
   int a1015[] = {-1, -2, -3, -4, -5, -5, -4, -3, -2, -1};
   int a1016[] = {-4, -3, -2, -1, 0, 0, -1, -2, -3, -4};
   int a1017[] = {0, 0, 0, 0, 0, -1, -2, -3, -4, -5};
   int a1018[] = {-1, -2, -3, -4, -5, 0, 0, 0, 0, 0};
   int a1019[] = {1, -5, 2, -4, 3, -3, 4, -2, 5, -1};

   cout << "HiIndexMinNeg for (zero-sized array) is "
        << HiIndexMinNeg(a11, 0) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 1; ++i)
      cout << a11[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a11, 1) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 1; ++i)
      cout << a12[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a12, 1) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 2; ++i)
      cout << a21[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a21, 2) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 2; ++i)
      cout << a22[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a22, 2) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 2; ++i)
      cout << a23[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a23, 2) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 2; ++i)
      cout << a24[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a24, 2) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 2; ++i)
      cout << a25[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a25, 2) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 2; ++i)
      cout << a26[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a26, 2) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 2; ++i)
      cout << a27[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a27, 2) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a31[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a31, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a32[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a32, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a33[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a33, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a34[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a34, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a35[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a35, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a36[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a36, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a37[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a37, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a38[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a38, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 3; ++i)
      cout << a39[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a39, 3) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1001[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1001, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1002[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1002, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1003[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1003, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1004[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1004, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1005[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1005, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1006[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1006, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1007[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1007, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1008[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1008, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1009[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1009, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1010[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1010, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1011[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1011, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1012[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1012, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1013[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1013, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1014[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1014, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1015[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1015, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1016[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1016, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1017[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1017, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1018[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1018, 10) << endl;

   cout << "HiIndexMinNeg for [ ";
   for (i = 0; i < 10; ++i)
      cout << a1019[i] << ' ';
   cout << "] is " << HiIndexMinNeg(a1019, 10) << endl;

   return EXIT_SUCCESS;
}

 int HiIndexMinNeg(const int a[], int n)
{
   if(n <= 0)
      return -999;
   if(n == 1)
   {
      if(a[n-1] < 0)
         return n-1;
      else
         return -999;
   }
   int negValIndex = HiIndexMinNeg(a, n-1);
  
   if(negValIndex < 0)
   {
      if(a[n-1] < 0)
         negValIndex = n-1;
         return negValIndex;
   }
   else if(a[n-1] <= a[negValIndex])
      negValIndex = n-1;
   return negValIndex;
}
