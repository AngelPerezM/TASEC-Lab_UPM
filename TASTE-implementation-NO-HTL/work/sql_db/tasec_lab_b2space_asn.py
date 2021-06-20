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
    children_ordered = ['mgt-raw', 'mgt-mgauss', 'accel-raw', 'accel-mg', 'gyro-raw', 'gyro-mdps', 'mgt-valid', 'acc-valid', 'gyro-valid']

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
        lines.append("mgt-valid ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.mgt_valid.Get())])
        lines.append(', ')
        lines.append("acc-valid ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.acc_valid.Get())])
        lines.append(', ')
        lines.append("gyro-valid ")
        lines.append(" "+{'0': 'valid', '1': 'invalid'}[str(self.gyro_valid.Get())])
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
        lines.append(" validity ")
        lines.append("  "+{'0': 'valid', '1': 'invalid'}[str(self.gps.validity.Get())])
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
        lines.append("  mgt-valid ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.mgt_valid.Get())])
        lines.append(', ')
        lines.append("  acc-valid ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.acc_valid.Get())])
        lines.append(', ')
        lines.append("  gyro-valid ")
        lines.append("   "+{'0': 'valid', '1': 'invalid'}[str(self.imu.data.gyro_valid.Get())])
        lines.append("}")
        lines.append(', ')
        lines.append(" timestamp ")
        lines.append("  "+str(self.imu.timestamp.Get()))
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
        lines.append(" timestamp ")
        lines.append("  "+str(self.tc74s.timestamp.Get()))
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
        lines.append(" timestamp ")
        lines.append("  "+str(self.pt1000s.timestamp.Get()))
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
        lines.append(" timestamp ")
        lines.append("  "+str(self.ps1.timestamp.Get()))
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
        lines.append(" timestamp ")
        lines.append("  "+str(self.ps2.timestamp.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("heater1 ")
        lines.append("{")
        lines.append(" data ")
        lines.append("  "+str(self.heater1.data.Get()))
        lines.append(', ')
        lines.append(" timestamp ")
        lines.append("  "+str(self.heater1.timestamp.Get()))
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
        lines.append(" timestamp ")
        lines.append("  "+str(self.heater2.timestamp.Get()))
        lines.append("}")
        lines.append(', ')
        lines.append("anemometer ")
        lines.append("{")
        lines.append(" data ")
        lines.append("  "+str(self.anemometer.data.Get()))
        lines.append(', ')
        lines.append(" timestamp ")
        lines.append("  "+str(self.anemometer.timestamp.Get()))
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


