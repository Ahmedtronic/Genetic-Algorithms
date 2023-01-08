#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


struct element
{
	// the element of which solution space is contained.

	int rank;
	

	// here we list the element contents ( i.e. the element DNA )
	int att1; 
	double att2;
	bool att3; 
	string att4; 
	int fitnessvalue;


	int calculatefitness()
	{
		// here we calculate the value by which which the element is judged.
		int fitness;


		// some calculations 

		return fitnessvalue = fitness;
	}

};


// create solutions space; 
vector<element> solutionspace; 


// create new generation container
vector<element> newgeneration;


int maxfitness = 1000000;

bool checksolution()
{
	for (auto i : solutionspace)
	{
		if (i.fitnessvalue > maxfitness)
		maxfitness = i.fitnessvalue;
	}

	// check the maxfit element
	if ( false ) //certain condition is met
		{
			cout << "best solution is found" << endl;
			return 1;
		}
	else 
	{	
		cout << "best solution so far is this element" << endl;
		return false;
	}

};



int minvalidfitness =  0;

void naturalselection()
{
	vector<element> v; 

	for ( auto i: solutionspace)
		if (i.fitnessvalue >= minvalidfitness)
			v.push_back(i);

	solutionspace.clear();

	// make the solution space only contains the best members 
	solutionspace = v;

}


void crossover()
{
	// a simple example is to select random elements from solution space and mix their values;

	element parentA;
	element parentB;


	element child; 
	// do some operation to generate the new element;
	

	newgeneration.push_back(child);


	// here we have many options, here's some of them
	// 1. keep the best selected elements from last generation 
	// 2. alter the whole solution space. 


	//here is the implementation for both 

	// we can even make it optional 

	char x; 
	cout << "Do you want to alter the whole generation y/n?" << endl;
	cin >> x; 

	if ( x == 'n')
	{
		for ( auto i : newgeneration)
		solutionspace.push_back(i);
	}	

	else 
	{
		solutionspace.clear();
		solutionspace = newgeneration;
	}

}


void mutate()
{
	// changing some att is the new generation to make sure that we will always
	// have new solutions to be tested.

	for (auto i : solutionspace)
	{
		// do some operations to changes their content, i.e. att1, att2;

	}

} 


int main()
{


	// tale input of each element in solution space ( only for the first time) :

	// could be random values or pre-derermined values, or taken as input 
	// here we will take them as input;

	cout << "Taking the number of samples" << endl;
	int samples; 
	cin >> samples;


	cout << "Adjusting solution space size" <<endl;
	solutionspace.resize(samples);




	cout << "taking each element content " << endl;
	int solsize = solutionspace.size();
	for (int i = 0 ; i < solsize ; i++) 
	{
		cin >> solutionspace[i].att1;
		cin >> solutionspace[i].att2;
		cin >> solutionspace[i].att3;
		cin >> solutionspace[i].att4;
		
	}


	while (true)
	{
		// calculate the fitness of each element: 

		cout << "starting calculating fitness" <<endl;
		
		for (auto i : solutionspace) 
			i.calculatefitness();

		cout << "calculating fitness is Done" <<endl;



		cout << "Checking whether we foind our best solution" << endl;
		// here we put the best solution we wnat to reach 
		if (checksolution())
		{ 
			break;
		}

		// if the previous function is returned so we have reached our solution
		// else: 
		cout << "best solution was not found yet, trying again" << endl;
		

		cout << "performing natural selection" << endl;
		// natural selection ( i.e. select some elements with a high fitness)
		naturalselection();



		cout << "performing crossover (making new generation with better attributes " <<endl; 
		// generate new solution space;
		crossover();


		cout << "Altering new elements att to make sure a new solsize space is generated" <<endl;
		// perform mutation ( i.e. get new atts / values for the generated gens )
		mutate(); 


		// here we can ask the user if he wants to stop.
	} 


}



