#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
//Class definitions - kept in this file for easy access
class Employee {
public:
    virtual double weeklySalary() const = 0;
    virtual double healthCare() const = 0;
    virtual int vacationDays() const = 0;
    virtual std::string getType() const = 0;
};

class Professional : public Employee {
public:
    Professional(double monthlySalary, int vacationDays);
    double weeklySalary() const override;
    double healthCare() const override;
    int vacationDays() const override;
    std::string getType() const override;
private:
    double monthlySalary_;
    int vacationDays_;
};

class NonProfessional : public Employee {
public:
    NonProfessional(double hourlyRate, int hoursWorked, int vacationHours);
    double weeklySalary() const override;
    double healthCare() const override;
    int vacationDays() const override;
    std::string getType() const override;
private:
    double hourlyRate_;
    int hoursWorked_;
    int vacationHours_;
};

#endif  // EMPLOYEE_H
