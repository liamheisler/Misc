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
#include "music.h"
#include "wavplayer.h"

//BUTTON PINS
#define marbleToggleID 7 //originally was 5
#define trainToggleID 13
#define galleryButtonID 11
#define treeButtonID 9
//#define galleryMSwitchID 7

//SERVO PINS
#define marbleServo 17
#define trainServo 16
#define galleryElfServo 12
#define galleryWheelServo 14
#define treeServo 15

//LED/MISC PINS
#define elfLEDID 5
#define servoAngularIncrement 10

//SERVO SPEEDS
#define marbleSpeed 35
#define trainSpeed -35
#define galleryWheelSpeed -5 //needs to be determined via testing
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
unsigned int stack1[40 + 25];
unsigned int stack2[40 + 25];
unsigned int stack3[40 + 25];
unsigned int stack4[40 + 25];
unsigned int stack5[40 + 25];
unsigned int stack6[40 + 25];

int *marbleCog;
int *trainOperationCog;
int *trainMusicCog;
int *galleryCog;
int *treeOperationCog;
int *treeMusicCog;  

int stackSize = 10;

int main() // Main function
{
  //These declarations are needed to communicate with the SD card.
  int DO = 22, CLK = 23, DI = 24, CS = 25; // SD I/O pins
  sd_mount(DO, CLK, DI, CS); // Mount SD card
  
  while(1)
  {
    /*for(int x = 0; x < galleryElfStart; x += servoAngularIncrement) 
    {
      servo_angle(galleryElfServo, x);
      pause(2); //ms
    } */ 
    servo_angle(galleryElfServo, galleryElfStart); 
    //handleOperations(marbleToggleID, trainToggleID, galleryButtonID, treeButtonID);
    
    marbleToggle = input(marbleToggleID);
    trainToggle = input(trainToggleID);
    galleryInitButton = input(galleryButtonID);
    treeButton = input(treeButtonID);
      
    if(marbleToggle == 1)
    {
      operateMarbleLift();    
    }
    else if(marbleToggle == 0)
    {
      servo_disable(marbleServo);
    }
    if(trainToggle == 1)
    {
      //cogstart(&silentNight, NULL, stack, sizeof(stack)); //start playing o' christmas tree...
      operateTrain(); 
    }
    else if(trainToggle == 0)
    {
      servo_disable(trainServo);
    }
    if(galleryInitButton == 1)
    {
      operateGallery();    
    }
    if(treeButton == 1)
    {
      //cogstart(&christmasTree, NULL, stack, sizeof(stack)); //start playing o' christmas tree...
      operateTree(); 
    }
    print("marble: %d || train: %d || shooter: %d || tree: %d\n", marbleToggle, trainToggle, galleryInitButton, treeButton);
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
  //print("marble method called \n");
  servo_speed(marbleServo, marbleSpeed);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void operateTrain()
{
  //print("train method called \n");
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
  //print("gallery method called \n");

  for(int x = galleryElfStart; x > 0; x -= servoAngularIncrement) 
  {
    servo_angle(galleryElfServo, x);
    pause(2); //ms
  }
  pause(750);

  servo_speed(galleryWheelServo, galleryWheelSpeed);

  //ducksSwitch = input(galleryMSwitch);

  pause(500);

  high(elfLEDID); //LIGHT LEDs
  wav_play(bell4); // Play bell sound
  wav_volume(10); // Adjust volume
  pause(4000); //allow time for bell sound to play.

  low(elfLEDID);

  wav_play(Santa2); //play Santa's voice
  wav_volume(10); // Adjust volume
  pause(9000); //allow time for bell sound to play.

  wav_play(elf);
  wav_volume(10);
  pause(4000);

  servo_disable(galleryWheelServo); // stops the wheel.
  for(int x = 0; x < galleryElfStart; x += servoAngularIncrement) 
  {
    servo_angle(galleryElfServo, x);
    pause(2); //ms
  } 
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void operateTree()
{
  //print("tree method called \n");
  //treeMusicCog = cog_run(&christmasTree, 10); 
  int pauseTime = 2; //This value controls how fast the tree rotates.
  
  for(int n = 0; n < 1800; n = n + 2)
  {
    servo_angle(treeServo, n);
    pause(pauseTime);
  }
  for(int n = 1700; n > 0 ; n = n - 2)
  {
    servo_angle(treeServo,n);
    pause(pauseTime);
  }
  servo_disable(treeServo); 
}
