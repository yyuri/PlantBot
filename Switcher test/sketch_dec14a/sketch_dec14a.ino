class Switcher   //Turn on/off a device and set delay time on and off.
{
  // Class Member Variables
  // These are initialized at startup
  int inPin;      // the number of the Power pin
  long OnTime;     // milliseconds of on-time
  long OffTime;    // milliseconds of off-time
 
  // These maintain the current state
  int inState;                 // inState used to set the DEVICE
  unsigned long previousMillis;   // will store last time DEVICE was updated
 
  // Constructor - creates a Switcher 
  // and initializes the member variables and state
  public:
  Switcher(int pin, long on, long off)
  {
  inPin = pin;
  pinMode(inPin, OUTPUT);     
    
  OnTime = on;
  OffTime = off;
  
  inState = LOW; 
  previousMillis = 0;
  }
 
  void Update()
  {
    // check to see if it's time to change the state of the DEVICE
    unsigned long currentMillis = millis();
     
    if((inState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      inState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(inPin, inState);  // Update the actual DEVICE
    }
    else if ((inState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      inState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(inPin, inState);   // Update the actual DEVICE
    }
  }
};

const long lightinterval = 3600000*hoursoflight;
const long darkinterval =  3600000*24-lightinterval;
Switcher light(lightPin, lightinterval, darkinterval);



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
