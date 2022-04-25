// Alex Jeter 4/24/22
// c++ FSTREAM

// This program taked in data from a file named SoftAverageData.txt. It then calculates the max and min value. Then the soft average and nicely formats
// them in the console output. if the file is not correct or the directory is false, it outputs "not cool bro". Otherwise it will finish.

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

double findMaxValue(vector<double> v);
double findMinValue(vector<double> v);
void PopulateVector(vector<double>& Vec, string filename);
double calculateSoftAverage(vector<double> v, double maxVal, double minVal);


int main() {

  string file = "SoftAverageData.txt";
  vector <double> v;
  PopulateVector(v, file);
  
  double max = findMaxValue(v);
  double min = findMinValue(v);
  double softAvg = calculateSoftAverage(v,max,min);

  
  cout << "Max Value:\t\t" << max << endl;
  cout << "Min Value:\t\t" << min << endl;
  cout << "Soft Average:\t" << setprecision(4) << softAvg << endl;
  
  return 0;
}

//find the maximum value in the array a which holds n items
double findMaxValue(vector<double> v){
  double max = v[0]; // max is the first element

  for(int i = 1; i < v.size(); i++){
    if(max < v[i]){ //  if max value is less than current Vector element
      max = v[i];  // Make the new max, the current element of the vector
    }
  }
  
  return max; //return the largest number
}

//find the minimum value in the array a holding n items
double findMinValue(vector<double> v){
    double min = v[0];  // min is the first element

  for(int i = 1; i < v.size(); i++){
    if(min > v[i]){  // if the min is larger than current vector element
      min = v[i];    // min is now the current element of vector
    }
  }
  
  return min; // return the smallest number
}

//calculate SoftAverage of array a having n items
double calculateSoftAverage(vector<double> v, double maxVal, double minVal){

  double sum = 0;  // sum starts at 0
  double softAvg; // will be used for soft Average

  for(int i = 0; i < v.size(); i++){
    sum += v[i]; // add all elements
  }

  sum -= maxVal; // subtract max Val
  sum -= minVal; // subtract min Val
  
  softAvg = sum / (v.size() - 2); // Calculate. Formula = (sum - max - min) / all elements - 2
  
  return softAvg; // return the soft avg
}

//copy n data items from disk file into array a
void PopulateVector(vector<double>& Vec, string filename){

  ifstream fin; // ifstream variable
  double grades; // temporary holder
  
  fin.open(filename); // open the file

  if(!fin){ // if file didnt open
    cout << "Not cool bro" << endl;
    return;
  }

  while (fin >> grades){ // while the file is inputting to grades

    Vec.push_back(grades); //put the variable taken in, into the vector
    
  }

}
