#ifndef __employeeList__h__
#define __employeeList__h__

#include <conio.h>
#include "doctor.h"
#include "nurse.h"

class VectorEmployee {
    private:
        vector<Employee*> employees;
        vector<Employee*> foundResults;
    public:
        void manualEntry() {
            cout << "Cung cap so luong nhan su can nhap: ";
            int number;
            cin >> number;
            cin.ignore();

            for (int i = 0; i < number; i++) {
                cout << "Nhap thong tin cho nhan su thu " << i + 1 << ":" << endl;

                string id;
                Employee* emp = nullptr;

                while (true) {
                    cout << "Nhap so CCCD (them tien to E, D, N neu lan luot la can bo benh vien, bac si, y ta): ";
                    cin >> id;
                    cin.ignore();

                    if (id[0] == 'E') {
                        emp = new Employee();
                        break; 
                    } else if (id[0] == 'D') {
                        cout << "haha" << endl;
                        emp = new Doctor();
                        break;
                    } else if (id[0] == 'N') {
                        emp = new Nurse();
                        break;
                    } else {
                        cerr << "So CCCD khong hop le. Vui long nhap lai.\n";
                    }
                }
                emp->setId(id);
                cin >> *emp;
                employees.push_back(emp);
            }
        }

        void fileEntry() {
            ifstream file;

            do {
                cout << "Nhap dia chi file: ";
                string filename;
                cin >> filename;
                file.open(filename);
                if (!file.is_open()) cout << "Dia chi file vua nhap sai" << filename << endl;
            }while (!file.is_open());

            fileEntry(file);

            cout << "Nhap thanh cong" << endl;
        }

        void fileEntry(ifstream& file) {
            string data;
            string id, name, dateOfBirth, address, phoneNumber, email, individualAttribute;
            
            while (getline(file, data)) {
                stringstream ss(data);
                
                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, dateOfBirth, ',');
                getline(ss, address, ',');
                getline(ss, phoneNumber, ',');
                getline(ss, email, ',');
                getline(ss, individualAttribute, ',');

                Employee* emp = nullptr;

                if (id[0] == 'E') {
                    emp = new Employee(id, name, dateOfBirth, address, phoneNumber, email);
                } else if (id[0] == 'D') {
                    emp = new Doctor(id, name, dateOfBirth, address, phoneNumber, email, individualAttribute);
                } else if (id[0] == 'N') {
                    emp = new Nurse(id, name, dateOfBirth, address, phoneNumber, email, individualAttribute);
                }

                employees.push_back(emp);
            }
        }

        void findByAttribute(string attribute, string& value) {
            foundResults.clear();

            for (auto emp : employees) {
                if (attribute == "id" && emp->getId() == value) {
                    foundResults.push_back(emp);
                } else if (attribute == "name" && emp->getName() == value) {
                    foundResults.push_back(emp);
                } else if (attribute == "dateOfBirth" && emp->getDateOfBirth() == value) {
                    foundResults.push_back(emp);
                } else if (attribute == "address" && emp->getAddress() == value) {
                    foundResults.push_back(emp);
                } else if (attribute == "phoneNumber" && emp->getPhoneNumber() == value) {
                    foundResults.push_back(emp);
                } else if (attribute == "email" && emp->getEmail() == value) {
                    foundResults.push_back(emp);
                } else if (attribute == "specialty") {
                    Doctor* doc = dynamic_cast<Doctor*>(emp);
                    if (doc && doc->getSpecialty() == value) {
                        foundResults.push_back(emp);
                    }
                } else if (attribute == "department") {
                    Nurse* nurse = dynamic_cast<Nurse*>(emp);
                    if (nurse && nurse->getDepartment() == value) {
                        foundResults.push_back(emp);
                    }
                }
            }
        }

        void findAllEmployees() {
            foundResults.clear();

            for (auto emp : employees) {
                if (emp->getId()[0] == 'E') {
                    foundResults.push_back(emp);
                }
            }
        }

        void findAllDoctors() {
            foundResults.clear();

            for (auto emp : employees) {
                if (emp->getId()[0] == 'D') {
                    foundResults.push_back(emp);
                }
            }
        }

        void findAllNurses() {
            foundResults.clear();

            for (auto emp : employees) {
                if (emp->getId()[0] == 'N') {
                    foundResults.push_back(emp);
                }
            }
        }

        void findAll() {
            foundResults.clear();

            for (auto emp : employees) {
                foundResults.push_back(emp);
            }
        }

        void displayFoundResults() {
            if (foundResults.size() == 0) {
                cout << "|                  Khong tim thay doi tuong                  |" << endl;
                cout << "--------------------------------------------------------------" << endl;
            } else {
                for (int i = 0; i < static_cast<int>(foundResults.size()); i++) {
                    cout << i + 1 << ". " << *foundResults[i] << endl;
                }
            }
        }

        void displayEmployees() {
            if (employees.size() == 0) {
                cout << "|                      Danh sach trong                       |" << endl;
                cout << "--------------------------------------------------------------" << endl;
            } else {
                for (int i = 0; i < static_cast<int>(employees.size()); i++) {
                    cout << i + 1 << ". " << *employees[i] << endl;
                }
            }
        }

        string getChoice() {
            char choice1, choice2;

            cout << "|                  Nhap lua chon (1-13):                     |";

            do {
                choice1 = _getch();
                cout << "\r|                  Nhap lua chon (1-13): " << choice1 << "                   |";
                choice2 = _getch();
                cout << "\r|                  Nhap lua chon (1-13): " << choice1 << choice2 << "                  |" << endl;
                cout << "--------------------------------------------------------------" << endl;
                
                if (choice1 == '0' && (choice2 >= '1' && choice2 <= '9')) {
                    break;
                } else if (choice1 == '1' && (choice2 >= '0' && choice2 <= '3')) {
                    break;
                } else {
                    cout << "|    Lua chon khong hop le. Vui long nhap lai (1-13):      |";
                    choice1 = _getch();
                    cout << "\r|    Lua chon khong hop le. Vui long nhap lai (1-13): " << choice1 << "    |";
                    choice2 = _getch();
                    cout << "\r|    Lua chon khong hop le. Vui long nhap lai (1-13): " << choice1 << choice2 << "   |" << endl;
                    cout << "--------------------------------------------------------------" << endl;
                }
            } while (true);

            string result;

            result.push_back(choice1); 
            result.push_back(choice2);

            return result;
        }
        
        void handleChoice(string result) {
            string data;

            if (result == "01") {
                cout << "Nhap so CCCD muon tim: ";
                getline(cin, data); 
                findByAttribute("id", data);
            } else if (result == "02") {
                cout << "Nhap ten nhan su muon tim: ";
                getline(cin, data);
                findByAttribute("name", data);
            } else if (result == "03") {
                cout << "Nhap ngay sinh muon tim: ";
                getline(cin, data);
                findByAttribute("dateOfBirth", data);
            } else if (result == "04") {
                cout << "Nhap dia chi muon tim: ";
                getline(cin, data);
                findByAttribute("address", data);
            } else if (result == "05") {
                cout << "Nhap so dien thoai muon tim: ";
                getline(cin, data);
                findByAttribute("phoneNumber", data);
            } else if (result == "06") {
                cout << "Nhap email muon tim: ";
                getline(cin, data);
                findByAttribute("email", data);
            } else if (result == "07") {
                cout << "Nhap chuyen mon muon tim: ";
                getline(cin, data);
                findByAttribute("specialty", data);
            } else if (result == "08") {
                cout << "Nhap phong ban muon tim: ";
                getline(cin, data);
                findByAttribute("department", data);
            } else if (result == "09") {
                findAllEmployees();
            } else if (result == "10") {
                findAllDoctors();
            } else if (result == "11") {
                findAllNurses();              
            } else if (result == "12") {
                findAll();
            }
        }

        void chooseDeleteData(int choice) {
            for (int i = 0; i < static_cast<int>(employees.size()); i++) {
                if (employees[i]->getId() == foundResults[choice - 1]->getId()) {
                    employees.erase(employees.begin() + i);
                    foundResults.erase(foundResults.begin() + (choice - 1));
                    break;
                }
            }
        }

        Employee* chooseModifyData(int choice) {
            for (int i = 0; i < static_cast<int>(employees.size()); i++) {
                if (employees[i]->getId() == foundResults[choice - 1]->getId()) {
                    return employees[i];
                }
            }
        }

        void sortById() {
            sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
                return a->getId().substr(1) < b->getId().substr(1);
            });
        }

        void sortByName() {
            sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
                return a->getName() < b->getName();
            });
        }

        void sortByIdDes() {
            sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
                return a->getId().substr(1) > b->getId().substr(1);
            });
        }

        void sortByNameDes() {
            sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
                return a->getName() > b->getName();
            });
        }

        void sortByDot() {
            sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
                return a < b;
            });
        }

        void sortByDotDes() {
            sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
                return a > b;
            });
        }

        void saveDataToFile() {
            string fileName;
            cout << "Nhap ten file: ";
            cin >> fileName;

            ofstream file(fileName);
            if (!file) {
                cout << "|                      Khong the mo tep                      |" << endl;
                cout << "--------------------------------------------------------------" << endl;
                return;
            }

            for (auto& emp: employees) {
                file << emp->getId() << ',' << emp->getName() << ',' << emp->getDateOfBirth() << ',' << emp->getAddress() << ',' << emp->getPhoneNumber() << ',' << emp->getEmail();
                if (emp->getId()[0] == 'E') {
                    file << endl;
                } else if (emp->getId()[0] == 'D') { 
                    Doctor* doctor = dynamic_cast<Doctor*>(emp);
                    if (doctor) {
                        file << ',' << doctor->getSpecialty();
                    }
                } else if (emp->getId()[0] == 'N') {
                    Nurse* nurse = dynamic_cast<Nurse*>(emp);
                    if (nurse) {
                        file << ',' << nurse->getDepartment();
                    }
                }
            }

            file.close();
            cout << "|                       Xuat thanh cong                      |" << endl;
            cout << "--------------------------------------------------------------" << endl;
        }

        int numberOfFoundResults() {
            return foundResults.size();
        }

        int numberOfEmployees() {
            return employees.size();
        }
};
#endif