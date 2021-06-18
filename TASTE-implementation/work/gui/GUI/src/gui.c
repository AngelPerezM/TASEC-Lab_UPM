/* Body file for GUI GUI
 * Generated by TASTE on 2021-06-18 13:10:28
 * DO NOT EDIT THIS FILE MANUALLY - MODIFY THE KAZOO TEMPLATE IF NECESSARY
*/

#include <unistd.h>
#include <mqueue.h>

#include "queue_manager.h"
#include "gui.h"
#include "gui_enums_def.h"

typedef struct _PI_Messages {
   T_gui_PI_list msg_id;
   union {
      asn1SccATT_GUI attitude_data_param;
      asn1SccENV_GUI environmental_data_param;
      asn1SccHTL_GUI htl_data_param;
   } msg_data;
} PI_Messages;

typedef struct _RI_Messages {
   T_gui_RI_list msg_id;
   union {
      asn1SccTC send_telecommand_param;
      asn1SccHTL_State setcurrentmode_param;
   } msg_data;
} RI_Messages;

// Queues of messages going from the binary to the user (PIs, or TMs)
static mqd_t gui_PI_queue_id,
             gui_PI_Python_queue_id;

// Queues of messages going from the user to the binary GUI (RIs, or TCs)
static mqd_t gui_RI_queue_id;


void gui_startup(void)
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
    int  len = snprintf (gui_queue_name, 0, "%d_gui_RI_queue", geteuid());
    gui_queue_name = (char *) malloc ((size_t) len + 1);
    if (NULL != gui_queue_name) {
       snprintf (gui_queue_name, len + 1, "%d_gui_RI_queue", geteuid());

       create_exchange_queue(gui_queue_name, 5, sizeof(RI_Messages), &gui_RI_queue_id);

       free (gui_queue_name);
       gui_queue_name = NULL;
    }

    len = snprintf (gui_queue_name, 0, "%d_gui_PI_queue", geteuid());
    gui_queue_name = (char *) malloc ((size_t) len + 1);
    if (NULL != gui_queue_name) {
       snprintf (gui_queue_name, len + 1, "%d_gui_PI_queue", geteuid());

       create_exchange_queue(gui_queue_name, 10, sizeof(PI_Messages), &gui_PI_queue_id);

       free (gui_queue_name);
       gui_queue_name = NULL;
    }

    len = snprintf (gui_queue_name, 0, "%d_gui_PI_Python_queue", geteuid());
    gui_queue_name = (char *) malloc ((size_t) len + 1);
    if (NULL != gui_queue_name) {
       snprintf (gui_queue_name, len + 1, "%d_gui_PI_Python_queue", geteuid());

       /* Extra queue for the TM sent to the Python mappers */
       create_exchange_queue(gui_queue_name, 10, sizeof (PI_Messages), &gui_PI_Python_queue_id);

       free (gui_queue_name);
       gui_queue_name = NULL;
    }
}

//  Function polling the message queue for incoming message from the user
void gui_PI_Poll(void)
{
   struct mq_attr msgq_attr;
   char* msgcontent = NULL;

   T_gui_RI_list message_received_type;

   if ((msgcontent = (char*)malloc(sizeof(RI_Messages))) == NULL) {
      perror("Error when allocating memory in GUI polling function");
      exit (-1);
   }

   mq_getattr(gui_RI_queue_id, &msgq_attr);

   while (!retrieve_message_from_queue(gui_RI_queue_id,
                                       sizeof(RI_Messages),
                                       msgcontent,
                                       (int *)&message_received_type)) {
      switch(message_received_type) {
         case i_send_telecommand:
            gui_RI_send_telecommand((asn1SccTC *)msgcontent);
            break;
         case i_setCurrentMode:
            gui_RI_setCurrentMode((asn1SccHTL_State *)msgcontent);
            break;
       default : break;
      }
   }

   free(msgcontent);
   return;
}

void gui_PI_Attitude_Data
      (const asn1SccATT_GUI *IN_attitude_lab_data)

{
   write_message_to_queue
      (gui_PI_queue_id,
       sizeof(asn1SccATT_GUI),
       (void*)IN_attitude_lab_data,
       i_Attitude_Data);

   write_message_to_queue
      (gui_PI_Python_queue_id,
       sizeof(asn1SccATT_GUI),
       (void*)IN_attitude_lab_data,
       i_Attitude_Data);
}
void gui_PI_Environmental_Data
      (const asn1SccENV_GUI *IN_env_lab_data)

{
   write_message_to_queue
      (gui_PI_queue_id,
       sizeof(asn1SccENV_GUI),
       (void*)IN_env_lab_data,
       i_Environmental_Data);

   write_message_to_queue
      (gui_PI_Python_queue_id,
       sizeof(asn1SccENV_GUI),
       (void*)IN_env_lab_data,
       i_Environmental_Data);
}
void gui_PI_HTL_Data
      (const asn1SccHTL_GUI *IN_htl_data)

{
   write_message_to_queue
      (gui_PI_queue_id,
       sizeof(asn1SccHTL_GUI),
       (void*)IN_htl_data,
       i_HTL_Data);

   write_message_to_queue
      (gui_PI_Python_queue_id,
       sizeof(asn1SccHTL_GUI),
       (void*)IN_htl_data,
       i_HTL_Data);
}


