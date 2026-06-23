/* The PERALCO "Pera-Saving" Bill & Payment Simulator 
By: Hans Mozol
For: CCPROG1
Language Used: C
Github Repo Link: */


#include <stdio.h>

//CONSTANT VALUES
#define BASERATE 11.50
#define ECOTHRESHOLD 200
#define SURCHARGERATE 2.50
#define GREENBONUS 150

//FUNCTION PROTOTYPES
double calculate_peralco_bill(double kwh_Consumed, double*base_cost); 
void display_peralco_report(double base_cost, double final_bill); 
void process_bayad_counter(double final_bill);






int main()
{
	double kwh_Consumed, base_cost, final_bill;


	printf("=== PERALCO BILLING SYSTEM ===");
	printf("\nEnter total kWh consumed: ");
	scanf("%lf", &kwh_Consumed);


	final_bill = calculate_peralco_bill(kwh_Consumed, &base_cost); //FUNCTION CALL 

	display_peralco_report(base_cost, final_bill); //FUNCTION CALL

	process_bayad_counter(final_bill); //FUNCTION CALL 
	

	return 0;
}





double calculate_peralco_bill(double kwh_Consumed, double*base_cost) // THIS FUNCTION WILL DO 2 THINGS: MODIFY BASE COST AND RETURN FINAL COST
{
	double kwh_Reference, final_bill;

	kwh_Reference = kwh_Consumed - 200; //REFERENCE IF THE KWH EXCEEDS 200	
	kwh_Consumed *= BASERATE; //BASE RATE OF 11.50
	*base_cost = kwh_Consumed;//SINCE I CAN ONLY RETURN 1 VALUE (WHICH IS THE FINAL BILL), I USED POINTERS TO DIRECTLY MODIFY THE BASE COST (SO THIS FUNCTION WILL DO 2 THINGS: MODIFY BASE COST AND RETURN FINAL COST)
	final_bill = kwh_Reference >= 1 ? (kwh_Consumed + (kwh_Reference * SURCHARGERATE)) : (kwh_Consumed - GREENBONUS); //IF KWH IS GREATER THAN 200, WILL ADD A SURCHARGE OF 2.50 PESOS PER EACH KWH EXCEEDING 200, OTHERWISE A 150 PESOS DISCOUNT WILL APPLY
	return final_bill;
}





void display_peralco_report(double base_cost, double final_bill) //PRINTS SUMMARY FOR THE USER
{
	printf("\n\n--- PERALCO Bill Summary ---");
	printf("\nBase Energy Cost: Php %.2lf", base_cost);
	printf("\nFinal Amount Due (with Surcharge/Bonus): Php %.2lf", final_bill);

}





void process_bayad_counter(double final_bill) //PROCESSES THE TRANSACTION
{
	double payAmount, change = 0, amountDue;

	printf("\n\n--- PERALCO Bayad Counter --- ");
	printf("\nFinal Amount Due: %.2lf ", final_bill);
	printf("\nEnter cash payment amount (Php): "); // USER INPUT
	scanf("%lf", &payAmount);

	payAmount >= final_bill ? (change = payAmount - final_bill) : (amountDue = final_bill - payAmount); // IF THE AMOUNT EXCEEDS THE BILL, THE VARIABLE CHANGE WILL BE ASSIGNED TO A VALUE, OTHERWISE THE DUE AMOUNT WILL BE UPDATED
	amountDue >= 1 ? printf("Payment Status: Partially Paid!") : printf("Payment Status: Fully Paid!"); // IF THERE IS AN AMOUNT DUE, PRINT "PARTIALLY PAID", OTHERWISE PRINT "FULLY PAID"
	
	change >= 1 ? printf("\n\nChange Cash-Back: Php %.2lf", change) : printf("\nAmount due: %.2lf", amountDue);
	printf("\nThank you for using the Peralco System!");
	
}



