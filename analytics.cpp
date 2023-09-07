/**
 * @file analytics.cpp
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-08-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"

/**
 * @brief Opens the ifstream file and checks for valid file name
 * 
 * @param file 
 * @param fileName 
 */
void openInputFile(ifstream &file, string fileName)
{   
    file.open(fileName);
    if (!file){
        cout << "Error opening file\n";
        exit(1);
    }
}

/**
 * @brief Read file data to GradEmploymentData and add to array
 * 
 * @param file 
 * @param a 
 */
void readFile(ifstream &file, GradEmploymentData a[])
{
    string header; // variable for first line
    char delim; // variable for ',' char between values
    int i = 0; // counter for array position

    getline(file, header);

    while(file.peek() != EOF){
        GradEmploymentData newData;

        // if loop to prevent last line from being entered twice
        if (!(file >> newData.demographicsTotal)) {
            break;  
        }
        
        file >> delim;

        // check if first char of string is '"'
        // if so, read until the next one
        //if not, read string until ','
        if(file.peek() == '"'){
            file >> delim;
            getline(file, newData.educationMajor, '"');
            file >> delim;
            file.ignore();
        } else{
            getline(file, newData.educationMajor, ',');
        }
        
        file >> newData.meanSalary >> delim
             >> newData.medianSalary >> delim
             >> newData.demographicsAsian >> delim
             >> newData.demographicsMinority >> delim
             >> newData.demographicsWhite >> delim
             >> newData.demographicsFemales >> delim
             >> newData.demographicsMales >> delim
             >> newData.educationBachelor >> delim
             >> newData.educationDoctorate >> delim
             >> newData.educationMasters;
        a[i] = newData;
        i++;
    }
}

/**
 * @brief Code for homescreen
 * 
 */
void homeScreen(){
    cout << "2015 National Survey of Recent College Graduate" << endl;
    cout << "1. Top 10 Majors with the Highest Mean Salary" << endl;
    cout << "2. Top 10 Majors with the Lowest Mean Salary" << endl;
    cout << "3. Top 10 Majors with the Highest Median Salary" << endl;
    cout << "4. Top 10 Majors with the Lowest Median Salary" << endl;
    cout << "5. Top 5 Majors with the Highest Number of Asians" << endl;
    cout << "6. Top 5 Majors with the Lowest Number of Asians" << endl;
    cout << "7. Top 5 Majors with the Highest Number of Minorities" << endl;
    cout << "8. Top 5 Majors with the Lowest Number of Minorities" << endl;
    cout << "9. Top 5 Majors with the Highest Number of Females" << endl;
    cout << "10. Top 5 Majors with the Lowest Number of Females" << endl;
    cout << "11. Display Information for a Specific Major" << endl;
    cout << "12. Exit\n" << endl;
}

/**
 * @brief Code used to view struct in early stages
 * 
 * @param a 
 * @param size 
 */
void showStruct(GradEmploymentData a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i].demographicsTotal << ",";
        cout << a[i].educationMajor << ",";
        cout << a[i].meanSalary << ",";
        cout << a[i].medianSalary << ",";
        cout << a[i].demographicsAsian << ",";
        cout << a[i].demographicsMinority << ",";
        cout << a[i].demographicsWhite << ",";
        cout << a[i].demographicsFemales << ",";
        cout << a[i].demographicsMales << ",";
        cout << a[i].educationBachelor << ",";
        cout << a[i].educationDoctorate << ",";
        cout << a[i].educationMasters << endl;
    }
}

/**
 * @brief function to sort by highest mean salary
 * 
 * @param a 
 * @param size 
 */
void highMeanSalary(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].meanSalary < a[i+1].meanSalary){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Mean Salary\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 10; i++){
        cout << setw(35) << left << a[i].educationMajor << right << "$" << setw(12) << fixed << setprecision(2) << a[i].meanSalary << endl;
    }
    
}

/**
 * @brief function to bubble sort by lowest mean salary
 * 
 * @param a 
 * @param size 
 */
void lowMeanSalary(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].meanSalary > a[i+1].meanSalary){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Mean Salary\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 10; i++){
        cout << setw(35) << left << a[i].educationMajor << right << "$" << setw(12) << fixed << setprecision(2) << a[i].meanSalary << endl;
    }
}

/**
 * @brief function to bubble sort by highest median salary
 * 
 * @param a 
 * @param size 
 */
void highMedianSalary(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].medianSalary < a[i+1].medianSalary){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Median Salary\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 10; i++){
        cout << setw(35) << left << a[i].educationMajor << right << "$" << setw(12) << a[i].medianSalary << endl;
    }
}

/**
 * @brief bubble sort lowest mean salary
 * 
 * @param a 
 * @param size 
 */
void lowMedianSalary(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].medianSalary > a[i+1].medianSalary){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Median Salary\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 10; i++){
        cout << setw(35) << left << a[i].educationMajor << right << "$" << setw(12) << a[i].medianSalary << endl;
    }
}

/**
 * @brief bubble sort highest asian demographic
 * 
 * @param a 
 * @param size 
 */
void highAsian(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].demographicsAsian < a[i+1].demographicsAsian){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Asian Students\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 5; i++){
        cout << setw(35) << left << a[i].educationMajor << right << setw(13) << a[i].demographicsAsian << endl;
    }
}


/**
 * @brief bubble sort lowest asian demographic
 * 
 * @param a 
 * @param size 
 */
void lowAsian(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].demographicsAsian > a[i+1].demographicsAsian){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Asian Students\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 5; i++){
        cout << setw(35) << left << a[i].educationMajor << right << setw(13) << a[i].demographicsAsian << endl;
    }
}

/**
 * @brief bubble sort highest minority demographic
 * 
 * @param a 
 * @param size 
 */
void highMinority(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].demographicsMinority < a[i+1].demographicsMinority){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Minority Students\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 5; i++){
        cout << setw(35) << left << a[i].educationMajor << right << setw(13) << a[i].demographicsMinority<< endl;
    }
}

/**
 * @brief bubble sort lowest minority demographic
 * 
 * @param a 
 * @param size 
 */
void lowMinority(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].demographicsMinority > a[i+1].demographicsMinority){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Minority Students\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 5; i++){
        cout << setw(35) << left << a[i].educationMajor << right << setw(13) << a[i].demographicsMinority << endl;
    }
}

/**
 * @brief bubble sort highest female demographic
 * 
 * @param a 
 * @param size 
 */
void highFemale(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].demographicsFemales < a[i+1].demographicsFemales){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Female Students\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 5; i++){
        cout << setw(35) << left << a[i].educationMajor << right << setw(13) << a[i].demographicsFemales << endl;
    }
}

/**
 * @brief bubble sort lowest female demographic
 * 
 * @param a 
 * @param size 
 */
void lowFemale(GradEmploymentData a[], int size){
    bool swap;
    GradEmploymentData temp;

    do{
        swap = false;
        for (int i = 0; i < size - 1; i++){
            if (a[i].demographicsFemales > a[i+1].demographicsFemales){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);

    cout << "Education Major                    Female Students\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < 5; i++){
        cout << setw(35) << left << a[i].educationMajor << right << setw(13) << a[i].demographicsFemales << endl;
    }
}

/**
 * @brief asks user to enter a major
 *        displays all information about requested major
 * 
 * @param a 
 * @param size 
 */
void specificMajor(GradEmploymentData a[], int size){
    string majorName;
    GradEmploymentData temp;
    bool valid = false;
    cout << "Please enter the name of a Major: ";
    while (!valid){
        getline(cin, majorName);
        for(int i = 0; i < size; i++){
            if (majorName == a[i].educationMajor){
                temp = a[i];
                a[i] = a[0];
                a[0] = temp;
                valid = true;
            } 
        }
        if (!valid){
            cout << "Major not found. Please enter valid Major. ";
        }
    }
    cout << a[0].educationMajor << " Information" << endl;
    cout << "------------------------------------------------" << endl;
    cout << setw(35) << left << "Total Demographics: " << right << setw(13) << a[0].demographicsTotal << endl;
    cout << setw(35) << left << "Mean Salary: " << right << "$" << setw(12) << fixed << setprecision(2) << a[0].meanSalary << endl;
    cout << setw(35) << left << "Median Salary: " << right << "$" << setw(12) << a[0].medianSalary << endl;
    cout << setw(35) << left << "Asian Demographic: " << right << setw(13) << a[0].demographicsAsian << endl;
    cout << setw(35) << left << "Minority Demographic: " << right << setw(13) << a[0].demographicsMinority << endl;
    cout << setw(35) << left << "White Demographic: " << right << setw(13) << a[0].demographicsWhite << endl;
    cout << setw(35) << left << "Female Demographic: " << right << setw(13) << a[0].demographicsFemales << endl;
    cout << setw(35) << left << "Male Demographic: " << right << setw(13) << a[0].demographicsMales << endl;
    cout << setw(35) << left << "Bachelors Degrees: " << right << setw(13) << a[0].educationBachelor << endl;
    cout << setw(35) << left << "Doctorate Degrees: " << right << setw(13) << a[0].educationDoctorate << endl;
    cout << setw(35) << left << "Masters Degrees: " << right << setw(13) << a[0].educationMasters << endl;

}