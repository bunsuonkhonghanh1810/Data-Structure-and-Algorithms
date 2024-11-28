#ifndef __good__h__
#define __good__h__

#include <bits/stdc++.h>
using namespace std;

class good {
    private:
        string goodName;
        int goodQuantity;
        double goodPrice;

    public:
        good() {}

        good(string a, int b, double c): goodName(a), goodQuantity(b), goodPrice(c) {}

        ~good() {}

        void issue(int n) {
            goodQuantity -= n;
        }

        void receipt(int n) {
            goodQuantity += n;
        }

        friend ostream& operator<<(ostream& os, good& g) {
            os << "Ten hang: " << g.goodName 
               << ", So luong: " << g.goodQuantity 
               << ", Gia: " << g.goodPrice;

            return os;
        }

        friend istream& operator>>(istream& is, good& g) {
            cout << "Nhap so luong: ";
            is >> g.goodQuantity;
            cin.ignore();

            cout << "Nhap gia: ";
            is >> g.goodPrice;
            cin.ignore();

            return is;
        }

        string getGoodName() {return goodName;}
        void setGoodName(string& name) {goodName = name;}

        int getGoodQuantity() {return goodQuantity;}
        void setGoodQuantity(int quantity) {goodQuantity = quantity;}

        double getGoodPrice() const {return goodPrice;}
        void setGoodPrice(double price) {goodPrice = price;}
};
#endif