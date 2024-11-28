#ifndef __doctor_h__
#define __doctor_h__

#include "employee.h"

class Doctor : public Employee {
    private:
        string specialty; 

    public:
        Doctor() {}

        Doctor(string id, string name, string dateOfBirth, string address, string phoneNumber, string email, string specialty)
            : Employee(id, name, dateOfBirth, address, phoneNumber, email), specialty(specialty) {}

        void input(istream& is) {
            Employee::input(is);
            cout << "Nhap chuyen mon cua bac si: ";
            getline(is, specialty);
        }

        void output(ostream& os) {
            Employee::output(os);
            os << ", Chuyen mon: " << specialty << endl;
        }


        string getSpecialty() {return specialty;}
        void setSpecialty(string& newSpecialty) {specialty = newSpecialty;}
};
#endif 