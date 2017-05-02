/*
 * Santa's Workshop program.
 * TODO:
 *  -check all pins 
 *  -separate into cogs
 *    --what needs to be separated?
 *  -add header files to allow for smaller program size
 *    --distribute the songs into a header file and call it "music.h"
*/
#include "simpletools.h" // Include simple tools
#include "servo.h"
#include "wavplayer.h"

//BUTTON PINS
#define marbleToggleID 5
#define trainToggleID 13
#define galleryButtonID 11
#define treeButtonID 9
#define galleryMSwitchID 7

//SERVO PINS
#define marbleServo 17
#define trainServo 16
#define galleryElfServo 12
#define galleryWheelServo 14
#define treeServo 15

//SERVO SPEEDS
#define marbleSpeed 35
#define trainSpeed -35
#define galleryWheelSpeed -25 //needs to be determined via testing
#define galleryWheelRest 0

//SERVO ANGLES
#define treeAngleA 0
#define treeAngleB 1800
#define galleryElfStart 900
#define galleryElfEnd 0

int marbleToggle;
int trainToggle;
int galleryInitButton;
int treeButton;
int ducksSwitch;
int galleryButton;

//void handleOperations(int marbleInput, int trainInput, int galleryInput, int treeInput);
void operateMarbleLift();
void operateTrain();
void operateGallery();
void operateTree();

//using separate cogs 
unsigned int stack[40 + 25];

int main() // Main function
{
  //These declarations are needed to communicate with the SD card.
  int DO = 22, CLK = 23, DI = 24, CS = 25; // SD I/O pins
  sd_mount(DO, CLK, DI, CS); // Mount SD card
  
  while(1)
  {
    servo_angle(galleryElfServo, galleryElfStart);
    //handleOperations(marbleToggleID, trainToggleID, galleryButtonID, treeButtonID);
    
    marbleToggle = input(marbleToggleID);
    trainToggle = input(trainToggleID);
    galleryInitButton = input(galleryButtonID);
    treeButton = input(treeButtonID);
      
    if(marbleToggle == 1)
    {
      //operateMarbleLift();
      //servo_speed(marbleServo, 35);
      cogstart(operateMarbleLift, NULL, stack, sizeof(stack));      
    }
    else if(marbleToggle == 0)
    {
      servo_disable(marbleServo);
    }
    if(trainToggle == 1)
    {
      operateTrain(); 
      //cogstart(operateTrain, NULL, stack, sizeof(stack));
    }
    else if(trainToggle == 0)
    {
      servo_disable(trainServo);
    }
    if(galleryInitButton == 1)
    {
      operateGallery(); 
      //cogstart(operateGallery, NULL, stack, sizeof(stack));      
    }
    if(treeButton == 1)
    {
      //operateTree(); 
      cogstart(operateTree, NULL, stack, sizeof(stack));
    }
    print("%cmarble: %d || train: %d || shooter: %d || tree: %d\n", HOME, marbleToggle, trainToggle, galleryInitButton, treeButton);
    //pause(350);

  }
}
/*void handleOperations(int marbleInput, int trainInput, int shooterInput, int treeInput)
{
  
} */

/*
 * The following methods handle the operations of each individual system. 
 */

//----------------------------------------------------------------------------------------------------------------------------------------------
void operateMarbleLift()
{
  print("marble method called \n");
  servo_speed(marbleServo, marbleSpeed);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void operateTrain()
{
  print("train method called \n");
  servo_speed(trainServo, trainSpeed);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void operateGallery()
{
  //these are all the sound files that we will be using
  const char elf[] = {"elf.wav"};
  const char bell2[] = {"bell2.wav"}; //this file will make santa sound like an elf
  const char bell4[] = {"bell4.wav"}; //this file will result in normal santa
  const char Santa2[] = {"Santa2.wav"}; 
  print("gallery method called \n");

  servo_angle(galleryElfServo, galleryElfEnd);
  pause(2000);

  servo_speed(galleryWheelServo, galleryWheelSpeed);

  //ducksSwitch = input(galleryMSwitch);

  pause(500);

  high(26); //LIGHT LEDs
  wav_play(bell4); // Play bell sound
  wav_volume(10); // Adjust volume
  pause(4000); //allow time for bell sound to play.

  low(26);

  wav_play(Santa2); //play Santa's voice
  wav_volume(10); // Adjust volume
  pause(9000); //allow time for bell sound to play.

  wav_play(elf);
  wav_volume(10);
  pause(4000);

  servo_disable(galleryWheelServo); // stops the wheel.
  servo_angle(galleryElfServo, galleryElfStart); //resets elf for next trial

}

//----------------------------------------------------------------------------------------------------------------------------------------------
void operateTree()
{
  print("tree method called \n");
  
  int pauseTime = 2; //This value controls how fast the tree rotates.
  
  for(int n = 0; n < 1800; n = n + 2)
  {
    servo_angle(treeServo, n);
    pause(pauseTime);
  }
  for(int n = 1700;n>0;n=n-2)
  {
    servo_angle(treeServo,n);
    pause(pauseTime);
  }
  servo_disable(treeServo);  
}
