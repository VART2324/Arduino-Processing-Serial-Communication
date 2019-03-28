//------------------------------------------------------------

int potPin = A0; // potentiometer on analog pin A0
int touchPin = 7; // touch sensor on digital pin D7

int potVal; // for data from the potentiometer
int touchVal; // for data from the touch sensor

// three characters used for Serial communication
char START_BYTE = '*';
char DELIMITER = ',';
char END_BYTE = '#';

//------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // begin serial communication at 9600 baud rate
  digitalWrite(touchPin, HIGH); // set the internal pullup resistor to HIGH
  establishContact(); // send a byte to establish contact until receiver responds
}

//------------------------------------------------------------

void loop() {
  // put your main code here, to run repeatedly:
  
  potVal = analogRead(potPin); // assign potPin input to potVal
  touchVal = digitalRead(touchPin); // assign touchPin input to touchVal

  
  Serial.write(START_BYTE); // start of input data being communicated...
  Serial.print(DELIMITER); // send comma
  
  Serial.print(potVal); // communicate data from potVal variable
  Serial.print(DELIMITER); // send comma

  Serial.print(touchVal); // communicate data from touchVal variable
  Serial.print(DELIMITER); // send comma

  Serial.write(END_BYTE); // communicate that communication has ended  
  Serial.println(); // send a carriage return
}

//------------------------------------------------------------

void establishContact(){
  // while there is zero (or less) serial communication
  // keep sending "hello" until the computer responds to the Arduino
  while(Serial.available() <= 0){
    Serial.println("hello");
    delay(300);
  }
}

//------------------------------------------------------------
