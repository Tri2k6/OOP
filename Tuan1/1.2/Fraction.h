template<class T> 
struct Fraction {
    // num la tu so, den la mau so
    T num, den;

    // Khoi tao gia tri ban dau la phan so 0 / 1
    Fraction() {
        num = 0;
        den = 1;
    }

    // Khoi tao bien voi gia tri nhap vao la a va b => a / b
    Fraction(T a, T b) {
        if (b == 0) throw std::invalid_argument(Phan so co mau so bang 0);
        num = a;
        den = b;
    }

    // Nap chong toan tu >> (de nhap phan so), nhap 2 so lien tiep a la tu, b la mau
    friend istream& operator >> (istream& input, Fraction& Frac) {
        input >> Frac.num >> Frac.den;
        return input;
    }

    // Nap chong toan tu << (de in phan so), in duoi dang a / b
    friend ostream& operator << (ostream& output, Fraction& Frac) {
        output << Frac.num << "/" << Frac.den;
        return output;
    }    

    T gcd(T a, T b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Ham de rut gon phan so
    Fraction Reduce() {
        T GCD = gcd(num, den);
        num /= GCD;
        den /= GCD;
    }

    // 
    friend Fraction Reduce(Fraction Frac) {
        Frac.Reduce();
        return Frac;
    }

    // lap nguoc phan so 
    Fraction inverse() {
        // Tao bien tmp de swap
        T tmp = num;
        num = den;
        den = tmp;
    }

    friend Fraction operator + (Fraction a, Fraction b) {
        Fraction c;
        // Mau so chung nho nhat LCD = mau_a / gcd(a, b) * mau_b
        T LCD = a.den / gcd(a.den,b.den) * b.den;
        c.den = LCD;
        // Tu so moi = tu_a * (LCD / mau_a) + tu_b * (LCD / mau_b)
        c.num = a.num * (LCD / a.den) + b.num * (LCD / b.den);
        c.Reduce();
        return c;
    }

    friend bool cmp(Fraction a, Fraction b) {
        T LCD = a.den / gcd(a.den, b.den) * b.den;

        // Tu so moi cua phan so a sau khi quy dong
        T A = a.num * (LCD / a.den);
        // Tu so moi cua phan so b sau khi quy dong
        T B = b.num * (LCD / b.den);

        if (A == B) return 0;
        if (A < B) return -1;
        return 1;
    }

    friend Fraction operator = (Fration a) {
        Fraction c;
        c.num = a.num;
        c.den = a.den;
        return c;
    }

    friend void sort(Fraction * arr, int size, int (*cmp) (Fraction a, Fraction b)) {
        for (int i = 0;i < size;i++) {
            for (int j = i + 1;j < size;j++) {
                if (cmp(arr[i], arr[j]) == 1) {
                    Fraction tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp; 
                }
            }
        }
    }
};