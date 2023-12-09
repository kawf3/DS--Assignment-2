#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <cmath>
#include <stdexcept>
#include <cstddef>
#include "Employee.h"

using namespace std;

//Professional
Professional::Professional(double monthlySalary, int vacationDays) :
    monthlySalary_(monthlySalary), vacationDays_(vacationDays) {}

double Professional::weeklySalary() const {
    return monthlySalary_ / 4;
}

double Professional::healthCare() const {
    return monthlySalary_ * 0.1;
}

int Professional::vacationDays() const {
    return vacationDays_;
}

string Professional::getType() const {
    return "Professional";
}

//Non professional
NonProfessional::NonProfessional(double hourlyRate, int hoursWorked, int vacationHours) :
    hourlyRate_(hourlyRate), hoursWorked_(hoursWorked), vacationHours_(vacationHours) {}

double NonProfessional::weeklySalary() const {
    return hourlyRate_ * hoursWorked_;
}

double NonProfessional::healthCare() const {
    return hourlyRate_ * hoursWorked_ * 0.05;
}

int NonProfessional::vacationDays() const {
    return vacationHours_ / 8;
}

string NonProfessional::getType() const {
    return "NonProfessional";
}