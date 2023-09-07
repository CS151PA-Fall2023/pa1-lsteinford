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
        ifstream inputFile;
        openInputFile(inputFile, "graduates2015.csv");

        int SIZE = 45;
        GradEmploymentData Majors[SIZE];
        
        readFile(inputFile, Majors);

        bool cont = true;
        while(cont){
                homeScreen();

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
