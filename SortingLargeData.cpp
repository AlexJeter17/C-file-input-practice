// Alex Jeter 4/25/22
//this assignment takes in a large list of cities and their city temperature.
//then it sorts them by temperature using bubble sort.
//Then it outputs the top 5 hottest and top 10 coldest cities

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

void bubbleSort(vector<string>& vc, vector<int>& vt, int VecSize){ //Takes in both vectors and the vecSize

  for(int i = 0; i < VecSize - 1; i++){ // for loop that starts at the beginning of the vector
    for(int j = 0; j < VecSize - i - 1; j++){ // this loop goes through the rest of the loop
      if(vt[j] > vt[j + 1]){ // if current vector element is less than the next vector element
        swap(vt[j], vt[j+1]); // swap the numbers(temp)
        swap(vc[j], vc[j+1]); // swap the cities
      }
    }
  }
}

int main() {

  vector<string> vcity;  // Vector that holds city names
  vector<int> vtemp;     // Vector that holds temp numbers
  string city;           // will be used in the loops for a temp holder
  string whitespace;     // will be used in the loops for a temp holder - After using fin >> temp; there is leftover whitespace at the end of the file
  int temp;              // will be used in the loops for a temp holder
  fstream fin;           // fstream variable

  fin.open("WORLDTEMP.txt"); // open the file

  if(!fin){ // if the file is not opened
    cout << "File unable to open" << endl;
    return 0; // end program
  }
  
  while(getline(fin, city)){ // while getting the line from the file
    vcity.push_back(city);   // put the city into the vector
    fin >> temp;             // take in a variable for temperature
    vtemp.push_back(temp);   // put the temp into the vector
    getline(fin,whitespace); // get the line that will mess up the rest of the vectors if you skip this step.
  }

  bubbleSort(vcity, vtemp, vtemp.size()); // sort both vectors

  cout << "Top 5 cities: " << endl;
  for(int i = vcity.size() - 5, k = 5; i < vcity.size(); i++, k--){
    cout << k << ". " << vcity[i] << " " << vtemp[i] << endl; // cout the top 5 cities and their temperatures
  }
  
  cout << "\nBottom 10 cities: " << endl;
  for(int i = 0, k = 1; i < 10; i++,k++){
    cout << k << ". " << vcity[i] << " " << vtemp[i] << endl; // cout the bottom 10 cities and their temperatures
  }
  
}

