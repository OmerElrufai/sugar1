#include "consoleUI.h"
#include "Mario.h"
#include "scada.h"

//static void __atribute__( uint8 sw = 80,sh = 26,sd = 1);
/*

Black 0 Red 4 Dark grey 8 Light red 12
Blue 1 Magenta 5 Light blue 9 Light magenta 13
Green 2 Brown 6 Light green 10 Light brown 14
Cyan 3 Light grey 7 Light cyan 11 White 15



*/

void scad(){
printCharAt('r', 200, 2, 2);
printCharAt('r', 200, 2, 3);
clearScreen();
}

void scad1(){
printCharAt('r', 200, 14, 12);
printCharAt('r', 200, 14, 13);
clearScreen();
}


void scad3(){
printCharAt('r', 200, 16, 12);
printCharAt('r', 200, 16, 13);
clearScreen();
}

void scad4(){
printCharAt('r', 200, 18, 12);
printCharAt('r', 200, 18, 13);
clearScreen();
}

void scad2(){
printCharAt('r', 200, 12, 12);
printCharAt('r', 200, 12, 13);
clearScreen();
}

static void appendCharAt(char c, int b, uint16 x, uint16 y) {
    string vidmem = (string) 0xb8000;
    vidmem [((y)*sw + x) * sd] = c;  //vidmem [(y * y + x *x) -sd] = c;       
    vidmem [((y)*sw + x) * sd + 1] = b; // vidmem [(y * y + x*x) + sd + 1] = b;    
}

void scado()
{
//drawBorder(2, 0, 0, 30, 4);
//printAt( "print h to move y to jump",7,3,2); 
string  dan = readStr(); //memory_copy(readStr(), ch,100);
		    if(strEql(dan,"h"))
		    {
		    
		   int counto=0;
		while (counto < 4300){    
		    	scad3();
		    	
		    	counto++;
		    	}
		    	scad4();
		    	clearScreen();
		    	print("NIDOS> ");
		    	
		    	
		    }		    
 
             else if(strEql(dan,"y"))
                   {
                       int count=0;
		        while (count <4330){    
		    	scad2();
		    	
		    	count++;
		    	} 
		    	scad4(); 
		    	clearScreen();
		         printAt( "GAME",7,40,12);
		    	 printAt( "OVER",7,40,16);
		    }
		    
		    else
		    {
		            print("\nBad command!\n");
		            print("NIDOS> ");
		    } 

//return 0;
}



void scads()
{ 
    //act();
   
  int counter=0;
  
   while (counter<800) {
        scad(); 
       // msound(36);                      // drawBorder(7, 8, 8, 14, 14);
	counter++;       
	}
   while (counter<1420) {
        scad1();
       // msound(36);                              //  drawBorder(7, 10, 10, 16, 16);
	counter++;       
 	}
   while (counter<2000) {
         scad3();
        // msound(36);                                 //drawBorder(7, 12, 12, 18, 18);
	counter++;       
	}
   while (counter<2600) {
         scado(); 
        // msound(36);                                      //drawBorder(7, 14, 14, 20, 20);
	counter++;       
	}
  while (counter<3600) {
         scad4(); 
        // msound(36);                                      //drawBorder(7, 14, 14, 20, 20);
	counter++;       
	}
}

void automatic(){
        set_screen_color(0,3); 
        //clearLine(uint8 from,uint8 to)
        //paintScreen(85);
        printCharAt('A', 200, 18, 12);  //printCharAt('A', 200, 18, 12);  gft  <
        appendCharAt('0', 33, 21, 12); // printCharAt(' ', 200, 21, 12);
        printCharAt('%', 200, 11, 12);
        drawFrame(64, 19, 13, 23, 17);	//pump 1
        drawFrame(33, 14, 16, 19, 17);	//pump 1 in pipe
        printCharAt('P', 200, 20,18);
        printCharAt('M', 200, 21,18);
        printCharAt('P', 200, 66,18);//pump 2 np
        printCharAt('M', 200, 67,18);	
	drawFrame(64, 23, 16, 28, 17);/* pipe line       */
        drawFrame(64, 28, 16, 33, 17);/* pipe line       */
        drawFrame(64, 33, 16, 38, 17);/* pipe line       */
        drawFrame(64, 38, 16, 47, 17);/* pipe line       */
        drawFrame(64, 45, 7, 46, 17);  //tank pipe in
        drawFrame(64, 51, 5, 52, 17);   //tank pipe out
        drawFrame(64, 49, 5, 52, 6);   //pipe out tank
        drawFrame(64, 51, 16, 65, 17);  // pipe line from pump
        drawFrame(64, 65, 13, 69, 17);	//pump 2
        drawFrame(64, 69, 16, 75, 17);  //pump2 pipe out
        printCharAt('T', 200, 44,2);
        printCharAt('K', 200, 45,2);
        drawFrame(64, 44, 3, 49, 4);
        drawFrame(64, 44, 4, 49, 5);
        drawFrame(64, 44, 5, 49, 6);
        drawFrame(64, 44, 6, 49, 7);
        drawFrame(64, 44, 7, 49, 8);
        printCharAt((char)gft, 200, 43,8);
       // tank();
       // timer1();
	
}

void pump2_start(){
    set_screen_color(0,3);
    //drawFrame(33, 69, 16, 75, 17);  
    //drawFrame(33, 65, 13, 69, 17);  //pump 2
   // drawFrame(64, 19, 13, 23, 17); //pump 1
    
     timer3();
     
     return 0;
}

void tank(){
      drawFrame(64, 44, 3, 49, 4);
      drawFrame(64, 44, 4, 49, 5);
      drawFrame(64, 44, 5, 49, 6);
      drawFrame(64, 44, 6, 49, 7);
      drawFrame(64, 44, 7, 49, 8);
}

void tank1(){
      printCharAt('T', 200, 44,2);
      printCharAt('K', 200, 45,2);
      printCharAt((char)gft, 200, 43,7);//	
      drawFrame(64, 44, 3, 49, 4);
      drawFrame(64, 44, 4, 49, 5);
      drawFrame(64, 44, 5, 49, 6);
      drawFrame(64, 44, 6, 49, 7);
      drawFrame(33, 44, 7, 49, 8);
      
}

void tank2(){
      printCharAt('T', 200, 44,2);
      printCharAt('K', 200, 45,2);
      drawFrame(64, 44, 3, 49, 4);
      drawFrame(64, 44, 4, 49, 5);
      drawFrame(64, 44, 5, 49, 6);
      drawFrame(33, 44, 6, 49, 7);
      drawFrame(33, 44, 7, 49, 8);
      printCharAt((char)gft, 200, 43,6);//
}

void tank3(){
      printCharAt('T', 200, 44,2);
      printCharAt('K', 200, 45,2);
      drawFrame(64, 44, 3, 49, 4);
      drawFrame(64, 44, 4, 49, 5);
      drawFrame(33, 44, 5, 49, 6);
      drawFrame(33, 44, 6, 49, 7);
      drawFrame(33, 44, 7, 49, 8);
      printCharAt((char)gft, 200, 43,5);//
}

void tank4(){
      printCharAt('T', 200, 44,2);
      printCharAt('K', 200, 45,2);
      drawFrame(64, 44, 3, 49, 4);
      drawFrame(33, 44, 4, 49, 5);
      drawFrame(33, 44, 5, 49, 6);
      drawFrame(33, 44, 6, 49, 7);
      drawFrame(33, 44, 7, 49, 8);
      printCharAt((char)gft, 200, 43,4);//
}

 void manual(){
 
        printCharAt('M', 200, 18, 12);
        printCharAt(' ', 200, 21, 12);	
        printCharAt('%', 200, 11, 12);  
        printCharAt('P', 200, 20,18);
        printCharAt('M', 200, 21,18);  
	drawFrame(64, 19, 13, 23, 17);	
	drawFrame(64, 23, 16, 28, 17);  
        drawFrame(64, 28, 16, 33, 17);
        drawFrame(64, 33, 16, 38, 17);
 }

void start_co1(){
        drawFrame(33, 19, 13, 23, 17);	
        printCharAt('P', 200, 20,18);
        printCharAt('M', 200, 21,18);
        printCharAt('P', 200, 66,18);//pump 2 np
        printCharAt('M', 200, 67,18);	
        drawFrame(64, 51, 16, 65, 17);
	drawFrame(64, 23, 16, 28, 17);
        drawFrame(64, 28, 16, 33, 17);
        drawFrame(64, 33, 16, 38, 17);
        drawFrame(64, 38, 16, 47, 17);
        drawFrame(64, 45, 7, 46, 17);
        drawFrame(64, 51, 5, 52, 17);
        drawFrame(64, 51, 16, 65, 17);     //outlet pipe
        drawFrame(64, 65, 13, 69, 17);	//pump 2
        drawFrame(33, 14, 16, 19, 17);	//pump 1 in pipe
        drawFrame(64, 69, 16, 75, 17);  //pump2 pipe out
        drawFrame(64, 49, 5, 52, 6);
}

void start_co(){

        drawFrame(33, 19, 13, 23, 17);
        printCharAt('P', 200, 20,18);
        printCharAt('M', 200, 21,18);
        printCharAt('P', 200, 66,18);//pump 2 np
        printCharAt('M', 200, 67,18);		
	drawFrame(33, 23, 16, 28, 17);  	
        drawFrame(64, 28, 16, 33, 17);
        drawFrame(64, 33, 16, 38, 17);
        drawFrame(64, 38, 16, 47, 17);
        drawFrame(64, 45, 7, 46, 17);
        drawFrame(64, 51, 16, 65, 17);     //outlet pipe
        drawFrame(64, 65, 13, 69, 17);	//pump 2
        drawFrame(33, 14, 16, 19, 17);	//pump 1 in pipe
        drawFrame(64, 69, 16, 75, 17);  //pump2 pipe out
        drawFrame(64, 51, 5, 52, 17);
        drawFrame(64, 49, 5, 52, 6);
}

void start_cos(){

        drawFrame(33, 19, 13, 23, 17);
        printCharAt('P', 200, 20,18);
        printCharAt('M', 200, 21,18);	
        printCharAt('P', 200, 66,18);//pump 2 np
        printCharAt('M', 200, 67,18);	
	drawFrame(33, 23, 16, 28, 17);  	
        drawFrame(33, 28, 16, 33, 17);
        drawFrame(64, 33, 16, 38, 17);
        drawFrame(64, 38, 16, 47, 17);
        drawFrame(64, 45, 7, 46, 17);
        drawFrame(64, 51, 5, 52, 17);
        drawFrame(64, 49, 5, 52, 6);
        drawFrame(64, 51, 16, 65, 17);     //outlet pipe
        drawFrame(64, 65, 13, 69, 17);	//pump 2
        drawFrame(33, 14, 16, 19, 17);	//pump 1 in pipe
        drawFrame(64, 69, 16, 75, 17);  //pump2 pipe out
}

void start_cow(){
        set_screen_color(0,3); 
        drawFrame(33, 19, 13, 23, 17);
        printCharAt('P', 200, 20,18);//pump 1 np
        printCharAt('M', 200, 21,18);	
        printCharAt('P', 200, 66,18);//pump 2 np
        printCharAt('M', 200, 67,18);	
	drawFrame(33, 23, 16, 28, 17);  	
        drawFrame(33, 28, 16, 33, 17);
        drawFrame(33, 33, 16, 38, 17);
        drawFrame(33, 38, 16, 47, 17);
        drawFrame(33, 45, 7, 46, 17);
        drawFrame(33, 51, 5, 52, 17);
        drawFrame(33, 49, 5, 52, 6);
        drawFrame(33, 51, 16, 65, 17);  //outlet pipe
        drawFrame(64, 65, 13, 69, 17);	//pump 2
        drawFrame(33, 14, 16, 19, 17);	//pump 1 in pipe
        drawFrame(64, 69, 16, 75, 17);  //pump2 pipe out
}
void myscada(){
        set_screen_color(0,3); 
        automatic();
        print("please inter a letter s for start :");
        print("\n");
        //drawBorder(2, 0, 0, 30, 4);
        //printAt( "print h to move y to jump",7,3,2); 
         string  dan = readStr(); //memory_copy(readStr(), ch,100);
         if(strEql(dan,"s"))   {
        paintScreen(85);
        clearScreen(); 
        printCharAt('S', 200, 18, 12);        
        printCharAt('%', 200, 11, 12);	    	
        timer2();
        timer1();
        scadon();
        
           print("please inter a letter s for stop o for restart :\n");
           print("\n");
                    int ck = str_to_int(readStr());
                    if(strEql(ck,"s")){
                     stop();
                       
                    }
                    else(strEql(ck,"o"));{
                     timer1();//manual();
               }
                                     

}				
		    else
		    {
	             automatic();
		    } while (!strEql(dan,"exit"));
	
        
 }
 
 
void stop(){
 
        printCharAt('A', 200, 18, 12);	    
	drawFrame(33, 19, 13, 23, 17);	
	drawFrame(33, 23, 16, 33, 17);  
        drawFrame(64, 28, 16, 33, 17);
        drawFrame(64, 33, 16, 38, 17);
        
         return 0;
 }


void scadon()
{
   drawFrame(33, 69, 16, 75, 17); 
   drawFrame(33, 65, 13, 69, 17);
    pump2_start(); // timer3();
    
    myscada();               
                   
                 
    return 0;            
}

/*
void sco1(){
start_co();
printAt("11",200, 21, 12);
//clearScreen();
;
}

void sco2(){
start_co();
printAt("21",200, 21, 12);
//clearScreen();

}
void sco3(){
start_co();
printAt("31",200, 21, 12);
//clearScreen();

}

void sco4(){
start_co();
printAt("41",200, 21, 12);
//clearScreen();

}
void sco5(){
start_co();
printAt("51",200, 21, 12);
//clearScreen();

}

*/

void timer1()
{ 
 asm("cli");   //act();
   
  int counter=0;
  
   while (counter<800) {
  // clearScreen();
   start_cow();
    tank();
	counter++;       
	}
   while (counter<1620) {
  // clearScreen();
     start_cow();
   tank1();
	counter++;       
 	}
   while (counter<2700) {
//   clearScreen();
     start_cow();
   tank2();
	counter++;       
	}
   while (counter<3800) {
  // clearScreen();
     start_cow();
     tank3();
    opencrlvlv();
	counter++;       
	}
  while (counter<4900) {
//   clearScreen();
  printAt("51",200, 21, 12);  // timer2();
     start_cow();
      tank4();
	counter++;       
	}
}



void timer2()
{ 
   asm("cli");  //act();
   
  int countero=0;
  
   while (countero<900) {
 //  clearScreen();
   tank();
    start_co();
    printAt("11",200, 21, 12);
	countero++;       
	}
   while (countero<1920) {
  // clearScreen();
    tank();
    start_co();
    printAt("21",200, 21, 12);
	countero++;       
 	}
   while (countero<2900) {
  // clearScreen();
    tank();
    start_cos();
    printAt("31",200, 21, 12);
	countero++;       
	}
   while (countero<4400) {
  // clearScreen();
    tank();
     start_cow();
     printAt("41",200, 21, 12);
	countero++;       
	}
  while (countero<5900) {
  // clearScreen();
    tank();
   start_cow();
   printAt("51",200, 21, 12);
	countero++;       
	}


}







void timer3()
{ 
   asm("cli");  //act();
   
  int cout=0;
  
   while (cout<6000) {
   clearScreen();
   start_cow();
   drawFrame(33, 69, 16, 75, 17); 
   drawFrame(33, 65, 13, 69, 17);
    tank4();
	cout++;       
	}
	  asm("cli"); 
   while (cout<7620) {
   clearScreen();
     start_cow();
     drawFrame(33, 69, 16, 75, 17); 
      drawFrame(33, 65, 13, 69, 17);
   tank3();
	cout++;       
 	}
 	  asm("cli"); 
   while (cout<8700) {
   clearScreen();
     start_cow();
     drawFrame(33, 69, 16, 75, 17); 
      drawFrame(33, 65, 13, 69, 17);
   tank2();
	cout++;       
	}
	  asm("cli");
   while (cout<9800) {
   clearScreen();
     start_cow();
     drawFrame(33, 69, 16, 75, 17); 
      drawFrame(33, 65, 13, 69, 17);
    tank1();
	cout++;       
	}
	  asm("cli"); 
  while (cout<10600) {
   clearScreen();
  printAt("51",200, 21, 12);  // timer2();
     start_cow();
     drawFrame(33, 69, 16, 75, 17); 
      drawFrame(33, 65, 13, 69, 17);
      tank();
	cout++;       
	}
}


void opencrlvlv(){
stop();
pump2_start();

}



void closecrlvlv(){
 

 print("please inter a letter d for auto f or restart :\n");
           print("\n");
                    int df = str_to_int(readStr());
                    if(strEql(df,"s")){
                     timer2();
                     timer1();
                    }
                    else(strEql(df,"o"));{
                    scadon();
               }
  

}


