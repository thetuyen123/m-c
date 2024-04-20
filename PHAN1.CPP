#include <iostream>
#include <string>

int main() {
    // Phần 1: Khai báo và khởi tạo mảng chứa chuỗi MSSV
    char arrayMSSV[5][11] = {"", "2301CT1234", "2302CT3456", "2305CT3999", "2304CT0002"};

     // Phần 2: Yêu cầu người dùng nhập MSSV vào phần tử đầu tiên của mảng
    std::cout << "Nhap MSSV cua ban: ";
    std::cin >> arrayMSSV[0];

    // Phần 3: In mảng theo thứ tự mặc định của nó
    std::cout << "Mang sau khi nhap:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "MSSV " << i << ": " << arrayMSSV[i] << std::endl;
    }

     // Phần 4: Sắp xếp mảng theo yêu cầu
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 - i; ++j) {
            // So sánh MSSV theo chỉ số và chỉ số đuôi
            if (std::string(arrayMSSV[j]).substr(0, 4) > std::string(arrayMSSV[j + 1]).substr(0, 4) ||
                (std::string(arrayMSSV[j]).substr(0, 4) == std::string(arrayMSSV[j + 1]).substr(0, 4) &&
                 std::string(arrayMSSV[j]).substr(7) > std::string(arrayMSSV[j + 1]).substr(7))) {
                std::swap(arrayMSSV[j], arrayMSSV[j + 1]);
            }
        }
    }

    std::cout << "\nMang sau khi sap xep:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "MSSV " << i << ": " << arrayMSSV[i] << std::endl;
    }

    // Phần 5: Tìm địa chỉ của phần tử chứa MSSV lớn nhất
    char *ptrMaxMSSV = arrayMSSV[0];
    for (int i = 1; i < 5; ++i) {
        if (std::string(arrayMSSV[i]) > std::string(ptrMaxMSSV)) {
            ptrMaxMSSV = arrayMSSV[i];
        }
    }

    std::cout << "\nDia chi cua phan tu chua MSSV lon nhat: " << static_cast<void*>(ptrMaxMSSV) << std::endl;
    std::cout << "Gia tri cua phan tu do: " << ptrMaxMSSV << std::endl;

    return 0;
}