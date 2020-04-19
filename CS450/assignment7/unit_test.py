import pathlib
import unittest

class Tests(unittest.TestCase):

    # Check if input files exist
    def test_exists(self):
        # Boolean value, should stay True
        filesExist = True

        # Paths to files
        trainee = pathlib.Path("bank_train.txt")
        testee  = pathlib.Path("bank_test.txt")

        # Check if training file exists
        if not trainee.exists():
            filesExist = False

        # Check if test file exists
        if not testee.exists():
            filesExist = False

        # Check if bool is true
        self.assertTrue(filesExist)

    # Check if comma delimiter works
    def test_split(self):
        # This is a line of data from the training file
        stringIn = '2.5605,9.2683,-3.5913,-1.356,0'

        # Split it and assert it works
        self.assertEqual(stringIn.split(','),['2.5605','9.2683','-3.5913','-1.356','0'])

        # Yay...

if __name__ == '__main__':
    unittest.main()
