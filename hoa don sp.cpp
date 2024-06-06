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
