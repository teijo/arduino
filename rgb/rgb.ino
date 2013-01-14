
const int low = 0;
const int high = 255;
const int middle = (high - low) / 2;

void setup() { }

void led(int* rgb) {
  analogWrite(11, rgb[0]);
  analogWrite(10, rgb[1]);
  analogWrite(9,  rgb[2]);
}

void blend(int intensity, int* rgb, int hold) {
  int* next = &rgb[(hold + 1) % 3];
  int* prev = &rgb[(hold + 2) % 3];

  rgb[hold] = high;

  if (intensity < middle) {
    *next = low;
    *prev = high - intensity * 2;
  }
  else {
    *next = (intensity - middle) * 2;
    *prev = low;
  }
}

void loop()  {
  static int rgb[3] = { high, low, low };
  static int hold = 0;

  for (int i = low ; i < high; i++) {
    blend(i, rgb, hold);
    led(rgb);
    delay(5);
  }

  hold = (hold + 1) % 3;
}
