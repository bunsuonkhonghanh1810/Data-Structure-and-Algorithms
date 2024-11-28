#ifndef __app__h__
#define __app__h__

#include <conio.h>
#include "employeeList.h"

class App {
    private:
        VectorEmployee vectorEmployee;
    public:
        void appStart() {
            cout << "<----------UNG DUNG QUAN LY NHAN SU TRONG BENH VIEN---------->" << endl; //62
            menu();
        }

        void menu() {
            cout << "----------------------LUA CHON THAO TAC-----------------------" << endl;
            cout << "|                 1. Them nhan su                            |" << endl;
            cout << "|                 2. Xoa nhan su                             |" << endl;
            cout << "|                 3. Tim kiem nhan su                        |" << endl;
            cout << "|                 4. Sap xep danh sach                       |" << endl;
            cout << "|                 5. Thay doi thong tin                      |" << endl;
            cout << "|                 6. Xuat danh sach vao file                 |" << endl;
            cout << "|                 7. Thoat                                   |" << endl;
            cout << "--------------------------------------------------------------" << endl;

            char choice;

            do {
                choice = _getch();
            }while (choice < '1' || choice > '7');

            switch(choice) {
                case '1':
                    addData();
                    break;
                case '2':
                    deleteData();
                    break;
                case '3':
                    findData();
                    break;
                case '4':
                    arrangeData();
                    break;
                case '5':
                    modifyData();
                    break;
                case '6':
                    exportData();
                    break;
                case '7':
                    cout << "------------------CAM ON DA SU DUNG UNG DUNG------------------";
                    return;
            }
        }

        void addData() {
            cout << "-------------------------THEM NHAN SU-------------------------" << endl;
            cout << "|               1. Nhap thong tin tu ban phim                |" << endl;
            cout << "|               2. Nhap thong tin tu file                    |" << endl;
            cout << "|               3. Quay lai                                  |" << endl;
            cout << "--------------------------------------------------------------" << endl;

            char choice;

            do {
                choice = _getch();
            }while (choice < '1' || choice > '3');

            switch(choice) {
                case '1':
                    vectorEmployee.manualEntry();
                    addData();
                    break;
                case '2':
                    vectorEmployee.fileEntry();
                    addData();
                    break;
                case '3':
                    menu();
                    break;
            }
        }

        void deleteData() {
            cout << "-------------------------XOA NHAN SU--------------------------" << endl;
            if (vectorEmployee.numberOfEmployees() == 0) {
                cout << "|                  Danh sach nhan su trong                   |" << endl;
                cout << "--------------------------------------------------------------" << endl;
                menu();
            } else {
                cout << "|              01. Tim kiem theo CCCD                        |" << endl;
                cout << "|              02. Tim kiem theo ten                         |" << endl;
                cout << "|              03. Tim kiem theo ngay sinh                   |" << endl;
                cout << "|              04. Tim kiem theo dia chi                     |" << endl;
                cout << "|              05. Tim kiem theo so dien thoai               |" << endl;
                cout << "|              06. Tim kiem theo email                       |" << endl;
                cout << "|              07. Tim kiem theo chuyen mon                  |" << endl;
                cout << "|              08. Tim kiem theo phong ban                   |" << endl;
                cout << "|              09. Toan bo can bo                            |" << endl;
                cout << "|              10. Toan bo bac si                            |" << endl;
                cout << "|              11. Toan bo y ta                              |" << endl;
                cout << "|              12. Toan bo danh sach                         |" << endl;
                cout << "|              13. Quay lai                                  |" << endl;
                cout << "--------------------------------------------------------------" << endl;

                string result = vectorEmployee.getChoice();
                
                if (result == "13") {
                    menu();
                } else {
                    vectorEmployee.handleChoice(result);
                    vectorEmployee.displayFoundResults();
                }
                
                if (vectorEmployee.numberOfFoundResults() == 0) {
                    deleteData();
                } else {
                    cout << vectorEmployee.numberOfFoundResults() + 1 << ". " << "Quay lai" << endl;
                    cout << "--------------------------------------------------------------" << endl;
                    int choice;
                    cout << "Chon thu tu muon xoa: ";
                    cin >> choice;
                    cout << "--------------------------------------------------------------" << endl;

                    while (choice < 1 || choice > vectorEmployee.numberOfFoundResults() + 1) {
                        cout << "|              Khong tim thay doi tuong can tim              |" << endl;
                        cout << "--------------------------------------------------------------" << endl;
                        cout << "Vui long nhap lai: ";
                        cin >> choice;
                        cout << "--------------------------------------------------------------" << endl;
                    }

                    if (choice == vectorEmployee.numberOfFoundResults() + 1) {
                        deleteData();
                    } else {
                        vectorEmployee.chooseDeleteData(choice);
                        if (vectorEmployee.numberOfFoundResults() == 0) {
                            vectorEmployee.displayFoundResults();
                            deleteData();
                        } else vectorEmployee.displayFoundResults();
                    }
                }
            }
        }

        void findData() {
            cout << "-------------------------TIM NHAN SU--------------------------" << endl;
            if (vectorEmployee.numberOfEmployees() == 0) {
                cout << "|                  Danh sach nhan su trong                   |" << endl;
                cout << "--------------------------------------------------------------" << endl;
                menu();
            } else {
                cout << "|              01. Tim kiem theo CCCD                        |" << endl;
                cout << "|              02. Tim kiem theo ten                         |" << endl;
                cout << "|              03. Tim kiem theo ngay sinh                   |" << endl;
                cout << "|              04. Tim kiem theo dia chi                     |" << endl;
                cout << "|              05. Tim kiem theo so dien thoai               |" << endl;
                cout << "|              06. Tim kiem theo email                       |" << endl;
                cout << "|              07. Tim kiem theo chuyen mon                  |" << endl;
                cout << "|              08. Tim kiem theo phong ban                   |" << endl;
                cout << "|              09. Toan bo can bo                            |" << endl;
                cout << "|              10. Toan bo bac si                            |" << endl;
                cout << "|              11. Toan bo y ta                              |" << endl;
                cout << "|              12. Toan bo danh sach                         |" << endl;
                cout << "|              13. Quay lai                                  |" << endl;
                cout << "--------------------------------------------------------------" << endl;

                string result = vectorEmployee.getChoice();
                
                if (result == "13") {
                    menu();
                } else {
                    vectorEmployee.handleChoice(result);
                    vectorEmployee.displayFoundResults();
                    findData();
                }
            }
        }

        void arrangeData() {
            cout << "----------------------SAP XEP DANH SACH----------------------" << endl;
            if (vectorEmployee.numberOfEmployees() == 0) {
                cout << "|                  Danh sach nhan su trong                   |" << endl;
                cout << "--------------------------------------------------------------" << endl;
                menu();
            } else {
                cout << "|            1. Sap xep theo so CCCD                         |" << endl;
                cout << "|            2. Sap xep theo ten                             |" << endl;
                cout << "|            3. Sap xep theo ngay thang nam sinh             |" << endl;
                cout << "|            4. Quay lai                                     |" << endl;
                cout << "--------------------------------------------------------------" << endl;

                char choice;
                do {
                    choice = _getch();
                } while (choice < '1' || choice > '4');

                if (choice == '4') {
                    menu();
                } else {
                    cout << "|                    1. Sap xep tang dan                     |" << endl;
                    cout << "|                    2. Sap xep giam dan                     |"<< endl;
                    cout << "--------------------------------------------------------------" << endl;

                    char subChoice;
                    do {
                        subChoice = _getch();
                    } while (subChoice < '1' || subChoice > '2');

                    string result;
                    result.push_back(choice);
                    result.push_back(subChoice);

                    if (result == "11") {
                        vectorEmployee.sortById();
                    } else if (result == "12") {
                        vectorEmployee.sortByIdDes();
                    } else if (result == "21") {
                        vectorEmployee.sortByName();
                    } else if (result == "22") {
                        vectorEmployee.sortByNameDes();
                    } else if (result == "31") {
                        vectorEmployee.sortByDot();
                    } else {
                        vectorEmployee.sortByDotDes();
                    }

                    cout << "|--------------------Danh sach da sap xep--------------------|" << endl;
                    cout << "--------------------------------------------------------------" << endl;
                    vectorEmployee.displayEmployees();
                    arrangeData();
                }   
            }
        }

        void modifyData() {
            cout << "----------------------THAY DOI THONG TIN----------------------" << endl;
            if (vectorEmployee.numberOfEmployees() == 0) {
                cout << "|                  Danh sach nhan su trong                   |" << endl;
                cout << "--------------------------------------------------------------" << endl;
                menu();
            } else {
                cout << "|              01. Tim kiem theo CCCD                        |" << endl;
                cout << "|              02. Tim kiem theo ten                         |" << endl;
                cout << "|              03. Tim kiem theo ngay sinh                   |" << endl;
                cout << "|              04. Tim kiem theo dia chi                     |" << endl;
                cout << "|              05. Tim kiem theo so dien thoai               |" << endl;
                cout << "|              06. Tim kiem theo email                       |" << endl;
                cout << "|              07. Tim kiem theo chuyen mon                  |" << endl;
                cout << "|              08. Tim kiem theo phong ban                   |" << endl;
                cout << "|              09. Toan bo can bo                            |" << endl;
                cout << "|              10. Toan bo bac si                            |" << endl;
                cout << "|              11. Toan bo y ta                              |" << endl;
                cout << "|              12. Toan bo danh sach                         |" << endl;
                cout << "|              13. Quay lai                                  |" << endl;
                cout << "--------------------------------------------------------------" << endl;

                string result = vectorEmployee.getChoice();
                
                if (result == "13") {
                    menu();
                } else {
                    vectorEmployee.handleChoice(result);
                    vectorEmployee.displayFoundResults();
                }
                
                if (vectorEmployee.numberOfFoundResults() == 0) {
                    modifyData();
                } else {
                    cout << vectorEmployee.numberOfFoundResults() + 1 << ". " << "Quay lai" << endl;
                    int choice;
                    cout << "Chon thu tu muon thay doi: ";
                    cin >> choice;

                    while (choice < 1 || choice > vectorEmployee.numberOfFoundResults() + 1) {
                        cout << "|              Khong tim thay doi tuong can tim              |" << endl;
                        cout << "--------------------------------------------------------------" << endl;
                        cout << "Vui long nhap lai: ";
                        cin >> choice;
                        cout << "--------------------------------------------------------------" << endl;
                    }

                    if (choice == vectorEmployee.numberOfFoundResults() + 1) {
                        modifyData();
                    } else {
                        Employee* emp = vectorEmployee.chooseModifyData(choice);

                        cout << "----------------------LUA CHON THAO TAC-----------------------" << endl;
                        cout << "|                 1. Thay doi ID                             |" << endl;
                        cout << "|                 2. Thay doi ten                            |" << endl;
                        cout << "|                 3. Thay doi ngay sinh                      |" << endl;
                        cout << "|                 4. Thay doi dia chi                        |" << endl;
                        cout << "|                 5. Thay doi so dien thoai                  |" << endl;
                        cout << "|                 6. Thay doi email                          |" << endl;

                        if (emp->getId()[0] == 'E') {
                            cout << "|                 7. Thang chuc                              |" << endl;
                            cout << "|                 8. Quay lai                                |" << endl;
                        } else if (emp->getId()[0] == 'D') {
                            cout << "|                 7. Thay doi chuyen mon                     |" << endl;
                            cout << "|                 8. Quay lai                                |" << endl;
                        } else if (emp->getId()[0] == 'N') {
                            cout << "|                 7. Thay doi phong ban                      |" << endl;
                            cout << "|                 8. Quay lai                                |" << endl;
                        }
                            cout << "--------------------------------------------------------------" << endl;

                        char choice;

                        do {
                            choice = _getch();
                        } while (choice < '1' || choice > '8');
                        
                        if (choice == '8') {
                            modifyData();
                        } else {
                            string newValue;
                            switch (choice) {
                                case '1':
                                    cout << "Nhap so CCCD moi: ";
                                    getline(cin, newValue);
                                    emp->setId(newValue);
                                    break;
                                case '2':
                                    cout << "Nhap ten moi: ";
                                    getline(cin, newValue);
                                    emp->setName(newValue);
                                    break;
                                case '3':
                                    cout << "Nhap ngay sinh moi (dd/mm/yyyy): ";
                                    getline(cin, newValue);
                                    emp->setDateOfBirth(newValue);
                                    break;
                                case '4':
                                    cout << "Nhap dia chi moi: ";
                                    getline(cin, newValue);
                                    emp->setAddress(newValue);
                                    break;
                                case '5':
                                    cout << "Nhap so dien thoai moi: ";
                                    getline(cin, newValue);
                                    emp->setPhoneNumber(newValue);
                                    break;
                                case '6':
                                    cout << "Nhap email moi: ";
                                    getline(cin, newValue);
                                    emp->setEmail(newValue);
                                    break;
                                case '7':
                                    if (emp->getId()[0] == 'E') {
                                        cout << "-----------------------Thang chuc thanh-----------------------" << endl;
                                        cout << "|                         1. Bac si                          |" << endl;
                                        cout << "|                         2. Y ta                            |" << endl;
                                        cout << "--------------------------------------------------------------" << endl;
                                        
                                        char subChoice;
                                        do {
                                            subChoice = _getch(); 
                                        } while (subChoice != '1' || subChoice != '2');
                                        
                                        if (subChoice == '1') {
                                            cout << "Nhap chuyen mon: ";
                                            getline(cin, newValue);
                                            emp = new Doctor(emp->getId(), emp->getName(), emp->getDateOfBirth(), emp->getAddress(), emp->getPhoneNumber(), emp->getEmail(), newValue);
                                            cout << "|-------------------Da chuyen thanh bac si-------------------|" << endl;
                                            cout << "--------------------------------------------------------------" << endl;
                                            modifyData();
                                        } else if (subChoice == '2') {
                                            cout << "Nhap phong ban: ";
                                            getline(cin, newValue);
                                            emp = new Nurse(emp->getId(), emp->getName(), emp->getDateOfBirth(), emp->getAddress(), emp->getPhoneNumber(), emp->getEmail(), newValue);
                                            cout << "|--------------------Da chuyen thanh y ta--------------------|" << endl;
                                            cout << "--------------------------------------------------------------" << endl;
                                            modifyData();
                                        }
                                    } else if (emp->getId()[0] == 'D') {
                                        cout << "Nhap chuyen mon moi: ";
                                        getline(cin, newValue);
                                        ((Doctor*)emp)->setSpecialty(newValue);
                                        modifyData();
                                    } else if (emp->getId()[0] == 'N') {
                                        cout << "Nhap phong ban moi : ";
                                        getline(cin, newValue);
                                        ((Nurse*)emp)->setDepartment(newValue);
                                        modifyData();
                                    }
                            }
                        }
                    }
                }
            }      
        }

        void exportData() {
            cout << "|------------------Xuat danh sach vao file-------------------|" << endl;
            cout << "--------------------------------------------------------------" << endl;
            vectorEmployee.saveDataToFile();
            menu();
        }
};
#endif