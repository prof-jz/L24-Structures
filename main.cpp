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

DBRecord fileRead(string fName, int rec);
void listPrint(string fileN, int rec, DBRecord DBOut);
void fileWrite(string fileN, int rec, DBRecord DBOut);
string cName(string question);
  

int main() 
{
  string fileName;
  DBRecord myDB;
  int Records = 3;

  fileName = cName("Enter the filename to read data from: "); // JZ - sets the name of the file to open
  if (fileName == "")
    fileName = "employeeData.txt";
  
  myDB = fileRead(fileName, Records); //JZ - uses fileRead to read the file and return the DB to main()

  fileName = cName("\nEnter the filename to write data to:"); // JZ - sets the name of the file to open
  if (fileName == "")
    fileName = "employeeInfo.txt";
  fileWrite(fileName, rec, myDB)
  return 0;
}



DBRecord fileRead(string fileN, int rec)
{
  bool done = false;            // JZ - variable to determine when sort is done
  int x = 0, y = 0;             // JZ - counter variables
  DBRecord empRecords[rec];       // JZ - creates database empRecords with rec elements

  
  ifstream myFile;    //JZ - associates file input stream with myFile
  myFile.open(fileN);

  if (myFile.is_open()) 
  {
    while (myFile.good()) // JZ - iterates until program encounters the EOF (end
                       // of file) character
    {
      
      /* JZ - pipes stream from the current location in'myfile' into the current 
        empRecord element*/ 
      myFile >> empRecords[x].fName;
      myFile >> empRecords[x].lName;
      myFile >> empRecords[x].employeeN;   
      x++;
    }
  }
  myFile.close();
  
  return empRecords[rec];
}



void fileWrite(string fileN, int rec, DBRecord DBOut[rec])
{
  int x = 0;
  ofstream saveF;
    saveF.open(fileN);
   for (x = 0; x < rec; x++)
     {
       saveF << "First Name " << x+1 << DBOut[x].fName;
       saveF << "Last Name " << x+1 << DBOut[x].lName;
       saveF << "Employee Number " << x+1 << DBOut[x].employeeN; 
       if (x < rec - 1)
         cout << "\n";  
     }
   saveF.close();
}



string cName(string question)
{
  string fileName;
  bool done = false;

  cout << question;
  while (!done)
    {
      done = true;
      getline(cin, fileName);
      for (int x = 0; x < sizeof(fileName); x++)
          if (fileName[x] == ' ')
          {
            cout << "invalid name";
            done = false;
          }
    }
  return fileName;
}