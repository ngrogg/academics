/* Assignment 5 menu code
 * Nicholas Grogg
 * CS450
 *
 * This is a menu code designed to function as a basic UI for the program
 * This code functions as a driver program
 * 
 * */

using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

using LexNs;

namespace menuNs
{
    public class Menu
    {

        public static void Main()
        {
            // Run the lexeme program
            RunProgram();

            // Line at end of program
            Console.WriteLine("Press any key to continue");
            Console.Read();
        }

        public class Variables
        {
            public static char inputVariable;
        }
        public static void DisplayMenu()
        {
            // I wanted to use chars, but ints were easier to program...
            Console.WriteLine("Enter 'q' to quit the program");
            Console.WriteLine("Enter 'r' to read in a file");
            Console.Write("Enter in a valid char: ");
            Variables.inputVariable = Console.ReadKey().KeyChar;
            Console.WriteLine(" ");
        }

        // Function to open the front.in file and parse results lists
        // Replaces main driver in textbook
        public static void RunProgram()
        {
            // Run menu
            DisplayMenu();

            while (Variables.inputVariable != 'q')
            {
                if (Variables.inputVariable == 'r')
                {
                    // Attempt to open file
                    // User defines path variable
                    Console.WriteLine("Enter relative path to file");
                    Console.WriteLine("If file is with C# file, path is ../../../front.in");
                    Console.WriteLine("Ex. '../Infiles/front.in'");
                    Console.Write("Input: ");
                    string inPath = Console.ReadLine();
                    int lineNumber = 1;


                    // If file exists, attempt to open
                    if (File.Exists(inPath))
                    {
                        // For debugging and as a visual progress bar
                        Console.WriteLine("File exists, opening");

                        /*
                        * Open file and read in file
                        * Output line number
                        * Read file in line by line in while loop
                        */
                        FileStream inFile = new FileStream(inPath, FileMode.Open);
                        using (A5.Variables.inFileStream = new StreamReader(inFile))
                        {
                            while ((A5.Variables.line = A5.Variables.inFileStream.ReadLine()) != null)
                            {
                                // Visual confirmation program is working
                                Console.WriteLine("Parsing infile line " + lineNumber);
                                Console.WriteLine(A5.Variables.line);

                                // Parse line to char array
                                A5.Variables.lineArray = A5.Variables.line.ToCharArray();
                                Console.WriteLine(A5.Variables.lineArray.Length);

                                // Set iterator to 0
                                A5.Variables.iterator = 0;

                                // If not first line of parsing, set token to something other than EOL
                                if (lineNumber > 1)
                                {
                                    A5.Variables.nextToken = 0;
                                }
                                // Run lexical analysis
                                A5.getChar();
                                while (A5.Variables.nextToken != A5.Variables.EOL)
                                {
                                    A5.lex();
                                }

                                // Iterate parsed line number by one
                                lineNumber += 1;

                                // Output that line is parsed, ask for user input
                                Console.WriteLine("Line parsed");
                                Console.WriteLine("Press any key to parse next line");
                                Console.Read();
                            }
                            Console.WriteLine("EOF reached, File parsed");
                        }
                    }
                    // Else file can't be opened, exit with error message
                    else
                    {
                        Console.WriteLine("Can't find file, check paths and try again");
                    }
                }
                else {
                    Console.WriteLine("Invalid option...");
                }
                DisplayMenu();
            }
        }
       


    }

}
