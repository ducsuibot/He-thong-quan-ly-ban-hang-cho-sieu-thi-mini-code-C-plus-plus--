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
