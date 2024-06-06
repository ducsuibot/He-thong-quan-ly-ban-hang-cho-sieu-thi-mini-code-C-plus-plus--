// san pham 
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
// nhan vien 
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
