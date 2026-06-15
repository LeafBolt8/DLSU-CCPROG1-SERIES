/* DLSU SERIES: Rainwater Catchment Yield Calculator 
By: Hans Mozol
6.15.2026 */

#include <stdio.h>

//PART OF THE FORMULA
#define LITERFORMULA 28.3168


//COMPUTATION OF THE VOLUME IN CUBIC FEET
double volumeCubicFeet (double areaFunc, double rainfallFunc)
{
	return areaFunc * (rainfallFunc/12);
}


//CONVERSION OF VOLUME FROM CUBIC FEET TO LITERS
double volumeLitersFunc (double volumeCubicFeet2)
{
	return volumeCubicFeet2 * LITERFORMULA;
}


int main()
{

	double area, rainfall, volumeCF, volumeLiters;


	//USER INPUTS
	printf("Enter catchment area (in square feet): ");
	scanf("%lf", &area);

	printf("Recent rainfall depth (inches): ");
	scanf("%lf", &rainfall);


	//HOLDS THE VOLUME IN CUBIC FEET
	volumeCF = volumeCubicFeet(area, rainfall);

	//HOLDS THE VOLUME IN LITERS
	volumeLiters = volumeLitersFunc(volumeCF);


	if (volumeLiters >= 15000)
	{
		printf("========== INPUT =========="
		       "\nVolume in Cubic Feet: %.2lf"
		       "\nVolume in Liters: %.2lf"
		       "\n\n========== SUMMARY =========="
		       "\nYield: HIGH", volumeCF, volumeLiters);
	}

	else if (volumeLiters < 3000)
	{
		printf("========== INPUT =========="
		       "\nVolume in Cubic Feet: %.2lf"
		       "\nVolume in Liters: %.2lf"
		       "\n\n========= SUMMARY ========="
		       "\nYield: LOW", volumeCF, volumeLiters);
	}
	else
	{
		printf("========== INPUT =========="
		       "\nVolume in Cubic Feet: %.2lf"
		       "\nVolume in Liters: %.2lf"
		       "\n\n========== SUMMARY =========="
		       "\nYield: MODERATE", volumeCF, volumeLiters);
	}

	return 0;
}