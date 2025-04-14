#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void drawHearttt(int q, int w, int sizeee) {
    // الرسم باستخدام معادلة رياضية لرسم القلب مع تكبير العرض
    for (float t = 0; t < 6.28; t += 0.0001000) {  // التكرار من 0 إلى 2π (360 درجة)
        // معادلة رسم القلب مع تعديل عامل التوسع في المحور الأفقي
        int px = q + sizeee * 18 * pow(sin(t), 3) * 1.3;  // تكبير العرض هنا
        int py = w - sizeee * (18 * cos(t) - 5 * cos(2*t) - 2 * cos(3*t) - cos(4*t));
        
        putpixel(px, py, RED_VALUE(500));  // رسم النقطة باستخدام اللون الأحمر
    }
}

void drawHeart(int x, int y, int size) {
    // الرسم باستخدام معادلة رياضية لرسم القلب مع تكبير العرض
    for (float t = 0; t < 6.28; t += 0.0001000) {  // التكرار من 0 إلى 2π (360 درجة)
        // معادلة رسم القلب مع تعديل عامل التوسع في المحور الأفقي
        int px = x + size * 15 * pow(sin(t), 3) * 1.3;  // تكبير العرض هنا
        int py = y - size * (15 * cos(t) - 5 * cos(2*t) - 2 * cos(3*t) - cos(4*t));
        
        putpixel(px, py, RED_VALUE(500));  // رسم النقطة باستخدام اللون الأحمر
    }
}

void drawHeartt(int z, int a, int sizee) {
    // الرسم باستخدام معادلة رياضية لرسم القلب مع تكبير العرض
    for (float t = 0; t < 6.28; t += 0.0001000) {  // التكرار من 0 إلى 2π (360 درجة)
        // معادلة رسم القلب مع تعديل عامل التوسع في المحور الأفقي
        int px = z + sizee * 10 * pow(sin(t), 3) * 1.5;  // تكبير العرض هنا
        int py = a - sizee * (10 * cos(t) - 5 * cos(2*t) - 2 * cos(3*t) - cos(4*t));
        
        putpixel(px, py, ABM_GETSTATE);  // رسم النقطة باستخدام اللون الأحمر
    }
}

int main() {
    // إعداد بيئة الرسومات
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    // تحديد مكان وحجم القلب
    int centerX = 320, centerY = 240;
    int size = 13;  // زيادة حجم القلب

    // رسم القلب
    drawHearttt(centerX, centerY, size);
    drawHeart(centerX, centerY, size);
    drawHeartt(centerX, centerY, size);
    // إضافة النص تحت القلب
    outtextxy(centerX - 45, centerY + size * -1+5, " ");
    outtextxy(centerX - 35, centerY + size * 1+5, " ");

    // انتظار الضغط على أي مفتاح لإغلاق الرسم
    getch();
    closegraph();

    return 0;
}
