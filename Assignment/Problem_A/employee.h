#ifndef __employee__h__
#define __employee__h__

#include <bits/stdc++.h>
using namespace std;

class Employee {
    private:
        string id;
        string name;
        string dateOfBirth;
        string address;
        string phoneNumber;
        string email;

    public:
        Employee() {}
        
        Employee(string id, string name, string dateOfBirth, string address, string phoneNumber, string email)
            : id(id), name(name), dateOfBirth(dateOfBirth), address(address), phoneNumber(phoneNumber), email(email) {}

        virtual ~Employee() {}

        virtual void input(istream& is) {
            cout << "Nhap ten: ";
            getline(is, name);
            cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
            getline(is, dateOfBirth);
            cout << "Nhap dia chi: ";
            getline(is, address);
            cout << "Nhap so dien thoai: ";
            getline(is, phoneNumber);
            cout << "Nhap email: ";
            getline(is, email);
        }

        friend istream& operator>>(istream& is, Employee& employee) {
            employee.input(is); 
            return is;
        }

        virtual void output(ostream& os) {
        os << "CCCD: " << id
           << ", Ten: " << name 
           << ", Ngay thang nam sinh: " << dateOfBirth 
           << ", Dia chi: " << address 
           << ", So dien thoai: " << phoneNumber 
           << ", Email: " << email;
        }

        friend ostream& operator<<(ostream& os, Employee& employee) {
            employee.output(os);
            return os;
        }
        bool operator < (Employee& other) {
            int day1, month1, year1;
            int day2, month2, year2;

            splitDate(this->dateOfBirth, day1, month1, year1);
            splitDate(other.dateOfBirth, day2, month2, year2);

            if (year1 != year2) return year1 < year2;
            if (month1 != month2) return month1 < month2;
            return day1 < day2;
        }

        string getId() {return id;}
        void setId(string& newId) {id = newId;}

        string getName() {return name;}
        void setName(string& newName) {name = newName;}

        string getDateOfBirth() {return dateOfBirth;}
        void setDateOfBirth(string& newDateOfBirth) {dateOfBirth = newDateOfBirth;}

        string getAddress() {return address;}
        void setAddress(string& newAddress) {address = newAddress;}

        string getPhoneNumber() {return phoneNumber;}
        void setPhoneNumber(string& newPhoneNumber) {phoneNumber = newPhoneNumber;}

        string getEmail() {return email;}
        void setEmail(string& newEmail) {email = newEmail;}

        void splitDate(string& dob, int& day, int& month, int& year) {
            stringstream ss(dob);
            string segment;
            getline(ss, segment, '/');
            day = stoi(segment);
            getline(ss, segment, '/');
            month = stoi(segment);
            getline(ss, segment, '/');
            year = stoi(segment);
        }
};
#endif