
class TempSwitch
{
  // Class Member Variables
  // These are initialized at startup
  int inPin;      // the number of the Power pin
  long OnTime;     // milliseconds of on-time
  int state;


  // These maintain the current state
  int inState;                    // Define initial State of the DEVICE
  unsigned long previousMillis;   // will store last time DEVICE was updated
  int currentState;

  // Constructor - creates a Temporal Switch 
  // and initializes the member variables and state
  public:
  TempSwitch(int pin, int state)
  {
  inPin = pin;
  pinMode(inPin, OUTPUT);     //Define pin and output
  inState = state;            //Define default State of the DEVICE
  currentState = inState;     //Define current State of the DEVICE as default
  previousMillis = 0;         //SET previousMillis variable to 0
  void Temp(float minutes);  //Temporizator in Minutes, float to make fractions of minutes possible
  int Switch();
  }


   int Switch()
  {
    if (inState == LOW && currentState == inState) //Wanna conect it?
    {
      Serial.print("1");
      currentState = HIGH;               //Set current State as ON
      digitalWrite(inPin, currentState); //Set DEVICE ON
      previousMillis = millis();         //Remember when you did it
      return(currentState);
    }
    if (inState == HIGH && currentState == inState) //Wanna disconect it?
    {
            Serial.print("2");

      currentState = LOW;                //Set current State as OFF
      digitalWrite(inPin, currentState); //Set DEVICE OFF
      previousMillis = millis();         //Remember when you did it
      return(currentState);
    }
  }

  
  void Temp(float minutes)
  {
    float OnTime;
    OnTime = minutes*60000;      //Minutes to milliseconds
    // check to see if it's time to change the state of the DEVICE
    unsigned long currentMillis = millis();
     
    if(currentState != inState  && (currentMillis - previousMillis >= OnTime))
    {
      Serial.print("3");
      currentState = inState;  // Turn it ON/OFF
      digitalWrite(inPin, inState);  // Update the actual DEVICE
    }
  }

};



//////////////////////////////////////////////////////////////////////////////////////////////////////// Arduino //////////////////////////////////////////////////////////////////////////
TempSwitch water(52, HIGH); //Define device status: Pin and InicialState
int turnon=0;

void setup()
{
    // put your setup code here, to run once:
  Serial.begin(9600);
  
}
 
void loop()
{

  if ( turnon == 0 ){
  water.Switch();
  turnon=1; }
  water.Temp(0.06);  //During 1 minute


  
}


