#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <mqueue.h>

#include "dataview-uniq.h"
#include "gui_enums_def.h"
#include "queue_manager.h"

int OpenMsgQueueForReading(char *queueName)
{
    mqd_t queue_id;
    if (0 == open_exchange_queue_for_reading(queueName, &queue_id))
        return queue_id;
    return -1;
}

void CloseMsgQueue(int queue_id)
{
    mq_close(queue_id);
}

int GetMsgQueueBufferSize(int _queue_id)
{
    struct mq_attr mqstat;
    mq_getattr(_queue_id, &mqstat);
    return mqstat.mq_msgsize;
}

int RetrieveMessageFromQueue(int queue_id, int maxSize, byte *pBuf)
{
    int message_received_type = -1;
    retrieve_message_from_queue(queue_id, maxSize, pBuf, &message_received_type);
    return(message_received_type);
}

T_gui_PI_list ii_Attitude_Data = i_Attitude_Data;
T_gui_PI_list ii_Environmental_Data = i_Environmental_Data;
T_gui_PI_list ii_HTL_Data = i_HTL_Data;
T_gui_RI_list ii_send_telecommand = i_send_telecommand;
typedef struct {
    int tc_id;
    TC tc;
} send_telecommand_TCDATA;

int SendTC_send_telecommand(void *p_tc)
{
    static mqd_t q = (mqd_t)-2;
    if (((mqd_t)-2) == q) {
        static char QName[1024];
        sprintf(QName, "%d_gui_RI_queue", geteuid());
        open_exchange_queue_for_writing(QName, &q);
    }
    send_telecommand_TCDATA data;
    data.tc_id = (int) i_send_telecommand;
    data.tc = * (TC *) p_tc;
    if (((mqd_t)-1) != q) {
        write_message_to_queue(q, sizeof(send_telecommand_TCDATA)-4, &data.tc, data.tc_id);
    } else {
        return -1;
    }
    return 0;
}
T_gui_RI_list ii_setCurrentMode = i_setCurrentMode;
typedef struct {
    int tc_id;
    HTL_State current_state;
} setCurrentMode_TCDATA;

int SendTC_setCurrentMode(void *p_current_state)
{
    static mqd_t q = (mqd_t)-2;
    if (((mqd_t)-2) == q) {
        static char QName[1024];
        sprintf(QName, "%d_gui_RI_queue", geteuid());
        open_exchange_queue_for_writing(QName, &q);
    }
    setCurrentMode_TCDATA data;
    data.tc_id = (int) i_setCurrentMode;
    data.current_state = * (HTL_State *) p_current_state;
    if (((mqd_t)-1) != q) {
        write_message_to_queue(q, sizeof(setCurrentMode_TCDATA)-4, &data.current_state, data.tc_id);
    } else {
        return -1;
    }
    return 0;
}
