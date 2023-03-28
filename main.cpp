/**********************************************
 * Alabama A&M University - EE109 - Spring 2023
 * Lesson 17 sample code: Structures and Sorting
 * By:            Prof J Zehnpfennig, PE
 * Created:       02 March 2023
 * Last Updated:  07 March 2023
 **********************************************/

#include <fstream>  //JZ - used to work with files
#include <iostream> //JZ - used to work with input/output streams
#include <string>   //JZ - used to work with strings

using namespace std;


void nameSort(string fileName);

int main() {
  bool done = false;            // JZ - variable to determine when sort is done
  int x = 0, y = 0;             // JZ - counter variables
  string animalNames[18], temp; // JZ - string array
  string fileName = "animals.txt"; // JZ - sets the name of the file to open

  nameSort(fileName);
  /*
   *JZ - 'ifstream' tells the compiler that we are
   * going to have an input file stream.
   * We call the input stream 'myfile'.
   * We set 'myfile' to be related to the file named above
   */

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
    sortListF << animalNames[x] << "\n";
  sortListF.close();
  
  
  cout << "\n\nThe list is sorted!\n";

  /*
   * JZ - Add your Project Code below:
   *  1. Move the file read out of main() and into a function
   *    a. Pass the file name to the function
   *    b. Open, read, and sort the file as demonstrated
   *    c. Close "animals.txt"
   *  2. Write the sorted list to a file called animalSort.txt
   *    a. In the sorting fuction,
   *      i.   open a the "animalSort.txt" file
   *      ii.  write sorted variable contents to the file
   *      iii. ensure each name appears on its own line
   *      iv.  close "animalSort.txt"
   *    b. return to main();
   *  3. Add features to main()
   *    a. create a menu with the following options:
   *      i.   Sort default animals.txt
   *      ii.  Sort custom named file & save to custom filenam
   *      iii. Print contents animals.txt
   *      iv.  Print contents of animalSort.txt
   *      v.   Print contents of custom named file
   *      vi.  Exit program
   *  4. Create new function calls
   *      i.  string customName() that returns a string into
   *      a string variable called 'cName'
   *      ii. void listPrint(string cName)
   *      ii. have all function calls pass custom names
   *  5.  Create two additional functions:
   *     a. string customName() {}
   *        i.  Asks user to input the filename
   *        ii. Validates input to ensure there are no spaces
   *        iii.Returns valid filename to main() string 'cName'
   *     b. void listPrint(string fileName)
   *        i.  Prints contents of 'fileName'
   *          Note: 'fileName' is cName from main()
   *        ii. Separates list by rows of 5 names
   */

  return 0;
}


void nameSort(string fileName)
{
  
}

