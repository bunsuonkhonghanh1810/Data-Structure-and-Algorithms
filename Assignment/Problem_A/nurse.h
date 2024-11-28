#ifndef __nurse_h__
#define __nurse_h__

#include "employee.h"

class Nurse : public Employee {
    private:
        string deparment; 

    public:
        Nurse() {}

        Nurse(string id, string name, string dateOfBirth, string address, string phoneNumber, string email, string deparment)
            : Employee(id, name, dateOfBirth, address, phoneNumber, email), deparment(deparment) {}

        void input(istream& is) {
            Employee::input(is);
            cout << "Nhap phong ban cua y ta: ";
            getline(is, deparment);
        }

        void output(ostream& os) {
            Employee::output(os);
            os << ", Phong ban: " << deparment << endl;
        }

        string getDepartment() {return deparment;}
        void setDepartment(string& newDepartment) {deparment = newDepartment;}
};
#endif 