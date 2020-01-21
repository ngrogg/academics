//This is the header file employee.h. 
//This is the interface for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;


class Employee
{
    public:
	Employee() {head = NULL;}	
	~Employee();
		
		//All removals will use this function, eid and name function as primary key for program
	void remove(int e, string n);
	
    protected:
	struct ListNode
	{
		int eid;
		string name;
		string ssn;
		double net_pay;
		ListNode *next;
		ListNode(int e, string n, string ss, ListNode *next1 = NULL)
		{
			eid = e;
			name = n;
			ssn = ss;
			next = next1;
		}
	};
	ListNode *head;
};

/*
    class Employee
    {
    public:
        Employee( );
        Employee(string the_name, string the_ssn);
        string get_name( ) const;
        string get_ssn( ) const;
        double get_net_pay( ) const;
        void set_name(string new_name); 
        void set_ssn(string new_ssn);
        void set_net_pay(double new_net_pay);
        void print_check( ) const;
    private:
        string name; 
        string ssn; 
        double net_pay;
    };
*/

#endif //EMPLOYEE_H
