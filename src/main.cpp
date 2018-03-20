#include <Arduino.h>
#include <WaveHC.h>
#include <WaveUtil.h>

SdReader card;    // This object holds the information for the card
FatVolume vol;    // This holds the information for the partition on the card
FatReader root;   // This holds the information for the volumes root directory
FatReader file;   // This object represent the WAV file for a pi digit or period
WaveHC wave;      // This is the only wave (audio) object, since we will only play one at a time

/*
 * print error message and halt if SD I/O error
 */
void sdErrorCheck(void) {
  if (!card.errorCode()) return;
  PgmPrint("\r\nSD I/O error: ");
  Serial.print(card.errorCode(), HEX);
  PgmPrint(", ");
  Serial.println(card.errorData(), HEX);
  while(1);
}

/*
 * print error message and halt
 */
void error_P(const char *str) {
  PgmPrint("Error: ");
  SerialPrint_P(str);
  sdErrorCheck();
  while(1);
}

/*
 * Open and start playing a WAV file
 */
void playfile(char *name) {
  if (wave.isplaying) {// already playing something, so stop it!
    wave.stop(); // stop it
  }
  if (!file.open(root, name)) {
    PgmPrint("Couldn't open file ");
    Serial.print(name); 
    return;
  }
  if (!wave.create(file)) {
    PgmPrintln("Not a valid WAV");
    return;
  }
  // ok time to play!
  wave.play();
}

/*
 * Define macro to put error messages in flash memory
 */
#define error(msg) error_P(PSTR(msg)) 

const int switches[3] = {A0,A1,A2};
byte switchStates;

void setup() {
  // set up Serial library at 9600 bps
  Serial.begin(9600);           
  
  PgmPrintln("Preuterbox wav player");

  for (int i=0; i < 3; i++){
    pinMode(switches[i], INPUT_PULLUP);
  }

  if (!card.init()) {
    error("Card init. failed!");
  }
  if (!vol.init(card)) {
    error("No partition!");
  }
  if (!root.openRoot(vol)) {
    error("Couldn't open dir");
  }

  PgmPrintln("Files found:");
  root.ls();

}

void loop() {
  bool changed = false;
  for (int i=0; i < 3; i++){
    int switchState = digitalRead(switches[i]);
    if (switchState != bitRead(switchStates,i)) {
      changed = true; 
      bitWrite(switchStates,i,switchState);
    } 
   }
   if (changed || !wave.isplaying) {
    switch (int(switchStates)) {
      case 0:
        if (wave.isplaying) {
          wave.stop();
        }
        break;
      case 1:
        playfile("01.WAV");
        break;
      case 2:
        playfile("02.WAV");
        break;
      case 3:
        playfile("03.WAV");
        break;
      case 4:
        playfile("04.WAV");
        break;
      case 5:
        playfile("05.WAV");
        break;
      case 6:
        playfile("06.WAV");
        break;
      case 7:
        playfile("07.WAV");
        break;
    }  
  }
  delay(1000);
}