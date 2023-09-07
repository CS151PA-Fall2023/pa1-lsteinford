/**
 * @file main.cpp
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-08-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"
using namespace std;

int main()
{
        ifstream inputFile; // file variable
        openInputFile(inputFile, "graduates2015.csv"); // opens the file

        int SIZE = 45; // variable for size of array
        GradEmploymentData Majors[SIZE]; // array of GradEmploymentData struct
        
        readFile(inputFile, Majors); // reads file and puts data into Majors array

        //while loop will bring user back to the home screen after each option
        bool cont = true; 
        while(cont){
                homeScreen();
                
                // input validation
                int userInput;
                do{
                        cout << "Select a Menu: ";
                        cin >> userInput;
                        cout << endl;
                }while (userInput < 1 || userInput > 12);

                cin.ignore();
                
                
                switch (userInput){
                        case 1: 
                                highMeanSalary(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 2:
                                lowMeanSalary(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 3:
                                highMedianSalary(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 4:
                                lowMedianSalary(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 5:
                                highAsian(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 6:
                                lowAsian(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 7:
                                highMinority(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 8:
                                lowMinority(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 9:
                                highFemale(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 10:
                                lowFemale(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 11:
                                specificMajor(Majors, SIZE);
                                cout << endl << "Press Enter to continue...";
                                cin.ignore();
                                break;
                        case 12:
                                cont = false;
                                break;
                        default:
                                break;
                }
        }
        inputFile.close();

        return 0;
}
