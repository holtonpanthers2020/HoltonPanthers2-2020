WALLABY

#include <kipr/botball.h>
#include <stdio.h>
#define left_motor 2 //left motor in 2
#define right_motor 0 //right motor in 0
//servo in servo port 2
//for claw orange on top
// when sensing black tape value is 3800
// on wood part of ramp value is 1000
// on bumpy white part value is 1400

int align() //scan left and right until find black line 
{
    int ticks = 0; //establish tick count 
    while (analog(0) < 1600 && ticks < 300) //if white 
    {
        mrp(0, 100, 2); //turn right 
        mrp(2, 100, -2);
        bmd(0);
        bmd(2);
        ticks += 10; //keeps track of how many ticks turned 
    }
    if (analog(0) < 1800) //if still white 
    {
        ticks = 0; //reset tick count 
        while (analog(0) < 1600 && ticks < 600) //if white 
    	{
        	mrp(0, 100, -2); //turn left 
        	mrp(2, 100, 2);
        	bmd(0);
        	bmd(2);
        	ticks += 10; //keeps track of how many ticks turned 
    	}
    } 
    return 0;
}



int turn (int ticks) // function for turning left/right (+ = left, - = right)
{
    if (ticks > 0) // if we are turning to the right
    {
    	mrp(right_motor, 520, ticks); // moving right motor
		mrp(left_motor, -500, ticks); // moving left motor
    	bmd(right_motor);
    	bmd(left_motor);
    }
    if (ticks < 0) // if we are turning to the left
    {
        mrp(right_motor, -520, ticks); // moving right motor
        mrp(left_motor, 500, ticks); // moving left motor
        bmd(right_motor);
        bmd(left_motor);
    }
    return 0;
}

int forward (int ticks) // moving forward/backward; negative milliseconds backwards, positive milliseconds means forwards
{
    int clawPosition = get_servo_position(2);
    if (ticks < 0) // moving backwards
    {
        if (clawPosition == 360) // allows robot to move backwards while claw is straight
        {
        	mrp(right_motor, 518, ticks); // moving right motor
	 		mrp(left_motor, 520, ticks); // moving left motor
        	bmd(right_motor);
        	bmd(left_motor);
        }
        
        if (clawPosition == 80) // allows robot to move backward while claw is open
        {
            mrp(right_motor, 510, ticks); // moving right motor
            mrp(left_motor, 520, ticks); // moving left motor
            bmd(right_motor);
            bmd(left_motor);
        }
        if (clawPosition == 500) // allows robot to move backward while claw is closed
        {
            mrp(right_motor, 510, ticks); // moving right motor
        	mrp(left_motor, 520, ticks); //moving left motor
        	bmd(right_motor);
        	bmd(left_motor);
        }
    }
    if (ticks > 0) // moving forwards
    {
        if (clawPosition == 360) // allows robot to move forward while claw is straight
        {
            mrp(right_motor, -510, ticks); // moving right motor 
            mrp(left_motor, -520, ticks); // moving left motor; v would be the same here as it would be up there
            bmd(right_motor);
            bmd(left_motor);
        }
        if (clawPosition == 80) // allows robot to move forward while claw is open
        {
            mrp(right_motor, -510, ticks); // moving right motor
        	mrp(left_motor, -520, ticks); // moving left motor
        	bmd(right_motor);
        	bmd(left_motor);
        }
        if (clawPosition == 500) // allows robot to move forward while claw is closed
        {
            mrp(right_motor, -510, ticks); // moving right motor
            mrp(left_motor, -520, ticks); //moving left motor
            bmd(right_motor);
            bmd(left_motor); 
        }
    }
    return 0;
}

 int claw (int open) // creating a function to open the door or close it; positive means that it is opening, negative means that it is closing
{
	if (open > 0) // to open the door
		{
		enable_servos(); // turns servo on
		set_servo_position(2, 80); // opens the door
        msleep(1200); // gives time for servos to move
		disable_servos(); // turns servos off
		}
	if (open < 0) // to close the door
		{
		enable_servos(); // turns servo on
		set_servo_position(2, 500); // closes the door
        msleep(1200); // gives time for servos to move
		}
    if (open == 0) //arm straight
    	{
        enable_servos(); //turns servo on
        set_servo_position(2,360); //puts door straight
        msleep(1200); //time for servos to move
    	}
	return 0; 
}

int main()
{
    wait_for_light(5);
    printf("i can see the light\n");
    shut_down_in(300);
	claw(0);
	mrp(0,300,3330); //move forward from starting box 
	mrp(2,300,3330);
	bmd(0);
	bmd(2);
	mrp(0,300,1550); //turning toward pipe 
	mrp(2,300,500);
	bmd(0);
	bmd(2);    
	claw(1); //open claw 
    mrp(0,300,1000); //moving forward to grab the pipe 
	mrp(2,300,1000);
	bmd(0);
    bmd(2);
	claw(-1); //close claw 
	mrp(0,1300,-2000); //moving back and pulling the pipe back 
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 2 
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 3 
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 4
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 5
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 6
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 7
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 8
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 9
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 10
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
    mrp(0,1300,-2000); //moving back and pulling the pipe back 11
	mrp(2,1300,-2000);
	bmd(0);
	bmd(2);
	mrp(0,1300,-1400); //turn back
    mrp(2,1300,600);
	bmd(0);
    bmd(2);
	mrp(0,300,-2000); //moving back to starting box 
	mrp(2,300,-2000);
	bmd(0);
	bmd(2);
	mrp(0,300,1500); //turning to drop the pipe 
	bmd(0);
	mrp(0,300,1200); //move forward 
	mrp(2,300,1200);
	bmd(0);
	bmd(2); 
	claw(1); //claw opens and drops pipe 
	mrp(0,300,-1200); //moves back 
	mrp(2,300,-1200);
	bmd(0);
	bmd(2); 
	claw(0); //claw close
	mrp(0,300,-1000); 

    
set_servo_position(2,730);  
    while (!digital(0))
   {
       if (analog(0)<1500) 
       { 
          align(); 
         	printf("we are looking for the black line\n");
          
       }
      if (analog(0)>1500)
      {
          printf("we found the black line\n");
          mav(0,300);
          mav(2,300);
      }
   }
mrp(0,300,-200);
mrp(2,300,-200);
bmd(0); 
bmd(2);
mrp(0,300,1000);
bmd(0);
mrp(0,300,300);
mrp(2,300,200);
bmd(0);
bmd(2);
     while (!digital(0))
   {
       if (analog(0)<1500) 
       { 
          align(); 
         	printf("we are looking for the black line\n");
          
       }
      if (analog(0)>1500)
      {
          printf("we found the black line\n");
          mav(0,300);
          mav(2,300);
      }
   }

    
ao();
return 0;
}





