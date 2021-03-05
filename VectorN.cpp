#include <iostream>
#include <vector>

class VectorN
{
public:
    // ����������� ������� ����������� n
    VectorN(unsigned int n);

    // ����������
    ~VectorN();

    // ��������� ����������� �������
    unsigned getSize() const;

    // ��������� �������� i-�� ���������� �������,
    // i ��������� � ��������� �� 0 �� n-1
    int getValue(unsigned int i) const;

    // ������� �������� i-�� ���������� ������� ������ value,
    // i ��������� � ��������� �� 0 �� n-1
    void setValue(unsigned int i, int value);

    // �������� == ��������� ��� ������� �� ���������,
    // ����� ���, ���� ������ ����� ��� �� ����������
    bool operator== (const VectorN& v2) const;

    // �������� != ��������� ��� ������� �� �����������,
    // ��� �� �����, ���� ���� �� ���� ���������� ����������
    bool operator!= (const VectorN& v2) const;

    // �������� + ���������� ��� ������� �������������,
    // ���������� ��������� ��� ����� ��������� �������
    VectorN operator+ (const VectorN& v2) const;

    // �������� * �������� ������ �� ������ ���� int �������������,
    // ���������� ��������� ��� ����� ��������� �������.
    // ��������� ������ �������� ��� ����� ������� ���������.
    VectorN operator* (const int a) const;

private:
    std::vector <int> v;
    unsigned int n=0;
};

VectorN::VectorN(unsigned int n) {
    this->n = n;
    for (unsigned int i=0; i<n; ++i) {
        this->v.push_back(0);
    }
}

VectorN::~VectorN() {}

unsigned VectorN::getSize() const {
    return this->n;
}

int VectorN::getValue(unsigned int i) const {
    if (i >= 0 && i < this->n){
        return this->v[i];
    }
    else {
        return false;
    }
}

void VectorN::setValue(unsigned int i, int value) {
    if (i >= 0 && i < this->n){
        this->v[i] = value;
    }
}

bool VectorN::operator== (const VectorN& v2) const {
    bool mistake = true;
    if (this->n == v2.getSize()) {
        for (unsigned i = 0; i < this->n; ++i) {
            if (this->v[i] != v2.getValue(i)) {
                mistake = false;
                i = this->n;
            }
        }
    }
    else {
        mistake = false;
    }
    return mistake;
}

bool VectorN::operator!= (const VectorN& v2) const {
    bool mistake = false;
    if (this->n == v2.getSize()) {
        for (unsigned i = 0; i < this->n; ++i) {
            if (this->v[i] != v2.getValue(i)) {
                mistake = true;
                i = this->n;
            }
        }
    }
    else {
        mistake = true;
    }
    return mistake;
}

VectorN VectorN::operator+ (const VectorN& v2) const {
    unsigned count;
    if (this->n == v2.getSize()) {
        count = this->n;
    }
    else {
        count = 1;
    }
    VectorN newV(count);
    if (this->n == v2.getSize()) {
        for (unsigned i = 0; i < this->n; ++i) {
            newV.setValue(i, this->v[i] + v2.getValue(i));
        }
    }
    else {
        newV.setValue(0, 0);
    }
    return newV;
}

VectorN VectorN::operator* (const int a) const {
    VectorN newV(this->n);
    for (unsigned i = 0; i < this->n; ++i) {
        newV.setValue(i, this->v[i] * a);
    }
    return newV;
}

VectorN operator* (const int a, const VectorN& v) {
    return v * a;
}

int main() {
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        std::cout << d.getValue(i) << std::endl;
    return 0;
}
