/************************
* A#: A02244600
* Course: CS1400
* HW#: 4
* Fall 2017
***********************/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Define functions
float GetT(float v, float d)
{
	//define variable
	float t;
	
	//if v is 0, we will get a distance of 0 and a time of 0
	//because we cannot devide by 0
	//Calculate t
	if(v != 0)
	{
		t = d/v;
	}
	else
	{
		t = 0;
	}
	
	return t;
}

float GetD(float v, float h)
{
	//Define constant
	const float g = 9.8;
	
	//define variable
	float d;
	
	//calculate d
	d = v * sqrt(2.0 * (h/g));
	
	return d;
}

void Report(int line, float v, float h, float d, float t) 
{
	cout << "On line " << right << setw(2) << line
		 << ",  v = " << setw(3) << v 
		 << ",  h = " << setw(5) << h << setprecision(5)
	 	 << ",  d = " << setw(6) << d << "m"
		 << ",  t = " << setw(6) << t << "s" << endl;
}

int main() 
{
	//define variables
	float v;
	float h;
	
	//Open input.txt for reading
    fstream file;
    file.open("input.txt");
 
	//set a counter to help keep track of lines read from the txt file
	int counter = 1;
	
	//Read a pair of (v, h) values from the file
	while(file >> v >> h)
	{
		//Compute the value for d with GetD() and t with GetT()
		GetT(v,GetD(v,h));
		
		//Call the function Report()
		Report(counter,v,h,GetD(v,h),GetT(v,GetD(v,h)));
		
		//Keep track of which line of the file we've read
		counter ++;
	}

	// TODO: Close input.txt
	file.close();

	return 0;
}
