//Name: Bruktawit Abebe
//Description: the program calculates the population estimate over the specified years given the birth rate and death rate.
//Date: 9/17/2023

#include <iostream>
using namespace std;

double GrowthRate(double BirthRate, double DeathRate)
{
    return BirthRate - DeathRate;
}
double EstimatedPopulation (double StartingPopulation, double BirthRate, double DeathRate)
{
    double EstimatePopulation = (StartingPopulation + ((BirthRate  * StartingPopulation) / 100)) - ((DeathRate * StartingPopulation) / 100);
    return EstimatePopulation;
}

int main()
{
    double StartingPopulation, years;
    double BirthRate, DeathRate;

    cout << "Enter the starting population: "<<endl;
    cin >> StartingPopulation;
    cout << "Enter the birth rate: "<<endl;
    cin >> BirthRate;
    cout << "Enter the death rate: "<<endl;
    cin >> DeathRate;
    cout << "Enter the number of years to project: "<<endl;
    cin >> years;

    if (StartingPopulation < 2)
    {
        cout << "Invalid! Population must be greater than or equal to 2."<<endl;
    }
    else if (BirthRate < 0)
    {
        cout << "Invalid! Birth rate cannot be negative."<<endl;
    }
    else if (DeathRate < 0)
    {
        cout << "Invalid! Death rate cannot be negative."<<endl;
    }
    else if (years < 1)
    {
        cout << "Invalid! Number of years to project must be greater than or equal to 1."<<endl;
    }
    else
    {
        for (int year = 1; year <= years; year++)
            {
              double growth = GrowthRate(BirthRate, DeathRate);
              double estimated_population = EstimatedPopulation (StartingPopulation, BirthRate, DeathRate);
              cout << "The growth rate is: " << growth <<endl;
              cout << "The estimated population after  " << years <<" years is: " <<  int(estimated_population) <<endl;

              StartingPopulation = estimated_population;
            }
    }
    return 0;
}

