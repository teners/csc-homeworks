#include "matrices.hpp"

using matrix_t = double *;

Matrix::Matrix()
{
    matrix_ = nullptr;
}

Matrix::Matrix(Matrix const& rhs)
{
    matrix_ = rhs.matrix_;
    rows_   = rhs.get_rows();
    cols_   = rhs.get_cols();
}

Matrix::~Matrix()
{
    if (matrix_ != nullptr)
    {
        delete [] matrix_;
        matrix_ = nullptr;
    }
}

Matrix& Matrix::operator=(Matrix const& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    rows_ = rhs.get_rows();
    cols_ = rhs.get_cols();

    delete [] matrix_;
    matrix_ = new double[rows_ * cols_];

    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            matrix_[(i * cols_) + j] = rhs(i, j);
        }
    }

    return *this;
}

Matrix& Matrix::operator+=(Matrix const& rhs)
{
    if (get_cols() != rhs.get_cols() || get_rows() != rhs.get_rows())
    {
        throw std::runtime_error("inappropriate sizes for addition operation");
    }

    matrix_t result = new double[rows_ * cols_];

    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            result[(i * cols_) + j] = matrix_[(i * cols_) + j] + rhs(i, j);
        }
    }

    delete [] matrix_;
    matrix_ = result;

    return *this;
}

Matrix& Matrix::operator*=(Matrix const& rhs)
{
    if (get_cols() != rhs.get_rows())
    {
        throw std::runtime_error("inappropriate sizes for multiplication operation");
    }

    size_t cols = rhs.get_cols();
    size_t size = rows_ * cols;
    matrix_t result = new double[size];

    for (size_t i = 0; i < size; ++i)
    {
        result[i] = 0.0;
    }

    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            for (size_t k = 0; k < cols_; ++k)
            {
                result[(i * cols) + j] += matrix_[(i * cols_) + k] * rhs(k, j);
            }
        }
    }

    delete [] matrix_;
    matrix_ = result;
    cols_ = cols;

    return *this;
}

double Matrix::operator()(size_t row, size_t col) const
{
    return matrix_[(row * cols_) + col];
}

size_t Matrix::get_rows() const noexcept
{
    return rows_;
}

size_t Matrix::get_cols() const noexcept
{
    return cols_;
}

std::ostream& operator<<(std::ostream& out, Matrix const& rhs)
{
    size_t rows = rhs.get_rows();
    size_t cols = rhs.get_cols();

    out << rows << " " << cols << "\n";
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            out << rhs(i, j) << " ";
        }
        out << "\n";
    }

    return out;
}

void Matrix::read_from_file(std::string const& filename)
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(filename);

    file >> rows_ >> cols_;
    matrix_ = new double[rows_ * cols_];

    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            file >> matrix_[(i * cols_) + j];
        }
    }
}
