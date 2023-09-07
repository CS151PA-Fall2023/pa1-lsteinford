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

void openInputFile(ifstream &file, string fileName)
{   
    file.open(fileName);
    if (!file){
        cout << "Error opening file\n";
        exit(1);
    }
}

void readFile(ifstream &file, GradEmploymentData a[])
{
    string header;
    char delim;
    int i = 0;

    getline(file, header);

    while(file.peek() != EOF){
        GradEmploymentData newData;

        // If loop to prevent duplicate line added to vector
        if (!(file >> newData.demographicsTotal)) {
            break;  
        }
        
        file >> delim;

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

void showStruct(GradEmploymentData a[], int size)
{
    int vectorSize = size;

    for (int i = 0; i < vectorSize; i++)
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