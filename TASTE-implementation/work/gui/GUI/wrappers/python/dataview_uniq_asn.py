from functools import partial

import DV

from Stubs import (
    myassert, Clean, DataStream, COMMON)

class T_Int16(COMMON):
    def __init__(self, ptr=None):
        super(T_Int16, self).__init__("T_Int16", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_UInt16(COMMON):
    def __init__(self, ptr=None):
        super(T_UInt16, self).__init__("T_UInt16", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_UInt64(COMMON):
    def __init__(self, ptr=None):
        super(T_UInt64, self).__init__("T_UInt64", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Float(COMMON):
    def __init__(self, ptr=None):
        super(T_Float, self).__init__("T_Float", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Double(COMMON):
    def __init__(self, ptr=None):
        super(T_Double, self).__init__("T_Double", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class File_Name(COMMON):
    def __init__(self, ptr=None):
        super(File_Name, self).__init__("File_Name", ptr)
#

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("\""+str(self.GetPyString()) + "\"")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Content_Validity(COMMON):
    # Allowed enumerants:
    valid = 0
    invalid = 1
    allowed = [valid, invalid]
    def __init__(self, ptr=None):
        super(Content_Validity, self).__init__("Content_Validity", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+{'0': 'valid', '1': 'invalid'}[str(self.Get())])

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class SPI_ID(COMMON):
    # Ordered list of fields:
    children_ordered = ['bus', 'cs']

    def __init__(self, ptr=None):
        super(SPI_ID, self).__init__("SPI_ID", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("bus ")
        lines.append(" "+str(self.bus.Get()))
        lines.append(', ')
        lines.append("cs ")
        lines.append(" "+str(self.cs.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class I2C_ID(COMMON):
    # Ordered list of fields:
    children_ordered = ['bus', 'address']

    def __init__(self, ptr=None):
        super(I2C_ID, self).__init__("I2C_ID", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("bus ")
        lines.append(" "+str(self.bus.Get()))
        lines.append(', ')
        lines.append("address ")
        lines.append(" "+str(self.address.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class GPS_PVT(COMMON):
    # Ordered list of fields:
    children_ordered = ['mode', 'date-and-time', 'ept', 'latitude', 'epy', 'longitude', 'epx', 'altitude', 'epv', 'course', 'epd', 'speed', 'eps', 'climb', 'epc']

    def __init__(self, ptr=None):
        super(GPS_PVT, self).__init__("GPS_PVT", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("mode ")
        lines.append(" "+{'0': 'not-seen', '1': 'no-fix', '2': 'two-dims', '3': 'three-dims'}[str(self.mode.Get())])
        lines.append(', ')
        lines.append("date-and-time ")
        lines.append(" "+str(self.date_and_time.Get()))
        lines.append(', ')
        lines.append("ept ")
        lines.append(" "+str(self.ept.Get()))
        lines.append(', ')
        lines.append("latitude ")
        lines.append(" "+str(self.latitude.Get()))
        lines.append(', ')
        lines.append("epy ")
        lines.append(" "+str(self.epy.Get()))
        lines.append(', ')
        lines.append("longitude ")
        lines.append(" "+str(self.longitude.Get()))
        lines.append(', ')
        lines.append("epx ")
        lines.append(" "+str(self.epx.Get()))
        lines.append(', ')
        lines.append("altitude ")
        lines.append(" "+str(self.altitude.Get()))
        lines.append(', ')
        lines.append("epv ")
        lines.append(" "+str(self.epv.Get()))
        lines.append(', ')
        lines.append("course ")
        lines.append(" "+str(self.course.Get()))
        lines.append(', ')
        lines.append("epd ")
        lines.append(" "+str(self.epd.Get()))
        lines.append(', ')
        lines.append("speed ")
        lines.append(" "+str(self.speed.Get()))
        lines.append(', ')
        lines.append("eps ")
        lines.append(" "+str(self.eps.Get()))
        lines.append(', ')
        lines.append("climb ")
        lines.append(" "+str(self.climb.Get()))
        lines.append(', ')
        lines.append("epc ")
        lines.append(" "+str(self.epc.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class MGT_Raw_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['x-axis', 'y-axis', 'z-axis']

    def __init__(self, ptr=None):
        super(MGT_Raw_Data, self).__init__("MGT_Raw_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("x-axis ")
        lines.append(" "+str(self.x_axis.Get()))
        lines.append(', ')
        lines.append("y-axis ")
        lines.append(" "+str(self.y_axis.Get()))
        lines.append(', ')
        lines.append("z-axis ")
        lines.append(" "+str(self.z_axis.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class MGT_MilliGauss_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['x-axis', 'y-axis', 'z-axis']

    def __init__(self, ptr=None):
        super(MGT_MilliGauss_Data, self).__init__("MGT_MilliGauss_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("x-axis ")
        lines.append(" "+str(self.x_axis.Get()))
        lines.append(', ')
        lines.append("y-axis ")
        lines.append(" "+str(self.y_axis.Get()))
        lines.append(', ')
        lines.append("z-axis ")
        lines.append(" "+str(self.z_axis.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class ACC_Raw_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['x-axis', 'y-axis', 'z-axis']

    def __init__(self, ptr=None):
        super(ACC_Raw_Data, self).__init__("ACC_Raw_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("x-axis ")
        lines.append(" "+str(self.x_axis.Get()))
        lines.append(', ')
        lines.append("y-axis ")
        lines.append(" "+str(self.y_axis.Get()))
        lines.append(', ')
        lines.append("z-axis ")
        lines.append(" "+str(self.z_axis.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class ACC_MilliG_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['x-axis', 'y-axis', 'z-axis']

    def __init__(self, ptr=None):
        super(ACC_MilliG_Data, self).__init__("ACC_MilliG_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("x-axis ")
        lines.append(" "+str(self.x_axis.Get()))
        lines.append(', ')
        lines.append("y-axis ")
        lines.append(" "+str(self.y_axis.Get()))
        lines.append(', ')
        lines.append("z-axis ")
        lines.append(" "+str(self.z_axis.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class GYRO_Raw_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['x-axis', 'y-axis', 'z-axis']

    def __init__(self, ptr=None):
        super(GYRO_Raw_Data, self).__init__("GYRO_Raw_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("x-axis ")
        lines.append(" "+str(self.x_axis.Get()))
        lines.append(', ')
        lines.append("y-axis ")
        lines.append(" "+str(self.y_axis.Get()))
        lines.append(', ')
        lines.append("z-axis ")
        lines.append(" "+str(self.z_axis.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class GYRO_MilliDPS_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['x-axis', 'y-axis', 'z-axis']

    def __init__(self, ptr=None):
        super(GYRO_MilliDPS_Data, self).__init__("GYRO_MilliDPS_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("x-axis ")
        lines.append(" "+str(self.x_axis.Get()))
        lines.append(', ')
        lines.append("y-axis ")
        lines.append(" "+str(self.y_axis.Get()))
        lines.append(', ')
        lines.append("z-axis ")
        lines.append(" "+str(self.z_axis.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class IMU_All_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['mgt-raw', 'mgt-mgauss', 'accel-raw', 'accel-mg', 'gyro-raw', 'gyro-mdps', 'temp-raw', 'temp-celsius', 'mgt-valid', 'acc-valid', 'gyro-valid', 'temp-valid']

    def __init__(self, ptr=None):
        super(IMU_All_Data, self).__init__("IMU_All_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("mgt-raw ")
        lines.append("{")
        lines.append(" x-axis ")
        lines.append("  "+str(self.mgt_raw.x_axis.Get()))
        lines.append(', ')
        lines.append(" y-axis ")
        lines.append("  "+str(self.mgt_raw.y_axis.Get()))
        lines.append(', ')
        lines.append(" z-axis ")
        lines.append("  "+str(self.mgt_raw.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("mgt-mgauss ")
        lines.append("{")
        lines.append(" x-axis ")
        lines.append("  "+str(self.mgt_mgauss.x_axis.Get()))
        lines.append(', ')
        lines.append(" y-axis ")
        lines.append("  "+str(self.mgt_mgauss.y_axis.Get()))
        lines.append(', ')
        lines.append(" z-axis ")
        lines.append("  "+str(self.mgt_mgauss.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("accel-raw ")
        lines.append("{")
        lines.append(" x-axis ")
        lines.append("  "+str(self.accel_raw.x_axis.Get()))
        lines.append(', ')
        lines.append(" y-axis ")
        lines.append("  "+str(self.accel_raw.y_axis.Get()))
        lines.append(', ')
        lines.append(" z-axis ")
        lines.append("  "+str(self.accel_raw.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("accel-mg ")
        lines.append("{")
        lines.append(" x-axis ")
        lines.append("  "+str(self.accel_mg.x_axis.Get()))
        lines.append(', ')
        lines.append(" y-axis ")
        lines.append("  "+str(self.accel_mg.y_axis.Get()))
        lines.append(', ')
        lines.append(" z-axis ")
        lines.append("  "+str(self.accel_mg.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("gyro-raw ")
        lines.append("{")
        lines.append(" x-axis ")
        lines.append("  "+str(self.gyro_raw.x_axis.Get()))
        lines.append(', ')
        lines.append(" y-axis ")
        lines.append("  "+str(self.gyro_raw.y_axis.Get()))
        lines.append(', ')
        lines.append(" z-axis ")
        lines.append("  "+str(self.gyro_raw.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("gyro-mdps ")
        lines.append("{")
        lines.append(" x-axis ")
        lines.append("  "+str(self.gyro_mdps.x_axis.Get()))
        lines.append(', ')
        lines.append(" y-axis ")
        lines.append("  "+str(self.gyro_mdps.y_axis.Get()))
        lines.append(', ')
        lines.append(" z-axis ")
        lines.append("  "+str(self.gyro_mdps.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("temp-raw ")
        lines.append(" "+str(self.temp_raw.Get()))
        lines.append(', ')
        lines.append("temp-celsius ")
        lines.append(" "+str(self.temp_celsius.Get()))
        lines.append(', ')
        lines.append("mgt-valid ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.mgt_valid.Get())])
        lines.append(', ')
        lines.append("acc-valid ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.acc_valid.Get())])
        lines.append(', ')
        lines.append("gyro-valid ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.gyro_valid.Get())])
        lines.append(', ')
        lines.append("temp-valid ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.temp_valid.Get())])
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class TC74s_I2CBuses(COMMON):
    def __init__(self, ptr=None):
        super(TC74s_I2CBuses, self).__init__("TC74s_I2CBuses", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append(" "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self), range(length)))
        self.Reset(state)
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class TC74s_All_Data(COMMON):
    def __init__(self, ptr=None):
        super(TC74s_All_Data, self).__init__("TC74s_All_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("{")
            lines.append(" temperature ")
            lines.append("  "+str(path[i].temperature.Get()))
            path.Reset(state)
            lines.append(', ')
            lines.append(" validity ")
            lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(path[i].validity.Get())])
            path.Reset(state)
            lines.append("}")
            path.Reset(state)
        state = self.GetState()
        length = self.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self), range(length)))
        self.Reset(state)
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PT1000s_Channels(COMMON):
    def __init__(self, ptr=None):
        super(PT1000s_Channels, self).__init__("PT1000s_Channels", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append(" "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self), range(length)))
        self.Reset(state)
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PT1000s_Raw_Data(COMMON):
    def __init__(self, ptr=None):
        super(PT1000s_Raw_Data, self).__init__("PT1000s_Raw_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("{")
            lines.append(" vcc-volts ")
            lines.append("  "+str(path[i].vcc_volts.Get()))
            path.Reset(state)
            lines.append(', ')
            lines.append(" pt1000 ")
            lines.append("  "+str(path[i].pt1000.Get()))
            path.Reset(state)
            lines.append("}")
            path.Reset(state)
        state = self.GetState()
        length = self.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self), range(length)))
        self.Reset(state)
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PT1000s_Celsius_Data(COMMON):
    def __init__(self, ptr=None):
        super(PT1000s_Celsius_Data, self).__init__("PT1000s_Celsius_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append(" "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self), range(length)))
        self.Reset(state)
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PT1000s_All_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['raw', 'celsius', 'validity']

    def __init__(self, ptr=None):
        super(PT1000s_All_Data, self).__init__("PT1000s_All_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("raw ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("{")
            lines.append("  vcc-volts ")
            lines.append("   "+str(path[i].vcc_volts.Get()))
            path.Reset(state)
            lines.append(', ')
            lines.append("  pt1000 ")
            lines.append("   "+str(path[i].pt1000.Get()))
            path.Reset(state)
            lines.append("}")
            path.Reset(state)
        state = self.GetState()
        length = self.raw.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.raw), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append("celsius ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("  "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.celsius.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.celsius), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append("validity ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(path[i].Get())])
            path.Reset(state)
        state = self.GetState()
        length = self.validity.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.validity), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PS_Calibration_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['c1', 'c2', 'c3', 'c4', 'c5', 'c6', 'sens-t1', 'off-t1', 'tcs', 'tco', 'tref', 'temp-sens']

    def __init__(self, ptr=None):
        super(PS_Calibration_Data, self).__init__("PS_Calibration_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("c1 ")
        lines.append(" "+str(self.c1.Get()))
        lines.append(', ')
        lines.append("c2 ")
        lines.append(" "+str(self.c2.Get()))
        lines.append(', ')
        lines.append("c3 ")
        lines.append(" "+str(self.c3.Get()))
        lines.append(', ')
        lines.append("c4 ")
        lines.append(" "+str(self.c4.Get()))
        lines.append(', ')
        lines.append("c5 ")
        lines.append(" "+str(self.c5.Get()))
        lines.append(', ')
        lines.append("c6 ")
        lines.append(" "+str(self.c6.Get()))
        lines.append(', ')
        lines.append("sens-t1 ")
        lines.append(" "+str(self.sens_t1.Get()))
        lines.append(', ')
        lines.append("off-t1 ")
        lines.append(" "+str(self.off_t1.Get()))
        lines.append(', ')
        lines.append("tcs ")
        lines.append(" "+str(self.tcs.Get()))
        lines.append(', ')
        lines.append("tco ")
        lines.append(" "+str(self.tco.Get()))
        lines.append(', ')
        lines.append("tref ")
        lines.append(" "+str(self.tref.Get()))
        lines.append(', ')
        lines.append("temp-sens ")
        lines.append(" "+str(self.temp_sens.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PS_Raw_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['d1', 'd2']

    def __init__(self, ptr=None):
        super(PS_Raw_Data, self).__init__("PS_Raw_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("d1 ")
        lines.append(" "+str(self.d1.Get()))
        lines.append(', ')
        lines.append("d2 ")
        lines.append(" "+str(self.d2.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PS_Processed_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['pressure', 'temp']

    def __init__(self, ptr=None):
        super(PS_Processed_Data, self).__init__("PS_Processed_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("pressure ")
        lines.append(" "+str(self.pressure.Get()))
        lines.append(', ')
        lines.append("temp ")
        lines.append(" "+str(self.temp.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PS_All_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['calib', 'raw', 'processed', 'validity']

    def __init__(self, ptr=None):
        super(PS_All_Data, self).__init__("PS_All_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("calib ")
        lines.append("{")
        lines.append(" c1 ")
        lines.append("  "+str(self.calib.c1.Get()))
        lines.append(', ')
        lines.append(" c2 ")
        lines.append("  "+str(self.calib.c2.Get()))
        lines.append(', ')
        lines.append(" c3 ")
        lines.append("  "+str(self.calib.c3.Get()))
        lines.append(', ')
        lines.append(" c4 ")
        lines.append("  "+str(self.calib.c4.Get()))
        lines.append(', ')
        lines.append(" c5 ")
        lines.append("  "+str(self.calib.c5.Get()))
        lines.append(', ')
        lines.append(" c6 ")
        lines.append("  "+str(self.calib.c6.Get()))
        lines.append(', ')
        lines.append(" sens-t1 ")
        lines.append("  "+str(self.calib.sens_t1.Get()))
        lines.append(', ')
        lines.append(" off-t1 ")
        lines.append("  "+str(self.calib.off_t1.Get()))
        lines.append(', ')
        lines.append(" tcs ")
        lines.append("  "+str(self.calib.tcs.Get()))
        lines.append(', ')
        lines.append(" tco ")
        lines.append("  "+str(self.calib.tco.Get()))
        lines.append(', ')
        lines.append(" tref ")
        lines.append("  "+str(self.calib.tref.Get()))
        lines.append(', ')
        lines.append(" temp-sens ")
        lines.append("  "+str(self.calib.temp_sens.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("raw ")
        lines.append("{")
        lines.append(" d1 ")
        lines.append("  "+str(self.raw.d1.Get()))
        lines.append(', ')
        lines.append(" d2 ")
        lines.append("  "+str(self.raw.d2.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("processed ")
        lines.append("{")
        lines.append(" pressure ")
        lines.append("  "+str(self.processed.pressure.Get()))
        lines.append(', ')
        lines.append(" temp ")
        lines.append("  "+str(self.processed.temp.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("validity ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.validity.Get())])
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Heater_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['power-watts', 'validity']

    def __init__(self, ptr=None):
        super(Heater_Data, self).__init__("Heater_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("power-watts ")
        lines.append(" "+str(self.power_watts.Get()))
        lines.append(', ')
        lines.append("validity ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.validity.Get())])
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Heater_On_Off(COMMON):
    # Allowed enumerants:
    on = 0
    off = 1
    allowed = [on, off]
    def __init__(self, ptr=None):
        super(Heater_On_Off, self).__init__("Heater_On_Off", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+{'0': 'on', '1': 'off'}[str(self.Get())])

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class HTL_State(COMMON):
    # Allowed enumerants:
    a1 = 0
    a2 = 1
    f1 = 2
    f2 = 3
    f3 = 4
    error = 5
    allowed = [a1, a2, f1, f2, f3, error]
    def __init__(self, ptr=None):
        super(HTL_State, self).__init__("HTL_State", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+{'0': 'a1', '1': 'a2', '2': 'f1', '3': 'f2', '4': 'f3', '5': 'error'}[str(self.Get())])

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class HTL_Config(COMMON):
    # Ordered list of fields:
    children_ordered = ['press-5km', 'press-10km', 'press-18km', 'a1-duration-emergency-secs', 'a1-duration-max-secs', 'a2-duration-max-secs', 'f1-duration-secs', 'f2-duration-secs']

    def __init__(self, ptr=None):
        super(HTL_Config, self).__init__("HTL_Config", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("press-5km ")
        lines.append(" "+str(self.press_5km.Get()))
        lines.append(', ')
        lines.append("press-10km ")
        lines.append(" "+str(self.press_10km.Get()))
        lines.append(', ')
        lines.append("press-18km ")
        lines.append(" "+str(self.press_18km.Get()))
        lines.append(', ')
        lines.append("a1-duration-emergency-secs ")
        lines.append(" "+str(self.a1_duration_emergency_secs.Get()))
        lines.append(', ')
        lines.append("a1-duration-max-secs ")
        lines.append(" "+str(self.a1_duration_max_secs.Get()))
        lines.append(', ')
        lines.append("a2-duration-max-secs ")
        lines.append(" "+str(self.a2_duration_max_secs.Get()))
        lines.append(', ')
        lines.append("f1-duration-secs ")
        lines.append(" "+str(self.f1_duration_secs.Get()))
        lines.append(', ')
        lines.append("f2-duration-secs ")
        lines.append(" "+str(self.f2_duration_secs.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class OBSW_DP_Data(COMMON):
    # Ordered list of fields:
    children_ordered = ['gps', 'imu', 'tc74s', 'pt1000s', 'ps1', 'ps2', 'heater1', 'heater2', 'anemometer']

    def __init__(self, ptr=None):
        super(OBSW_DP_Data, self).__init__("OBSW_DP_Data", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("gps ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        lines.append("  mode ")
        lines.append("   "+{'0': 'not-seen', '1': 'no-fix', '2': 'two-dims', '3': 'three-dims'}[str(self.gps.data.mode.Get())])
        lines.append(', ')
        lines.append("  date-and-time ")
        lines.append("   "+str(self.gps.data.date_and_time.Get()))
        lines.append(', ')
        lines.append("  ept ")
        lines.append("   "+str(self.gps.data.ept.Get()))
        lines.append(', ')
        lines.append("  latitude ")
        lines.append("   "+str(self.gps.data.latitude.Get()))
        lines.append(', ')
        lines.append("  epy ")
        lines.append("   "+str(self.gps.data.epy.Get()))
        lines.append(', ')
        lines.append("  longitude ")
        lines.append("   "+str(self.gps.data.longitude.Get()))
        lines.append(', ')
        lines.append("  epx ")
        lines.append("   "+str(self.gps.data.epx.Get()))
        lines.append(', ')
        lines.append("  altitude ")
        lines.append("   "+str(self.gps.data.altitude.Get()))
        lines.append(', ')
        lines.append("  epv ")
        lines.append("   "+str(self.gps.data.epv.Get()))
        lines.append(', ')
        lines.append("  course ")
        lines.append("   "+str(self.gps.data.course.Get()))
        lines.append(', ')
        lines.append("  epd ")
        lines.append("   "+str(self.gps.data.epd.Get()))
        lines.append(', ')
        lines.append("  speed ")
        lines.append("   "+str(self.gps.data.speed.Get()))
        lines.append(', ')
        lines.append("  eps ")
        lines.append("   "+str(self.gps.data.eps.Get()))
        lines.append(', ')
        lines.append("  climb ")
        lines.append("   "+str(self.gps.data.climb.Get()))
        lines.append(', ')
        lines.append("  epc ")
        lines.append("   "+str(self.gps.data.epc.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.gps.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.gps.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("imu ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        lines.append("  mgt-raw ")
        lines.append("{")
        lines.append("   x-axis ")
        lines.append("    "+str(self.imu.data.mgt_raw.x_axis.Get()))
        lines.append(', ')
        lines.append("   y-axis ")
        lines.append("    "+str(self.imu.data.mgt_raw.y_axis.Get()))
        lines.append(', ')
        lines.append("   z-axis ")
        lines.append("    "+str(self.imu.data.mgt_raw.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  mgt-mgauss ")
        lines.append("{")
        lines.append("   x-axis ")
        lines.append("    "+str(self.imu.data.mgt_mgauss.x_axis.Get()))
        lines.append(', ')
        lines.append("   y-axis ")
        lines.append("    "+str(self.imu.data.mgt_mgauss.y_axis.Get()))
        lines.append(', ')
        lines.append("   z-axis ")
        lines.append("    "+str(self.imu.data.mgt_mgauss.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  accel-raw ")
        lines.append("{")
        lines.append("   x-axis ")
        lines.append("    "+str(self.imu.data.accel_raw.x_axis.Get()))
        lines.append(', ')
        lines.append("   y-axis ")
        lines.append("    "+str(self.imu.data.accel_raw.y_axis.Get()))
        lines.append(', ')
        lines.append("   z-axis ")
        lines.append("    "+str(self.imu.data.accel_raw.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  accel-mg ")
        lines.append("{")
        lines.append("   x-axis ")
        lines.append("    "+str(self.imu.data.accel_mg.x_axis.Get()))
        lines.append(', ')
        lines.append("   y-axis ")
        lines.append("    "+str(self.imu.data.accel_mg.y_axis.Get()))
        lines.append(', ')
        lines.append("   z-axis ")
        lines.append("    "+str(self.imu.data.accel_mg.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  gyro-raw ")
        lines.append("{")
        lines.append("   x-axis ")
        lines.append("    "+str(self.imu.data.gyro_raw.x_axis.Get()))
        lines.append(', ')
        lines.append("   y-axis ")
        lines.append("    "+str(self.imu.data.gyro_raw.y_axis.Get()))
        lines.append(', ')
        lines.append("   z-axis ")
        lines.append("    "+str(self.imu.data.gyro_raw.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  gyro-mdps ")
        lines.append("{")
        lines.append("   x-axis ")
        lines.append("    "+str(self.imu.data.gyro_mdps.x_axis.Get()))
        lines.append(', ')
        lines.append("   y-axis ")
        lines.append("    "+str(self.imu.data.gyro_mdps.y_axis.Get()))
        lines.append(', ')
        lines.append("   z-axis ")
        lines.append("    "+str(self.imu.data.gyro_mdps.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  temp-raw ")
        lines.append("   "+str(self.imu.data.temp_raw.Get()))
        lines.append(', ')
        lines.append("  temp-celsius ")
        lines.append("   "+str(self.imu.data.temp_celsius.Get()))
        lines.append(', ')
        lines.append("  mgt-valid ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.mgt_valid.Get())])
        lines.append(', ')
        lines.append("  acc-valid ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.acc_valid.Get())])
        lines.append(', ')
        lines.append("  gyro-valid ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.gyro_valid.Get())])
        lines.append(', ')
        lines.append("  temp-valid ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.temp_valid.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.imu.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.imu.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("tc74s ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("{")
            lines.append("   temperature ")
            lines.append("    "+str(path[i].temperature.Get()))
            path.Reset(state)
            lines.append(', ')
            lines.append("   validity ")
            lines.append("    "+{'0': 'valid', '1': 'invalid'}[str(path[i].validity.Get())])
            path.Reset(state)
            lines.append("}")
            path.Reset(state)
        state = self.GetState()
        length = self.tc74s.data.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.tc74s.data), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.tc74s.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.tc74s.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("pt1000s ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        lines.append("  raw ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("{")
            lines.append("    vcc-volts ")
            lines.append("     "+str(path[i].vcc_volts.Get()))
            path.Reset(state)
            lines.append(', ')
            lines.append("    pt1000 ")
            lines.append("     "+str(path[i].pt1000.Get()))
            path.Reset(state)
            lines.append("}")
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s.data.raw.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s.data.raw), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append("  celsius ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("    "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s.data.celsius.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s.data.celsius), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append("  validity ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("    "+{'0': 'valid', '1': 'invalid'}[str(path[i].Get())])
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s.data.validity.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s.data.validity), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.pt1000s.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.pt1000s.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("ps1 ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        lines.append("  calib ")
        lines.append("{")
        lines.append("   c1 ")
        lines.append("    "+str(self.ps1.data.calib.c1.Get()))
        lines.append(', ')
        lines.append("   c2 ")
        lines.append("    "+str(self.ps1.data.calib.c2.Get()))
        lines.append(', ')
        lines.append("   c3 ")
        lines.append("    "+str(self.ps1.data.calib.c3.Get()))
        lines.append(', ')
        lines.append("   c4 ")
        lines.append("    "+str(self.ps1.data.calib.c4.Get()))
        lines.append(', ')
        lines.append("   c5 ")
        lines.append("    "+str(self.ps1.data.calib.c5.Get()))
        lines.append(', ')
        lines.append("   c6 ")
        lines.append("    "+str(self.ps1.data.calib.c6.Get()))
        lines.append(', ')
        lines.append("   sens-t1 ")
        lines.append("    "+str(self.ps1.data.calib.sens_t1.Get()))
        lines.append(', ')
        lines.append("   off-t1 ")
        lines.append("    "+str(self.ps1.data.calib.off_t1.Get()))
        lines.append(', ')
        lines.append("   tcs ")
        lines.append("    "+str(self.ps1.data.calib.tcs.Get()))
        lines.append(', ')
        lines.append("   tco ")
        lines.append("    "+str(self.ps1.data.calib.tco.Get()))
        lines.append(', ')
        lines.append("   tref ")
        lines.append("    "+str(self.ps1.data.calib.tref.Get()))
        lines.append(', ')
        lines.append("   temp-sens ")
        lines.append("    "+str(self.ps1.data.calib.temp_sens.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  raw ")
        lines.append("{")
        lines.append("   d1 ")
        lines.append("    "+str(self.ps1.data.raw.d1.Get()))
        lines.append(', ')
        lines.append("   d2 ")
        lines.append("    "+str(self.ps1.data.raw.d2.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  processed ")
        lines.append("{")
        lines.append("   pressure ")
        lines.append("    "+str(self.ps1.data.processed.pressure.Get()))
        lines.append(', ')
        lines.append("   temp ")
        lines.append("    "+str(self.ps1.data.processed.temp.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  validity ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.ps1.data.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.ps1.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.ps1.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("ps2 ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        lines.append("  calib ")
        lines.append("{")
        lines.append("   c1 ")
        lines.append("    "+str(self.ps2.data.calib.c1.Get()))
        lines.append(', ')
        lines.append("   c2 ")
        lines.append("    "+str(self.ps2.data.calib.c2.Get()))
        lines.append(', ')
        lines.append("   c3 ")
        lines.append("    "+str(self.ps2.data.calib.c3.Get()))
        lines.append(', ')
        lines.append("   c4 ")
        lines.append("    "+str(self.ps2.data.calib.c4.Get()))
        lines.append(', ')
        lines.append("   c5 ")
        lines.append("    "+str(self.ps2.data.calib.c5.Get()))
        lines.append(', ')
        lines.append("   c6 ")
        lines.append("    "+str(self.ps2.data.calib.c6.Get()))
        lines.append(', ')
        lines.append("   sens-t1 ")
        lines.append("    "+str(self.ps2.data.calib.sens_t1.Get()))
        lines.append(', ')
        lines.append("   off-t1 ")
        lines.append("    "+str(self.ps2.data.calib.off_t1.Get()))
        lines.append(', ')
        lines.append("   tcs ")
        lines.append("    "+str(self.ps2.data.calib.tcs.Get()))
        lines.append(', ')
        lines.append("   tco ")
        lines.append("    "+str(self.ps2.data.calib.tco.Get()))
        lines.append(', ')
        lines.append("   tref ")
        lines.append("    "+str(self.ps2.data.calib.tref.Get()))
        lines.append(', ')
        lines.append("   temp-sens ")
        lines.append("    "+str(self.ps2.data.calib.temp_sens.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  raw ")
        lines.append("{")
        lines.append("   d1 ")
        lines.append("    "+str(self.ps2.data.raw.d1.Get()))
        lines.append(', ')
        lines.append("   d2 ")
        lines.append("    "+str(self.ps2.data.raw.d2.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  processed ")
        lines.append("{")
        lines.append("   pressure ")
        lines.append("    "+str(self.ps2.data.processed.pressure.Get()))
        lines.append(', ')
        lines.append("   temp ")
        lines.append("    "+str(self.ps2.data.processed.temp.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("  validity ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.ps2.data.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.ps2.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.ps2.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("heater1 ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        lines.append("  power-watts ")
        lines.append("   "+str(self.heater1.data.power_watts.Get()))
        lines.append(', ')
        lines.append("  validity ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.heater1.data.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.heater1.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.heater1.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("heater2 ")
        lines.append("{")
        lines.append(" data ")
        lines.append("{")
        lines.append("  power-watts ")
        lines.append("   "+str(self.heater2.data.power_watts.Get()))
        lines.append(', ')
        lines.append("  validity ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.heater2.data.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.heater2.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.heater2.mission_time.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("anemometer ")
        lines.append("{")
        lines.append(" data ")
        lines.append("  "+str(self.anemometer.data.Get()))
        lines.append(', ')
        lines.append(" gps-time ")
        lines.append("  "+str(self.anemometer.gps_time.Get()))
        lines.append(', ')
        lines.append(" mission-time ")
        lines.append("  "+str(self.anemometer.mission_time.Get()))
        lines.append("}")
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class OBSW_DP_Filter(COMMON):
    # Allowed enumerants:
    gps = 0
    imu = 1
    tc74s = 2
    pt1000s = 3
    ps1 = 4
    ps2 = 5
    heater1 = 6
    heater2 = 7
    anemometer = 8
    allowed = [gps, imu, tc74s, pt1000s, ps1, ps2, heater1, heater2, anemometer]
    def __init__(self, ptr=None):
        super(OBSW_DP_Filter, self).__init__("OBSW_DP_Filter", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+{'0': 'gps', '1': 'imu', '2': 'tc74s', '3': 'pt1000s', '4': 'ps1', '5': 'ps2', '6': 'heater1', '7': 'heater2', '8': 'anemometer'}[str(self.Get())])

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class OBSW_DP_SingleData(COMMON):
    def __init__(self, ptr=None):
        super(OBSW_DP_SingleData, self).__init__("OBSW_DP_SingleData", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        if self.kind.Get() == DV.gps_PRESENT:
         lines.append("gps: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         lines.append("  mode ")
         lines.append("   "+{'0': 'not-seen', '1': 'no-fix', '2': 'two-dims', '3': 'three-dims'}[str(self.gps.data.mode.Get())])
         lines.append(', ')
         lines.append("  date-and-time ")
         lines.append("   "+str(self.gps.data.date_and_time.Get()))
         lines.append(', ')
         lines.append("  ept ")
         lines.append("   "+str(self.gps.data.ept.Get()))
         lines.append(', ')
         lines.append("  latitude ")
         lines.append("   "+str(self.gps.data.latitude.Get()))
         lines.append(', ')
         lines.append("  epy ")
         lines.append("   "+str(self.gps.data.epy.Get()))
         lines.append(', ')
         lines.append("  longitude ")
         lines.append("   "+str(self.gps.data.longitude.Get()))
         lines.append(', ')
         lines.append("  epx ")
         lines.append("   "+str(self.gps.data.epx.Get()))
         lines.append(', ')
         lines.append("  altitude ")
         lines.append("   "+str(self.gps.data.altitude.Get()))
         lines.append(', ')
         lines.append("  epv ")
         lines.append("   "+str(self.gps.data.epv.Get()))
         lines.append(', ')
         lines.append("  course ")
         lines.append("   "+str(self.gps.data.course.Get()))
         lines.append(', ')
         lines.append("  epd ")
         lines.append("   "+str(self.gps.data.epd.Get()))
         lines.append(', ')
         lines.append("  speed ")
         lines.append("   "+str(self.gps.data.speed.Get()))
         lines.append(', ')
         lines.append("  eps ")
         lines.append("   "+str(self.gps.data.eps.Get()))
         lines.append(', ')
         lines.append("  climb ")
         lines.append("   "+str(self.gps.data.climb.Get()))
         lines.append(', ')
         lines.append("  epc ")
         lines.append("   "+str(self.gps.data.epc.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.gps.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.gps.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.imu_PRESENT:
         lines.append("imu: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         lines.append("  mgt-raw ")
         lines.append("{")
         lines.append("   x-axis ")
         lines.append("    "+str(self.imu.data.mgt_raw.x_axis.Get()))
         lines.append(', ')
         lines.append("   y-axis ")
         lines.append("    "+str(self.imu.data.mgt_raw.y_axis.Get()))
         lines.append(', ')
         lines.append("   z-axis ")
         lines.append("    "+str(self.imu.data.mgt_raw.z_axis.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  mgt-mgauss ")
         lines.append("{")
         lines.append("   x-axis ")
         lines.append("    "+str(self.imu.data.mgt_mgauss.x_axis.Get()))
         lines.append(', ')
         lines.append("   y-axis ")
         lines.append("    "+str(self.imu.data.mgt_mgauss.y_axis.Get()))
         lines.append(', ')
         lines.append("   z-axis ")
         lines.append("    "+str(self.imu.data.mgt_mgauss.z_axis.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  accel-raw ")
         lines.append("{")
         lines.append("   x-axis ")
         lines.append("    "+str(self.imu.data.accel_raw.x_axis.Get()))
         lines.append(', ')
         lines.append("   y-axis ")
         lines.append("    "+str(self.imu.data.accel_raw.y_axis.Get()))
         lines.append(', ')
         lines.append("   z-axis ")
         lines.append("    "+str(self.imu.data.accel_raw.z_axis.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  accel-mg ")
         lines.append("{")
         lines.append("   x-axis ")
         lines.append("    "+str(self.imu.data.accel_mg.x_axis.Get()))
         lines.append(', ')
         lines.append("   y-axis ")
         lines.append("    "+str(self.imu.data.accel_mg.y_axis.Get()))
         lines.append(', ')
         lines.append("   z-axis ")
         lines.append("    "+str(self.imu.data.accel_mg.z_axis.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  gyro-raw ")
         lines.append("{")
         lines.append("   x-axis ")
         lines.append("    "+str(self.imu.data.gyro_raw.x_axis.Get()))
         lines.append(', ')
         lines.append("   y-axis ")
         lines.append("    "+str(self.imu.data.gyro_raw.y_axis.Get()))
         lines.append(', ')
         lines.append("   z-axis ")
         lines.append("    "+str(self.imu.data.gyro_raw.z_axis.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  gyro-mdps ")
         lines.append("{")
         lines.append("   x-axis ")
         lines.append("    "+str(self.imu.data.gyro_mdps.x_axis.Get()))
         lines.append(', ')
         lines.append("   y-axis ")
         lines.append("    "+str(self.imu.data.gyro_mdps.y_axis.Get()))
         lines.append(', ')
         lines.append("   z-axis ")
         lines.append("    "+str(self.imu.data.gyro_mdps.z_axis.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  temp-raw ")
         lines.append("   "+str(self.imu.data.temp_raw.Get()))
         lines.append(', ')
         lines.append("  temp-celsius ")
         lines.append("   "+str(self.imu.data.temp_celsius.Get()))
         lines.append(', ')
         lines.append("  mgt-valid ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.mgt_valid.Get())])
         lines.append(', ')
         lines.append("  acc-valid ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.acc_valid.Get())])
         lines.append(', ')
         lines.append("  gyro-valid ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.gyro_valid.Get())])
         lines.append(', ')
         lines.append("  temp-valid ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.temp_valid.Get())])
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.imu.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.imu.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.tc74s_PRESENT:
         lines.append("tc74s: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         def emitElem(path, i):
             state = path.GetState()
             if i > 0:
                 lines.append(",")
             lines.append("{")
             lines.append("   temperature ")
             lines.append("    "+str(path[i].temperature.Get()))
             path.Reset(state)
             lines.append(', ')
             lines.append("   validity ")
             lines.append("    "+{'0': 'valid', '1': 'invalid'}[str(path[i].validity.Get())])
             path.Reset(state)
             lines.append("}")
             path.Reset(state)
         state = self.GetState()
         length = self.tc74s.data.GetLength()
         self.Reset(state)
         list(map(partial(emitElem, self.tc74s.data), range(length)))
         self.Reset(state)
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.tc74s.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.tc74s.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.pt1000s_PRESENT:
         lines.append("pt1000s: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         lines.append("  raw ")
         lines.append("{")
         def emitElem(path, i):
             state = path.GetState()
             if i > 0:
                 lines.append(",")
             lines.append("{")
             lines.append("    vcc-volts ")
             lines.append("     "+str(path[i].vcc_volts.Get()))
             path.Reset(state)
             lines.append(', ')
             lines.append("    pt1000 ")
             lines.append("     "+str(path[i].pt1000.Get()))
             path.Reset(state)
             lines.append("}")
             path.Reset(state)
         state = self.GetState()
         length = self.pt1000s.data.raw.GetLength()
         self.Reset(state)
         list(map(partial(emitElem, self.pt1000s.data.raw), range(length)))
         self.Reset(state)
         lines.append("}")
         lines.append(', ')
         lines.append("  celsius ")
         lines.append("{")
         def emitElem(path, i):
             state = path.GetState()
             if i > 0:
                 lines.append(",")
             lines.append("    "+str(path[i].Get()))
             path.Reset(state)
         state = self.GetState()
         length = self.pt1000s.data.celsius.GetLength()
         self.Reset(state)
         list(map(partial(emitElem, self.pt1000s.data.celsius), range(length)))
         self.Reset(state)
         lines.append("}")
         lines.append(', ')
         lines.append("  validity ")
         lines.append("{")
         def emitElem(path, i):
             state = path.GetState()
             if i > 0:
                 lines.append(",")
             lines.append("    "+{'0': 'valid', '1': 'invalid'}[str(path[i].Get())])
             path.Reset(state)
         state = self.GetState()
         length = self.pt1000s.data.validity.GetLength()
         self.Reset(state)
         list(map(partial(emitElem, self.pt1000s.data.validity), range(length)))
         self.Reset(state)
         lines.append("}")
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.pt1000s.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.pt1000s.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.ps1_PRESENT:
         lines.append("ps1: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         lines.append("  calib ")
         lines.append("{")
         lines.append("   c1 ")
         lines.append("    "+str(self.ps1.data.calib.c1.Get()))
         lines.append(', ')
         lines.append("   c2 ")
         lines.append("    "+str(self.ps1.data.calib.c2.Get()))
         lines.append(', ')
         lines.append("   c3 ")
         lines.append("    "+str(self.ps1.data.calib.c3.Get()))
         lines.append(', ')
         lines.append("   c4 ")
         lines.append("    "+str(self.ps1.data.calib.c4.Get()))
         lines.append(', ')
         lines.append("   c5 ")
         lines.append("    "+str(self.ps1.data.calib.c5.Get()))
         lines.append(', ')
         lines.append("   c6 ")
         lines.append("    "+str(self.ps1.data.calib.c6.Get()))
         lines.append(', ')
         lines.append("   sens-t1 ")
         lines.append("    "+str(self.ps1.data.calib.sens_t1.Get()))
         lines.append(', ')
         lines.append("   off-t1 ")
         lines.append("    "+str(self.ps1.data.calib.off_t1.Get()))
         lines.append(', ')
         lines.append("   tcs ")
         lines.append("    "+str(self.ps1.data.calib.tcs.Get()))
         lines.append(', ')
         lines.append("   tco ")
         lines.append("    "+str(self.ps1.data.calib.tco.Get()))
         lines.append(', ')
         lines.append("   tref ")
         lines.append("    "+str(self.ps1.data.calib.tref.Get()))
         lines.append(', ')
         lines.append("   temp-sens ")
         lines.append("    "+str(self.ps1.data.calib.temp_sens.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  raw ")
         lines.append("{")
         lines.append("   d1 ")
         lines.append("    "+str(self.ps1.data.raw.d1.Get()))
         lines.append(', ')
         lines.append("   d2 ")
         lines.append("    "+str(self.ps1.data.raw.d2.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  processed ")
         lines.append("{")
         lines.append("   pressure ")
         lines.append("    "+str(self.ps1.data.processed.pressure.Get()))
         lines.append(', ')
         lines.append("   temp ")
         lines.append("    "+str(self.ps1.data.processed.temp.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  validity ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.ps1.data.validity.Get())])
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.ps1.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.ps1.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.ps2_PRESENT:
         lines.append("ps2: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         lines.append("  calib ")
         lines.append("{")
         lines.append("   c1 ")
         lines.append("    "+str(self.ps2.data.calib.c1.Get()))
         lines.append(', ')
         lines.append("   c2 ")
         lines.append("    "+str(self.ps2.data.calib.c2.Get()))
         lines.append(', ')
         lines.append("   c3 ")
         lines.append("    "+str(self.ps2.data.calib.c3.Get()))
         lines.append(', ')
         lines.append("   c4 ")
         lines.append("    "+str(self.ps2.data.calib.c4.Get()))
         lines.append(', ')
         lines.append("   c5 ")
         lines.append("    "+str(self.ps2.data.calib.c5.Get()))
         lines.append(', ')
         lines.append("   c6 ")
         lines.append("    "+str(self.ps2.data.calib.c6.Get()))
         lines.append(', ')
         lines.append("   sens-t1 ")
         lines.append("    "+str(self.ps2.data.calib.sens_t1.Get()))
         lines.append(', ')
         lines.append("   off-t1 ")
         lines.append("    "+str(self.ps2.data.calib.off_t1.Get()))
         lines.append(', ')
         lines.append("   tcs ")
         lines.append("    "+str(self.ps2.data.calib.tcs.Get()))
         lines.append(', ')
         lines.append("   tco ")
         lines.append("    "+str(self.ps2.data.calib.tco.Get()))
         lines.append(', ')
         lines.append("   tref ")
         lines.append("    "+str(self.ps2.data.calib.tref.Get()))
         lines.append(', ')
         lines.append("   temp-sens ")
         lines.append("    "+str(self.ps2.data.calib.temp_sens.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  raw ")
         lines.append("{")
         lines.append("   d1 ")
         lines.append("    "+str(self.ps2.data.raw.d1.Get()))
         lines.append(', ')
         lines.append("   d2 ")
         lines.append("    "+str(self.ps2.data.raw.d2.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  processed ")
         lines.append("{")
         lines.append("   pressure ")
         lines.append("    "+str(self.ps2.data.processed.pressure.Get()))
         lines.append(', ')
         lines.append("   temp ")
         lines.append("    "+str(self.ps2.data.processed.temp.Get()))
         lines.append("}")
         lines.append(', ')
         lines.append("  validity ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.ps2.data.validity.Get())])
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.ps2.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.ps2.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.heater1_PRESENT:
         lines.append("heater1: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         lines.append("  power-watts ")
         lines.append("   "+str(self.heater1.data.power_watts.Get()))
         lines.append(', ')
         lines.append("  validity ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.heater1.data.validity.Get())])
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.heater1.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.heater1.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.heater2_PRESENT:
         lines.append("heater2: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("{")
         lines.append("  power-watts ")
         lines.append("   "+str(self.heater2.data.power_watts.Get()))
         lines.append(', ')
         lines.append("  validity ")
         lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.heater2.data.validity.Get())])
         lines.append("}")
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.heater2.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.heater2.mission_time.Get()))
         lines.append("}")
        if self.kind.Get() == DV.anemometer_PRESENT:
         lines.append("anemometer: ")
         lines.append("{")
         lines.append(" data ")
         lines.append("  "+str(self.anemometer.data.Get()))
         lines.append(', ')
         lines.append(" gps-time ")
         lines.append("  "+str(self.anemometer.gps_time.Get()))
         lines.append(', ')
         lines.append(" mission-time ")
         lines.append("  "+str(self.anemometer.mission_time.Get()))
         lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class TM(COMMON):
    # Ordered list of fields:
    children_ordered = ['state-htl', 'heater1', 'heater2', 'tc74s', 'pt1000s', 'gps', 'imu', 'ps1', 'ps2', 'ps1-validity', 'ps2-validity', 'anemometer']

    def __init__(self, ptr=None):
        super(TM, self).__init__("TM", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("state-htl ")
        lines.append(" "+{'0': 'a1', '1': 'a2', '2': 'f1', '3': 'f2', '4': 'f3', '5': 'error'}[str(self.state_htl.Get())])
        lines.append(', ')
        lines.append("heater1 ")
        lines.append("{")
        lines.append(" power-watts ")
        lines.append("  "+str(self.heater1.power_watts.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.heater1.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("heater2 ")
        lines.append("{")
        lines.append(" power-watts ")
        lines.append("  "+str(self.heater2.power_watts.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.heater2.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("tc74s ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("{")
            lines.append("  temperature ")
            lines.append("   "+str(path[i].temperature.Get()))
            path.Reset(state)
            lines.append(', ')
            lines.append("  validity ")
            lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(path[i].validity.Get())])
            path.Reset(state)
            lines.append("}")
            path.Reset(state)
        state = self.GetState()
        length = self.tc74s.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.tc74s), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append("pt1000s ")
        lines.append("{")
        lines.append(" raw ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("{")
            lines.append("   vcc-volts ")
            lines.append("    "+str(path[i].vcc_volts.Get()))
            path.Reset(state)
            lines.append(', ')
            lines.append("   pt1000 ")
            lines.append("    "+str(path[i].pt1000.Get()))
            path.Reset(state)
            lines.append("}")
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s.raw.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s.raw), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append(" celsius ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("   "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s.celsius.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s.celsius), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append(" validity ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(path[i].Get())])
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s.validity.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s.validity), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append("}")
        lines.append(', ')
        lines.append("gps ")
        lines.append("{")
        lines.append(" mode ")
        lines.append("  "+{'0': 'not-seen', '1': 'no-fix', '2': 'two-dims', '3': 'three-dims'}[str(self.gps.mode.Get())])
        lines.append(', ')
        lines.append(" date-and-time ")
        lines.append("  "+str(self.gps.date_and_time.Get()))
        lines.append(', ')
        lines.append(" ept ")
        lines.append("  "+str(self.gps.ept.Get()))
        lines.append(', ')
        lines.append(" latitude ")
        lines.append("  "+str(self.gps.latitude.Get()))
        lines.append(', ')
        lines.append(" epy ")
        lines.append("  "+str(self.gps.epy.Get()))
        lines.append(', ')
        lines.append(" longitude ")
        lines.append("  "+str(self.gps.longitude.Get()))
        lines.append(', ')
        lines.append(" epx ")
        lines.append("  "+str(self.gps.epx.Get()))
        lines.append(', ')
        lines.append(" altitude ")
        lines.append("  "+str(self.gps.altitude.Get()))
        lines.append(', ')
        lines.append(" epv ")
        lines.append("  "+str(self.gps.epv.Get()))
        lines.append(', ')
        lines.append(" course ")
        lines.append("  "+str(self.gps.course.Get()))
        lines.append(', ')
        lines.append(" epd ")
        lines.append("  "+str(self.gps.epd.Get()))
        lines.append(', ')
        lines.append(" speed ")
        lines.append("  "+str(self.gps.speed.Get()))
        lines.append(', ')
        lines.append(" eps ")
        lines.append("  "+str(self.gps.eps.Get()))
        lines.append(', ')
        lines.append(" climb ")
        lines.append("  "+str(self.gps.climb.Get()))
        lines.append(', ')
        lines.append(" epc ")
        lines.append("  "+str(self.gps.epc.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("imu ")
        lines.append("{")
        lines.append(" mgt-mgauss ")
        lines.append("{")
        lines.append("  x-axis ")
        lines.append("   "+str(self.imu.mgt_mgauss.x_axis.Get()))
        lines.append(', ')
        lines.append("  y-axis ")
        lines.append("   "+str(self.imu.mgt_mgauss.y_axis.Get()))
        lines.append(', ')
        lines.append("  z-axis ")
        lines.append("   "+str(self.imu.mgt_mgauss.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append(" accel-mg ")
        lines.append("{")
        lines.append("  x-axis ")
        lines.append("   "+str(self.imu.accel_mg.x_axis.Get()))
        lines.append(', ')
        lines.append("  y-axis ")
        lines.append("   "+str(self.imu.accel_mg.y_axis.Get()))
        lines.append(', ')
        lines.append("  z-axis ")
        lines.append("   "+str(self.imu.accel_mg.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append(" gyro-mdps ")
        lines.append("{")
        lines.append("  x-axis ")
        lines.append("   "+str(self.imu.gyro_mdps.x_axis.Get()))
        lines.append(', ')
        lines.append("  y-axis ")
        lines.append("   "+str(self.imu.gyro_mdps.y_axis.Get()))
        lines.append(', ')
        lines.append("  z-axis ")
        lines.append("   "+str(self.imu.gyro_mdps.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append(" temp-celsius ")
        lines.append("  "+str(self.imu.temp_celsius.Get()))
        lines.append(', ')
        lines.append(" mgt-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.mgt_valid.Get())])
        lines.append(', ')
        lines.append(" acc-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.acc_valid.Get())])
        lines.append(', ')
        lines.append(" gyro-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.gyro_valid.Get())])
        lines.append(', ')
        lines.append(" temp-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.temp_valid.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("ps1 ")
        lines.append("{")
        lines.append(" pressure ")
        lines.append("  "+str(self.ps1.pressure.Get()))
        lines.append(', ')
        lines.append(" temp ")
        lines.append("  "+str(self.ps1.temp.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("ps2 ")
        lines.append("{")
        lines.append(" pressure ")
        lines.append("  "+str(self.ps2.pressure.Get()))
        lines.append(', ')
        lines.append(" temp ")
        lines.append("  "+str(self.ps2.temp.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("ps1-validity ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.ps1_validity.Get())])
        lines.append(', ')
        lines.append("ps2-validity ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.ps2_validity.Get())])
        lines.append(', ')
        lines.append("anemometer ")
        lines.append(" "+str(self.anemometer.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class TC_Heater(COMMON):
    # Ordered list of fields:
    children_ordered = ['heater', 'command']

    def __init__(self, ptr=None):
        super(TC_Heater, self).__init__("TC_Heater", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("heater ")
        lines.append(" "+{'0': 'heater-HTL', '1': 'heater-anemo'}[str(self.heater.Get())])
        lines.append(', ')
        lines.append("command ")
        if self.command.kind.Get() == DV.power_manual_PRESENT:
         lines.append(" power-manual: ")
         lines.append("  "+str(self.command.power_manual.Get()))
        if self.command.kind.Get() == DV.max_min_PRESENT:
         lines.append(" max-min: ")
         lines.append("  "+{'0': 'max', '1': 'min'}[str(self.command.max_min.Get())])
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class TC(COMMON):
    # Ordered list of fields:
    children_ordered = ['heater-of-HTL', 'tc74s-temp-celsius', 'pt1000s-temp-celsius', 'pressure1-mbar', 'pressure2-mbar']

    def __init__(self, ptr=None):
        super(TC, self).__init__("TC", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("heater-of-HTL ")
        lines.append("{")
        lines.append(" heater ")
        lines.append("  "+{'0': 'heater-HTL', '1': 'heater-anemo'}[str(self.heater_of_HTL.heater.Get())])
        lines.append(', ')
        lines.append(" command ")
        if self.heater_of_HTL.command.kind.Get() == DV.power_manual_PRESENT:
         lines.append("  power-manual: ")
         lines.append("   "+str(self.heater_of_HTL.command.power_manual.Get()))
        if self.heater_of_HTL.command.kind.Get() == DV.max_min_PRESENT:
         lines.append("  max-min: ")
         lines.append("   "+{'0': 'max', '1': 'min'}[str(self.heater_of_HTL.command.max_min.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("tc74s-temp-celsius ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("  "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.tc74s_temp_celsius.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.tc74s_temp_celsius), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append("pt1000s-temp-celsius ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("  "+str(path[i].Get()))
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s_temp_celsius.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s_temp_celsius), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append(', ')
        lines.append("pressure1-mbar ")
        lines.append(" "+str(self.pressure1_mbar.Get()))
        lines.append(', ')
        lines.append("pressure2-mbar ")
        lines.append(" "+str(self.pressure2_mbar.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class HTL_GUI(COMMON):
    # Ordered list of fields:
    children_ordered = ['state', 'heater', 'delta-T', 'pt1000s', 'tc74s']

    def __init__(self, ptr=None):
        super(HTL_GUI, self).__init__("HTL_GUI", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("state ")
        lines.append(" "+{'0': 'a1', '1': 'a2', '2': 'f1', '3': 'f2', '4': 'f3', '5': 'error'}[str(self.state.Get())])
        lines.append(', ')
        lines.append("heater ")
        lines.append("{")
        lines.append(" power-watts ")
        lines.append("  "+str(self.heater.power_watts.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.heater.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("delta-T ")
        lines.append(" "+str(self.delta_T.Get()))
        lines.append(', ')
        lines.append("pt1000s ")
        lines.append("{")
        lines.append(" aire-abajo ")
        lines.append("  "+str(self.pt1000s.aire_abajo.Get()))
        lines.append(', ')
        lines.append(" aire-arriba ")
        lines.append("  "+str(self.pt1000s.aire_arriba.Get()))
        lines.append(', ')
        lines.append(" placa-abajo ")
        lines.append("  "+str(self.pt1000s.placa_abajo.Get()))
        lines.append(', ')
        lines.append(" placa-arriba ")
        lines.append("  "+str(self.pt1000s.placa_arriba.Get()))
        lines.append(', ')
        lines.append(" infinito ")
        lines.append("  "+str(self.pt1000s.infinito.Get()))
        lines.append(', ')
        lines.append(" exterior ")
        lines.append("  "+str(self.pt1000s.exterior.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(path[i].Get())])
            path.Reset(state)
        state = self.GetState()
        length = self.pt1000s.validity.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.pt1000s.validity), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append("}")
        lines.append(', ')
        lines.append("tc74s ")
        lines.append("{")
        lines.append(" x-positive ")
        lines.append("  "+str(self.tc74s.x_positive.Get()))
        lines.append(', ')
        lines.append(" x-negative ")
        lines.append("  "+str(self.tc74s.x_negative.Get()))
        lines.append(', ')
        lines.append(" y-positive ")
        lines.append("  "+str(self.tc74s.y_positive.Get()))
        lines.append(', ')
        lines.append(" y-negative ")
        lines.append("  "+str(self.tc74s.y_negative.Get()))
        lines.append(', ')
        lines.append(" z-techo ")
        lines.append("  "+str(self.tc74s.z_techo.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("{")
        def emitElem(path, i):
            state = path.GetState()
            if i > 0:
                lines.append(",")
            lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(path[i].Get())])
            path.Reset(state)
        state = self.GetState()
        length = self.tc74s.validity.GetLength()
        self.Reset(state)
        list(map(partial(emitElem, self.tc74s.validity), range(length)))
        self.Reset(state)
        lines.append("}")
        lines.append("}")
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class Date_Time(COMMON):
    # Ordered list of fields:
    children_ordered = ['day', 'month', 'year', 'hour', 'minute', 'second']

    def __init__(self, ptr=None):
        super(Date_Time, self).__init__("Date_Time", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("day ")
        lines.append(" "+str(self.day.Get()))
        lines.append(', ')
        lines.append("month ")
        lines.append(" "+str(self.month.Get()))
        lines.append(', ')
        lines.append("year ")
        lines.append(" "+str(self.year.Get()))
        lines.append(', ')
        lines.append("hour ")
        lines.append(" "+str(self.hour.Get()))
        lines.append(', ')
        lines.append("minute ")
        lines.append(" "+str(self.minute.Get()))
        lines.append(', ')
        lines.append("second ")
        lines.append(" "+str(self.second.Get()))
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class ATT_GUI(COMMON):
    # Ordered list of fields:
    children_ordered = ['gps', 'gps-date-time', 'imu']

    def __init__(self, ptr=None):
        super(ATT_GUI, self).__init__("ATT_GUI", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("gps ")
        lines.append("{")
        lines.append(" mode ")
        lines.append("  "+{'0': 'not-seen', '1': 'no-fix', '2': 'two-dims', '3': 'three-dims'}[str(self.gps.mode.Get())])
        lines.append(', ')
        lines.append(" date-and-time ")
        lines.append("  "+str(self.gps.date_and_time.Get()))
        lines.append(', ')
        lines.append(" ept ")
        lines.append("  "+str(self.gps.ept.Get()))
        lines.append(', ')
        lines.append(" latitude ")
        lines.append("  "+str(self.gps.latitude.Get()))
        lines.append(', ')
        lines.append(" epy ")
        lines.append("  "+str(self.gps.epy.Get()))
        lines.append(', ')
        lines.append(" longitude ")
        lines.append("  "+str(self.gps.longitude.Get()))
        lines.append(', ')
        lines.append(" epx ")
        lines.append("  "+str(self.gps.epx.Get()))
        lines.append(', ')
        lines.append(" altitude ")
        lines.append("  "+str(self.gps.altitude.Get()))
        lines.append(', ')
        lines.append(" epv ")
        lines.append("  "+str(self.gps.epv.Get()))
        lines.append(', ')
        lines.append(" course ")
        lines.append("  "+str(self.gps.course.Get()))
        lines.append(', ')
        lines.append(" epd ")
        lines.append("  "+str(self.gps.epd.Get()))
        lines.append(', ')
        lines.append(" speed ")
        lines.append("  "+str(self.gps.speed.Get()))
        lines.append(', ')
        lines.append(" eps ")
        lines.append("  "+str(self.gps.eps.Get()))
        lines.append(', ')
        lines.append(" climb ")
        lines.append("  "+str(self.gps.climb.Get()))
        lines.append(', ')
        lines.append(" epc ")
        lines.append("  "+str(self.gps.epc.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("gps-date-time ")
        lines.append("{")
        lines.append(" day ")
        lines.append("  "+str(self.gps_date_time.day.Get()))
        lines.append(', ')
        lines.append(" month ")
        lines.append("  "+str(self.gps_date_time.month.Get()))
        lines.append(', ')
        lines.append(" year ")
        lines.append("  "+str(self.gps_date_time.year.Get()))
        lines.append(', ')
        lines.append(" hour ")
        lines.append("  "+str(self.gps_date_time.hour.Get()))
        lines.append(', ')
        lines.append(" minute ")
        lines.append("  "+str(self.gps_date_time.minute.Get()))
        lines.append(', ')
        lines.append(" second ")
        lines.append("  "+str(self.gps_date_time.second.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("imu ")
        lines.append("{")
        lines.append(" mgt-mgauss ")
        lines.append("{")
        lines.append("  x-axis ")
        lines.append("   "+str(self.imu.mgt_mgauss.x_axis.Get()))
        lines.append(', ')
        lines.append("  y-axis ")
        lines.append("   "+str(self.imu.mgt_mgauss.y_axis.Get()))
        lines.append(', ')
        lines.append("  z-axis ")
        lines.append("   "+str(self.imu.mgt_mgauss.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append(" accel-mg ")
        lines.append("{")
        lines.append("  x-axis ")
        lines.append("   "+str(self.imu.accel_mg.x_axis.Get()))
        lines.append(', ')
        lines.append("  y-axis ")
        lines.append("   "+str(self.imu.accel_mg.y_axis.Get()))
        lines.append(', ')
        lines.append("  z-axis ")
        lines.append("   "+str(self.imu.accel_mg.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append(" gyro-mdps ")
        lines.append("{")
        lines.append("  x-axis ")
        lines.append("   "+str(self.imu.gyro_mdps.x_axis.Get()))
        lines.append(', ')
        lines.append("  y-axis ")
        lines.append("   "+str(self.imu.gyro_mdps.y_axis.Get()))
        lines.append(', ')
        lines.append("  z-axis ")
        lines.append("   "+str(self.imu.gyro_mdps.z_axis.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append(" temp-celsius ")
        lines.append("  "+str(self.imu.temp_celsius.Get()))
        lines.append(', ')
        lines.append(" mgt-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.mgt_valid.Get())])
        lines.append(', ')
        lines.append(" acc-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.acc_valid.Get())])
        lines.append(', ')
        lines.append(" gyro-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.gyro_valid.Get())])
        lines.append(', ')
        lines.append(" temp-valid ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.imu.temp_valid.Get())])
        lines.append("}")
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class PS_GUI(COMMON):
    # Ordered list of fields:
    children_ordered = ['pressure-mbar', 'temperature-celsius', 'validity']

    def __init__(self, ptr=None):
        super(PS_GUI, self).__init__("PS_GUI", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("pressure-mbar ")
        lines.append(" "+str(self.pressure_mbar.Get()))
        lines.append(', ')
        lines.append("temperature-celsius ")
        lines.append(" "+str(self.temperature_celsius.Get()))
        lines.append(', ')
        lines.append("validity ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.validity.Get())])
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class ENV_GUI(COMMON):
    # Ordered list of fields:
    children_ordered = ['pressure-sensor-1', 'pressure-sensor-2', 'anemometer', 'heater']

    def __init__(self, ptr=None):
        super(ENV_GUI, self).__init__("ENV_GUI", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("pressure-sensor-1 ")
        lines.append("{")
        lines.append(" pressure-mbar ")
        lines.append("  "+str(self.pressure_sensor_1.pressure_mbar.Get()))
        lines.append(', ')
        lines.append(" temperature-celsius ")
        lines.append("  "+str(self.pressure_sensor_1.temperature_celsius.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.pressure_sensor_1.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("pressure-sensor-2 ")
        lines.append("{")
        lines.append(" pressure-mbar ")
        lines.append("  "+str(self.pressure_sensor_2.pressure_mbar.Get()))
        lines.append(', ')
        lines.append(" temperature-celsius ")
        lines.append("  "+str(self.pressure_sensor_2.temperature_celsius.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.pressure_sensor_2.validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("anemometer ")
        lines.append("{")
        lines.append(" global-counter ")
        lines.append("  "+str(self.anemometer.global_counter.Get()))
        lines.append(', ')
        lines.append(" temperature-celsius ")
        lines.append("  "+str(self.anemometer.temperature_celsius.Get()))
        lines.append(', ')
        lines.append(" temperature-validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.anemometer.temperature_validity.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append("heater ")
        lines.append("{")
        lines.append(" power-watts ")
        lines.append("  "+str(self.heater.power_watts.Get()))
        lines.append(', ')
        lines.append(" validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.heater.validity.Get())])
        lines.append("}")
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Int32(COMMON):
    def __init__(self, ptr=None):
        super(T_Int32, self).__init__("T_Int32", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_UInt32(COMMON):
    def __init__(self, ptr=None):
        super(T_UInt32, self).__init__("T_UInt32", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Int8(COMMON):
    def __init__(self, ptr=None):
        super(T_Int8, self).__init__("T_Int8", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_UInt8(COMMON):
    def __init__(self, ptr=None):
        super(T_UInt8, self).__init__("T_UInt8", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()))

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Boolean(COMMON):
    def __init__(self, ptr=None):
        super(T_Boolean, self).__init__("T_Boolean", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append(""+str(self.Get()!=0).upper())

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


class T_Null_Record(COMMON):
    # Ordered list of fields:
    children_ordered = ['']

    def __init__(self, ptr=None):
        super(T_Null_Record, self).__init__("T_Null_Record", ptr)

    def GSER(self):
        ''' Return the GSER representation of the value '''
        lines = []
        lines.append("{")
        lines.append("}")

        return ' '.join(lines)

    def PrintAll(self):
        ''' Display a variable of this type '''
        print(self.GSER() + '\n')


