    /* SimpleToggle_PB_LED */
    // Added code to turn on LED on startup

#define LEDpin 3
#define SWITCHpin 2

byte LEDstate = HIGH;  //Set to turn on LED
byte SWITCHstate;
byte lastSWITCHstate = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(LEDpin, OUTPUT);
pinMode(SWITCHpin, INPUT);
digitalWrite(SWITCHpin, HIGH);
digitalWrite(LEDpin, LEDstate); //Turn on LED
}


void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(SWITCHpin);
 
  if (reading != lastSWITCHstate) {
    lastDebounceTime = millis();
  }
 
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != SWITCHstate) {
        SWITCHstate = reading;
  
        if (SWITCHstate == HIGH) {
          LEDstate = !LEDstate;
        }
      } 
  }
  if ((lastSWITCHstate == HIGH) && (SWITCHstate == LOW))
  {
      digitalWrite(LEDpin, LEDstate);
      
  }
lastSWITCHstate = SWITCHstate;
}
