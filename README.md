# Kit Relay Memory

> Thông tin khách hàng:
> - ...

## Về Version 1

### Yêu cầu

...

## Danh sách phần cứng

1. [HFE10-2-12-HT-L2 Rơ Le SPST 12VDC 50A](https://www.thegioiic.com/hfe10-2-12-ht-l2-ro-le-spst-12vdc-50a).
2. [Mạch Opto Cách Ly 4 Kênh TLP281](https://hshop.vn/products/mach-opto-coch-ly-4-kenh).
3. [Mạch mở rộng I2C WaveShare PCF8574](https://nshopvn.com/product/mach-mo-rong-i2c-waveshare-pcf8574/).
4. [2.8" Touch Display Module For Pico Resistive Touch Controller XPT2046, ST7789 Driver](https://pivietnam.com.vn/28inch-touch-display-module-for-raspberry-pi-pico-pivietnam-com-vn.html).
5. [Kit phát triển ESP32 ESCREEN](https://shope.ee/5ztDiIupN3).

## Sơ đồ kết nối

### 1. Relay nhớ (HFE10-2-12-HT-L2)

> Thông số kỹ thuật:
> - Type: HFE10
> - Version: `(2)` - No auxiliary convexity, with manual switch
> - Coil Voltage: Điện áp kích coil 12VDC
> - Contact Form: `(H)` - 1 Form A (SPST)
> - Sort: `(L2)` - Double coils latching

Sử dụng chế độ **(Negative Polarity)**, trong đó:
- Chế độ *"set"*
  - Input kích chân `1(+) và 5(-)`
  - Output chân `(4) và (3) kết nối`
- Chế độ *"reset"*
  - Input kích chân `2(+) và 5(-)`
  - Output chân `(4) và (3) ngắt kết nối`

Lợi ích của chế độ này, là các chân khi ở trạng thái bình thường ko có kết nối điều khiển, nó sẽ ở trạng thái *"lơ lửng"* và thường là **mức LOW**.

Chính vì vậy khi dùng ở chế độ này, tất cả chân **(1)**, **(2)** và cả chân chung **(5)** đều ở **mức LOW**, như lúc Relay còn cầm trên tay.

Điều này giúp cho các cuộn Relay ở trạng thái nghỉ hoàn toàn.

    Một số lưu ý:
    _ Không cấp điện áp cho cuộn "set" và cuộn "reset" đồng thời.
    _ Để duy trì trạng thái "set" hoặc "reset"
      . Điện áp cấp cho cuộn dây phải đạt điện áp định mức (tức 12VDC).
      . Độ rộng xung phải lớn hơn 5 lần so với thời gian "set" hoặc "reset" (cụ thể 50ms * 5 = 250ms).
    _ Nên tránh thời gian cấp điện cho các cuộn dây lâu (hơn 1 phút).

### 2. Opto cách ly (TLP281)

> Nguồn tài liệu:
> [Interfacing TLP281 4-Channel Opto-isolator IC Module with Arduino](https://electropeak.com/learn/interfacing-tlp281-4-channel-opto-isolator-ic-module-with-arduino/).

> Thông số kỹ thuật:
> - Input 3.3~5VDC
> - Output 0~24VDC

_ Mạch Opto này, khi bên **IN** kích `HIGH` bên **OUT** cũng sẽ xuất mức `HIGH`.<br>_ Và ngược lại, khi bên **IN** kích `LOW` bên **OUT** sẽ xuất mức `LOW`.

    Cảnh báo:
    → "Do not connect the ground of low-voltage section to the ground of high-voltage section"
    |
    Tức GND của bên INPUT và GND của bên OUTPUT phải ko được nối chung?

### 3. Mạch mở rộng I2C (PCF8574)

> Nguồn tài liệu:
> - ...

> Thông số kỹ thuật:
> - ...

### 4. Màn hình 2.8 Inch (ST7789)

> Nguồn tài liệu:
> - [RGB565 Color Picker](https://www.barth-dev.de/online/rgb565-color-picker/).
> - |
> - [GUIslice](https://github.com/ImpulseAdventure/GUIslice).
> - [XPT2046_Touchscreen](https://github.com/PaulStoffregen/XPT2046_Touchscreen).
> - [GUIslice  0.16.0
Embedded GUI in C](https://impulseadventure.github.io/GUIslice/index.html).
> - |
> - [LVGL](https://lvgl.io/).
> - [lvgl/lvgl](https://github.com/lvgl/lvgl).
> - |
> - [ESP32 | LittlevGL | Arduino IDE - [Part.0] Touch Display Setup for Simple Note App📝](https://www.youtube.com/watch?v=OXUZEHMFFwc&list=RDCMUCRr2LnXXXuHn4z0rBvpfG7w&index=4&ab_channel=ThatProject).

> Thông số kỹ thuật:
> - Resolution: **320*240** - Rộng x Cao (px).
> - Touch Driver: **XPT2046** (res).

> Cấu hình: tất cả cấu hình nằm trong **[...\Kit_RelayMemory\config]**
> - Bên **AE Maker** có gửi file thư viện **TFT_eSPI** với cấu hình cho riêng phần cứng **Kit phát triển ESP32 ESCREEN** của họ (`TFT_eSPI_ESP32 of AE Maker.rar`).
> - Để sử dụng thư viện **GUIslice** cần cấu hình file `GUIslice_config.h` trong đường dẫn *"C:\Users\TRUNG\Documents\Arduino\libraries\GUIslice\src"* với cấu hình từ file `esp-tftespi-default-xpt2046_int.h`.
> - Với UI Image trong GUIslice Builder, mình cấu hình dùng **PROGMEM** nên sẽ cần thêm 1 file .c của img đó vào thư mục dự án. File này được tạo từ công cụ [GUIslice_Image2C](https://github.com/Pconti31/GUIslice_Image2C).

    *** TFT_eSPI → Generic → Touch_calibrate ***
    |
    Use this calibration code in setup():
    uint16_t calData[5] = { 210, 3480, 370, 3370, 1 };
    tft.setTouch(calData);

    *** GUIslice → arduino → diag_ard_touch_calib ***
    |
    #define ADATOUCH_X_MIN 3891
    #define ADATOUCH_X_MAX 146
    #define ADATOUCH_Y_MIN 227
    #define ADATOUCH_Y_MAX 3800
    #define ADATOUCH_REMAP_YX 0

### 5. ESP32

> Nguồn tài liệu:
> - [Welcome to ESP32 Arduino Core’s documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/index.html).
> - |
> - [Windows XP on ESP32](https://www.youtube.com/watch?v=J3o-_SYOqTo&ab_channel=AEMaker).
> - [AnimatedGIF Library](https://github.com/bitbank2/AnimatedGIF).
> - [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI).
> - [TFT_eWidget](https://github.com/Bodmer/TFT_eWidget).
> - |
> - [CREATING OUR FIRST ESP32 FLIGHT DISPLAY GRAPHICS](https://www.bitsanddroids.com/creating-our-first-esp32-flight-display-graphics/).

> Thông số kỹ thuật:
> - Chipset: ESPRESSIF-ESP32 240MHz Xtensa® Dual-Core 32-bit LX6
> -	Bộ nhớ FLASH: QSPI Flash 4MB
> -	SRAM: 520 KB SRAM