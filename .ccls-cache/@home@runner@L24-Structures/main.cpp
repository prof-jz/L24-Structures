/**********************************************
 * Alabama A&M University - EE109 - Spring 2023
 * Lesson 24 sample code: Structures 
 * By:            Prof J Zehnpfennig, PE
 * Created:       02 March 2023
 * Last Updated:  06 April 2023
 **********************************************/

#include <fstream>  //JZ - used to work with files
#include <iostream> //JZ - used to work with input/output streams
#include <string>   //JZ - used to work with strings

using namespace std;


/*Create a datatype using Structures.  Structures are formally interconnected records of datatypes.*/
struct DBRecord  //JZ - defines a new data structure called DBRecord.    
{
  string fName;  //JZ - first name record within every DBRecord instance
  string lName;  //JZ - last name record within every DBRecord instance
  int employeeN; //JZ - employee number record within every DBRecord instance
}

DBRecord fileRead(string fileName, int numRec);


int main() {
 
  string fileName = "employeeData"; // JZ - sets the name of the file to open
  DBRecord myDB;
  int Records = 3;
  
  myDB = fileRead(fileName); //JZ - uses fileRead to read the file and return the DB to main()
  
  return 0;
}

void nameSort(string fileName)
{
  bool done = false;            // JZ - variable to determine when sort is done
  int x = 0, y = 0;             // JZ - counter variables
  DBRecord empRecords[3]; // JZ - string array

  
  ifstream myfile;
  myfile.open(fileName);

  /*JZ - Next we test to see if the file is open,
   * if so we reading each element of the file into a
   *   string array variable,
   * we then close the file
   */
  if (myfile.is_open()) {
    while (myfile.good()) // JZ - iterates until program encounters the EOF (end
                       // of file) character
    {
      myfile >> animalNames[x]; // JZ - pipes stream from the urrent location in
                                // 'myfile' into the current 'animalNames'
                                // pidgeonhole until it encounters a ' ' or '\n'
      x++;
    }
  }
   myfile.close();
  
  while (done == false) {
    done = true;

    cout << "\n\nThe list after " << y << " sort iterations is: \n";
    y++;

    // JZ - outputs the list in each iteration
    for (x = 0; x < sizeof(animalNames) / sizeof(string); x++) {
      if ((x) % 5 == 0) // JZ - note use of '%' modulo
      {
        cout << endl; // JZ - adds a carriage return between every 5 elements so
                      // the list displays neatly.
      }
      cout << animalNames[x] << " ";
    }

    /*
     * JZ - sorting on the 'sizeof' the string array results       * in sorting
     * each letter.
     */

    for (x = 1; x < sizeof(animalNames) / sizeof(string); x++) {
      if (animalNames[x - 1] > animalNames[x]) {
        done = false;
        temp = animalNames[x];
        animalNames[x] = animalNames[x - 1];
        animalNames[x - 1] = temp;
      }
    }
  }

 ofstream sortListF;
    sortListF.open("animalSort.txt");
   for (x = 0; x < sizeof(animalNames)/sizeof(string); x++)
     {
       sortListF << animalNames[x];
       if ( x < sizeof(animalNames)/sizeof(string) - 1)
       sortListF <<  "\n";
     }
   sortListF.close();
  
  
  cout << "\n\nThe list is sorted!\n";

}

string cName()
{
  string fileName;
  bool done = false;

  cout << "WHat filename";
  while (!done)
    {
      done = true;
  getline(cin, fileName);
  for (int x = 0; x < sizeof(fileName); x++)
    if (fileName[x] == ' ')
      cout << "invalid name";
      done = false;
    }
  return fileName;
}