#include "Function.h"

bool isPrime(int n) {
    for (int i = 2;i * i <= n;i++) {
        if (n % i == 0) return true;
    }
    return n <= 1;
}

void Solve(const std::string& InputFile, const std::string& OutputFile) {
    // Mo file + nhap du lieu
    std::ifstream f(InputFile);
    auto f_begin = std::istream_iterator<int>(f);
    auto f_end = std::istream_iterator<int>();
    std::vector<int> v;
    auto o = std::back_inserter(v);
    for (auto it = f_begin;it != f_end;it++) {
        *o = *it;
    } 
    f.close();

    // Xu ly

    std::ofstream fout(OutputFile);

    std::ostream_iterator<int> it_fout(fout, "\n");

    std::copy_if(v.begin(), v.end(), it_fout, isPrime);

    fout.close();

    f.close();
}