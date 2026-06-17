#include <stdio.h>
#include <math.h>

#define KIRPICH1 0.01947
#define KIRPICH2 0.77
#define KIRPICH3 -0.365
#define PRFR1 0.278

double kirpichEquation (double flowPathLength, double watershedSlope)
{
	double timeConcentration = KIRPICH1 * pow(flowPathLength, KIRPICH2) * pow(watershedSlope, KIRPICH3);
	return timeConcentration;
}

double idfRainfallIntensity (double idfConstantA, double timeConcentration, double idfConstantB, double idfConstantN)
{
	double rainfallIntensity = idfConstantA / pow ((timeConcentration + idfConstantB), idfConstantN);
	return rainfallIntensity;
}

double peakRunoffFlowRate (double runoffCoefficient, double drainageArea, double rainfallIntensity)
{
	double runoffFlowRate = PRFR1 * runoffCoefficient * drainageArea * rainfallIntensity;
	return runoffFlowRate;
}


int main()
{
	
	double runoffCoefficient, drainageArea, flowPathLength, watershedSlope, idfConstantA, idfConstantB, idfConstantN;
	double timeConcentration, rainfallIntensity, runoffFlowRate;
	
	printf("Peak Runoff Rate Calculator");
	printf("\nPlease enter the value of the given attribute, then press enter");

	printf("\n\nRunoff Coefficient: ");
	scanf("%lf", &runoffCoefficient);

	printf("\nDrainage Area (km²): ");
	scanf("%lf", &drainageArea);
	
	printf("\nFlow Path Length (m): ");
	scanf("%lf", &flowPathLength);

	printf("\nWatershed Slope: ");
	scanf("%lf", &watershedSlope);

	printf("\nIDF Constant A: ");
	scanf("%lf", &idfConstantA);

	printf("\nIDF Constant B: ");
	scanf("%lf", &idfConstantB);

	printf("\nIDF Constant N: ");
	scanf("%lf", &idfConstantN);

	
	timeConcentration = kirpichEquation (flowPathLength, watershedSlope);

	rainfallIntensity = idfRainfallIntensity (idfConstantA, timeConcentration, idfConstantB, idfConstantN);

	runoffFlowRate = peakRunoffFlowRate (runoffCoefficient, drainageArea, rainfallIntensity);

	printf("\n\nPeak Runoff Flow Rate is: %.2lf", runoffFlowRate);

	


	return 0;
}

/*git add rain_yield_calc.c
git commit -m "Test commit"*/