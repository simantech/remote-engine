const int a_input = 10; //input tombol a
const int b_input = 12; //input tombol b  
const int c_input = 9;  //input tombol c
const int d_input = 11; //input tombol d

const int acc_output =  8; //output relay accesories    
const int ign_output = 7; //output relay ignition
const int st_output = 6; //output relay start

int start_state = 0; //safety supaya tidak bisa start 2 kali

int engine_start = 0;
int start_all = 0;
int engine_stop = 0; 

void setup() {
  pinMode(a_input, INPUT);
  pinMode(b_input, INPUT);
  pinMode(c_input, INPUT);
  pinMode(acc_output, OUTPUT);
  pinMode(ign_output, OUTPUT);
  pinMode(st_output, OUTPUT);
}

void loop() {
  engine_start = digitalRead(a_input);
  engine_stop = digitalRead(d_input);
  start_all = digitalRead(b_input);

  
  if (engine_start == 1 & start_state == 0) {
    start_state = 1;
    digitalWrite(ign_output, 1);
    delay(2000); // delay untuk fuel pump 
    digitalWrite(st_output,1);
    delay(1200); // waktu untuk starter
    digitalWrite(st_output,0);
  }
  if (start_all == 1 & start_state == 0) {
    start_state = 1;
    digitalWrite(ign_output, 1);
    delay(2000); //delay untuk fuel pump
    digitalWrite(st_output,1);
    delay(1200); //waktu untuk starter
    digitalWrite(st_output,0);
    delay(1000); //accesories di nyalakan setelah mobil start
    digitalWrite(acc_output,1);
  }
  if (engine_stop == 1) {
    digitalWrite(acc_output, 0); //matikan accesories
    delay(500);
    digitalWrite(ign_output, 0); //matikan ignition
    start_state = 0;
  }
}
