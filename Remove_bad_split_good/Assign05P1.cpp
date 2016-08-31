#include "llcpInt.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void SeedRand();
int  BoundedRandomInt(int lowerBound, int upperBound);
int  ListLengthCheck(Node* head, int whatItShouldBe);
bool match(Node* head, const int procInts[], int procSize);
void PruneArray(int a[], int& size, char whichOne);
void ShowArray(const int a[], int size);
void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues[], int caseSize);

int main()
{
   int TEST_CASES_TO_DO = 900000,
       testCasesDone = 0,
       LO_SIZE = 1,
       HI_SIZE = 20,
       LO_VALUE = -3,
       HI_VALUE = 12;
   int numInts,
       used_INI,
       used,
       used_LE5,
       used_GE7,
       intCount,
       intHolder,
       iLenChk,
       iLenChk_LE5,
       iLenChk_GE7;
   int *intArr_INI = 0,
       *intArr = 0,
       *intArr_LE5 = 0,
       *intArr_GE7 = 0;
   Node *head = 0,
        *head_LE5,      // intentionally left uninitialized
        *head_GE7;      // intentionally left uninitialized
   RemBadSplitGood(head, head_LE5, head_GE7);
   cout << "================================" << endl;
   if (head->data == -99 && head->link == 0 &&
       head_LE5->data == -99 && head_LE5->link == 0 &&
       head_GE7->data == -99 && head_GE7->link == 0)
   {
      ListClear(head, 1);
      ListClear(head_LE5, 1);
      ListClear(head_GE7, 1);
      cout << "test with empty list ... passed" << endl;
   }
   else
   {
      cout << "test with empty list ... failed" << endl;
      exit(EXIT_FAILURE);
   }
   cout << "================================" << endl;

   // SeedRand(); // disabled for reproducible result

   do
   {
      ++testCasesDone;
      numInts = BoundedRandomInt(LO_SIZE, HI_SIZE);
      intArr_INI = new int [numInts];
      intArr = new int [numInts];
      intArr_LE5 = new int [numInts];
      intArr_GE7 = new int [numInts];

      used_INI = used = used_LE5 = used_GE7 = 0;
      for (intCount = 0; intCount < numInts; ++intCount)
      {
         intHolder = BoundedRandomInt(LO_VALUE, HI_VALUE);
         intArr_INI[used_INI++] = intHolder;
         intArr[used++] = intHolder;
         InsertAsTail(head, intHolder);
      }
      PruneArray(intArr, used, 'I');
      if (testCasesDone % 45000 == 0)
      {
         cout << "================================" << endl;
         clog << "testing case " << testCasesDone
              << " of " << TEST_CASES_TO_DO << endl;
         clog << "================================" << endl;
         ShowArray(intArr_INI, used_INI);
         cout << "initial\"[09] list\": ";
         ShowArray(intArr, used);
      }

      for (int i = 0; i < used; ++i)
      {
         intHolder = intArr[i];
         intArr_LE5[used_LE5++] = intHolder;
         intArr_GE7[used_GE7++] = intHolder;
      }
      PruneArray(intArr, used, 'O');
      PruneArray(intArr_LE5, used_LE5, 'L');
      PruneArray(intArr_GE7, used_GE7, 'G');

     // DebugShowCase(testCasesDone, TEST_CASES_TO_DO, intArr_INI, used_INI);

      RemBadSplitGood(head, head_LE5, head_GE7);

      iLenChk = ListLengthCheck(head, used);
      if (iLenChk != 0)
      {
         if (iLenChk == -1)
         {
            cout << "\"==6\" list node-count error ... too few" << endl;
            cout << "test_case: ";
            ShowArray(intArr_INI, used_INI);
            cout << "#expected: " << used << endl;
            cout << "#returned: " << FindListLength(head) << endl;
         }
         else
         {
            cout << "\"==6\" list node-count error ... too many (circular list?)" << endl;
            cout << "test_case: ";
            ShowArray(intArr_INI, used_INI);
            cout << "#expected: " << used << endl;
            cout << "returned # is higher (may be infinite)" << endl;
         }
         exit(EXIT_FAILURE);
      }
      iLenChk_LE5 = ListLengthCheck(head_LE5, used_LE5);
      if (iLenChk_LE5 != 0)
      {
         if (iLenChk_LE5 == -1)
         {
            cout << "\"<=5\" list node-count error ... too few" << endl;
            cout << "test_case: ";
            ShowArray(intArr_INI, used_INI);
            cout << "#expected: " << used_LE5 << endl;
            cout << "#returned: " << FindListLength(head_LE5) << endl;
         }
         else
         {
            cout << "\"<=5\" list node-count error ... too many (circular list?)" << endl;
            cout << "test_case: ";
            ShowArray(intArr_INI, used_INI);
            cout << "#expected: " << used_LE5 << endl;
            cout << "returned # is higher (may be infinite)" << endl;
         }
         exit(EXIT_FAILURE);
      }
      iLenChk_GE7 = ListLengthCheck(head_GE7, used_GE7);
      if (iLenChk_GE7 != 0)
      {
         if (iLenChk_GE7 == -1)
         {
            cout << "\">=7\" list node-count error ... too few" << endl;
            cout << "test_case: ";
            ShowArray(intArr_INI, used_INI);
            cout << "#expected: " << used_GE7 << endl;
            cout << "#returned: " << FindListLength(head_GE7) << endl;
         }
         else
         {
            cout << "\">=7\" list node-count error ... too many (circular list?)" << endl;
            cout << "test_case: ";
            ShowArray(intArr_INI, used_INI);
            cout << "#expected: " << used_GE7 << endl;
            cout << "returned # is higher (may be infinite)" << endl;
         }
         exit(EXIT_FAILURE);
      }

      if ( !match(head, intArr, used) || !match(head_LE5, intArr_LE5, used_LE5) || !match(head_GE7, intArr_GE7, used_GE7) )
      {
         cout << "Contents error ... mismatch found in value or order" << endl;
         cout << "test case at issue: ";
         ShowArray(intArr_INI, used_INI);
         cout << "ought2b \"==6 list\": ";
         ShowArray(intArr, used);
         cout << "        \"<=5 list\": ";
         ShowArray(intArr_LE5, used_LE5);
         cout << "        \">=7 list\": ";
         ShowArray(intArr_GE7, used_GE7);
         cout << "outcome \"==6 list\": ";
         ShowAll(cout, head);
         cout << "        \"<=5 list\": ";
         ShowAll(cout, head_LE5);
         cout << "        \">=7 list\": ";
         ShowAll(cout, head_GE7);
         exit(EXIT_FAILURE);
      }

      if (testCasesDone % 45000 == 0)
      {
         //cout << "================================" << endl;
         //clog << "testing case " << testCasesDone
         //     << " of " << TEST_CASES_TO_DO << endl;
         //clog << "================================" << endl;
         //ShowArray(intArr_INI, used_INI);
         cout << "ought2b \"==6 list\": ";
         ShowArray(intArr, used);
         cout << "        \"<=5 list\": ";
         ShowArray(intArr_LE5, used_LE5);
         cout << "        \">=7 list\": ";
         ShowArray(intArr_GE7, used_GE7);
         cout << "outcome \"==6 list\": ";
         ShowAll(cout, head);
         cout << "        \"<=5 list\": ";
         ShowAll(cout, head_LE5);
         cout << "        \">=7 list\": ";
         ShowAll(cout, head_GE7);
      }

      ListClear(head, 1);
      ListClear(head_LE5, 1);
      ListClear(head_GE7, 1);
      delete [] intArr_INI;
      delete [] intArr;
      delete [] intArr_LE5;
      delete [] intArr_GE7;
      intArr_INI = intArr = intArr_LE5 = intArr_GE7 = 0;
   }
   while (testCasesDone < TEST_CASES_TO_DO);
   cout << "================================" << endl;
   cout << "test program terminated normally" << endl;
   cout << "================================" << endl;

   return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////////
// Function to seed the random number generator
// PRE:  none
// POST: The random number generator has been seeded.
/////////////////////////////////////////////////////////////////////
void SeedRand()
{
   srand( (unsigned) time(NULL) );
}

/////////////////////////////////////////////////////////////////////
// Function to generate a random integer between
// lowerBound and upperBound (inclusive)
// PRE:  lowerBound is a positive integer.
//       upperBound is a positive integer.
//       upperBound is larger than lowerBound
//       The random number generator has been seeded.
// POST: A random integer between lowerBound and upperBound
//       has been returned.
/////////////////////////////////////////////////////////////////////
int BoundedRandomInt(int lowerBound, int upperBound)
{
   return ( rand() % (upperBound - lowerBound + 1) ) + lowerBound;
}

/////////////////////////////////////////////////////////////////////
// Function to check # of nodes in list against what it should be
// POST: returns
//          -1 if # of nodes is less than what it should be
//           0 if # of nodes is equal to  what it should be
//           1 if # of nodes is more than what it should be
/////////////////////////////////////////////////////////////////////
int ListLengthCheck(Node* head, int whatItShouldBe)
{
   int length = 0;
   while (head != 0)
   {
      ++length;
      if (length > whatItShouldBe) return 1;
      head = head->link;
   }
   return (length < whatItShouldBe) ? -1 : 0;
}

bool match(Node* head, const int procInts[], int procSize)
{
   int iProc = 0;
   while (head != 0)
   {
      if (iProc == procSize) return false;
      if (head->data != procInts[iProc]) return false;
      ++iProc;
      head = head->link;
   }
   return true;
}

void PruneArray(int a[], int& size, char whichOne)
{
   int target, count = 0, i;
   for (i = 0; i < size; ++i)
   {
      target = a[i];
      if ( (whichOne == 'O' && target != 6) ||
           (whichOne == 'L' && target > 5) ||
           (whichOne == 'G' && target < 7) ||
           ( whichOne == 'I' && (target < 0 || target > 9) )
         )
         ++count;
      else if (count)
         a[i - count] = a[i];
   }
   size -= count;
   if (size == 0)
   {
      if (whichOne == 'O' || whichOne == 'L' || whichOne == 'G')
      {
         a[0] = -99;
         ++size;
      }
   }
}

void ShowArray(const int a[], int size)
{
   for (int i = 0; i < size; ++i)
      cout << a[i] << "  ";
   cout << endl;
}

void DebugShowCase(int whichCase, int totalCasesToDo,
                   const int caseValues[], int caseSize)
{
   cout << "test case " << whichCase
        << " of " << totalCasesToDo << endl;
   cout << "test case: ";
   ShowArray(caseValues, caseSize);
}
