#include <iostream>
#include <vector>

class Logger {
public:
    static void log(const std::string& message) {
        std::cout << "LOG: " << message << std::endl;
    }
};

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(const std::vector<std::vector<int>>& input) : data(input) {}

    // Toan tu cong ma tran
    Matrix operator+(const Matrix& other) const {
        Logger::log("Thuc hien phep cong ma tran");
        Matrix result(*this);
        // Thuc hien nap chong toan tu cong o day
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result.data[i][j] += other.data[i][j];
            }
        }
        return result;
    }

    // Toan tu tru ma tran
    Matrix operator-(const Matrix& other) const {
        Logger::log("Thuc hien phep tru ma tran");
        Matrix result(*this);
        // Thuc hien nap chong toan tu tru o day
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result.data[i][j] -= other.data[i][j];
            }
        }
        return result;
    }

    // Toan tu nhan ma tran
    Matrix operator*(const Matrix& other) const {
        Logger::log("Thuc hien phep nhan ma tran");
        Matrix result(data.size(), std::vector<int>(other.data[0].size(), 0));
        // Thuc hien nap chong toan tu nhan o day
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < data[0].size(); ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Toan tu chia ma tran (chi mo phong, khong xu ly cac truong hop dac biet)
    Matrix operator/(const Matrix& other) const {
        Logger::log("Thuc hien phep chia ma tran");
        Matrix result(*this);
        // Thuc hien nap chong toan tu chia o day
        return result;
    }

    // Ham utility de tao ma tran voi gia tri mac dinh
    Matrix(size_t rows, size_t cols, int defaultValue = 0)
        : data(rows, std::vector<int>(cols, defaultValue)) {}
};

int main() {
    Matrix matrix1({{1, 2}, {3, 4}});
    Matrix matrix2({{5, 6}, {7, 8}});

    Matrix resultAddition = matrix1 + matrix2;
    Matrix resultSubtraction = matrix1 - matrix2;
    Matrix resultMultiplication = matrix1 * matrix2;
    //Matrix resultDivision = matrix1 / matrix2; // Chia ma tran co the khong phai luc nao cung co giai phap

    return 0;
}

