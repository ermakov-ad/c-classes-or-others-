#include <iostream>

class Vector2D
{
public:
    // ������������
    Vector2D();
    Vector2D(int x, int y);

    // ����������
    ~Vector2D();

    // ��������� ���������
    int getX() const;
    int getY() const;

    // ������� ���������
    void setX(int x);
    void setY(int y);

    // ������������� �������� - ��������� ���� �������� �� ���������
    bool operator== (const Vector2D& v2) const;

    // ��� ���� ������������� �������� - ����������� ��������
    // ��, ��� ��������� ��������! ���� - ��������� ������ ������ ��� != ������������ ��� ���������� ==
    bool operator!= (const Vector2D& v2) const;

    // ����� ���� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator+ (const Vector2D& v2) const;

    // ��������� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator- (const Vector2D& v2) const;

    // �������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
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
