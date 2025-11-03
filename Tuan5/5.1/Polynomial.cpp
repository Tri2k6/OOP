#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial() {
    _degree = 0;
    Coef_arr = new double[1];
    Coef_arr[0] = 0.0;
}

Polynomial::Polynomial(size_t degree, double* C_arr) {
    _degree = degree;
    Coef_arr = new double[_degree + 1];
    for (int i = 0;i <= _degree;i++) {
        Coef_arr[i] = C_arr[i];
    }
}

Polynomial::Polynomial(const Polynomial& other) {
    _degree = other._degree;
    Coef_arr = new double[_degree + 1];
    for (int i = 0;i <= _degree;i++) {
        Coef_arr[i] = other.Coef_arr[i];
    }
}

Polynomial::~Polynomial() {
    delete[] Coef_arr;
    Coef_arr = nullptr;
}

int Polynomial::getDegree() {
    return _degree;
}

double Polynomial::getCoeff(size_t idx) {
    if (idx > _degree + 1) throw std::invalid_argument("Loi so mu khong nam trong da thuc");
    return Coef_arr[idx];
}

void Polynomial::setDegree(size_t D) {
    double* Tmp_arr = new double[D + 1];
    for (int i = 0;i <= D;i++) {
        if (i <= _degree) Tmp_arr[i] = Coef_arr[i];
        else Tmp_arr[i] = 0.0;
    }
    std::swap(Tmp_arr, Coef_arr);
    delete[] Tmp_arr;
    _degree = D;
}

void Polynomial::setCoeff(size_t idx, double val) {
    if (idx > _degree) throw std::invalid_argument("Loi so mu khong nam trong da thuc");
    Coef_arr[idx] = val;
}

Polynomial Polynomial::operator +(const Polynomial& other) {
    Polynomial res;
    res._degree = std::max(_degree, other._degree);
    res.Coef_arr = new double[res._degree + 1];
    for (int i = 0;i <= res._degree;i++) {
        double Coef_A = (i < _degree + 1) ? Coef_arr[i] : 0;
        double Coef_B = (i < other._degree + 1) ? other.Coef_arr[i] : 0;
        res.Coef_arr[i] = Coef_A + Coef_B;
    }
    return res;
}

Polynomial Polynomial::operator - (const Polynomial& other) {
    Polynomial res;
    res._degree = std::max(_degree, other._degree);
    res.Coef_arr = new double[res._degree + 1];
    for (int i = 0;i <= res._degree;i++) {
        double Coef_A = (i < _degree + 1) ? Coef_arr[i] : 0;
        double Coef_B = (i < other._degree + 1) ? other.Coef_arr[i] : 0;
        res.Coef_arr[i] = Coef_A - Coef_B;
    }
    return res;
}

Polynomial Polynomial::operator * (const Polynomial& other) {
    Polynomial res;
    res._degree = _degree + other._degree;
    res.Coef_arr = new double[res._degree + 1] ();

    for (int i = 0;i <= _degree;i++) {
        for (int j = 0;j <= other._degree;j++) {
            res.Coef_arr[i + j] += Coef_arr[i] * other.Coef_arr[j];
        }
    }
    return res;
}

Polynomial& Polynomial::operator = (const Polynomial& other) {
    _degree = other._degree;
    double * Tmp_arr = new double[_degree + 1];
    for (int i = 0;i <= _degree;i++) {
        Tmp_arr[i] = other.Coef_arr[i];
    }
    std::swap(Tmp_arr, Coef_arr);
    delete[] Tmp_arr;
    return *this;
}

bool Polynomial::operator > (const Polynomial& other) {
    if (_degree != other._degree) return _degree > other._degree;
    for (int i = _degree;~i;i--) {
        if (Coef_arr[i] != other.Coef_arr[i]) return Coef_arr[i] > other.Coef_arr[i];
    }
    return false;
}

bool Polynomial::operator < (const Polynomial& other) {
    if (_degree != other._degree) return _degree < other._degree;
    for (int i = _degree;~i;i--) {
        if (Coef_arr[i] != other.Coef_arr[i]) return Coef_arr[i] < other.Coef_arr[i];
    }
    return false;    
}

bool Polynomial::operator == (const Polynomial& other) {
    if (_degree != other._degree) return false;
    for (int i = _degree;~i;i--) {
        if (Coef_arr[i] != other.Coef_arr[i]) return false;
    }
    return true;    
}

bool Polynomial::operator >= (const Polynomial& other) {
    if (_degree != other._degree) return _degree > other._degree;
    for (int i = _degree;~i;i--) {
        if (Coef_arr[i] != other.Coef_arr[i]) return Coef_arr[i] >= other.Coef_arr[i];
    }
    return true;
}

bool Polynomial::operator <= (const Polynomial& other) {
    if (_degree != other._degree) return _degree <= other._degree;
    for (int i = _degree;~i;i--) {
        if (Coef_arr[i] != other.Coef_arr[i]) return Coef_arr[i] <= other.Coef_arr[i];
    }
    return true;
}

bool Polynomial::operator != (const Polynomial& other) {
    if (_degree != other._degree) return true;
    for (int i = _degree;~i;i--) {
        if (Coef_arr[i] != other.Coef_arr[i]) return true;
    }
    return false;    
}

Polynomial& Polynomial::operator !() {
    if (_degree == 0) {
        Coef_arr[0] = 0.0;
        return *this;
    }
    double* arr = new double[_degree];
    for (int i = _degree - 1;i >= 0;i--) {
        arr[i] = Coef_arr[i + 1] * (i + 1); 
    }
    std::swap(Coef_arr, arr);
    delete[] arr;
    _degree--;
    return *this;
}

Polynomial& Polynomial::operator ~() {
    double* arr = new double[_degree + 2];
    arr[0] = 0.0;
    for (int i = _degree + 1;i >= 1;i--) {
        arr[i] = Coef_arr[i - 1] / i;
    }
    std::swap(Coef_arr, arr);
    delete[] arr;
    _degree++;
    return *this;
}

istream& operator >> (istream& input, Polynomial& a) {
    std::string strLine;
    std::cout << "Moi ban nhap bac cao nhat cua da thuc: ";
    getline(input, strLine);
    std::stringstream ss(strLine);
    if ((!(ss >> a._degree)) || a._degree < 0) throw std::invalid_argument("Loi khi nhap bac cua da thuc");
    ss >> std::ws;
    if (!ss.eof()) {
        throw std::invalid_argument("Loi khi nhap bac cua da thuc");
    }
    delete[] a.Coef_arr;
    a.Coef_arr = new double[a._degree + 1];
    if (!a.Coef_arr) throw std::bad_alloc();

    for (int i = a._degree;i >= 0;i--) {
        std::cout << "Moi ban nhap he so cua don thuc bac " << i << ": ";
        getline(input,strLine);
        
        ss.str(strLine);
        ss.clear();

        if (!(ss >> a.Coef_arr[i])) throw std::invalid_argument("Loi nhap he so trong da thuc");
        ss >> std::ws;
        if (!ss.eof()) throw std::invalid_argument("Loi nhap he so trong da thuc");
    }
    return input;
}

ostream& operator << (ostream& output, const Polynomial& a) {
    if (a.Coef_arr == NULL) return output;
    for (int i = a._degree;i >= 0;i--) {
        if (i != 0) output << a.Coef_arr[i] << ".x^" << i << " + ";
        else output << a.Coef_arr[i];
    }
    return output;
}
