#include "grove_slide_potentiometer_gen.h"
#include "rpc_server.h"
#include "rpc_stream.h"

bool __grove_slide_potentiometer_read_analog(void *class_ptr, char *method_name, void *input_pack)
{
    GroveSlidePotentiometer *grove = (GroveSlidePotentiometer *)class_ptr;
    uint8_t *arg_ptr = (uint8_t *)input_pack;
    int analog;


    if(grove->read_analog(&analog))
    {
        writer_print(TYPE_STRING, "{");
        writer_print(TYPE_STRING, "\"analog\":");
        writer_print(TYPE_INT, &analog);
        writer_print(TYPE_STRING, "}");
        return true;
    }else
    {
        writer_print(TYPE_STRING, "null");
        return false;
    }
}

bool __grove_slide_potentiometer_read_voltage(void *class_ptr, char *method_name, void *input_pack)
{
    GroveSlidePotentiometer *grove = (GroveSlidePotentiometer *)class_ptr;
    uint8_t *arg_ptr = (uint8_t *)input_pack;
    float volt;


    if(grove->read_voltage(&volt))
    {
        writer_print(TYPE_STRING, "{");
        writer_print(TYPE_STRING, "\"volt\":");
        writer_print(TYPE_FLOAT, &volt);
        writer_print(TYPE_STRING, "}");
        return true;
    }else
    {
        writer_print(TYPE_STRING, "null");
        return false;
    }
}

