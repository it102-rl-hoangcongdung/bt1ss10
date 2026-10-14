#include <stdio.h>
#include <string.h>

#define MAX_VE 100
#define MAX_VE_PER_ORDER 4

struct VeBan {
    int maVe;
    char tenKhuVuc[20];
    float giaGoc;
    int isEarlyBird;
};

int datVeConcert(struct VeBan dsVe[], int soLuong, struct VeBan veMoi);
void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong);

int main() {
    struct VeBan dsVe[MAX_VE];
    int soLuong = 0;
    
    printf('=== HỆ THỐNG ĐẶT VÉ CONCERT TICKETBOX ===\n\n');

    struct VeBan ve1 = {101, 'VIP', 2000000.0f, 1};
    struct VeBan ve2 = {102, 'Zone A', 1200000.0f, 0};

    soLuong = datVeConcert(dsVe, soLuong, ve1);
    soLuong = datVeConcert(dsVe, soLuong, ve2);

    printf('\n>>> KẾT QUẢ KIỂM TRA GIỎ HÀNG TRONG MAIN <<<>\n');
    hienThiDanhSachVe(dsVe, soLuong);

    return 0;
}

int datVeConcert(struct VeBan dsVe[], int soLuong, struct VeBan veMoi) {
    if (soLuong >= MAX_VE) {
        printf('[LỖI]: Mảng lưu trữ vé của hệ thống đã đầy!\n');
        return soLuong;
    }
    
    if (soLuong >= MAX_VE_PER_ORDER) {
        printf('[LỖI]: Vượt quá hạn ngạch tối đa %d vé cho phép trong một đơn hàng!\n', MAX_VE_PER_ORDER);
        return soLuong;
    }

    if (veMoi.isEarlyBird == 1) {
        veMoi.giaGoc = veMoi.giaGoc * 0.85f;
    }

    dsVe[soLuong] = veMoi;
    soLuong++;
    printf('[THÀNH CÔNG]: Đã thêm vé %d (%s) vào đơn hàng.\n', veMoi.maVe, veMoi.tenKhuVuc);
    
    return soLuong;
}

void hienThiDanhSachVe(const struct VeBan dsVe[], int soLuong) {
    if (soLuong == 0) {
        printf('[THÔNG BÁO]: Hiện chưa có vé nào được đặt thành công trong hệ thống!\n');
        return;
    }
    
    printf('--- DANH SÁCH VÉ ĐÃ ĐẶT (%d vé) ---\n', soLuong);
    for (int i = 0; i < soLuong; i++) {
        printf('STT: %d | Mã vé: %d | Khu vực: %s | Giá thanh toán: %.0f VND\n',
               i + 1, dsVe[i].maVe, dsVe[i].tenKhuVuc, dsVe[i].giaGoc);
    }
}