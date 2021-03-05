#include <iostream>

class Vector2D
{
public:
    // Конструкторы
    Vector2D();
    Vector2D(int x, int y);

    // Деструктор
    ~Vector2D();

    // Получение координат
    int getX() const;
    int getY() const;

    // Задание координат
    void setX(int x);
    void setY(int y);

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const;

    // Ещё один перегруженный оператор - неравенство векторов
    // Да, это отдельный оператор! Хинт - настоящие джедаи смогут для != использовать уже написанное ==
    bool operator!= (const Vector2D& v2) const;

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const;

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator- (const Vector2D& v2) const;

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector2D operator* (const int a) const;

protected:
    int x;
    int y;
};

Vector2D::Vector2D() : x(0), y(0) {}
Vector2D::Vector2D(int _x, int _y) : x(_x), y(_y) {}
Vector2D::~Vector2D() {}

int Vector2D::getX() const { return this->x; }
int Vector2D::getY() const { return this->y; }

void Vector2D::setX(int x) { this-> x = x; }
void Vector2D::setY(int y) { this-> y = y; }

bool Vector2D::operator== (const Vector2D& v2) const {
    return x == v2.x && y == v2.y;
}

bool Vector2D::operator!= (const Vector2D& v2) const {
    if (x == v2.x && y == v2.y){
        return false;
    }
    else {
        return true;
    }
}

Vector2D Vector2D::operator+ (const Vector2D& v2) const {
    return Vector2D(x + v2.x, y + v2.y);
}

Vector2D Vector2D::operator- (const Vector2D& v2) const{
    return Vector2D(x - v2.x, y - v2.y);
}

Vector2D Vector2D::operator* (const int a) const{
    return Vector2D(a*x, a*y);
}

Vector2D operator* (const int a, const Vector2D& v){
    return v * a;
}

std::ostream& operator << (std::ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

std::istream& operator >> (std::istream &is, Vector2D &v) {
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main(){
    using namespace std;
    Vector2D v1;
    cin >> v1;
    cout << v1 << endl;
    Vector2D v2;
    cin >> v2;
    cout << v2 << endl;
    cout << boolalpha << (v1 == v2) << endl;
    cout << boolalpha << (v1 != v2) << endl;
    Vector2D v3 = v1 - v2;
    cout << v3 << endl;
    cout << v3 * 42 << endl;
    cout << 42 * v3 << endl;
}
