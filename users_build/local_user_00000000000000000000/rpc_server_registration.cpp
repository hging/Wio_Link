#include "suli2.h"
#include "rpc_server.h"
#include "rpc_stream.h"
#include "Main.h"

GroveSlidePotentiometer *GroveSlidePotentiometerA0_ins;

void rpc_server_register_resources()
{
    uint8_t arg_types[MAX_INPUT_ARG_LEN];
    EVENT_T *event;
    

    //GroveSlidePotentiometerA0
    GroveSlidePotentiometerA0_ins = new GroveSlidePotentiometer(17);
    memset(arg_types, TYPE_NONE, MAX_INPUT_ARG_LEN);
    rpc_server_register_method("GroveSlidePotentiometerA0", "analog", METHOD_READ, __grove_slide_potentiometer_read_analog, GroveSlidePotentiometerA0_ins, arg_types);
    memset(arg_types, TYPE_NONE, MAX_INPUT_ARG_LEN);
    rpc_server_register_method("GroveSlidePotentiometerA0", "voltage", METHOD_READ, __grove_slide_potentiometer_read_voltage, GroveSlidePotentiometerA0_ins, arg_types);


    event = GroveSlidePotentiometerA0_ins->attach_event_reporter_for_slide_changed(rpc_server_event_report);
}

void print_well_known()
{
    writer_print(TYPE_STRING, "{\"well_known\":");
    writer_print(TYPE_STRING, "[");
    writer_block_print(TYPE_STRING, "\"GET " OTA_SERVER_URL_PREFIX "/node/GroveSlidePotentiometerA0/analog -> int analog\",");
    writer_block_print(TYPE_STRING, "\"GET " OTA_SERVER_URL_PREFIX "/node/GroveSlidePotentiometerA0/voltage -> float volt\",");
    writer_block_print(TYPE_STRING, "\"Event GroveSlidePotentiometerA0 slide_changed\"");
    writer_print(TYPE_STRING, "]}");
}
