
#include <bits/stdc++.h>
using namespace std;
#define SIZE 50
// checks if the given integer is prime
bool is_prime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
// Util function to find minimum sum for a path
int maxSumPathRec(vector<vector<int>>& tri, int i, int j){
    // Base Case 
    if(i == tri.size() )
      return 0 ;
    
    if(is_prime(tri[i][j]))
        tri[i][j]=-999999999;   //makes prime numbers negative infinity
        

    // Add current to the maximum  of the next paths and return 
    return  tri[i][j] +  max( maxSumPathRec(tri, i+1,j), maxSumPathRec(tri,i+1, j+1) );
    
}
 
int maxSumPath(vector<vector<int>>& tri) {
    
    return maxSumPathRec(tri, 0, 0) ;
}
vector<vector<int> >  createMatrix(ifstream &input_file){
    vector< vector<int> > triMatrix;
    triMatrix.resize(SIZE);
    int number,columns=1,flag=0;
     while (true) {
         
         if(columns>=SIZE)                          //If the maximum number of columns in the given input 
            triMatrix.resize(triMatrix.size()*2);   //is larger than the size of the vector, it will increase the size of the vector by 2 times.

         for (int i = 0; i < columns; i++)    //goes up to the number of columns in each row.
         {
             if(input_file >> number){  //reads 1 integer number
                triMatrix[columns-1].push_back(number);
             }
             else{
                triMatrix.resize(columns-1);
                return triMatrix;
             }
                
         }

         columns++;
     }
}

int main()
{
    vector<vector<int> > tri;
    
    string filename="input.txt";

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    
    tri=createMatrix(input_file);
    
    cout<< maxSumPath(tri);
    input_file.close();
    return 0;
}