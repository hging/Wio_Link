#include "wio.h"
#include "suli2.h"
#include "Main.h"
#include "grove_slide_potentiometer_gen.h"

float voltage = 0.0f;

uint32_t last_time;


void setup()
{
    Serial1.println("setup done");
}

void loop()
{
    uint32_t t = millis();
    if (t - last_time > 2000)
    {
        last_time = t;
        GroveSlidePotentiometerA0_ins->read_voltage(&voltage);
        Serial1.print("voltage: ");
        Serial1.println(voltage);
    }
}


/* The following is an exmaple for ULB */
/*int var1 = 10;
float f = 123.45;
String s;
uint32_t time;

void setup()
{
    s = "this is a string...";
    wio.registerVar("var1", var1);
    wio.registerVar("var2", f);
    wio.registerVar("var3", s);
    time = millis();
}

void loop()
{
    if (millis() - time > 1000)
    {
        time = millis();
        Serial1.println(var1);
    }
}*/
