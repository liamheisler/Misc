/*
  Multicore Example.c
 
  Launch a function into another cog (processor) and display what it does
  to the global n variable over time.
*/

#include "simpletools.h"                      // Include simpletools
#include "servo.h"

#define contRotation 17
#define treeServo 16

void adder(void *par);                        // Forward declaration

static volatile int t, n;                     // Global vars for cogs to share
unsigned int stack[40 + 25];                  // Stack vars for other cog

int main()                                    // main function
{
  t = 50;                                     // Set values of t & n
  n = 5000;

  // Launch adder function into another cog (processor).
  cogstart(adder, NULL, stack, sizeof(stack));

  // Watch what the other cog is doing to the value of n.
  while(1)
  {
    int pauseTime = 2; 
    for(int n = 0; n < 1800; n = n + 2)
    {
      servo_angle(treeServo, n);
      pause(pauseTime);
    }
    for(int n = 1700;n>0;n=n-2)
    {
      servo_angle(treeServo,n);
      pause(pauseTime);
    }                           // Wait 1/10 of a second    
  }    
}

// Function that can continue on its
// own if launched into another cog.
void adder(void *par)                         // adder keeps going on its own
{
  while(1)                                    // Endless loop
  {
    servo_speed(contRotation, 45); 
  }                            
}
