#include <kipr/botball.h>


void forward(int inches){ //in inches
    int milimeters = inches*25.4;
    set_create_distance(0);
    while(get_create_distance() < milimeters){ // milimeters
        create_drive_direct(99,96);
    }
    create_stop();
         printf("go forward %d inches\n", inches);
	
    double actualDIST=(double) get_create_distance();
    printf("final distance is :%lf\n", actualDIST);
}

void backwards(int inches){ //in inches
    int milimeters = inches*25.4;
    set_create_distance(0);
    while(get_create_distance() < milimeters){ // milimeters
        create_drive_direct(-99,-96);
    }
    create_stop();
         printf("go forward %d inches\n", inches);
	
    double actualDIST=(double) get_create_distance();
    printf("final distance is :%lf\n", actualDIST);
}


void Turn_Left (double angle) {
    set_create_total_angle(0);
    double actualANG = 0;
    while (actualANG<angle) {
    create_drive_direct (-34, 30);
   msleep(1000);
    //printf("%lf\n", actualANG);
    actualANG=(double) get_create_total_angle();
    }
    printf("final angle is :%lf\n", actualANG);
}

void Turn_Right (double angle) {
set_create_total_angle(0);
    double actualANG = 0;
    while (actualANG>-angle) {
        create_drive_direct (34, -40);
        msleep(50);
        //printf("%lf\n", actualANG);
        actualANG=(double) get_create_total_angle();
    }
    printf("final angle is :%lf\n", actualANG);
}

int align()
{
    int ticks = 0; //establish tick count
    while (analog(0) < 1600 && ticks < 300) //if white
    {
        create_drive_direct(-68, 95.999);
        msleep(50);
        ticks += 10; //keeps track of how many ticks turned
    }
    if (analog(0) < 1800)
    { 
        while (analog(0) < 1800 && ticks < 600) //if still white
        {
            create_drive_direct(68, -95.999);
            msleep(50);
            ticks += 10; 
        }
    }
    return 0;
}

int main()
{
	
    create_connect();
    
    /*
    //moving towards astronauts from starting box
	while ((get_create_rbump() == 0) && (get_create_lbump() == 0))
    {
          if(analog(0)<1500)
        {
            align();
            printf("we are looking for the black line\n");
        }
        if(analog(0)>1500)
        {
            printf("we found the black line\n");
            create_drive_direct(34, 30);
            msleep(5);
            get_create_lbump();
        }
    }
    
    //Moving backwards to prep for turn
  	 create_drive_direct(-68, -95.999);
        msleep(1103); //note to future self: test this value
    
   //lining up to turn right 
    while(analog(0)>1500)
    {
        create_drive_direct(34, -40);
        msleep(5);
    }
    
    
    //Turning right w/ correction
    create_drive_direct(-34, 40);
    msleep(6);
    Turn_Right(90);
    
    //Moving Forward to collect astronauts and then moving backwards to go back to starting box
    forward(20);
    msleep(100);
    
    */
        //moving backwards until hits black line
        while(analog(0)<1500)
        {
            printf("we're looking for the black line\n");
            create_drive_direct(-34, -40);
            msleep(5);
        }

        //moving backwards to get in line for turn
        create_drive_direct(-99, -96);
    	msleep(1103);
    
    //turning to go on black line
    while(analog(0)<1500)
    {
        printf("turning to hit black line\n");
        create_drive_direct(34, -40);
        msleep(5);
    }
            
    /*
    //moving back to starting box; hits PVC pipe and then stops
    while ((get_create_rbump() == 0) && (get_create_lbump() == 0))
    {
          if(analog(0)<1500)
        {
            align();
            printf("we are looking for the black line\n");
        }
        if(analog(0)>1500)
     {
            printf("we found the black line\n");
            create_drive_direct(34, 30);
            msleep(5);
            get_create_lbump();
        }
    }
    
    
     //Moving backwards to prep for turn
  	 create_drive_direct(-68, -95.999);
     msleep(1103); //note to future self: test this value
    
    //lining up to turn right
    while(analog(0)>1500)
    {
        create_drive_direct(34, -40);
        msleep(5);
    }
    
    //Turning right w/ correction
    create_drive_direct(-34, 40);
    msleep(6);
    Turn_Right(90);
    
    //moving back into starting box so that we're done :)
   	forward(7); //note to future self: test this value 
    
    */
create_disconnect(); //we done :)
return 0;

}





 

OLD
#include <kipr/botball.h>

void Forward (double distance) {
    set_create_distance(0);
    double actualDIST = 0;
    while (actualDIST<distance) {
        create_drive_direct(68, 95.999);
        msleep(490);
        
        //printf("%lf\n", actualDIST);
        actualDIST=(double) get_create_distance();
    }   
    printf("final distance is :%lf\n", actualDIST);
}

void Backwards (double distance) {
set_create_distance(0);
    double actualDIST = 0;
    while (actualDIST>distance) {
    create_drive_direct(-68, -95.999);
        msleep(50);
        create_drive_direct(-67, -100);
        msleep(144);
        //printf("%lf\n", actualDIST);
        actualDIST=(double) get_create_distance();
    }
    printf("final distance is :%lf\n", actualDIST);
}

void Turn_Left (double angle) {
    set_create_total_angle(0);
    double actualANG = 0;
    while (actualANG<angle) {
    create_drive_direct (-34, 30);
   msleep(1000);
    //printf("%lf\n", actualANG);
    actualANG=(double) get_create_total_angle();
    }
    printf("final angle is :%lf\n", actualANG);
}

void Turn_Right (double angle) {
set_create_total_angle(0);
    double actualANG = 0;
    while (actualANG>-angle) {
        create_drive_direct (34, -40);
        msleep(50);
        //printf("%lf\n", actualANG);
        actualANG=(double) get_create_total_angle();
    }
    printf("final angle is :%lf\n", actualANG);
}

int align()
{
    int ticks = 0; //establish tick count
    while (analog(0) < 1600 && ticks < 300) //if white
    {
        create_drive_direct(-68, 95.999);
        msleep(50);
        ticks += 10; //keeps track of how many ticks turned
    }
    if (analog(0) < 1800)
    { 
        while (analog(0) < 1800 && ticks < 600) //if still white
        {
            create_drive_direct(68, -95.999);
            msleep(50);
            ticks += 10; 
        }
    }
    return 0;
}

int main()
{
	create_connect();
    
    //moving towards astronauts from starting box
	while ((get_create_rbump() == 0) && (get_create_lbump() == 0))
    {
          if(analog(0)<1500)
        {
            align();
            printf("we are looking for the black line\n");
        }
        if(analog(0)>1500)
        {
            printf("we found the black line\n");
            create_drive_direct(34, 30);
            msleep(5);
            get_create_lbump();
        }
    	Forward(30); // moves forward a bit
    }
    
    //Moving backwards to prep for turn
  	 create_drive_direct(-68, -95.999);
        msleep(2205); //note to future self: test this value
    
   //lining up to turn right
    while(analog(0)>1500)
    {
        create_drive_direct(34, -40);
        msleep(5);
    }
    
    
    //Turning right w/ correction 
    create_drive_direct(-34, 40);
    msleep(6);
    Turn_Right(90);
    
create_disconnect(); 
return 0;

}





 

