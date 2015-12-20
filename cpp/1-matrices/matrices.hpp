#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <string>

class Matrix
{
private:
    using matrix_t = double *;

    matrix_t matrix_;
    size_t rows_;
    size_t cols_;

public:
    Matrix();

    Matrix(Matrix const& rhs);

    Matrix(Matrix&& rhs) = delete;

    ~Matrix();

    size_t get_rows() const noexcept;
    size_t get_cols() const noexcept;

    Matrix& operator= (Matrix const& rhs);
    Matrix& operator= (Matrix     && rhs) = delete;
    Matrix& operator+=(Matrix const& rhs);
    Matrix& operator*=(Matrix const& rhs);

    double operator()(size_t row, size_t col) const;

    void read_from_file(std::string const& filename);
    friend std::ostream& operator<<(std::ostream& out, Matrix const& rhs);
};
