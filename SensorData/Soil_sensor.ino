
#define ONEMIN (1000UL * 60 * 1)
#define FIVEMIN (1000UL * 60 * 5)

unsigned long rolltime1 = millis() + ONEMIN;
unsigned long rolltime5 = millis() + FIVEMIN;



void setup() {
  // put your setup code here, to run once:

}

void loop() {



// Stuff we check every 1 minutes

  if((long)(millis() - rolltime1) >= 0) {

   //  Take data from sensors every ONEMIN

   rolltime1 += ONEMIN;
    
 }


 
// Stuff we check every 5 minutes

  if((long)(millis() - rolltime5) >= 0) {

   //  Take data from sensors every FIVEMIN

   rolltime5 += FIVEMIN;
    
 }


 
 
}
