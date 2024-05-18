#include <thread>
#include <iostream>
#include "wiringPi.h"
#include <csignal>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <cstdlib>
#include "motorkontrol.h"
#include "database.h"
#include <string>
#include "UR.h"
#include <vector>
#include "UR5.h"

void testThread(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    UR5 server;
    a.exec();
}

int main(int argc, char *argv[])
{
    //UR5 server;
   //server.newConnection();
    int test = 0;
    database d;

    std::thread t = std::thread(testThread, std::ref(test), argv);
    motorkontrol m;
    wiringPiSetupGpio();
    //set input og en
    m.setSpeed(1400);
    int knap1 = 23; //Open knap
    int knap2 = 24; //luk knap
    pinMode(knap1, INPUT);
    pinMode(knap2, INPUT);

    delay(6000);
    //Vi starter med at lukke griperen i programmet
    m.closeGripper();
    d.setKnap1(digitalRead(knap1));


    while(1) {
    std::cout << "Åben Knap: " << digitalRead(knap1) << std::endl;
    std::cout << "Luk Knap: " << digitalRead(knap2) << std::endl;
    std::cout << "thread: " << test << std::endl;

        delay(200);

        if(m.checkClKnap()) {
            m.openGripper();
            delay(2000);
            d.setKnap2(digitalRead(knap2));


            std::cout << "Der åbnes nu" << std::endl;
        } else if(m.checkOpKnap()) {
            m.closeGripper();
            std::cout << "Der gribes nu" << std::endl;
        }
    }
    t.~thread();
    return 0;
}




/*
    std::string ROBOT_IP = "192.168.1.54";


    // Initialiser kontrol- og modtageobjekter
    ur_rtde::RTDEControlInterface rtde_control(ROBOT_IP);
    ur_rtde::RTDEReceiveInterface rtde_receive(ROBOT_IP);

    // Flyt robotten til en specifik position (x, y, z, rx, ry, rz)
    std::vector<double> target_pose = {0.5, 0.0, 0.5, 0.0, 3.14, 0.0};

    // Juster positionen efter dine behov
    rtde_control.moveL(target_pose);

    // Hent nuværende position på robotten
    std::vector<double> current_pose = rtde_receive.getActualTCPPose();
    std::cout << "Current pose: ";
    for (const auto& value : current_pose)
        std::cout << value << " ";
    std::cout << std::endl;

    // Afslut
    rtde_control.stopScript();




    /*  For at få Motoren til at køre */
/*
    motorkontrol m;
    wiringPiSetupGpio();
    //set input og en
    m.setSpeed(700);
    int knap1 = 23;
    int knap2 = 24;
    pinMode(knap1, INPUT);
    pinMode(knap2, INPUT);


    while(1) {
    std::cout << "Åben Knap: " << digitalRead(knap1) << std::endl;
    std::cout << "Luk Knap: " << digitalRead(knap2) << std::endl;
	delay(500);

    int i=0;
        ++i;
        if(m.checkClKnap()) {
            m.openGripper();
        } else if(m.checkOpKnap()) {
            m.closeGripper();
        } else if(i>=40) {
            break;
        }
        delay(50);
    }
*/

/*
    pinMode(12, PWM_OUTPUT);

    //set pwm
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(3840);
    pwmSetRange(2500);
    pwmWrite(12, 250);
    int speed = 0;
    while(1) {
        speed+=100;
        m.setSpeed(speed);
        m.openGripper();
        delay(50);
        if (speed >= 3000) {
            break;
        }
    }

*/


    /* Database kode
    database d;

    //d.setKnap1(digitalRead(5));
    bool opdater;
    std::cout << "værdi for knap1: " << std::endl;
    std::cin >> opdater;
    d.setKnap1(opdater);

    std::cout << "Vælg værdi for knap2: " << std::endl;
    std::cin >> opdater;
    d.setKnap2(opdater);

    motorkontrol m;

    m.closeGripper();

    d.setTime(m.getTid());

    d.insertRow();



    bool opdater;
    std::cout << "vælg true or false: \n ";
    std::cin >> opdater;
    std::cout << " du valgte " << opdater << std::endl;
    */
    //d.insertKnap1(opdater);
    //d.insertKnap2(opdater);
    //d.insertKnap1(opdater);

    /*
    int opdaterK1;
    int opdaterK2;
    int opdaterSucces;
    database d;
    d.updateKnap1();
    d.updateKnap2();
    d.updateSucces();
    */



    /*
    wiringPiSetupGpio();
    //set input og en
    pinMode(23, OUTPUT);
    pinMode(24, OUTPUT);
    digitalWrite(23, HIGH);
    digitalWrite(24, LOW);

    pinMode(12, PWM_OUTPUT);

    //set pwm
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(3840);
    pwmSetRange(1000);
    pwmWrite(12, 0);

    */



    /*
    for(int i = 1024; i != 1; i/=2){
        std::cout << i << std::endl;
        pwmWrite(26, i);
        delay(5000);
    }
    */




    /*
   database d;
   //setup wiring pi
   wiringPiSetupGpio();
   // set knap pins
   pinMode(5, INPUT);
   pinMode(6, INPUT);

   while(1){
       std::cout << "hej \n";

   if(!digitalRead(5)){
       std::cout << "knap1 er tændt";
       d.updateKnap1(1);
     }

   if(!digitalRead(6)){
       std::cout << "knap2 er tændt";
       d.updateKnap2(1);
     }

    delay(2000);
   }
   */

    /* ------------------------------------------------------- */

    /*
   //set input og en, kører motor
   pinMode(23, OUTPUT);
   pinMode(24, OUTPUT);
   digitalWrite(23, HIGH);
   digitalWrite(24, LOW);

   pinMode(26, PWM_OUTPUT);

   //set pwm
   pwmSetMode(PWM_MODE_MS);
   pwmSetClock(3840);
   pwmSetRange(1000);



   for(int i = 1024; i != 1; i/=2){
       std::cout << i << std::endl;
       pwmWrite(26, i);
       delay(5000);
   }
   */





//"CREATE TABLE gripperData(ID INTEGER PRIMARY KEY AUTOINCREMENT, knap1 INTEGER, knap2 INTEGER, tid INTEGER, succes INTEGER)"
  // query.prepare("INSERT into gripperData(knap1,knap2,tid,succes) VALUES (1,1,5,1)");
   //if(!query.exec()){std::cout << "insert failed";}





    /*
    query.prepare("SELECT * from t1;");
    query.exec();
    while (query.next()){
        int vis = query.value(0).toInt();
        int visNU = query.value(1).toInt();
        qDebug() << "Der er forbindelse til database, her får du data fra t1:" << vis << visNU;
    }
    */




   //"CREATE TABLE gripperData(ID INTEGER PRIMARY KEY AUTOINCREMENT, knap1 INTEGER, knap2 INTEGER, tid INTEGER, succes INTEGER)"
  //    query.prepare("INSERT into gripperData(knap1,knap2,tid,succes) VALUES (1,1,5,1)");
  //    if(!query.exec()){std::cout << "insert failed";}



    /*

     //  controll a diode using buttons
    //wiringPiSetupGpio();


    int out2 = 20;

    if(wiringPiSetup() == -1){exit;}
    std::cout << "setting pins" << std::endl;
    pinMode(out2, OUTPUT);

    while(1){
        digitalWrite(out2, HIGH);
        delay(500);
        digitalWrite(out2, LOW);
        delay(500);
    }

    */


    //std::signal(SIGINT, myhandler);
    /* wiringPiSetupGpio();
    int out1 = 23;
    int out2 = 24;
    int pwm = 12;
    int opKnap = 5;
    int clKnap = 6;
    int inKnap = 13;


    std::cout << "setting pins" << std::endl;
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(pwm, OUTPUT);
    pinMode(opKnap, INPUT);
    pinMode(clKnap, INPUT);
    pinMode(inKnap, INPUT);

    digitalWrite(out1,LOW);
    digitalWrite(out2,LOW);
    digitalWrite(pwm,LOW);
    digitalWrite(opKnap, LOW);
    digitalWrite(clKnap, LOW);
    digitalWrite(inKnap, LOW);
    */

    /*  PWM
    pinMode (pwm, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock (3840);
    pwmSetRange (200);

    delay (10);
    digitalWrite(out1,LOW);
    digitalWrite(out2,HIGH);
    */

   /* ------------------------------------------------------------ */



    /*
   motorkontrol m;
    int in = 0;
    while(1){
        std::cout << "Sæt en speed mellem 0-1024: ";
        std::cin >> in;
        if(in != 0){
            m.setSpeed(in);
            delay(100);
            m.closeGripper();
            in = 0;
        }

    } */



    /*
    while(1){
        switch(state) {
        case 0:
            std::cout << "Nu er vi i case 0" << std::endl;
            m.closeGripper();
            if(m.getClose()){
                state = 1;
            }
            break;
        case 1:
            std::cout << "Der er skiftet" << std::endl;
            m.openGripper();
            if(m.getOpen()){break;}

            break;
        case 2:

            break;
        case 3:
            break;
        }
        delay(1000);
    }
    */


    /*
    digitalWrite(out1,LOW);
    digitalWrite(out2,LOW);
    digitalWrite(pwm,LOW);
    digitalWrite(opKnap, LOW);
    digitalWrite(clKnap, LOW);
    digitalWrite(inKnap, LOW);
    */
        /*
        // LEDPIN is wiringPi Pin #1 or GPIO #18
        // we choose this pin since it supports PWM as
        // PWM is not supported by any other GPIO pins.
        const int LEDPIN = 26;

        if (wiringPiSetup() == -1) {
            printf ("Setup wiringPi Failed!\n");
            return -1;
        }

        //printf ("Reminder: this program must be run with sudo. Delay 5 seconds.\n");
        //delay (5000);
        //printf ("   starting now.\n");
        pinMode (LEDPIN, PWM_OUTPUT);
        // set the PWM mode to Mark Space
        pwmSetMode(PWM_MODE_MS);
        // set the clock divisor to reduce the 19.2 Mhz clock
        // to something slower, 5 Khz.
        // Range of pwmSetClock() is 2 to 4095.
        pwmSetClock (3840);  // 19.2 Mhz divided by 3840 is 5 Khz.

        // set the PWM range which is the value for the range counter
        // which is decremented at the modified clock frequency.
        // in this case we are decrementing the range counter 5,000
        // times per second since the clock at 19.2 Mhz is being
        // divided by 3840 to give us 5 Khz.
        pwmSetRange (5000);  // range is 2500 counts to give us half second.

        delay (10);   // delay a moment to let hardware settings settle.



        int x;
        std::cin >> x;
            std::cout << x << std::endl;
            delay(50);
            // range for the value written is 0 to 1024.
        for(int i = 0; i<5000; ++i) {
            std::cout << i << std::endl;
            delay(25);
            pwmWrite (LEDPIN, i);  // set the Duty Cycle for this range.
            // delay 10 seconds to watch the LED flash due to the PWM hardware.
        }*/




 // return 0;
//}
