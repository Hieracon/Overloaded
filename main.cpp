#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Complex {
private:
    double real, imag;
public:
    void setReal(double r){
        this->real = r;
    }

    void setImag(double i){
        this->imag = i;
    }

    double getReal(){
        return this->real;
    }

    double getImag(){
        return this->imag;
    }

    Complex(){
        this->real = 0;
        this->imag = 0;
    }

    Complex(double r){
        this->real = r;
        this->imag = 0;
    }

    Complex(double r, double i){
        this->real = r;
        this->imag = i;
    }

    Complex operator = (const Complex &obj){
         this->real = obj.real;
         this->imag = obj.imag;

         return *this;
    }

    Complex operator + (const Complex &obj){
        Complex temp(0, 0);

        temp.real = this->real + obj.real;
        temp.imag = this->imag + obj.imag;

        return temp;
    }

    Complex operator * (const Complex &obj){
        Complex temp(0, 0);

        temp.real = this->real * obj.real - this->imag * obj.imag;
        temp.imag = this->real * obj.imag + this->imag * obj.real;

        return temp;
    }

    Complex operator / (const Complex &obj){
        Complex temp(this->real, this->imag);

        temp.real = ( this->real * obj.real + this->imag * obj.imag ) / ( pow(obj.real, 2) + pow(obj.imag, 2) ) ;
        temp.imag = ( this->imag * obj.real - this->real * obj.imag ) / ( pow(obj.real, 2) + pow(obj.imag, 2) );

        return temp;
    }

    double operator ~ (){
        return sqrt(pow(this->real, 2) + pow(this->imag, 2));
    }

    Complex operator ^ (int power){
        Complex result(this->real, this->imag);
        Complex base(this->real, this->imag);

        for(int it = 1; it < power; ++it){
            result = result * base;
        }

        return result;
    }

    void print(){
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    vector <Complex> z;

    int verify;

    do{
        cout << "Press 1 to add a complex number press 1." << endl;
        cout << "Press 2 to stop." << endl;
        cin >> verify;

        if(verify == 1){
            double temp_1, temp_2;
            cout << "Real = ";
            cin>>temp_1;
            cout << "Imag = ";
            cin>>temp_2;
            z.push_back(Complex(temp_1, temp_2));
        }
    }while(verify == 1);

    Complex sum_odd(0, 0);
    Complex sum_even(0, 0);

    for(unsigned int it = 0; it != z.size(); ++it){
        if(it % 2 == 0){
            sum_even = sum_even + (z.at(it) ^ 4);
        }
        else{
            sum_odd = sum_odd + (z.at(it) ^ 3);
        }
    }

    Complex z_result = sum_odd / sum_even;

    cout << "Result is:"<<endl;
    cout << "Real: " << z_result.getReal() << endl;
    cout << "Imag: " << z_result.getImag() << endl;

    return 0;
}
