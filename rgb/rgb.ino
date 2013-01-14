
int low = 0;
int high = 255;
int middle = (high - low) / 2;

#define RED 0
#define GREEN 1
#define BLUE 2

#define OUT 0
#define IN 1

int rgb[3] = { high, low, low };
int hold = RED;

void setup()  { 
  Serial.begin(9600);
} 

void led(int red, int green, int blue) {
  analogWrite(11, red);
  analogWrite(10, blue);
  analogWrite(9,  green); 
}

void blend(int intensity) {
  int next = (hold + 1) % 3;
  int prev = (hold + 2) % 3;
  rgb[hold] = high;
  
  if (intensity < middle) {
    rgb[next] = low;
    rgb[prev] = high - intensity * 2;
  }
  else {
    rgb[next] = (intensity - middle) * 2;
    rgb[prev] = low;
  }
}

void pr(int *c) {
  Serial.print(c[RED]); 
  Serial.print(":");
  Serial.print(c[GREEN]); 
  Serial.print(":");
  Serial.print(c[BLUE]); 
  Serial.println();
}

void loop()  { 
  for(int i = low ; i < high; i += 4) {
    pr(rgb);
    blend(i);
    led(rgb[0], rgb[1], rgb[2]);
    delay(50);                            
  } 
  hold = (hold + 1) % 3;
}






