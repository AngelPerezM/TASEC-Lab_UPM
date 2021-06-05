from __future__ import absolute_import


import threading, time, sys, os, ctypes

import DV
try:
    PythonAccess = ctypes.cdll.LoadLibrary("./PythonAccess.so")
except OSError:
    folder = os.path.dirname(os.path.abspath(__file__))
    PythonAccess = ctypes.cdll.LoadLibrary(folder + "/PythonAccess.so")
    sys.path.append(folder)
OpenMsgQueueForReading = PythonAccess.OpenMsgQueueForReading
OpenMsgQueueForReading.restype = ctypes.c_int
CloseMsgQueue =  PythonAccess.CloseMsgQueue
GetMsgQueueBufferSize = PythonAccess.GetMsgQueueBufferSize
GetMsgQueueBufferSize.restype = ctypes.c_int
RetrieveMessageFromQueue = PythonAccess.RetrieveMessageFromQueue
RetrieveMessageFromQueue.restype = ctypes.c_int
import dataview_uniq_asn
i_Attitude_Data = ctypes.c_int.in_dll(PythonAccess, "ii_Attitude_Data").value
i_Environmental_Data = ctypes.c_int.in_dll(PythonAccess, "ii_Environmental_Data").value
i_HTL_Data = ctypes.c_int.in_dll(PythonAccess, "ii_HTL_Data").value
i_send_telecommand = ctypes.c_int.in_dll(PythonAccess, "ii_send_telecommand").value
SendTC_send_telecommand = PythonAccess.SendTC_send_telecommand

class Poll_gui(threading.Thread):
    def run(self):
        self._bDie = False
        while True:
            if self._bDie:
                return
            self._msgQueue = OpenMsgQueueForReading(str(os.geteuid()) + "_gui_PI_Python_queue")
            if (self._msgQueue != -1): break
            print("Communication channel over %d_gui_PI_Python_queue not established yet...\n" % os.geteuid())
            time.sleep(1)
        bufferSize = GetMsgQueueBufferSize(self._msgQueue)
        self._pMem = ctypes.create_string_buffer(bufferSize).raw
        while not self._bDie:
            self.messageReceivedType = RetrieveMessageFromQueue(self._msgQueue, bufferSize, self._pMem)
            if self.messageReceivedType == -1:
                time.sleep(0.01)
                continue
            ProcessTM(self)

def Invoke_send_telecommand(var_TC_Heater):
    if -1 == SendTC_send_telecommand(var_TC_Heater._ptr):
        print('Failed to send TC: send_telecommand...\n')
        raise IOError("send_telecommand")

def ProcessTM(self):
    if self.messageReceivedType == i_Attitude_Data:
        print("\n"+chr(27)+"[32m" + "Received Telemetry: Attitude_Data" + chr(27) + "[0m\n")
        backup = self._pMem
        # Read the data for param attitude_lab_data
        var_attitude_lab_data = dataview_uniq_asn.ATT_GUI()
        var_attitude_lab_data.SetData(self._pMem)
        print("Parameter attitude_lab_data:")
        var_attitude_lab_data.PrintAll()
        print()
        # self._pMem = DV.MovePtrBySizeOf_ATT_GUI(self._pMem)
        # Revert the pointer to start of the data
        self._pMem = backup
    if self.messageReceivedType == i_Environmental_Data:
        print("\n"+chr(27)+"[32m" + "Received Telemetry: Environmental_Data" + chr(27) + "[0m\n")
        backup = self._pMem
        # Read the data for param env_lab_data
        var_env_lab_data = dataview_uniq_asn.ENV_GUI()
        var_env_lab_data.SetData(self._pMem)
        print("Parameter env_lab_data:")
        var_env_lab_data.PrintAll()
        print()
        # self._pMem = DV.MovePtrBySizeOf_ENV_GUI(self._pMem)
        # Revert the pointer to start of the data
        self._pMem = backup
    if self.messageReceivedType == i_HTL_Data:
        print("\n"+chr(27)+"[32m" + "Received Telemetry: HTL_Data" + chr(27) + "[0m\n")
        backup = self._pMem
        # Read the data for param htl_data
        var_htl_data = dataview_uniq_asn.HTL_GUI()
        var_htl_data.SetData(self._pMem)
        print("Parameter htl_data:")
        var_htl_data.PrintAll()
        print()
        # self._pMem = DV.MovePtrBySizeOf_HTL_GUI(self._pMem)
        # Revert the pointer to start of the data
        self._pMem = backup

if __name__ == "__main__":
    poll_gui = Poll_gui()
    poll_gui.start()
    try:
        time.sleep(1e8)
    except:
        poll_gui._bDie = True
        poll_gui.join()