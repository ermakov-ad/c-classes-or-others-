#include <iostream>
#include <vector>
#include <cmath>

class Extension{
public:
  static bool vector_check(std::vector<double> const &lhs, std::vector<double> const &rhs){
    if (lhs.size() != rhs.size())
      return print_state(lhs, rhs, false);

    for (auto i = 0u; i < lhs.size(); ++i)
      if (std::abs(lhs[i] - rhs[i]) > eps())
        return print_state(lhs, rhs, false);;
    return print_state(lhs, rhs, true);;
  }

private:
  static bool print_state(std::vector<double> const &lhs, std::vector<double> const &rhs, bool state){
    if (lhs.size() != rhs.size()) {
      std::cout << "Vector size not equal " << lhs.size() << " != " << rhs.size() << std::endl;
      return false;
    }

    print_vector(lhs);
    if (state) {
      std::cout << "== ";
    } else {
      std::cout << "!= ";
    }
    print_vector(rhs);
    std::cout << ((state) ? "All Ok!" : "Fail!") << std::endl;

    return state;
  }
  static void print_vector(std::vector<double> const &v) {
    std::cout << "{" << v[0];
    for (auto i = 1u; i < v.size(); ++i)
      std::cout << ", " << v[i];
    std::cout << "} ";
  }

  static constexpr double eps() { return 1e-6; }
};

class i_transformation {

public:
  virtual void transform(std::vector<double>* data) = 0;

  virtual ~i_transformation() = default;
};

class multiply: public i_transformation{
public:
    multiply(double x);
    void transform(std::vector<double>* data);
private:
    double mult;
};

class slice: public i_transformation{
public:
    slice(size_t begin, size_t end);
    void transform(std::vector<double>* data);
private:
    size_t begin_, end_;
};

class filter_less: public i_transformation{
public:
    filter_less(double a);
    void transform(std::vector<double>* data);
private:
    double max_;
};

class filter_set: public i_transformation{
public:
    filter_set();
    void transform(std::vector<double>* data);
    void add_filter_value(double value);
private:
    std::vector<double> numbers;
};

class reduce: public i_transformation{
public:
    reduce();
    void transform(std::vector<double>* data);
};

multiply::multiply(double x){
    this -> mult = x;
}

void multiply::transform(std::vector<double>* data){
    for (unsigned long i=0; i < (*data).size(); ++i){
        (*data)[i] = (*data)[i]*(this->mult);
    }
}

slice::slice(size_t begin, size_t end){
    this->begin_ = begin;
    this->end_ = end;
}

void slice::transform(std::vector<double>* data){
    std::vector<double> n_vec;
    for (size_t i=0; i<((this->end_) - (this->begin_)); ++i){
        n_vec.vector::push_back((*data)[this->begin_ + i]);
    }
    for (size_t i=(*data).size(); i > n_vec.size(); --i){
        (*data).vector::pop_back();
    }
    for (size_t i=0; i < n_vec.size(); ++i){
        (*data)[i] = n_vec[i];
    }
}

filter_less::filter_less(double a): max_{a}{}

void filter_less::transform(std::vector<double>* data){
    std::vector<double> n_vec;
    for (size_t i=0; i < (*data).size(); ++i){
        if ((*data)[i] < (this->max_)){
            n_vec.vector::push_back((*data)[i]);
        }
    }
    for (size_t i=(*data).size(); i > n_vec.size(); --i){
        (*data).vector::pop_back();
    }
    for (size_t i=0; i < n_vec.size(); ++i){
        (*data)[i] = n_vec[i];
    }
}

filter_set::filter_set(){}

void filter_set::add_filter_value(double value){
    numbers.vector::push_back(value);
}

void filter_set::transform(std::vector<double>* data){
    std::vector<double> n_vec;
    for (size_t i = 0; i < (*data).size(); ++i){
        for (size_t j = 0; j < (this->numbers).size(); ++j){
            if ((*data)[i] == (this->numbers)[j]){
                n_vec.vector::push_back((*data)[i]);
                j = (this->numbers).size();
            }
        }
    }
    for (size_t i=(*data).size(); i > n_vec.size(); --i){
        (*data).vector::pop_back();
    }
    for (size_t i=0; i < n_vec.size(); ++i){
        (*data)[i] = n_vec[i];
    }
}

reduce::reduce(){}

void reduce::transform(std::vector<double>* data){
    for (size_t i =(*data).size()-1; i > 0; --i){
        (*data)[0]+=(*data)[i];
        (*data).vector::pop_back();
    }
}

int main(){
    //some testing code
    right_triangle tr(1, 2);
    std::cout << tr.get_square() << std::endl;
    std::cout << std::boolalpha << tr.contain_point(point2d(0.5, -0.1)) << std::endl;
    std::cout << std::boolalpha << tr.contain_point(point2d(0.25, 0.25)) << std::endl;
    tr.rotate(45);
    std::cout << tr.get_square() << std::endl;
    std::cout << std::boolalpha << tr.contain_point(point2d(0.5, -0.1)) << std::endl;
    return 0;
}
