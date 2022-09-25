// Program untuk menentukan posisi end-effector
// Sumber: https://github.com/cgxeiji/CGx-InverseK

// library InverseK.h
#include <InverseK.h>

void setup() {
  // Setup limit lengths dan rotation limits untuk masing-masing link
  
  Link base, lengan1, lengan2, lengan3; // terdapat 4 DOF
  
  // .init(_length_, _min_angle_, _max_angle_);
  // angle (sudut) dalam radian, length (panjang) dalam mm
  base.init(0, b2a(0.0), b2a(180.0));
  lengan1.init(200, b2a(15.0), b2a(165.0));
  lengan2.init(200, b2a(0.0), b2a(180.0));
  lengan3.init(270, b2a(0.0), b2a(180.0));

  // Attach the links to the inverse kinematic model
  InverseK.attach(base, lengan1, lengan2, lengan3);

  float a0, a1, a2, a3; // terhubung dengan motor servo
  
  // InverseK.solve(x, y, z, a0, a1, a2, a3, phi) 
  // InverseK.solve() mengembalikan nilai TRUE atau FALSE
  if(InverseK.solve(300, 0, 50, a0, a1, a2, a3, 0.54 )) {
    Serial.print(a2b(a0)); Serial.print(',');
    Serial.print(a2b(a1)); Serial.print(',');
    Serial.print(a2b(a2)); Serial.print(',');
    Serial.println(a2b(a3));
  } 
  else {
    Serial.println("Tidak ada solusi");
  }
}

void loop() {

}
// Konversi radian
float a2b(float a) {
  return (a + HALF_PI) * 180 / PI;
}
