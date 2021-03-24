#include "iostream"
#include "vector"
#include "exception"
#include "stdexcept"

using namespace std;

class  Matrix {
    private:
        int _num_rows;
        int _num_cols;
        vector<int> matrix;
    public:
    Matrix() :  _num_rows(0), _num_cols(0){};
    Matrix(int num_rows, int num_cols) { 
        if ((num_rows < 0)||(num_cols < 0))
            throw out_of_range("out of range");
        else {
            _num_rows = num_rows;
            _num_cols = num_cols;
            matrix.resize(num_rows * num_cols, 0);
        }
    };
    Matrix(int num_rows, int num_cols, vector<int> _matrix) { 
        if ((num_rows < 0)||(num_cols < 0))
            throw out_of_range("out of range");
        else {
            _num_rows = num_rows;
            _num_cols = num_cols;
            matrix.resize(num_rows * num_cols, 0);
            matrix = _matrix;
        }
    };
    ~Matrix(){};
    void Reset(int num_rows, int num_cols) {
        if ((num_rows < 0)||(num_cols < 0))
            throw out_of_range("out of range");
        else
        {   
            _num_rows=num_rows;
            _num_cols = num_cols;
            matrix.resize(0);
            matrix.resize(num_cols*num_rows, 0);
        }
    };
    int At(int num_rows, int num_cols) const {
        if ((num_rows >= 0) && (num_rows <= _num_rows-1) && (num_cols >= 0) && (num_cols <= _num_cols-1) )
            return matrix[num_rows*_num_cols + num_cols]; 
        else 
            throw out_of_range("out of range");
    };
    int& At(int num_rows, int num_cols) {
        if ((num_rows >= 0) && (num_rows <= _num_rows-1) && (num_cols >= 0) && (num_cols <= _num_cols-1) ) {
            int& p= matrix[num_rows*_num_cols + num_cols];
            return p;
        } else 
            throw out_of_range("out_of_range"); 
    };
    int GetNumRows() const {return _num_rows; };
    int GetNumColumns() const {return _num_cols; };
    friend istream& operator >> (istream&, Matrix&);
    friend ostream& operator << (ostream&,const Matrix&);
    friend bool operator == (const Matrix&, const Matrix&);
    friend Matrix operator + (const Matrix&, const Matrix&);
    friend Matrix operator+(const Matrix&);
};

    istream& operator >> (istream& in, Matrix& p)
    {
        in >> p._num_rows >> p._num_cols;
        p.matrix.resize(p._num_cols*p._num_rows);
        for (int i = 0; i < p._num_rows*p._num_cols; i++){
            in >> p.matrix[i]; }
        return in;
    };

    ostream& operator << (ostream& out, const Matrix& p)
    {
        out << p._num_rows << " " << p._num_cols << endl;
        for (int i = 0; i < p._num_rows; i++) {
            for (int j= 0; j < p._num_cols; j++)
            {
                out << p.matrix[i * p._num_cols + j] << " ";
            }
            out << endl;
        }
        return out;
    };

    bool operator == (const Matrix& r, const Matrix& l) {
        if ((r._num_cols == 0 && (l._num_cols == 0  || l._num_rows == 0))||(r._num_rows == 0 && (l._num_cols == 0  || l._num_rows == 0)))
            return true;
        if ((r._num_cols != l._num_cols)|| (r._num_rows != l._num_rows))
            return false;
        for (int i = 0; i < r._num_rows*r._num_cols; i++) {
            if (r.matrix[i] != l.matrix[i]) 
                return false;
        }
        return true;
    };

    Matrix operator + (const Matrix& r, const Matrix& l){
        if ((r._num_cols == 0 && (l._num_cols == 0  || l._num_rows == 0))||(r._num_rows == 0 && (l._num_cols == 0  || l._num_rows == 0)))
            return Matrix();
        if (r._num_cols != l._num_cols || r._num_rows != l._num_rows)
            throw invalid_argument("invalid_argument");
        else{
            vector<int> _matrix(r._num_cols*r._num_rows); 
            for (int i = 0; i < r._num_cols*r._num_rows; i++) {
                _matrix[i] = r.matrix[i] + l.matrix[i]; 
            }
        return Matrix(r._num_rows, r._num_cols, _matrix);
        }

    };

    // Matrix operator + (const Matrix& r){
    //     if (r._num_cols != this ->_num_cols || r._num_rows != this ->_num_rows)
    //         throw invalid_argument("invalid_argument");
    //     else
    //     return Matrix(r._num_rows, r._num_cols, this -> matrix + r.matrix);

    // };

// int main() {
//     Matrix a(1, 5);
//     cout << a.At(0,4);
// }

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}

// int main() {
//   Matrix one;

//   one.Reset(3, 2);
//   cout << one << endl;
//   return 0;
// }

// 3 5
// 6 4 -1 9 8
// 12 1 2 9 -5
// -4 0 12 8 6

// 3 5
// 5 1 0 -8 23
// 14 5 -6 6 9
// 8 0 5 4 1

// 3 5
// 11 5 -1 1 31
// 26 6 -4 15 4
// 4 0 17 12 7