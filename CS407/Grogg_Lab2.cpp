#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void quadratic(double a, double b, double c)
{
    double r1, r2;

    r1 = ((b*-1) - ( sqrt( (pow(b,2)) - (4*a*c) )))/(2*a);
    r2 = ((b*-1) + ( sqrt( (pow(b,2)) - (4*a*c) )))/(2*a);

    cout << "answer 1 = " << r1 << endl;
    cout << "answer 2 = " << r2 << endl;

}

int main()
{
    cout << "Nicholas Grogg Lab 1" << endl;

    // Taylor's Theorem for (x+h)
    // Page 26
    
    // Complete Horner's Algorithm
    // Page 23 
    
    // Part 2
    // Mclaurin Series
    // Page 22
    
    // Part 3
    // Quadratic Function
  
   /* 
    double a1,b1,c1;
    cout << "Enter values for a, b, and c: ";
    cin >> a1 >> b1 >> c1;
    quadratic(a1,b1,c1);
    */

    // Part 4 log table
    
    int n;
    double answer = 0;
    cout << "Enter a number: ";
    cin >> n;
    
    /*
    for (int i = 1; i <= n; i++)
    {
        cout << "i = " << i << endl;
        answer += log(static_cast<double>(i));
        cout << "Log of factorial " << i << " = " << answer << endl;
    }
    */ 

}
