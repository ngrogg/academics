//This is the header file executive.h. 
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "salariedemployee.h"

using namespace std;

    class Executive : public SalariedEmployee
    {
    public:
        Executive( );
        Executive (string the_name, string the_ssn,
                                  double the_weekly_salary);
        double get_salary( ) const;
        void set_salary(double new_salary); 
        void print_check( );                                            
    private:
        double salary;//weekly
    };  
    

    
#endif //EXECUTIVE_H
