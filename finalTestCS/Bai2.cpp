#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;


//Class Vemaybay
class Vemaybay {
private:
    char tenchuyen[50];
    char ngaybay[20];
    float giave;

public:
    Vemaybay() {
        giave = 0;
    }

    void Nhap() {
        cout << "Nhap ten chuyen: ";
        cin.ignore();
        cin.getline(tenchuyen, 50);
        cout << "Nhap ngay bay: ";
        cin.getline(ngaybay, 20);
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    float getgiave() {
        return giave;
    }
};

class Nguoi {
private:
    char hoten[50];
    char gioitinh[10];
    int tuoi;

public:
    Nguoi() {
        tuoi = 0;
    }

    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        cin.getline(hoten, 50);
        cout << "Nhap gioi tinh: ";
        cin.getline(gioitinh, 10);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class HanhKhach : public Nguoi {
private:
    Vemaybay* ve;
    int soluong;

public:
    HanhKhach() {
        soluong = 0;
        ve = nullptr;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;

        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            cout << "Nhap thong tin ve thu " << i + 1 << endl;
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;

        for (int i = 0; i < soluong; ++i) {
            cout << "Thong tin ve thu " << i + 1 << endl;
            ve[i].Xuat();
        }
    }

    float tongtien() {
        float total = 0;
        for (int i = 0; i < soluong; ++i) {
            total += ve[i].getgiave();
        }
        return total;
    }
};

int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;

    HanhKhach* danhSachHanhKhach = new HanhKhach[n];

    // Nhập thông tin cho mỗi hành khách
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << endl;
        danhSachHanhKhach[i].Nhap();
    }

    // Hiển thị thông tin và tổng tiền của mỗi hành khách
    cout << "\nDanh sach hanh khach va so tien phai tra:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachHanhKhach[i].Xuat();
        cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
        cout << "------------------------" << endl;
    }

    // Sắp xếp danh sách hành khách theo chiều giảm dần của tổng tiền
    sort(danhSachHanhKhach, danhSachHanhKhach + n);

    // Hiển thị danh sách đã sắp xếp
    cout << "\nDanh sach sau khi sap xep:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachHanhKhach[i].Xuat();
        cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}
