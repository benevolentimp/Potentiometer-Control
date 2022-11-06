int A = 13;
int B = 12;
int C = 11;
int D = 10;
int E = 9;
int F = 8;
int G = 7;
int H = 6;
int output = 0;
int pin = 3;
int ledr = 5;
int ledg = 2;
int ledb = 4;


void setup(void)
{
  //Seven segment display
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  
  //Serial monitor
  Serial.begin(9600);
  
  //RGB Led
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
}

//Functions that implement seven segment display numbers

void reset(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
  analogWrite(ledr, 0);
  analogWrite(ledg, 0);
  analogWrite(ledb, 0);
}

void zero(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void one(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void two(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void three(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void four(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void five(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void six(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void seven(void) {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void eight(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void nine(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

// Main loop
void loop(void)
{
  output = map(analogRead(A0), 0, 1023, 0, 255);
  Serial.println(output);
  analogWrite(pin, output); // Speed (pin 3, npn base) according to result from pot (pin a0)
  
  switch(output) {
    case 127: // 0
    	analogWrite(pin, 0);
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 0);
  		analogWrite(ledb, 255);
    	zero();
    	break;
    
    case 128 ... 143: // 1
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	one();
    	break;
    case 144 ... 159: // 2
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	two();
    	break;
    case 160 ... 175: // 3
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	three();
    	break;
    case 176 ... 191: // 4
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	four();
    	break;
    case 192 ... 207: // 5
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	five();
    	break;
    case 208 ... 223: // 6
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	six();
    	break;
    case 224 ... 239: // 7
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	seven();
    	break;
    case 240 ... 254: // 8
    	analogWrite(ledr, 0);
  		analogWrite(ledg, 255);
  		analogWrite(ledb, 0);
    	eight();
    	break;
    
    case 255: // 9
    	analogWrite(ledr, 255);
  		analogWrite(ledg, 0);
  		analogWrite(ledb, 0);
    	nine();
    	break;
    default:
    	reset();
    	break;
  }
}
