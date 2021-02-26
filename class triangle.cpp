#include <iostream>
#include <cmath>

class point2d{
public:
  point2d(double x, double y): x_{x}, y_{y} {
  }

  double get_x() const { return x_; }
  double get_y() const { return y_; }
  void set_x(double x) { x_ = x; }
  void set_y(double y) { y_ = y; }
private:
  double x_, y_;
};

class triangle{
public:
  //Конструктор класса принимающий координаты вершин треугольника, заданные классом point2d который вам доступен
  triangle(point2d A, point2d B, point2d C);

  //метод выполняющий поворот треугольника на угол angle градусов по часовой стрелке относительно начала координат
  void rotate(double angle);

  //метод возвращающий площадь треугольника
  double get_square() const;

  //метод определяющий находится ли точка point внутри треугольника.
  bool contain_point(point2d const &point) const;
protected:
    point2d A_, B_, C_;
};

triangle::triangle(point2d A, point2d B, point2d C): A_{A}, B_{B}, C_{C}{}

double triangle::get_square() const{
    double a = sqrt(((this->B_.get_x())-(this->C_.get_x()))*((this->B_.get_x())-(this->C_.get_x())) + ((this->B_.get_y())-(this->C_.get_y()))*((this->B_.get_y())-(this->C_.get_y())));
    double b = sqrt(((this->A_.get_x())-(this->C_.get_x()))*((this->A_.get_x())-(this->C_.get_x())) + ((this->A_.get_y())-(this->C_.get_y()))*((this->A_.get_y())-(this->C_.get_y())));
    double c = sqrt(((this->B_.get_x())-(this->A_.get_x()))*((this->B_.get_x())-(this->A_.get_x())) + ((this->B_.get_y())-(this->A_.get_y()))*((this->B_.get_y())-(this->A_.get_y())));
    return sqrt(0.5*0.5*0.5*0.5*(a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
}

void triangle::rotate(double angle){
    double fi = 4*atan(1.0)*angle/180;
    double nx, ny;
    nx = (this->A_.get_x())*std::cos(fi) + (this->A_.get_y())*std::sin(fi);
    ny = - (this->A_.get_x())*std::sin(fi) + (this->A_.get_y())*std::cos(fi);
    this->A_.set_x(nx);
    this->A_.set_y(ny);

    nx = (this->B_.get_x())*std::cos(fi) + (this->B_.get_y())*std::sin(fi);
    ny = - (this->B_.get_x())*std::sin(fi) + (this->B_.get_y())*std::cos(fi);
    this->B_.set_x(nx);
    this->B_.set_y(ny);

    nx = (this->C_.get_x())*std::cos(fi) + (this->C_.get_y())*std::sin(fi);
    ny = - (this->C_.get_x())*std::sin(fi) + (this->C_.get_y())*std::cos(fi);
    this->C_.set_x(nx);
    this->C_.set_y(ny);
}

bool triangle::contain_point(point2d const &point) const{
    point2d a(this->A_.get_x(), this->A_.get_y()), b(this->B_.get_x(), this->B_.get_y()), c(this->C_.get_x(), this->C_.get_y());
    triangle tr_1(a, b, c);
    triangle tr_2(a, b, point);
    triangle tr_3(a, point, c);
    triangle tr_4(point, b, c);
    if (std::abs(tr_2.get_square() + tr_3.get_square() + tr_4.get_square() - tr_1.get_square()) < 1e-6){
        return true;
    }
    else {
        return false;
    }
}

class right_triangle: public triangle{

public:

  //Конструктор создающий треугольник с прямым углом в начале координат и катетами, параллельными осям координат, с заданной длиной

  //cathetus1_lenght -- длина катета параллельного оси y

  //cathetus2_lenght -- длина катета параллельного оси x

  right_triangle(double  cathetus1_lenght, double  cathetus2_lenght);

  //тоже самое, что и первый конструктор, но теперь координаты угла заданы третьим параметром

  right_triangle(double cathetus1_lenght, double  cathetus2_lenght, point2d const &right_angle_coord);
};

right_triangle::right_triangle(double  cathetus1_lenght, double  cathetus2_lenght): triangle{point2d(0.0, 0.0), point2d(0.0, cathetus1_lenght), point2d(cathetus2_lenght, 0.0)}{}

right_triangle::right_triangle(double cathetus1_lenght, double  cathetus2_lenght, point2d const &right_angle_coord): triangle{right_angle_coord, point2d(0.0, cathetus1_lenght), point2d(cathetus2_lenght, 0.0)}{}

int main(){
right_triangle tr(1, 2);
std::cout << tr.get_square() << std::endl;
std::cout << std::boolalpha << tr.contain_point(point2d(0.5, -0.1)) << std::endl;
std::cout << std::boolalpha << tr.contain_point(point2d(0.25, 0.25)) << std::endl;
tr.rotate(45);
std::cout << tr.get_square() << std::endl;
std::cout << std::boolalpha << tr.contain_point(point2d(0.5, -0.1)) << std::endl;
    return 0;
}
