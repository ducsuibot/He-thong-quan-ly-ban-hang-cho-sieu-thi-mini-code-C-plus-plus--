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
