/**
 * @file analytics.h
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-08-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major
};

void openInputFile(ifstream &file, string fileName);
void readFile(ifstream &file, GradEmploymentData a[]);
void homeScreen();
void showStruct(GradEmploymentData a[], int size);
void highMeanSalary(GradEmploymentData a[], int size);
void lowMeanSalary(GradEmploymentData a[], int size);
void highMedianSalary(GradEmploymentData a[], int size);
void lowMedianSalary(GradEmploymentData a[], int size);
void highAsian(GradEmploymentData a[], int size);
void lowAsian(GradEmploymentData a[], int size);
void highMinority(GradEmploymentData a[], int size);
void lowMinority(GradEmploymentData a[], int size);
void highFemale(GradEmploymentData a[], int size);
void lowFemale(GradEmploymentData a[], int size);
void specificMajor(GradEmploymentData a[], int size);


#endif