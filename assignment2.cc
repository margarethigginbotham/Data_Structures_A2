//******************************************************************//
//   PROGRAM:    CSCI 340 Assignment 2                              //
//   PROGRAMMER: Margaret Higginbotham                              //
//   LOGON ID:   z1793581                                           //
//   DUE DATE:   February 5, 2018                                   //
//                                                                  //
//   FUNCTION:   Implements a linear search and binary search on    //
//               randomly generated integers stored in vectors      //
//******************************************************************//

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>

using std::vector;
using std::cout;
using std::endl;
using std::srand;
using std::rand;
using std::sort;
using std::fixed;
using std::left;
using std::setw;
using std::find;
using std::binary_search;

using namespace std;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;
const int HIGH = 100;
const int LOW = 1;
const int NO_ITEMS = 10;
const int ITEM_W = 6;

void genRndNums(vector<int>& v, int seed){
  vector<int>::iterator iterator;		//Iterator
  srand(seed);					//Random number generator

  //Initializes numbers to fill the vector
  for(iterator = v.begin(); iterator != v.end(); iterator++){
    *iterator = rand() % (HIGH - LOW + 1) + LOW;
  }

}

bool linearSearch(const vector<int>& inputVec, int x){
  //find() implements the routuine using <algorithm>
  if(find(inputVec.begin(), inputVec.end(), x) == inputVec.end())
    return false;

  else
    return true;
}

bool binarySearch(const vector<int>& inputVec, int x){
  //binary_search() implements the routine using <algorithm>
  if(binary_search(inputVec.begin(), inputVec.end(), x))
    return true;

  else
    return false;
}

int search(const vector<int>& inputVec, const vector<int>& searchVec, bool (*p)(const vector<int>&, int)){
  int searchNum = 0;				//Counter variable

  for(int i = 0; i < 100; i++){			//Loops counter throughout the DATA_SIZE
    if(p(inputVec, searchVec[i]) == true)	//While true
      ++searchNum;				//Implements the counter
  }

  return searchNum;				//Returns the counter
}

void sortVector (vector<int>& inputVec){
  sort(inputVec.begin(), inputVec.end());	//Sorts the vector using sort*();
}

void print_vec(const vector<int>& vec){
  vector<int>::const_iterator iterator;         //Implementing iterator
  int count = 0;                                //Implementing a counter

  for(iterator = vec.begin(); iterator != vec.end(); iterator++){
    //Ensures only a certain amount of numbers are displayed on each line
    if(count % NO_ITEMS == 0 && count != 0)
      cout << endl;

    cout << setw(ITEM_W) << *iterator;
    count++;                                    //Continues to print
  }

  cout << endl;
}

void printStat (int totalSucCnt, int vec_size){
  double percent = 0;						//Sets default percent variable
  percent = ((double) totalSucCnt / (double) vec_size);		//Equation to get the percentage

  cout << "Sucessful searches: " << (percent * 100) << ".00%" << endl;	//Print line
}

int main(){
  vector<int> inputVec(DATA_SIZE);
  vector<int> searchVec(SEARCH_SIZE);
  genRndNums(inputVec, DATA_SEED);
  genRndNums(searchVec, SEARCH_SEED);

  cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
  print_vec( inputVec );
  cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
  print_vec( searchVec );

  cout << "\nConducting linear search on unsorted data source ..." << endl;
  int linear_search_count = search( inputVec, searchVec, linearSearch );
  printStat ( linear_search_count, SEARCH_SIZE );

  cout << "\nConducting binary search on unsorted data source ..." << endl;
  int binary_search_count = search( inputVec, searchVec, binarySearch );
  printStat ( binary_search_count, SEARCH_SIZE );

  sortVector( inputVec );

  cout << "\nConducting linear search on sorted data source ..." << endl;
  linear_search_count = search( inputVec, searchVec, linearSearch );
  printStat ( linear_search_count, SEARCH_SIZE );

  cout << "\nConducting binary search on sorted data source ..." << endl;
  binary_search_count = search( inputVec, searchVec, binarySearch );
  printStat ( binary_search_count, SEARCH_SIZE );

  return 0;
}
