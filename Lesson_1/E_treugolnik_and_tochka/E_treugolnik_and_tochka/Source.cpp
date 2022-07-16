//E.����� � �����������
//����������� �������	1 �������
//����������� ������	64Mb
//����	����������� ���� ��� input.txt
//�����	����������� ����� ��� output.txt
//�� ������������ ��������� ����������� �������������� ������������� ����������� ABC 
//� ������ ������ d � ����� X.������ ������������ ����� �� ���� ���������, � ������� 
//����������� � ������ : A(0, 0), B(d, 0), C(0, d).
//
//�������� ���������, ������� ���������� �������� ������������ ����� X � ������������.
//���� ����� X ����������� ������ ��� �� �������� ������������, �������� 0. ���� �� ����� 
//��������� ��� ������������, �������� ����� ��������� � ��� �������.
//
//������ �����
//������� �������� ����������� ����� d(�� ������������� 1000), � ����� ���������� ����� X 
//� ��� ����� ����� �� ��������� �� ��1000 �� 1000.
//
//������ ������
//���� ����� ����� ������, �� ������� ������������ ��� ��������� � ����� �� ������, �� 
//�������� ����� 0. ���� ����� ����� ��� ������������, �� �������� ����� ������� 
//������������, � ������� ��� ����������� ����� �����(1 � � ������� A, 2 � � B, 3 � � C).
//���� ����� ����������� �� ���������� ���������� �� ���� ������, �������� �� �������, 
//����� ������� ������.
//
//������ 1
//����	    �����
//5       0
//1 1
//
//������ 2
//����	    �����
//3           1
//- 1 - 1
//
//������ 3
//����	    �����
//4           2
//4 4
//
//������ 4
//����	    �����
//4           0
//2 2
//
//����������
//����������� � �������� ������
//
//1. ����� ����� ������ ������������.
//
//2. ����� ����� ��� ������������ � ����� ����� � ��� ������� A
//
//3. ����� ����� �� ������ ���������� �� ������ B � C, � ���� ������ ����� ������� �� 
//�������, � ������� ����� ������, �.�.�������� ������ ���� ����� 2
//
//4. ����� ����� �� ������� ������������.

#include<iostream>
#include<map>
#include<algorithm>
#include <math.h>
using namespace std;


int vect_lenght(const double& x,const double& y,const double& d) {
    double lenght = 0;
    map<double,int> v;

    //������� ���������� ���������� �� �����
    // lenght=sqrt( (x(X)-x(A))^2 + (y(X)-y(A))^2 )
    //������ ���������� �� ����� �
    lenght = x * x + y * y;
    lenght = sqrt(lenght);
    v[1] =lenght;

    //������ ���������� �� ����� B
    lenght = (x - d) * (x - d) + y * y;
    lenght = sqrt(lenght);
    v[2] = lenght;

    //������ ���������� �� ����� C
    lenght = x * x + (y-d) * (y-d);
    lenght = sqrt(lenght);
    v[3] = lenght;

    //���������� ����������� ����������
    int result = min(v[1], v[2]);
    if (result == v[1]) {
        result = min(v[1], v[3]);
    }
    else {
        result = min(v[2], v[3]);
    }

    for (auto x : v) {
        if (x.second == result) {
            return x.first;
            return 0;
        }
    }
}


int main() {
    double d, x, y;
    //���� ������
    
    cin >> d >> x >> y;

    //������� � ����� ������� �� ���������
    if (x >= 0 && y >= 0) {
        //�������� �������������� ��������
        if (y <= -x + d) {
            cout << 0;
            return 0;
        }
    }
    //����� ������ ��������� �������
    cout << vect_lenght(x, y, d);

    return 0;
}