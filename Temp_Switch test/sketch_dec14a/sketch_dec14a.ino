
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
 
  void Temp(float minutes)
  {
    float OnTime;
    OnTime = minutes*60000;      //Minutes to milliseconds
    // check to see if it's time to change the state of the DEVICE
    unsigned long currentMillis = millis();
     
    if(currentState != inState  && (currentMillis - previousMillis >= OnTime))
    {
      currentState = inState;  // Turn it OFF
      digitalWrite(inPin, currentState);  // Update the actual DEVICE
    }
  }
  int Switch()
  {
    if (inState == LOW) //Wanna conect it?
    {
      currentState = HIGH;               //Set current State as ON
      digitalWrite(inPin, currentState); //Set DEVICE ON
      previousMillis = millis();         //Remember when you did it
      return(currentState);
    }
    if (inState == HIGH) //Wanna disconect it?
    {
      currentState = LOW;                //Set current State as OFF
      digitalWrite(inPin, currentState); //Set DEVICE OFF
      previousMillis = millis();         //Remember when you did it
      return(currentState);
    }
  }
};

TempSwitch water(1, LOW); //Define device status: Pin and InicialState


void setup()
{
    // put your setup code here, to run once:

}
 
void loop()
{
    // put your main code here, to run repeatedly:

  water.Switch(); //Turn on waterpump
  water.Temp(1);  //During 1 minute
}


