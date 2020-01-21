//This is the header file hourlyemployee.h. 
//This is the interface for the class HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;

    class HourlyEmployee : public Employee 
    {
    public:
		// Constructor
        HourlyEmployee() {head = NULL;}

		// Destructor
	~HourlyEmployee();

		// Add item to node
	void addHE(int ei, double wr, double h, string n, string ssnllhe);

		// Edit item in list
	void editHE(int tei, string tn, int ei, double wr, double h, string n, string ssnllhe);

		// Output list
	void displaylistHE();

		// Output employee
	void displayemployeeHE(int tei, string tn);

	/*
        void set_rate(double new_wage_rate);
        double get_rate( ) const;
        void set_hours(double hours_worked);
        double get_hours( ) const;
        void print_check( );
    	private:
        double wage_rate; 
        double hours;
     	Overloaded Constructor
        HourlyEmployee(string the_name, string the_ssn,
                           double the_wage_rate, double the_hours);

    	*/

    protected:
	struct HourlyListNode : Employee::ListNode
	{
	//int eid;
	double wage_rate;
	double hours;
	//string name; 
        //string ssn; 
        //double net_pay;
	HourlyListNode *next;
	HourlyListNode(int eidllhe, double wage_ratellhe, double hoursllhe, string namellhe, string ssnllhe, HourlyListNode *next1 = NULL)
	{
	eid = eidllhe;
	wage_rate = wage_ratellhe;
	hours = hoursllhe;
	name = namellhe;
	ssn = ssnllhe;
	net_pay = wage_ratellhe * hoursllhe;
	next = next1;
	}
	};
	HourlyListNode *head;
    };


#endif //HOURLYMPLOYEE_H
