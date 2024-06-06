#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 100
#define MAX_SUPPLIERS 100
#define MAX_BILLS 100 
#define MAX_EMPLOYEES 100 

using namespace std;

class NhanVien {
public:
    int ma;
    string ten;
    float luong;
    string chucVu;
    string soDienThoai;
};

class SanPham {
public:
    int ma;
    string ten;
    float gia;
    int soLuong;
};

class KhachHang {
public:
    int ma;
    string ten;
    string diaChi;
    string soDienThoai;
};

class NhaCungCap {
public:
    int ma;
    string ten;
    string diaChi;
    string soDienThoai;
};

class HoaDon {
public:
    int ma;
    int maKhachHang;
    int maSanPham;
    int soLuong;
    float tongGia;
    float giamGia;
    float giaCuoi;
};

vector<SanPham> dsSanPham;
vector<KhachHang> dsKhachHang;
vector<NhaCungCap> dsNhaCungCap;
vector<HoaDon> dsHoaDon;
vector<NhanVien> dsNhanVien;

void themSanPham();
void suaSanPham();
void xoaSanPham();
void timSanPham();
void timSanPhamTheoTen();
void sapXepSanPhamTheoGia();
void sapXepSanPhamTheoTen();
void luuSanPhamVaoTep();
void taiSanPhamTuTep();

void luuKhachHangVaoTep();
void taiKhachHangTuTep();
void themKhachHang();
void suaKhachHang();
void xoaKhachHang();
void timKhachHang();

void themNhanVien();
void suaNhanVien();
void xoaNhanVien();
void timNhanVien();
void luuNhanVienVaoTep();
void taiNhanVienTuTep();

void luuNhaCungCapVaoTep();
void taiNhaCungCapTuTep();
void themNhaCungCap();
void suaNhaCungCap();
void xoaNhaCungCap();
void timNhaCungCap();

void themHoaDon();
void suaHoaDon();
void xoaHoaDon();
void timHoaDon();
void tinhTongDoanhThu();
void menuChinh();

void themSanPham() {
    if (dsSanPham.size() >= MAX_PRODUCTS) {
        cout << "Khong the them san pham moi. Danh sach da day." << endl;
        return;
    }
    SanPham sp;
    cout << "Nhap ma san pham: ";
    cin >> sp.ma;
    cout << "Nhap ten san pham: ";
    cin.ignore();
    getline(cin, sp.ten);
    cout << "Nhap gia san pham: ";
    cin >> sp.gia;
    cout << "Nhap so luong san pham: ";
    cin >> sp.soLuong;
    dsSanPham.push_back(sp);
    cout << "Them san pham thanh cong!" << endl;
}

void suaSanPham() {
    int ma;
    cout << "Nhap ma san pham can sua: ";
    cin >> ma;
    for (auto &sp : dsSanPham) {
        if (sp.ma == ma) {
            cout << "Nhap ten san pham moi: ";
            cin.ignore();
            getline(cin, sp.ten);
            cout << "Nhap gia san pham moi: ";
            cin >> sp.gia;
            cout << "Nhap so luong san pham moi: ";
            cin >> sp.soLuong;
            cout << "Sua thong tin san pham thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham voi ma da cho." << endl;
}

void xoaSanPham() {
    int ma;
    cout << "Nhap ma san pham can xoa: ";
    cin >> ma;
    auto it = remove_if(dsSanPham.begin(), dsSanPham.end(), [ma](SanPham &sp) {
        return sp.ma == ma;
    });
    if (it != dsSanPham.end()) {
        dsSanPham.erase(it, dsSanPham.end());
        cout << "Xoa san pham thanh cong!" << endl;
    } else {
        cout << "Khong tim thay san pham voi ma da cho." << endl;
    }
}

void timSanPham() {
    int ma;
    cout << "Nhap ma san pham can tim: ";
    cin >> ma;
    for (const auto &sp : dsSanPham) {
        if (sp.ma == ma) {
            cout << "San pham tim thay: Ma: " << sp.ma << ", Ten: " << sp.ten << ", Gia: " << sp.gia << ", So luong: " << sp.soLuong << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham voi ma da cho." << endl;
}

void timSanPhamTheoTen() {
    string ten;
    cout << "Nhap ten san pham can tim: ";
    cin.ignore();
    getline(cin, ten);
    for (const auto &sp : dsSanPham) {
        if (sp.ten == ten) {
            cout << "San pham tim thay: Ma: " << sp.ma << ", Ten: " << sp.ten << ", Gia: " << sp.gia << ", So luong: " << sp.soLuong << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham voi ten da cho." << endl;
}

void sapXepSanPhamTheoGia() {
    sort(dsSanPham.begin(), dsSanPham.end(), [](SanPham &a, SanPham &b) {
        return a.gia < b.gia;
    });
    cout << "Da sap xep san pham theo gia tang dan." << endl;
}

void sapXepSanPhamTheoTen() {
    sort(dsSanPham.begin(), dsSanPham.end(), [](SanPham &a, SanPham &b) {
        return a.ten < b.ten;
    });
    cout << "Da sap xep san pham theo ten tang dan." << endl;
}

void luuSanPhamVaoTep() {
    ofstream f("sanpham.txt");
    if (!f) {
        cout << "Khong the mo tep de ghi." << endl;
        return;
    }
    f << dsSanPham.size() << endl;
    for (const auto &sp : dsSanPham) {
        f << sp.ma << endl
          << sp.ten << endl
          << sp.gia << endl
          << sp.soLuong << endl;
    }
    cout << "Da luu danh sach san pham vao tep sanpham.txt." << endl;
}

void taiSanPhamTuTep() {
    ifstream f("sanpham.txt");
    if (!f) {
        cout << "Khong the mo tep de doc." << endl;
        return;
    }
    size_t soLuongSanPham;
    f >> soLuongSanPham;
    f.ignore();
    dsSanPham.clear();
    for (size_t i = 0; i < soLuongSanPham; ++i) {
        SanPham sp;
        f >> sp.ma;
        f.ignore();
        getline(f, sp.ten);
        f >> sp.gia;
        f >> sp.soLuong;
        f.ignore();
        dsSanPham.push_back(sp);
    }
    cout << "Da tai danh sach san pham tu tep sanpham.txt." << endl;
}

void luuKhachHangVaoTep() {
    ofstream f("khachhang.txt");
    if (!f) {
        cout << "Khong the mo tep de ghi." << endl;
        return;
    }
    f << dsKhachHang.size() << endl;
    for (const auto &kh : dsKhachHang) {
        f << kh.ma << endl
          << kh.ten << endl
          << kh.diaChi << endl
          << kh.soDienThoai << endl;
    }
    cout << "Da luu danh sach khach hang vao tep khachhang.txt." << endl;
}

void taiKhachHangTuTep() {
    ifstream f("khachhang.txt");
    if (!f) {
        cout << "Khong the mo tep de doc." << endl;
        return;
    }
    size_t soLuongKhachHang;
    f >> soLuongKhachHang;
    f.ignore();
    dsKhachHang.clear();
    for (size_t i = 0; i < soLuongKhachHang; ++i) {
        KhachHang kh;
        f >> kh.ma;
        f.ignore();
        getline(f, kh.ten);
        getline(f, kh.diaChi);
        getline(f, kh.soDienThoai);
        dsKhachHang.push_back(kh);
    }
    cout << "Da tai danh sach khach hang tu tep khachhang.txt." << endl;
}

void themKhachHang() {
    if (dsKhachHang.size() >= MAX_CUSTOMERS) {
        cout << "Khong the them khach hang moi. Danh sach da day." << endl;
        return;
    }
    KhachHang kh;
    cout << "Nhap ma khach hang: ";
    cin >> kh.ma;
    cout << "Nhap ten khach hang: ";
    cin.ignore();
    getline(cin, kh.ten);
    cout << "Nhap dia chi khach hang: ";
    getline(cin, kh.diaChi);
    cout << "Nhap so dien thoai khach hang: ";
    getline(cin, kh.soDienThoai);
    dsKhachHang.push_back(kh);
    cout << "Them khach hang thanh cong!" << endl;
}

void suaKhachHang() {
    int ma;
    cout << "Nhap ma khach hang can sua: ";
    cin >> ma;
    for (auto &kh : dsKhachHang) {
        if (kh.ma == ma) {
            cout << "Nhap ten khach hang moi: ";
            cin.ignore();
            getline(cin, kh.ten);
            cout << "Nhap dia chi khach hang moi: ";
            getline(cin, kh.diaChi);
            cout << "Nhap so dien thoai khach hang moi: ";
            getline(cin, kh.soDienThoai);
            cout << "Sua thong tin khach hang thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ma da cho." << endl;
}

void xoaKhachHang() {
    int ma;
    cout << "Nhap ma khach hang can xoa: ";
    cin >> ma;
    auto it = remove_if(dsKhachHang.begin(), dsKhachHang.end(), [ma](KhachHang &kh) {
        return kh.ma == ma;
    });
    if (it != dsKhachHang.end()) {
        dsKhachHang.erase(it, dsKhachHang.end());
        cout << "Xoa khach hang thanh cong!" << endl;
    } else {
        cout << "Khong tim thay khach hang voi ma da cho." << endl;
    }
}

void timKhachHang() {
    int ma;
    cout << "Nhap ma khach hang can tim: ";
    cin >> ma;
    for (const auto &kh : dsKhachHang) {
        if (kh.ma == ma) {
            cout << "Khach hang tim thay: Ma: " << kh.ma << ", Ten: " << kh.ten << ", Dia chi: " << kh.diaChi << ", So dien thoai: " << kh.soDienThoai << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang voi ma da cho." << endl;
}

void themNhanVien() {
    if (dsNhanVien.size() >= MAX_EMPLOYEES) {
        cout << "Khong the them nhan vien moi. Danh sach da day." << endl;
        return;
    }
    NhanVien nv;
    cout << "Nhap ma nhan vien: ";
    cin >> nv.ma;
    cout << "Nhap ten nhan vien: ";
    cin.ignore();
    getline(cin, nv.ten);
    cout << "Nhap luong nhan vien: ";
    cin >> nv.luong;
    cout << "Nhap chuc vu nhan vien: ";
    cin.ignore();
    getline(cin, nv.chucVu);
    cout << "Nhap so dien thoai nhan vien: ";
    getline(cin, nv.soDienThoai);
    dsNhanVien.push_back(nv);
    cout << "Them nhan vien thanh cong!" << endl;
}

void suaNhanVien() {
    int ma;
    cout << "Nhap ma nhan vien can sua: ";
    cin >> ma;
    for (auto &nv : dsNhanVien) {
        if (nv.ma == ma) {
            cout << "Nhap ten nhan vien moi: ";
            cin.ignore();
            getline(cin, nv.ten);
            cout << "Nhap luong nhan vien moi: ";
            cin >> nv.luong;
            cout << "Nhap chuc vu nhan vien moi: ";
            cin.ignore();
            getline(cin, nv.chucVu);
            cout << "Nhap so dien thoai nhan vien moi: ";
            getline(cin, nv.soDienThoai);
            cout << "Sua thong tin nhan vien thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien voi ma da cho." << endl;
}

void xoaNhanVien() {
    int ma;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> ma;
    auto it = remove_if(dsNhanVien.begin(), dsNhanVien.end(), [ma](NhanVien &nv) {
        return nv.ma == ma;
    });
    if (it != dsNhanVien.end()) {
        dsNhanVien.erase(it, dsNhanVien.end());
        cout << "Xoa nhan vien thanh cong!" << endl;
    } else {
        cout << "Khong tim thay nhan vien voi ma da cho." << endl;
    }
}

void timNhanVien() {
    int ma;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> ma;
    for (const auto &nv : dsNhanVien) {
        if (nv.ma == ma) {
            cout << "Nhan vien tim thay: Ma: " << nv.ma << ", Ten: " << nv.ten << ", Luong: " << nv.luong << ", Chuc vu: " << nv.chucVu << ", So dien thoai: " << nv.soDienThoai << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien voi ma da cho." << endl;
}

void luuNhanVienVaoTep() {
    ofstream f("nhanvien.txt");
    if (!f) {
        cout << "Khong the mo tep de ghi." << endl;
        return;
    }
    f << dsNhanVien.size() << endl;
    for (const auto &nv : dsNhanVien) {
        f << nv.ma << endl
          << nv.ten << endl
          << nv.luong << endl
          << nv.chucVu << endl
          << nv.soDienThoai << endl;
    }
    cout << "Da luu danh sach nhan vien vao tep nhanvien.txt." << endl;
}

void taiNhanVienTuTep() {
    ifstream f("nhanvien.txt");
    if (!f) {
        cout << "Khong the mo tep de doc." << endl;
        return;
    }
    size_t soLuongNhanVien;
    f >> soLuongNhanVien;
    f.ignore();
    dsNhanVien.clear();
    for (size_t i = 0; i < soLuongNhanVien; ++i) {
        NhanVien nv;
        f >> nv.ma;
        f.ignore();
        getline(f, nv.ten);
        f >> nv.luong;
        f.ignore();
        getline(f, nv.chucVu);
        getline(f, nv.soDienThoai);
        dsNhanVien.push_back(nv);
    }
    cout << "Da tai danh sach nhan vien tu tep nhanvien.txt." << endl;
}

void luuNhaCungCapVaoTep() {
    ofstream f("nhacungcap.txt");
    if (!f) {
        cout << "Khong the mo tep de ghi." << endl;
        return;
    }
    f << dsNhaCungCap.size() << endl;
    for (const auto &ncc : dsNhaCungCap) {
        f << ncc.ma << endl
          << ncc.ten << endl
          << ncc.diaChi << endl
          << ncc.soDienThoai << endl;
    }
    cout << "Da luu danh sach nha cung cap vao tep nhacungcap.txt." << endl;
}

void taiNhaCungCapTuTep() {
    ifstream f("nhacungcap.txt");
    if (!f) {
        cout << "Khong the mo tep de doc." << endl;
        return;
    }
    size_t soLuongNhaCungCap;
    f >> soLuongNhaCungCap;
    f.ignore();
    dsNhaCungCap.clear();
    for (size_t i = 0; i < soLuongNhaCungCap; ++i) {
        NhaCungCap ncc;
        f >> ncc.ma;
        f.ignore();
        getline(f, ncc.ten);
        getline(f, ncc.diaChi);
        getline(f, ncc.soDienThoai);
        dsNhaCungCap.push_back(ncc);
    }
    cout << "Da tai danh sach nha cung cap tu tep nhacungcap.txt." << endl;
}

void themNhaCungCap() {
    if (dsNhaCungCap.size() >= MAX_SUPPLIERS) {
        cout << "Khong the them nha cung cap moi. Danh sach da day." << endl;
        return;
    }
    NhaCungCap ncc;
    cout << "Nhap ma nha cung cap: ";
    cin >> ncc.ma;
    cout << "Nhap ten nha cung cap: ";
    cin.ignore();
    getline(cin, ncc.ten);
    cout << "Nhap dia chi nha cung cap: ";
    getline(cin, ncc.diaChi);
    cout << "Nhap so dien thoai nha cung cap: ";
    getline(cin, ncc.soDienThoai);
    dsNhaCungCap.push_back(ncc);
    cout << "Them nha cung cap thanh cong!" << endl;
}

void suaNhaCungCap() {
    int ma;
    cout << "Nhap ma nha cung cap can sua: ";
    cin >> ma;
    for (auto &ncc : dsNhaCungCap) {
        if (ncc.ma == ma) {
            cout << "Nhap ten nha cung cap moi: ";
            cin.ignore();
            getline(cin, ncc.ten);
            cout << "Nhap dia chi nha cung cap moi: ";
            getline(cin, ncc.diaChi);
            cout << "Nhap so dien thoai nha cung cap moi: ";
            getline(cin, ncc.soDienThoai);
            cout << "Sua thong tin nha cung cap thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nha cung cap voi ma da cho." << endl;
}

void xoaNhaCungCap() {
    int ma;
    cout << "Nhap ma nha cung cap can xoa: ";
    cin >> ma;
    auto it = remove_if(dsNhaCungCap.begin(), dsNhaCungCap.end(), [ma](NhaCungCap &ncc) {
        return ncc.ma == ma;
    });
    if (it != dsNhaCungCap.end()) {
        dsNhaCungCap.erase(it, dsNhaCungCap.end());
        cout << "Xoa nha cung cap thanh cong!" << endl;
    } else {
        cout << "Khong tim thay nha cung cap voi ma da cho." << endl;
    }
}

void timNhaCungCap() {
    int ma;
    cout << "Nhap ma nha cung cap can tim: ";
    cin >> ma;
    for (const auto &ncc : dsNhaCungCap) {
        if (ncc.ma == ma) {
            cout << "Nha cung cap tim thay: Ma: " << ncc.ma << ", Ten: " << ncc.ten << ", Dia chi: " << ncc.diaChi << ", So dien thoai: " << ncc.soDienThoai << endl;
            return;
        }
    }
    cout << "Khong tim thay nha cung cap voi ma da cho." << endl;
}
void themHoaDon() {
    if (dsHoaDon.size() >= MAX_BILLS) {
        cout << "Khong the them hoa don moi. Danh sach da day." << endl;
        return;
    }
    HoaDon hd;
    cout << "Nhap ma hoa don: ";
    cin >> hd.ma;
    cout << "Nhap ma khach hang: ";
    cin >> hd.maKhachHang;
    cout << "Nhap ma san pham: ";
    cin >> hd.maSanPham;
    cout << "Nhap so luong san pham: ";
    cin >> hd.soLuong;
    cout << "Nhap tong gia: ";
    cin >> hd.tongGia;
    cout << "Nhap giam gia: ";
    cin >> hd.giamGia;
    hd.giaCuoi = hd.tongGia - hd.giamGia;
    dsHoaDon.push_back(hd);
    cout << "Them hoa don thanh cong!" << endl;
}

void suaHoaDon() {
    int ma;
    cout << "Nhap ma hoa don can sua: ";
    cin >> ma;
    for (auto &hd : dsHoaDon) {
        if (hd.ma == ma) {
            cout << "Nhap ma khach hang moi: ";
            cin >> hd.maKhachHang;
            cout << "Nhap ma san pham moi: ";
            cin >> hd.maSanPham;
            cout << "Nhap so luong san pham moi: ";
            cin >> hd.soLuong;
            cout << "Nhap tong gia moi: ";
            cin >> hd.tongGia;
            cout << "Nhap giam gia moi: ";
            cin >> hd.giamGia;
            hd.giaCuoi = hd.tongGia - hd.giamGia;
            cout << "Sua thong tin hoa don thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay hoa don voi ma da cho." << endl;
}

void xoaHoaDon() {
    int ma;
    cout << "Nhap ma hoa don can xoa: ";
    cin >> ma;
    auto it = remove_if(dsHoaDon.begin(), dsHoaDon.end(), [ma](HoaDon &hd) {
        return hd.ma == ma;
    });
    if (it != dsHoaDon.end()) {
        dsHoaDon.erase(it, dsHoaDon.end());
        cout << "Xoa hoa don thanh cong!" << endl;
    } else {
        cout << "Khong tim thay hoa don voi ma da cho." << endl;
    }
}

void timHoaDon() {
    int ma;
    cout << "Nhap ma hoa don can tim: ";
    cin >> ma;
    for (const auto &hd : dsHoaDon) {
        if (hd.ma == ma) {
            cout << "Hoa don tim thay: Ma: " << hd.ma << ", Ma khach hang: " << hd.maKhachHang 
                 << ", Ma san pham: " << hd.maSanPham << ", So luong: " << hd.soLuong 
                 << ", Tong gia: " << hd.tongGia << ", Giam gia: " << hd.giamGia 
                 << ", Gia cuoi: " << hd.giaCuoi << endl;
            return;
        }
    }
    cout << "Khong tim thay hoa don voi ma da cho." << endl;
}

void tinhTongDoanhThu() {
    float tongDoanhThu = 0;
    for (const auto &hd : dsHoaDon) {
        tongDoanhThu += hd.giaCuoi;
    }
    cout << "Tong doanh thu: " << tongDoanhThu << endl;
}

void menuChinh() {
    int luaChon;
    do {
        printf("\n============= MENU =============\n");
        printf("1. Quan ly san pham\n");
        printf("2. Quan ly khach hang\n");
        printf("3. Quan ly nha cung cap\n");
        printf("4. Lap hoa don\n");
        printf("5. Tim kiem hoa don\n");
        printf("6. Tinh tong doanh thu\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                printf("\n============= QUAN LY SAN PHAM =============\n");
                printf("1. Them san pham\n");
                printf("2. Sua san pham\n");
                printf("3. Xoa san pham\n");
                printf("4. Tim san pham\n");
                printf("5. Tim san pham theo ten\n");
                printf("6. Sap xep san pham theo gia\n");
                printf("7. Sap xep san pham theo ten\n");
                printf("8. Luu danh sach san pham vao tep\n");
                printf("9. Tai danh sach san pham tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themSanPham();
                        break;
                    case 2:
                        suaSanPham();
                        break;
                    case 3:
                        xoaSanPham();
                        break;
                    case 4:
                        timSanPham();
                        break;
                    case 5:
                        timSanPhamTheoTen();
                        break;
                    case 6:
                        sapXepSanPhamTheoGia();
                        break;
                    case 7:
                        sapXepSanPhamTheoTen();
                        break;
                    case 8:
                        luuSanPhamVaoTep();
                        break;
                    case 9:
                        taiSanPhamTuTep();
                        break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break;
            case 2:
                printf("\n============= QUAN LY KHACH HANG =============\n");
                printf("1. Them khach hang\n");
                printf("2. Sua khach hang\n");
                printf("3. Xoa khach hang\n");
                printf("4. Tim khach hang\n");
                printf("5. Luu danh sach khach hang vao tep\n");
                printf("6. Tai danh sach khach hang tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themKhachHang();
                        break;
                    case 2:
                        suaKhachHang();
                        break;
                    case 3:
                        xoaKhachHang();
                        break;
                    case 4:
                        timKhachHang();
                        break;
                    case 5:
                        luuKhachHangVaoTep();
                        break;
                    case 6:
                        taiKhachHangTuTep();
                        break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break;
            case 3:
                printf("\n============= QUAN LY NHA CUNG CAP =============\n");
                printf("1. Them nha cung cap\n");
                printf("2. Sua nha cung cap\n");
                printf("3. Xoa nha cung cap\n");
                printf("4. Tim nha cung cap\n");
                printf("5. Luu danh sach nha cung cap vao tep\n");
                printf("6. Tai danh sach nha cung cap tu tep\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &luaChon);
                switch (luaChon) {
                    case 1:
                        themNhaCungCap();
                        break;
                    case 2:
                        suaNhaCungCap();
                        break;
                    case 3:
                        xoaNhaCungCap();
                        break;
                    case 4:
                        timNhaCungCap();
                        break;
                    case 5:
                        luuNhaCungCapVaoTep();
                        break;
                    case 6:
                        taiNhaCungCapTuTep();
                        break;
                    default:
                        printf("Lua chon khong hop le!\n");
                        break;
                }
                break;
            case 4:
                printf("\n============= LAP HOA DON =============\n");
                themHoaDon();
                break;
            case 5:
                printf("\n============= TIM KIEM HOA DON =============\n");
                timHoaDon();
                break;
            case 6:
                printf("\n============= TINH TONG DOANH THU =============\n");
                tinhTongDoanhThu();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 0);
}

int main() {
    menuChinh();
    return 0;
}

