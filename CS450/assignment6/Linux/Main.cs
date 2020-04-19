/* Assignment 6
* Nicholas Grogg
* CS450
*
* This program is a lexical analyzer that reads a file and
* outputs the the token and lexeme. This iteration changes 
* adds a logical operator character class and adds new 
* operators '==', '!=', '>', '<'
*
* TODO
* Handle the multi char logic operators, all in getChar()
* Replace streamreader
* Add try catch to file opening
* * Exception in addChar
*
* */

using System;
using System.IO;
using System.Collections.Generic;

// This code is based on the code from pages 190-194 from
// "Concepts of Progamming Languages 11th edition"
namespace LexNs
{
    public class A5
    {

        // Define variables to be used in program
        public class Variables
        {
            // Define Variables
            public static char[] lexeme = new char[100];
            public static char nextChar;
            public static int charClass;
            public static int lexLen;
            public static int nextToken;
            public static int token;

            // Define Character classes
            public const int LETTER = 0;
            public const int DIGIT = 1;
            public const int LOG_OP = 3;
            public const int UNKNOWN = 99;
            public const int EOF = -1;
            public const int EOL = 2;
            // Define new logical operator token
            public const int LOGICAL_OPERATOR = 27;

            // Define tokens
            public const int INT_LIT = 10;
            public const int IDENT = 11;
            public const int ASSIGN_OP = 20;
            public const int ADD_OP = 21;
            public const int SUB_OP = 22;
            public const int MULT_UP = 23;
            public const int DIV_OP = 24;
            public const int LEFT_PAREN = 25;
            public const int RIGHT_PAREN = 26;

            // Define variables for parts 4 and 5
            // Variable to read in File stream
            public static StreamReader inFileStream;
            // Variable to hold line read by program
            public static string line;
            // Array to hold string in char array
            public static char[] lineArray;
            // Iterator for char array
            public static int iterator;
        }

        /* Define functions based on original code */

        // This function adds the nextChar variable to the lexeme
        public static void addChar()
        {
            if (Variables.lexLen <= 98)
            {
                Variables.lexeme[Variables.lexLen++] = Variables.nextChar;
            }
            else
            {
                Console.WriteLine("Lexeme is too long");
            }

        }

        // Function to get the next character of input and determine character class
        public static void getChar()
        {
            // Assign nextChar to a variable
            Variables.nextChar = Variables.lineArray[Variables.iterator];

            // Prevent function from going out of bounds
            if (Variables.iterator < Variables.lineArray.Length - 1)
            {
                Variables.iterator += 1;
            }

            // If Variable is not the end of the line or end of file, determine nextChar's type
            if (Variables.nextChar != Variables.EOF && Variables.nextChar != Variables.EOL)
            {
                // Check if value is a Letter or a Digit
                if (Char.IsLetter(Variables.nextChar))
                {
                    Variables.charClass = Variables.LETTER;
                }
                else if (Char.IsNumber(Variables.nextChar))
                {
                    Variables.charClass = Variables.DIGIT;
                }
                // If value is not a letter or digit, check if it's a logical operator or unknown
                else
                {
                    // If variable is '=', check previous and next char for classification
                    // Else If var is '!', check next char for classification
                    // Else var is an unknown
                    Variables.charClass = Variables.UNKNOWN;
                }
            }
            // Check for End of line
            else if (Variables.nextChar == Variables.EOL)
            {
                Variables.charClass = Variables.EOL;
            }
            // Else it's end of file
            else
            {
                Variables.charClass = Variables.EOF;
            }

        }

        // A function to call getChar until it returns a non-white space character
        public static void getNonBlank()
        {
            while (Char.IsWhiteSpace(Variables.nextChar))
            {
                getChar();
            }
        }

        // Lexical analyzer for arithmetic expressions
        public static int lex()
        {
            Variables.lexLen = 0;

            // Skip white space
            getNonBlank();

            switch (Variables.charClass)
            {

                // Parse identifiers
                case Variables.LETTER:
                    addChar();
                    getChar();
                    while (Variables.charClass == Variables.LETTER || Variables.charClass == Variables.DIGIT)
                    {
                        addChar();
                        getChar();
                    }
                    Variables.nextToken = Variables.IDENT;
                    break;

                // Parse integer literals
                case Variables.DIGIT:
                    addChar();
                    getChar();
                    while (Variables.charClass == Variables.DIGIT)
                    {
                        addChar();
                        getChar();
                    }
                    Variables.nextToken = Variables.INT_LIT;
                    break;
                // Parse Logic operators
                case Variables.LOG_OP:
                    addChar();
                    getChar();
                    while (Variables.charClass == Variables.LOG_OP)
                    {
                        addChar();
                        getChar();
                    }
                    Variables.nextToken = Variables.LOGICAL_OPERATOR;
                    break;
                    

                // Check for parentheses and operators
                case Variables.UNKNOWN:
                    lookup(Variables.nextChar);
                    getChar();
                    break;

                // Check it it's EOL
                case Variables.EOL:
                    Variables.nextToken = Variables.EOL;
                    Variables.lexeme[0] = 'E';
                    Variables.lexeme[1] = 'O';
                    Variables.lexeme[2] = 'L';
                    break;

                // EOF
                case Variables.EOF:
                    Variables.nextToken = Variables.EOF;
                    Variables.lexeme[0] = 'E';
                    Variables.lexeme[1] = 'O';
                    Variables.lexeme[2] = 'F';
                    break;
            }
            Console.WriteLine("Next token is: {0}, Next lexeme is {1}", Variables.nextToken, string.Join("", Variables.lexeme));
            // Create new empty array
            Variables.lexeme = new char[100];
            return Variables.nextToken;
        }

        // Function to lookup operators and parentheses and return the token
        public static int lookup(char ch)
        {
            // Switched from a switch statement, since I can nest if statements
            if (ch == '(')
            {
                addChar();
                Variables.nextToken = Variables.LEFT_PAREN;
            }
            else if (ch == ')')
            {
                addChar();
                Variables.nextToken = Variables.RIGHT_PAREN;
            }
            else if (ch == '+')
            {
                addChar();
                Variables.nextToken = Variables.ADD_OP;
            }
            else if (ch == '-')
            {
                addChar();
                Variables.nextToken = Variables.SUB_OP;
            }
            else if (ch == '*')
            {
                addChar();
                Variables.nextToken = Variables.MULT_UP;
            }
            else if (ch == '/')
            {
                addChar();
                Variables.nextToken = Variables.DIV_OP;
            }
            else if (ch == '=')
            {
                 addChar();
                 Variables.nextToken = Variables.ASSIGN_OP; 
            }
            else if (ch == ';')
            {
                addChar();
                Variables.nextToken = Variables.EOL;
                Variables.lexeme[0] = 'E';
                Variables.lexeme[1] = 'O';
                Variables.lexeme[2] = 'L';
            }
            // Default, UNKNOWN
            else
            {
                addChar();
                Variables.nextToken = Variables.UNKNOWN;
            }

            return Variables.nextToken;
        }
    }
}
