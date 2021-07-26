/* Body file for GUI GroundSw
 * Generated by TASTE on 2021-05-17 22:58:20
 * DO NOT EDIT THIS FILE MANUALLY - MODIFY THE KAZOO TEMPLATE IF NECESSARY
*/

#include <unistd.h>
#include <mqueue.h>

#include "queue_manager.h"
#include "groundsw.h"
#include "groundsw_enums_def.h"

typedef bool PI_Messages;

typedef bool RI_Messages;

// Queues of messages going from the binary to the user (PIs, or TMs)
static mqd_t groundsw_PI_queue_id,
             groundsw_PI_Python_queue_id;

// Queues of messages going from the user to the binary GUI (RIs, or TCs)
static mqd_t groundsw_RI_queue_id;


void groundsw_startup(void)
{
   unsigned msgsize_max = 8192;
   FILE *f = fopen("/proc/sys/fs/mqueue/msgsize_max", "r");
   fscanf(f, "%d", &msgsize_max);

   if (msgsize_max < sizeof (PI_Messages) || msgsize_max < sizeof (RI_Messages)) {
      printf("[ERROR] The GUI is passing a message which parameter size "
             "exceeds your system limit (which is %d bytes per message).\n"
             "You can extend this limit by running: \n"
             "    echo NUMBER | sudo tee /proc/sys/fs/mqueue/msgsize_max\n"
             " ...  with NUMBER > %ld\n"
             "You can also make it permanent (check TASTE wiki)\n\n",
             msgsize_max,
             sizeof(PI_Messages) > sizeof(RI_Messages) ? sizeof(PI_Messages):sizeof(RI_Messages));
      exit(1);
   }

    char *gui_queue_name = NULL;
    int  len = snprintf (gui_queue_name, 0, "%d_groundsw_RI_queue", geteuid());
    gui_queue_name = (char *) malloc ((size_t) len + 1);
    if (NULL != gui_queue_name) {
       snprintf (gui_queue_name, len + 1, "%d_groundsw_RI_queue", geteuid());

       create_exchange_queue(gui_queue_name, 5, sizeof(RI_Messages), &groundsw_RI_queue_id);

       free (gui_queue_name);
       gui_queue_name = NULL;
    }

    len = snprintf (gui_queue_name, 0, "%d_groundsw_PI_queue", geteuid());
    gui_queue_name = (char *) malloc ((size_t) len + 1);
    if (NULL != gui_queue_name) {
       snprintf (gui_queue_name, len + 1, "%d_groundsw_PI_queue", geteuid());

       create_exchange_queue(gui_queue_name, 10, sizeof(PI_Messages), &groundsw_PI_queue_id);

       free (gui_queue_name);
       gui_queue_name = NULL;
    }

    len = snprintf (gui_queue_name, 0, "%d_groundsw_PI_Python_queue", geteuid());
    gui_queue_name = (char *) malloc ((size_t) len + 1);
    if (NULL != gui_queue_name) {
       snprintf (gui_queue_name, len + 1, "%d_groundsw_PI_Python_queue", geteuid());

       /* Extra queue for the TM sent to the Python mappers */
       create_exchange_queue(gui_queue_name, 10, sizeof (PI_Messages), &groundsw_PI_Python_queue_id);

       free (gui_queue_name);
       gui_queue_name = NULL;
    }
}

//  Function polling the message queue for incoming message from the user
void groundsw_PI_Poll(void)
{
   return;
}

void groundsw_PI_sendAllData
      (const asn1SccOBSW_DP_Data *IN_alldata)

{
   write_message_to_queue
      (groundsw_PI_queue_id,
       sizeof(asn1SccOBSW_DP_Data),
       (void*)IN_alldata,
       i_sendAllData);

   write_message_to_queue
      (groundsw_PI_Python_queue_id,
       sizeof(asn1SccOBSW_DP_Data),
       (void*)IN_alldata,
       i_sendAllData);
}

