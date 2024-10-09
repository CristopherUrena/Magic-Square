#include <iostream>
#include <fstream>

using namespace std;

// readMagicSquareValues() - reads the contents of the supplied file object
// which are assumed to be a nXn array of numbers. The function returns a
// MagicSquare struct with the contents of the file loaded into the
// magicSquare.square member variable and the magicSquare.order variable set to
// the dimension of the array that has been read.
// Parameters:
//   ifstream inFile - the file object to read from
//   int order - the dimension of the magic square array to be read
// Returns:
//   a MagicSquare struct
struct MagicSquare readMagicSquareValues(std::ifstream& inFile, int order);

// validateMagicSquare() - validates the supplied MagicSquare struct to confirm
// that is satisfies the properties of a Magic Square.
// Parameters:
//   struct MagicSquare magicSquare - the magic square values to be validated
// Returns:
//   true if the magic square is correct; false otherwise
bool validateMagicSquare(struct MagicSquare &magicSquare);

// MagicSquare structure to store a 2-dimensional array and its dimension
struct MagicSquare {
    int **square;
    int order;
};


int main()
{
    using namespace std;

    string fileName;
    int order;
    ifstream inFile;

    cout << "Enter the name of the file that contains your magic square: ";
    cin >> fileName;
    cout << "Enter the dimension of your magic square: ";
    cin >> order;

    // TODO: Open the file containing the magic square values.
    inFile.open(fileName);
    if(!inFile) 
    {
	    cerr << "Error opening file : " <<fileName << endl;
	    return 1; 
    }


    // TODO: Call your readMagicSquareValues() function saving the returned
    // MagicSquare struct into a variable.
    MagicSquare myMagicSquare = readMagicSquareValues(inFile, order); 

    // TODO: Close the file you opened.
    inFile.close();

    // TODO: Call your validateMagicSquare() function to determine if the 
    // given magic square is correct or not. If it is correct, print a 
    // message to the screen: "Your magic square is perfect!\n". If it is
    // not correct, print "Your magic square is not very magical, is it?\n".
    if (validateMagicSquare(myMagicSquare)) 
    {
	    cout << "Your magic square is perfect!"<<endl; 
    }
    else
    {
	    cout<<"Your magic square is not very magical, is it?\n";
    }

    // TODO: Free the memory allocated to myMagicSquare.square.
    for(int i = 0; i < order; i++)
    {
	    delete[] myMagicSquare.square[i]; 
    }
    delete[] myMagicSquare.square;

    return 0;
}


bool validateMagicSquare(struct MagicSquare &magicSquare) 
{
    int order = magicSquare.order; 
    int sumRow = 0, sumCol = 0; 
    int magicSum = 0; 
     
    // TODO: initialize a flag to indicate whether or not the given
    // magic square is valid or not.
    bool isValid = true;

    // TODO: Write the code to check that the sums of the rows and columns of
    // the magic square are all the same.  Remember that you are working with a
    // 2-dimensional array, which suggests that two for loops will be useful.
    for ( int i = 0; i < order; i++)
     {
	     magicSum += magicSquare.square[0][i];
     }

       
    // TODO: Write a pair (inner and outer) of for loops to check that all the
    // rows add up to the same value.
    for( int i = 0; i < order; i++)
    {
	    sumRow = 0; 
	    for( int j = 0; j < order; j++)
	    {
		    sumRow += magicSquare.square[i][j];
	    }
	    if(sumRow != magicSum)
	    {
		    isValid = false; 
		    break;
	    }
    }



    // TODO: Bonus Part +5 points. Write a pair (inner and outer) of for loops
    // to check that all the columns add up to the same value.
    if (isValid)
    {
	    for(int i = 0; i < order; i++) 
	    {
		    sumCol = 0; 
		    for(int j = 0; j < order; j++)
		    {
			   sumCol +=magicSquare.square[i][j];
		    }
		   if (sumCol != magicSum)
		   {
			  isValid = false;
			 break;
		   }
	    }
          }
    return isValid;

}

 


struct MagicSquare readMagicSquareValues(std::ifstream& inFile, int order)
{
    int **magicSquareArray; // Pointer to a two-dimensional array.
    int currentValue;

    // TODO: allocate memory for the rows of the two-dimensional array.
    // See slide #51 03 - Pointers and Dynamic Arrays
    magicSquareArray = new int*[order];   
 
   
        for(int i = 0; i < order; i++)
	{
		magicSquareArray[i] = new int[order];

        for (int j = 0; j < order; j++) 
	{
            // TODO: read the values in this row of the array. You can read
            // and store a value into the currentValue variable and then place
            // that value into your magicSquareArray array.
            inFile >> currentValue; 
	    magicSquareArray[i][j] = currentValue;
        }
    }

    // TODO: Declare a MagicSquare struct variable and set its member elements
    // to the magicSquareArray and the order.
   
    MagicSquare magicSquare;
    magicSquare.square = magicSquareArray;
    magicSquare.order = order;
    // TODO: Return the MagicSquare struct you created in this function.

   return magicSquare;

}

