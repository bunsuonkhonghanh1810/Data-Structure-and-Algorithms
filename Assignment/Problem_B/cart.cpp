#include <conio.h>
#include "single_list.h"
#include "good.h"
using namespace std;

class cart {
    private:
        single_list<good> goods;
    public:
        void menu() {
            cout << "1. Them mat hang" << endl;
            cout << "2. Tinh tien gio hang" << endl;
            cout << "3. Xuat du lieu gio hang" << endl;
            cout << "4. Ket thuc" << endl;

            char choice;
            do {
                choice = _getch();
            } while (choice < '1' || choice > '4');

            if (choice == '4') {
                return;
            } else if (choice == '1') {
                addGoodToCart();
            } else if (choice == '2') {
                totalPrice();
            } else if (choice == '3') {
                exportData();
            }
        }

        void addGoodToCart() {
            good newGood;

            string name;

            cout << "Nhap ten mat hang: ";
            getline(cin, name);
            for (auto i = goods.begin(); i != goods.end(); ++i) {
                if ((*i).getGoodName() == name) { 
                    cout << "Mat hang da co trong danh sach" << endl;
                    cout << (*i);

                    cout << "1. Tang so luong" << endl;
                    cout << "2. Giam so luong" << endl;
                    cout << "3. Quay lai" << endl;

                    char choice;
                    do {
                        choice = _getch();
                    } while (choice < '1' || choice > '3');

                    if (choice == '3') {
                        menu();
                    } else if (choice == '1') {
                        cout << "Nhap so luong hang muon them: ";
                        int number;
                        cin >> number;
                        cin.ignore();
                        while(number < 0) {
                            cout << "Vui long nhap lai cho dung: ";
                            cin >> number;
                            cin.ignore();
                        }
                        (*i).setGoodQuantity((*i).getGoodQuantity() + number);
                        cout << "Da cap nhat" << endl;
                        menu();
                        break;
                    } else {
                        cout << "Nhap so luong hang muon giam: ";
                        int number;
                        cin >> number;
                        cin.ignore();
                        while(number < 0 || number > (*i).getGoodQuantity()) {
                            cout << "Vui long nhap lai cho dung: ";
                            cin >> number;
                            cin.ignore();
                        }
                        (*i).setGoodQuantity((*i).getGoodQuantity() - number);
                        if ((*i).getGoodQuantity() == 0) {
                            goods.erase(i.getCurrent());
                            cout << "So luong mon hang bang 0. Tu dong xoa mon hang khoi gio hang" << endl;
                        } else {
                            cout << "Da cap nhat" << endl;
                        }
                        menu();
                        break;
                    }
                }
            }

            cin >> newGood;
            goods.push_back(newGood);
            cout << "Da them vao danh sach";
            menu();
        }

        void totalPrice() {
            long long total = 0;
            for (auto i = goods.begin(); i != goods.end(); ++i) {
                total += (*i).getGoodPrice();
            }
            cout << "Tong tien cua gio hang la: " << total << endl;
            menu();
        }

        void exportData() {
            ofstream file("F:/projects/DSA/Assignment/Problem_B/hoadon.txt");
            if (!file) {
                cout << "Khong the mo tep" << endl;
                return;
            }

            int mark = 1;

            for (auto i = goods.begin(); i != goods.end(); ++i) {
                file << mark << ". " << (*i) << endl;
            }

            file.close();
            cout << "Xuat thanh cong" << endl;
        }
};

int main() {
    cart cart;
    cart.menu();
}