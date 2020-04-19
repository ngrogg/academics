/* Assignment 5 Unit Testing
* Nicholas Grogg
* CS450
*
* This program is a helper program for unit testing
* the lexical analyzer
*
* TODO: Add unit tests for logical operators
*
* */

// Libraries
using System;
using System.IO;
using Xunit;

// Namespaces
using LexNs;

namespace A5Tests
{
    public class UnitTests
    {
        [Fact]
        public void TestAssignment()
        {
            // 'Using' statements should close things when done
            using (FileStream test1 = new FileStream("../../../test1.in", FileMode.Open))
            {
                using (A5.Variables.inFileStream = new StreamReader(test1))
                {
                    while ((A5.Variables.line = A5.Variables.inFileStream.ReadLine()) != null)
                    {
                        A5.Variables.lineArray = A5.Variables.line.ToCharArray();
                        A5.getChar();
                        A5.lex();
                        int actual = A5.Variables.ASSIGN_OP;
                        Assert.Equal(actual, A5.Variables.nextToken);
                    }
                }
            }
        }

        [Fact]
        public void TestUnknown()
        {
            using (FileStream test2 = new FileStream("../../../test2.in", FileMode.Open))
            {
                using (A5.Variables.inFileStream = new StreamReader(test2))
                {
                    while ((A5.Variables.line = A5.Variables.inFileStream.ReadLine()) != null)
                    {
                        A5.Variables.lineArray = A5.Variables.line.ToCharArray();
                        A5.getChar();
                        A5.lex();
                        int actual = A5.Variables.UNKNOWN;
                        Assert.Equal(actual, A5.Variables.nextToken);
                    }
                }
            }
        }


        // Test sentence
        [Fact]
        public void TestSentence()
        {
            using (FileStream test3 = new FileStream("../../../test3.in", FileMode.Open))
            {
                using (A5.Variables.inFileStream = new StreamReader(test3))
                {
                    while ((A5.Variables.line = A5.Variables.inFileStream.ReadLine()) != null)
                    {
                        A5.Variables.lineArray = A5.Variables.line.ToCharArray();
                        A5.getChar();

                        // Create two arrays, one with the real values and one for testing accuracy
                        int[] testList = { A5.Variables.IDENT, A5.Variables.ASSIGN_OP, A5.Variables.IDENT,
                                           A5.Variables.SUB_OP, A5.Variables.IDENT, A5.Variables.DIV_OP,
                                           A5.Variables.INT_LIT, A5.Variables.EOL};
                        int[] realList = new int[testList.Length];

                        // Populate realList using lex
                        for (int i = 0; i < realList.Length; i++)
                        {
                            realList[i] = A5.lex();
                        }
                        // Check if they're equal
                        Assert.Equal(testList, realList);
                    }
                }
            }
        }

        // Test for if file exists
        // Was going to test for all files.
        // In a production unit test I'd use this to testfor all files
        [Fact]
        public void Testexists()
        {
            bool file1;
            bool file2;

            // File exists
            if (File.Exists("../../../test1.in"))
            {
                file1 = true;
            }
            else
            {
                file1 = false;
            }

            // File doesn't exist
            if (File.Exists("../../../fail.in"))
            {
                file2 = true;
            }
            else
            {
                file2 = false;
            }
            Assert.True(file1);
            Assert.False(file2);
        }

        // Test for files with only white space
        [Fact]
        public void TestSpace()
        {

            using (FileStream space = new FileStream("../../../testUser2.in", FileMode.Open))
            {
                // Assign variable a non-existing token
                A5.Variables.nextToken = -10;

                using (A5.Variables.inFileStream = new StreamReader(space))
                {
                    bool isEmpty = true;
                    while ((A5.Variables.line = A5.Variables.inFileStream.ReadLine()) != null)
                    {
                        A5.getNonBlank();
                        // If there's something in the file, it'll get a new value
                        if (A5.Variables.nextToken != -10)
                        {
                            isEmpty = false;
                        }
                        Assert.True(isEmpty);
                    }
                }
            }
        }

        // Test for UNKNOWN \
        [Fact]
        public void TestUnknown2()
        {
            using (FileStream test3 = new FileStream("../../../testUser3.in", FileMode.Open))
            {
                using (A5.Variables.inFileStream = new StreamReader(test3))
                {
                    while ((A5.Variables.line = A5.Variables.inFileStream.ReadLine()) != null)
                    {
                        A5.Variables.lineArray = A5.Variables.line.ToCharArray();
                        A5.getChar();
                        A5.lex();
                        int actual = A5.Variables.UNKNOWN;
                        Assert.Equal(actual, A5.Variables.nextToken);
                    }
                }
            }
        }

        // Replacing the other unit test with a simpler character test for '?'
        [Fact]
        public void TestSentence2()
        {
            using (FileStream testUser5 = new FileStream("../../../testUser5.in", FileMode.Open))
            {
                using (A5.Variables.inFileStream = new StreamReader(testUser5))
                {
                    while ((A5.Variables.line = A5.Variables.inFileStream.ReadLine()) != null)
                    {
                        A5.Variables.lineArray = A5.Variables.line.ToCharArray();
                        A5.getChar();
                        A5.lex();
                        int actual = A5.Variables.UNKNOWN;

                        // Check if they're equal
                        Assert.Equal(actual, A5.Variables.nextToken);
                    }
                }
            }
        }
    }
}
