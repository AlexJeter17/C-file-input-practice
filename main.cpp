// Alex Jeter 4/24/22
// c++
// fstream

#include <iostream>
#include <fstream>
#include <vector>

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

  
  cout << "Max Value:\t" << max << endl;
  cout << "Min Value:\t" << min << endl;
  cout << "Soft Average:\t" << softAvg << endl;
  
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

  double sum = 0;
  double softAvg;

  for(int i = 0; i < v.size(); i++){
    sum += v[i];
  }
  softAvg = sum / v.size();

  return softAvg;
}

//copy n data items from disk file into array a
void PopulateVector(vector<double>& Vec, string filename){
  // cout << filename;
  ifstream fin;
  double grades;
  
  fin.open(filename);

  if(!fin){
    cout << "Not cool bro" << endl;
    return;
  }

  while (fin >> grades){

    // grades = stod(grade);
    Vec.push_back(grades);
    
  }

}
