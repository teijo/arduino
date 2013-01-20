#define END -1
const int rows[] = { A1, 12, A0, 2 /*&& A4*/, 6, 0, 5, END };
const int cols[] = { A5, 4, A3, A2, 1, END };

void resetArray(const int* array) {
  for (const int* pin = array; *pin != END; pin++) {
    pinMode(*pin, OUTPUT);
    digitalWrite(*pin, LOW);
  }
}

void setup() {
  resetArray(rows);
  resetArray(cols);
}

void loop()  {
  for (int i = 0; i < 7; i++) {
    if (i == 3)
        digitalWrite(A4, HIGH);
    digitalWrite(rows[i], HIGH);
    delay(100);
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(cols[i], HIGH);
    delay(100);
    digitalWrite(cols[i], LOW);
  }
  for (int i = 0; i < 7; i++) {
    digitalWrite(rows[i], LOW);
    if (i == 3)
      digitalWrite(A4, LOW);
    delay(100);
  }
}
