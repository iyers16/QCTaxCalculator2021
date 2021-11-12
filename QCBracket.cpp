//GOAL: Return to user his Provincial income tax and net income for an input of gross revenue
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  //Declare input variable
  float taxableIncome;
  //Declare output variables
  float incomeTax, netIncome, averageTaxRate, marginalTaxRate;
  //Declare problem set variables
  float tax1 = 0.15;
  float tax2 = 0.20;
  float tax3 = 0.24;
  float tax4 = 0.2575;

  float range1 = 44545;
  float range2 = 89080;
  float range3 = 108390;

  float addingRevenue;

  //Get user input
  cout << "Enter Taxable Income: ";
  cin >> taxableIncome;
  cout <<endl;

  //if revenue is below specified range, add summation of taxes preceding that range and add it to the subtraction of the revenue and the floor value of the present range
  if (taxableIncome <= range1)
  {
    incomeTax = (taxableIncome * tax1);
    marginalTaxRate = tax1 * 100;
  }else if (taxableIncome > range1 && taxableIncome <= range2)
  {
    addingRevenue = range1 * tax1;
    incomeTax = ((taxableIncome - range1) * tax2) + addingRevenue;
    marginalTaxRate = tax2 * 100;
  }else if (taxableIncome > range2 && taxableIncome <= range3)
  {
    addingRevenue = ((range2 - range1) * tax2) + (range1 * tax1);
    incomeTax = ((taxableIncome - range2) * tax3) + addingRevenue;
    marginalTaxRate = tax3 * 100;
  }else
  {
    addingRevenue = ((range3 - range2) * tax3) + ((range2 - range1) * tax2) + (range1 * tax1);
    incomeTax = ((taxableIncome - range3) * tax4) + addingRevenue;
    marginalTaxRate = tax4 * 100;
  }

  //return income tax value to user
  cout << "Income Tax: " << fixed << setprecision(2) << incomeTax <<endl;

  //calculate and return net income to user
  netIncome = taxableIncome - incomeTax;
  cout << "Net Income: " << fixed << setprecision(2) << netIncome <<endl;

  //calculate average tax rate and return to user
  averageTaxRate = incomeTax * 100 / taxableIncome;
  cout << "Average Tax Rate: " << fixed << setprecision(2) << averageTaxRate << " %" <<endl;

  //return marginal tax rate to user
  cout << "Marginal Tax Rate: " << fixed << setprecision(2) << marginalTaxRate << " %" <<endl;

  return 0;

}
