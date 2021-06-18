
#  SQLAlchemy models for types used in "tasec_lab_b2space.asn"

from sqlalchemy.ext.declarative import declarative_base
Base = declarative_base()

from sqlalchemy import (Column, Integer, String, Boolean, Float,
                        ForeignKey, CheckConstraint, UniqueConstraint)
from sqlalchemy.orm import relationship

from tasec_lab_b2space_asn import (
    ACC_MilliG_Data, ACC_Raw_Data, Content_Validity, GPS_PVT, GYRO_MilliDPS_Data, GYRO_Raw_Data, Heater_Data, I2C_ID, IMU_All_Data, MGT_MilliGauss_Data, MGT_Raw_Data, OBSW_DP_Data, PS_All_Data, PS_Calibration_Data, PS_Processed_Data, PS_Raw_Data, PT1000s_All_Data, PT1000s_Celsius_Data, PT1000s_Channels, PT1000s_Raw_Data, SPI_ID, T_Boolean, T_Double, T_Float, T_Int16, T_Int32, T_Int8, T_Null_Record, T_UInt16, T_UInt32, T_UInt64, T_UInt8, TC74s_All_Data, TC74s_I2CBuses
)

import DV


class Content_Validity_SQL(Base):
    __tablename__ = 'Content_Validity'
    __table_args__ = (UniqueConstraint('iid'),)
    valid = 0
    invalid = 1
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data=0 OR data=1'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Content_Validity_SQL).filter(Content_Validity_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Content_Validity()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class GPS_PVT_mode_SQL(Base):
    __tablename__ = 'GPS_PVT_mode'
    __table_args__ = (UniqueConstraint('iid'),)
    not_seen = 0
    no_fix = 1
    two_dims = 2
    three_dims = 3
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data=0 OR data=1 OR data=2 OR data=3'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            GPS_PVT_mode_SQL).filter(GPS_PVT_mode_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = GPS_PVT_mode()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class PT1000s_All_Data_validity_indexes_SQL(Base):
    __tablename__ = 'PT1000s_All_Data_validity_indexes'
    __table_args__ = (UniqueConstraint('idx', 'fk_PT1000s_All_Data_validity_iid'),)
    iid = Column(Integer, primary_key=True)
    idx = Column(Integer, CheckConstraint('idx>=0 AND idx<6'), nullable=False)
    fk_PT1000s_All_Data_validity_iid = Column(
        Integer,
        ForeignKey('PT1000s_All_Data_validity.iid'),
        nullable=False)
    fk_Content_Validity_iid = Column(
        Integer,
        ForeignKey('Content_Validity.iid'),
        nullable=False)
    array = relationship(
        "PT1000s_All_Data_validity_SQL",
        foreign_keys=[fk_PT1000s_All_Data_validity_iid],
        backref='arrIndexes_PT1000s_All_Data_validity')
    data = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_Content_Validity_iid])

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

class PT1000s_All_Data_validity_SQL(Base):
    __tablename__ = 'PT1000s_All_Data_validity'
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PT1000s_All_Data_validity_SQL).filter(PT1000s_All_Data_validity_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PT1000s_All_Data_validity()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()

        for idx, idxObj in enumerate(self.arrIndexes_PT1000s_All_Data_validity):
            pyObj.Reset(state)
            idxObj.data.assignToASN1object(pyObj[idxObj.idx])
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        for c in self._children:
            session.add(c[0])
            session.add(c[1])
        session.commit()
        return self.iid

    def __init__(self, pyObj):
        self._children = []
        state = pyObj.GetState()
        for i in range(pyObj.GetLength()):
            pyObj.Reset(state)
            newIndex = PT1000s_All_Data_validity_indexes_SQL()
            newIndex.idx = i
            newIndex.array = self
            newData = Content_Validity_SQL(pyObj[i])
            newIndex.data = newData
            self._children.append((newIndex, newData))

        pyObj.Reset(state)


class T_Boolean_SQL(Base):
    __tablename__ = 'T_Boolean'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Boolean, nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Boolean_SQL).filter(T_Boolean_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Boolean()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Double_SQL(Base):
    __tablename__ = 'T_Double'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Float, CheckConstraint('data>=-1.7e+308 and data<=1.7e+308'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Double_SQL).filter(T_Double_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Double()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Float_SQL(Base):
    __tablename__ = 'T_Float'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Float, CheckConstraint('data>=-3.4e+38 and data<=3.4e+38'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Float_SQL).filter(T_Float_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Float()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Int16_SQL(Base):
    __tablename__ = 'T_Int16'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=-32768 and data<=32767'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Int16_SQL).filter(T_Int16_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Int16()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Int32_SQL(Base):
    __tablename__ = 'T_Int32'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=-2147483648 and data<=2147483647'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Int32_SQL).filter(T_Int32_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Int32()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Int8_SQL(Base):
    __tablename__ = 'T_Int8'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=-128 and data<=127'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Int8_SQL).filter(T_Int8_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Int8()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_Null_Record_SQL(Base):
    __tablename__ = 'T_Null_Record'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_Null_Record_SQL).filter(T_Null_Record_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_Null_Record()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


    def __init__(self, pyObj):
        state = pyObj.GetState()


class T_UInt16_SQL(Base):
    __tablename__ = 'T_UInt16'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=65535'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_UInt16_SQL).filter(T_UInt16_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_UInt16()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_UInt32_SQL(Base):
    __tablename__ = 'T_UInt32'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=4294967295'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_UInt32_SQL).filter(T_UInt32_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_UInt32()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_UInt64_SQL(Base):
    __tablename__ = 'T_UInt64'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=18446744073709551615'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_UInt64_SQL).filter(T_UInt64_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_UInt64()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class T_UInt8_SQL(Base):
    __tablename__ = 'T_UInt8'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)
    data = Column(Integer, CheckConstraint('data>=0 and data<=255'), nullable=False)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            T_UInt8_SQL).filter(T_UInt8_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = T_UInt8()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        pyObj.Set(self.data)

    def __init__(self, pyObj):
        self.data = pyObj.Get()

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid


class TC74s_All_Data_elem_SQL(Base):
    __tablename__ = 'TC74s_All_Data_elem'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            TC74s_All_Data_elem_SQL).filter(TC74s_All_Data_elem_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = TC74s_All_Data_elem()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.temperature.assignToASN1object(pyObj.temperature)
        pyObj.Reset(state)
        self.validity.assignToASN1object(pyObj.validity)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_temperature_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    temperature = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_temperature_iid])
    fk_validity_iid = Column(Integer, ForeignKey('Content_Validity.iid'), nullable=False)
    validity = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_validity_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.temperature = T_Float_SQL(pyObj.temperature)
        pyObj.Reset(state)
        self.validity = Content_Validity_SQL(pyObj.validity)
        pyObj.Reset(state)


class TC74s_I2CBuses_indexes_SQL(Base):
    __tablename__ = 'TC74s_I2CBuses_indexes'
    __table_args__ = (UniqueConstraint('idx', 'fk_TC74s_I2CBuses_iid'),)
    iid = Column(Integer, primary_key=True)
    idx = Column(Integer, CheckConstraint('idx>=0 AND idx<5'), nullable=False)
    fk_TC74s_I2CBuses_iid = Column(
        Integer,
        ForeignKey('TC74s_I2CBuses.iid'),
        nullable=False)
    fk_T_Int32_iid = Column(
        Integer,
        ForeignKey('T_Int32.iid'),
        nullable=False)
    array = relationship(
        "TC74s_I2CBuses_SQL",
        foreign_keys=[fk_TC74s_I2CBuses_iid],
        backref='arrIndexes_TC74s_I2CBuses')
    data = relationship(
        "T_Int32_SQL",
        foreign_keys=[fk_T_Int32_iid])

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

class TC74s_I2CBuses_SQL(Base):
    __tablename__ = 'TC74s_I2CBuses'
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            TC74s_I2CBuses_SQL).filter(TC74s_I2CBuses_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = TC74s_I2CBuses()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()

        for idx, idxObj in enumerate(self.arrIndexes_TC74s_I2CBuses):
            pyObj.Reset(state)
            idxObj.data.assignToASN1object(pyObj[idxObj.idx])
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        for c in self._children:
            session.add(c[0])
            session.add(c[1])
        session.commit()
        return self.iid

    def __init__(self, pyObj):
        self._children = []
        state = pyObj.GetState()
        for i in range(pyObj.GetLength()):
            pyObj.Reset(state)
            newIndex = TC74s_I2CBuses_indexes_SQL()
            newIndex.idx = i
            newIndex.array = self
            newData = T_Int32_SQL(pyObj[i])
            newIndex.data = newData
            self._children.append((newIndex, newData))

        pyObj.Reset(state)


class ACC_MilliG_Data_SQL(Base):
    __tablename__ = 'ACC_MilliG_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            ACC_MilliG_Data_SQL).filter(ACC_MilliG_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = ACC_MilliG_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.x_axis.assignToASN1object(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis.assignToASN1object(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis.assignToASN1object(pyObj.z_axis)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_x_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    x_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_x_axis_iid])
    fk_y_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    y_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_y_axis_iid])
    fk_z_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    z_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_z_axis_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.x_axis = T_Float_SQL(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis = T_Float_SQL(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis = T_Float_SQL(pyObj.z_axis)
        pyObj.Reset(state)


class ACC_Raw_Data_SQL(Base):
    __tablename__ = 'ACC_Raw_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            ACC_Raw_Data_SQL).filter(ACC_Raw_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = ACC_Raw_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.x_axis.assignToASN1object(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis.assignToASN1object(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis.assignToASN1object(pyObj.z_axis)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_x_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    x_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_x_axis_iid])
    fk_y_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    y_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_y_axis_iid])
    fk_z_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    z_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_z_axis_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.x_axis = T_Int16_SQL(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis = T_Int16_SQL(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis = T_Int16_SQL(pyObj.z_axis)
        pyObj.Reset(state)


class GPS_PVT_SQL(Base):
    __tablename__ = 'GPS_PVT'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            GPS_PVT_SQL).filter(GPS_PVT_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = GPS_PVT()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.mode.assignToASN1object(pyObj.mode)
        pyObj.Reset(state)
        self.date_and_time.assignToASN1object(pyObj.date_and_time)
        pyObj.Reset(state)
        self.ept.assignToASN1object(pyObj.ept)
        pyObj.Reset(state)
        self.latitude.assignToASN1object(pyObj.latitude)
        pyObj.Reset(state)
        self.epy.assignToASN1object(pyObj.epy)
        pyObj.Reset(state)
        self.longitude.assignToASN1object(pyObj.longitude)
        pyObj.Reset(state)
        self.epx.assignToASN1object(pyObj.epx)
        pyObj.Reset(state)
        self.altitude.assignToASN1object(pyObj.altitude)
        pyObj.Reset(state)
        self.epv.assignToASN1object(pyObj.epv)
        pyObj.Reset(state)
        self.course.assignToASN1object(pyObj.course)
        pyObj.Reset(state)
        self.epd.assignToASN1object(pyObj.epd)
        pyObj.Reset(state)
        self.speed.assignToASN1object(pyObj.speed)
        pyObj.Reset(state)
        self.eps.assignToASN1object(pyObj.eps)
        pyObj.Reset(state)
        self.climb.assignToASN1object(pyObj.climb)
        pyObj.Reset(state)
        self.epc.assignToASN1object(pyObj.epc)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_mode_iid = Column(Integer, ForeignKey('GPS_PVT_mode.iid'), nullable=False)
    mode = relationship(
        "GPS_PVT_mode_SQL",
        foreign_keys=[fk_mode_iid])
    fk_date_and_time_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    date_and_time = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_date_and_time_iid])
    fk_ept_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    ept = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_ept_iid])
    fk_latitude_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    latitude = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_latitude_iid])
    fk_epy_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    epy = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_epy_iid])
    fk_longitude_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    longitude = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_longitude_iid])
    fk_epx_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    epx = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_epx_iid])
    fk_altitude_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    altitude = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_altitude_iid])
    fk_epv_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    epv = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_epv_iid])
    fk_course_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    course = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_course_iid])
    fk_epd_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    epd = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_epd_iid])
    fk_speed_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    speed = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_speed_iid])
    fk_eps_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    eps = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_eps_iid])
    fk_climb_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    climb = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_climb_iid])
    fk_epc_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    epc = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_epc_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.mode = GPS_PVT_mode_SQL(pyObj.mode)
        pyObj.Reset(state)
        self.date_and_time = T_Double_SQL(pyObj.date_and_time)
        pyObj.Reset(state)
        self.ept = T_Double_SQL(pyObj.ept)
        pyObj.Reset(state)
        self.latitude = T_Double_SQL(pyObj.latitude)
        pyObj.Reset(state)
        self.epy = T_Double_SQL(pyObj.epy)
        pyObj.Reset(state)
        self.longitude = T_Double_SQL(pyObj.longitude)
        pyObj.Reset(state)
        self.epx = T_Double_SQL(pyObj.epx)
        pyObj.Reset(state)
        self.altitude = T_Double_SQL(pyObj.altitude)
        pyObj.Reset(state)
        self.epv = T_Double_SQL(pyObj.epv)
        pyObj.Reset(state)
        self.course = T_Double_SQL(pyObj.course)
        pyObj.Reset(state)
        self.epd = T_Double_SQL(pyObj.epd)
        pyObj.Reset(state)
        self.speed = T_Double_SQL(pyObj.speed)
        pyObj.Reset(state)
        self.eps = T_Double_SQL(pyObj.eps)
        pyObj.Reset(state)
        self.climb = T_Double_SQL(pyObj.climb)
        pyObj.Reset(state)
        self.epc = T_Double_SQL(pyObj.epc)
        pyObj.Reset(state)


class GYRO_MilliDPS_Data_SQL(Base):
    __tablename__ = 'GYRO_MilliDPS_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            GYRO_MilliDPS_Data_SQL).filter(GYRO_MilliDPS_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = GYRO_MilliDPS_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.x_axis.assignToASN1object(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis.assignToASN1object(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis.assignToASN1object(pyObj.z_axis)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_x_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    x_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_x_axis_iid])
    fk_y_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    y_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_y_axis_iid])
    fk_z_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    z_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_z_axis_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.x_axis = T_Float_SQL(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis = T_Float_SQL(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis = T_Float_SQL(pyObj.z_axis)
        pyObj.Reset(state)


class GYRO_Raw_Data_SQL(Base):
    __tablename__ = 'GYRO_Raw_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            GYRO_Raw_Data_SQL).filter(GYRO_Raw_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = GYRO_Raw_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.x_axis.assignToASN1object(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis.assignToASN1object(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis.assignToASN1object(pyObj.z_axis)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_x_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    x_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_x_axis_iid])
    fk_y_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    y_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_y_axis_iid])
    fk_z_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    z_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_z_axis_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.x_axis = T_Int16_SQL(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis = T_Int16_SQL(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis = T_Int16_SQL(pyObj.z_axis)
        pyObj.Reset(state)


class Heater_Data_SQL(Base):
    __tablename__ = 'Heater_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            Heater_Data_SQL).filter(Heater_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = Heater_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.power_watts.assignToASN1object(pyObj.power_watts)
        pyObj.Reset(state)
        self.validity.assignToASN1object(pyObj.validity)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_power_watts_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    power_watts = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_power_watts_iid])
    fk_validity_iid = Column(Integer, ForeignKey('Content_Validity.iid'), nullable=False)
    validity = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_validity_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.power_watts = T_Float_SQL(pyObj.power_watts)
        pyObj.Reset(state)
        self.validity = Content_Validity_SQL(pyObj.validity)
        pyObj.Reset(state)


class I2C_ID_SQL(Base):
    __tablename__ = 'I2C_ID'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            I2C_ID_SQL).filter(I2C_ID_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = I2C_ID()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.bus.assignToASN1object(pyObj.bus)
        pyObj.Reset(state)
        self.address.assignToASN1object(pyObj.address)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_bus_iid = Column(Integer, ForeignKey('T_UInt8.iid'), nullable=False)
    bus = relationship(
        "T_UInt8_SQL",
        foreign_keys=[fk_bus_iid])
    fk_address_iid = Column(Integer, ForeignKey('T_UInt8.iid'), nullable=False)
    address = relationship(
        "T_UInt8_SQL",
        foreign_keys=[fk_address_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.bus = T_UInt8_SQL(pyObj.bus)
        pyObj.Reset(state)
        self.address = T_UInt8_SQL(pyObj.address)
        pyObj.Reset(state)


class MGT_MilliGauss_Data_SQL(Base):
    __tablename__ = 'MGT_MilliGauss_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            MGT_MilliGauss_Data_SQL).filter(MGT_MilliGauss_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = MGT_MilliGauss_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.x_axis.assignToASN1object(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis.assignToASN1object(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis.assignToASN1object(pyObj.z_axis)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_x_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    x_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_x_axis_iid])
    fk_y_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    y_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_y_axis_iid])
    fk_z_axis_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    z_axis = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_z_axis_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.x_axis = T_Float_SQL(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis = T_Float_SQL(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis = T_Float_SQL(pyObj.z_axis)
        pyObj.Reset(state)


class MGT_Raw_Data_SQL(Base):
    __tablename__ = 'MGT_Raw_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            MGT_Raw_Data_SQL).filter(MGT_Raw_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = MGT_Raw_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.x_axis.assignToASN1object(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis.assignToASN1object(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis.assignToASN1object(pyObj.z_axis)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_x_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    x_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_x_axis_iid])
    fk_y_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    y_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_y_axis_iid])
    fk_z_axis_iid = Column(Integer, ForeignKey('T_Int16.iid'), nullable=False)
    z_axis = relationship(
        "T_Int16_SQL",
        foreign_keys=[fk_z_axis_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.x_axis = T_Int16_SQL(pyObj.x_axis)
        pyObj.Reset(state)
        self.y_axis = T_Int16_SQL(pyObj.y_axis)
        pyObj.Reset(state)
        self.z_axis = T_Int16_SQL(pyObj.z_axis)
        pyObj.Reset(state)


class OBSW_DP_Data_anemometer_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_anemometer'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_anemometer_SQL).filter(OBSW_DP_Data_anemometer_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_anemometer()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('T_UInt64.iid'), nullable=False)
    data = relationship(
        "T_UInt64_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = T_UInt64_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class OBSW_DP_Data_gps_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_gps'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_gps_SQL).filter(OBSW_DP_Data_gps_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_gps()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.validity.assignToASN1object(pyObj.validity)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('GPS_PVT.iid'), nullable=False)
    data = relationship(
        "GPS_PVT_SQL",
        foreign_keys=[fk_data_iid])
    fk_validity_iid = Column(Integer, ForeignKey('Content_Validity.iid'), nullable=False)
    validity = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_validity_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = GPS_PVT_SQL(pyObj.data)
        pyObj.Reset(state)
        self.validity = Content_Validity_SQL(pyObj.validity)
        pyObj.Reset(state)


class OBSW_DP_Data_heater1_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_heater1'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_heater1_SQL).filter(OBSW_DP_Data_heater1_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_heater1()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    data = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = T_Float_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class OBSW_DP_Data_heater2_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_heater2'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_heater2_SQL).filter(OBSW_DP_Data_heater2_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_heater2()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('Heater_Data.iid'), nullable=False)
    data = relationship(
        "Heater_Data_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = Heater_Data_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class PS_Calibration_Data_SQL(Base):
    __tablename__ = 'PS_Calibration_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PS_Calibration_Data_SQL).filter(PS_Calibration_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PS_Calibration_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.c1.assignToASN1object(pyObj.c1)
        pyObj.Reset(state)
        self.c2.assignToASN1object(pyObj.c2)
        pyObj.Reset(state)
        self.c3.assignToASN1object(pyObj.c3)
        pyObj.Reset(state)
        self.c4.assignToASN1object(pyObj.c4)
        pyObj.Reset(state)
        self.c5.assignToASN1object(pyObj.c5)
        pyObj.Reset(state)
        self.c6.assignToASN1object(pyObj.c6)
        pyObj.Reset(state)
        self.sens_t1.assignToASN1object(pyObj.sens_t1)
        pyObj.Reset(state)
        self.off_t1.assignToASN1object(pyObj.off_t1)
        pyObj.Reset(state)
        self.tcs.assignToASN1object(pyObj.tcs)
        pyObj.Reset(state)
        self.tco.assignToASN1object(pyObj.tco)
        pyObj.Reset(state)
        self.tref.assignToASN1object(pyObj.tref)
        pyObj.Reset(state)
        self.temp_sens.assignToASN1object(pyObj.temp_sens)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_c1_iid = Column(Integer, ForeignKey('T_UInt16.iid'), nullable=False)
    c1 = relationship(
        "T_UInt16_SQL",
        foreign_keys=[fk_c1_iid])
    fk_c2_iid = Column(Integer, ForeignKey('T_UInt16.iid'), nullable=False)
    c2 = relationship(
        "T_UInt16_SQL",
        foreign_keys=[fk_c2_iid])
    fk_c3_iid = Column(Integer, ForeignKey('T_UInt16.iid'), nullable=False)
    c3 = relationship(
        "T_UInt16_SQL",
        foreign_keys=[fk_c3_iid])
    fk_c4_iid = Column(Integer, ForeignKey('T_UInt16.iid'), nullable=False)
    c4 = relationship(
        "T_UInt16_SQL",
        foreign_keys=[fk_c4_iid])
    fk_c5_iid = Column(Integer, ForeignKey('T_UInt16.iid'), nullable=False)
    c5 = relationship(
        "T_UInt16_SQL",
        foreign_keys=[fk_c5_iid])
    fk_c6_iid = Column(Integer, ForeignKey('T_UInt16.iid'), nullable=False)
    c6 = relationship(
        "T_UInt16_SQL",
        foreign_keys=[fk_c6_iid])
    fk_sens_t1_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    sens_t1 = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_sens_t1_iid])
    fk_off_t1_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    off_t1 = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_off_t1_iid])
    fk_tcs_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    tcs = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_tcs_iid])
    fk_tco_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    tco = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_tco_iid])
    fk_tref_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    tref = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_tref_iid])
    fk_temp_sens_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    temp_sens = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_temp_sens_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.c1 = T_UInt16_SQL(pyObj.c1)
        pyObj.Reset(state)
        self.c2 = T_UInt16_SQL(pyObj.c2)
        pyObj.Reset(state)
        self.c3 = T_UInt16_SQL(pyObj.c3)
        pyObj.Reset(state)
        self.c4 = T_UInt16_SQL(pyObj.c4)
        pyObj.Reset(state)
        self.c5 = T_UInt16_SQL(pyObj.c5)
        pyObj.Reset(state)
        self.c6 = T_UInt16_SQL(pyObj.c6)
        pyObj.Reset(state)
        self.sens_t1 = T_Float_SQL(pyObj.sens_t1)
        pyObj.Reset(state)
        self.off_t1 = T_Float_SQL(pyObj.off_t1)
        pyObj.Reset(state)
        self.tcs = T_Float_SQL(pyObj.tcs)
        pyObj.Reset(state)
        self.tco = T_Float_SQL(pyObj.tco)
        pyObj.Reset(state)
        self.tref = T_Float_SQL(pyObj.tref)
        pyObj.Reset(state)
        self.temp_sens = T_Float_SQL(pyObj.temp_sens)
        pyObj.Reset(state)


class PS_Processed_Data_SQL(Base):
    __tablename__ = 'PS_Processed_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PS_Processed_Data_SQL).filter(PS_Processed_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PS_Processed_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.pressure.assignToASN1object(pyObj.pressure)
        pyObj.Reset(state)
        self.temp.assignToASN1object(pyObj.temp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_pressure_iid = Column(Integer, ForeignKey('T_Int32.iid'), nullable=False)
    pressure = relationship(
        "T_Int32_SQL",
        foreign_keys=[fk_pressure_iid])
    fk_temp_iid = Column(Integer, ForeignKey('T_Int32.iid'), nullable=False)
    temp = relationship(
        "T_Int32_SQL",
        foreign_keys=[fk_temp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.pressure = T_Int32_SQL(pyObj.pressure)
        pyObj.Reset(state)
        self.temp = T_Int32_SQL(pyObj.temp)
        pyObj.Reset(state)


class PS_Raw_Data_SQL(Base):
    __tablename__ = 'PS_Raw_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PS_Raw_Data_SQL).filter(PS_Raw_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PS_Raw_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.d1.assignToASN1object(pyObj.d1)
        pyObj.Reset(state)
        self.d2.assignToASN1object(pyObj.d2)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_d1_iid = Column(Integer, ForeignKey('T_UInt32.iid'), nullable=False)
    d1 = relationship(
        "T_UInt32_SQL",
        foreign_keys=[fk_d1_iid])
    fk_d2_iid = Column(Integer, ForeignKey('T_UInt32.iid'), nullable=False)
    d2 = relationship(
        "T_UInt32_SQL",
        foreign_keys=[fk_d2_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.d1 = T_UInt32_SQL(pyObj.d1)
        pyObj.Reset(state)
        self.d2 = T_UInt32_SQL(pyObj.d2)
        pyObj.Reset(state)


class PT1000s_Celsius_Data_indexes_SQL(Base):
    __tablename__ = 'PT1000s_Celsius_Data_indexes'
    __table_args__ = (UniqueConstraint('idx', 'fk_PT1000s_Celsius_Data_iid'),)
    iid = Column(Integer, primary_key=True)
    idx = Column(Integer, CheckConstraint('idx>=0 AND idx<6'), nullable=False)
    fk_PT1000s_Celsius_Data_iid = Column(
        Integer,
        ForeignKey('PT1000s_Celsius_Data.iid'),
        nullable=False)
    fk_T_Float_iid = Column(
        Integer,
        ForeignKey('T_Float.iid'),
        nullable=False)
    array = relationship(
        "PT1000s_Celsius_Data_SQL",
        foreign_keys=[fk_PT1000s_Celsius_Data_iid],
        backref='arrIndexes_PT1000s_Celsius_Data')
    data = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_T_Float_iid])

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

class PT1000s_Celsius_Data_SQL(Base):
    __tablename__ = 'PT1000s_Celsius_Data'
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PT1000s_Celsius_Data_SQL).filter(PT1000s_Celsius_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PT1000s_Celsius_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()

        for idx, idxObj in enumerate(self.arrIndexes_PT1000s_Celsius_Data):
            pyObj.Reset(state)
            idxObj.data.assignToASN1object(pyObj[idxObj.idx])
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        for c in self._children:
            session.add(c[0])
            session.add(c[1])
        session.commit()
        return self.iid

    def __init__(self, pyObj):
        self._children = []
        state = pyObj.GetState()
        for i in range(pyObj.GetLength()):
            pyObj.Reset(state)
            newIndex = PT1000s_Celsius_Data_indexes_SQL()
            newIndex.idx = i
            newIndex.array = self
            newData = T_Float_SQL(pyObj[i])
            newIndex.data = newData
            self._children.append((newIndex, newData))

        pyObj.Reset(state)


class PT1000s_Channels_indexes_SQL(Base):
    __tablename__ = 'PT1000s_Channels_indexes'
    __table_args__ = (UniqueConstraint('idx', 'fk_PT1000s_Channels_iid'),)
    iid = Column(Integer, primary_key=True)
    idx = Column(Integer, CheckConstraint('idx>=0 AND idx<6'), nullable=False)
    fk_PT1000s_Channels_iid = Column(
        Integer,
        ForeignKey('PT1000s_Channels.iid'),
        nullable=False)
    fk_T_Int32_iid = Column(
        Integer,
        ForeignKey('T_Int32.iid'),
        nullable=False)
    array = relationship(
        "PT1000s_Channels_SQL",
        foreign_keys=[fk_PT1000s_Channels_iid],
        backref='arrIndexes_PT1000s_Channels')
    data = relationship(
        "T_Int32_SQL",
        foreign_keys=[fk_T_Int32_iid])

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

class PT1000s_Channels_SQL(Base):
    __tablename__ = 'PT1000s_Channels'
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PT1000s_Channels_SQL).filter(PT1000s_Channels_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PT1000s_Channels()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()

        for idx, idxObj in enumerate(self.arrIndexes_PT1000s_Channels):
            pyObj.Reset(state)
            idxObj.data.assignToASN1object(pyObj[idxObj.idx])
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        for c in self._children:
            session.add(c[0])
            session.add(c[1])
        session.commit()
        return self.iid

    def __init__(self, pyObj):
        self._children = []
        state = pyObj.GetState()
        for i in range(pyObj.GetLength()):
            pyObj.Reset(state)
            newIndex = PT1000s_Channels_indexes_SQL()
            newIndex.idx = i
            newIndex.array = self
            newData = T_Int32_SQL(pyObj[i])
            newIndex.data = newData
            self._children.append((newIndex, newData))

        pyObj.Reset(state)


class PT1000s_Raw_Data_elem_SQL(Base):
    __tablename__ = 'PT1000s_Raw_Data_elem'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PT1000s_Raw_Data_elem_SQL).filter(PT1000s_Raw_Data_elem_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PT1000s_Raw_Data_elem()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.vcc_volts.assignToASN1object(pyObj.vcc_volts)
        pyObj.Reset(state)
        self.pt1000.assignToASN1object(pyObj.pt1000)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_vcc_volts_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    vcc_volts = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_vcc_volts_iid])
    fk_pt1000_iid = Column(Integer, ForeignKey('T_Float.iid'), nullable=False)
    pt1000 = relationship(
        "T_Float_SQL",
        foreign_keys=[fk_pt1000_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.vcc_volts = T_Float_SQL(pyObj.vcc_volts)
        pyObj.Reset(state)
        self.pt1000 = T_Float_SQL(pyObj.pt1000)
        pyObj.Reset(state)


class SPI_ID_SQL(Base):
    __tablename__ = 'SPI_ID'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            SPI_ID_SQL).filter(SPI_ID_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = SPI_ID()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.bus.assignToASN1object(pyObj.bus)
        pyObj.Reset(state)
        self.cs.assignToASN1object(pyObj.cs)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_bus_iid = Column(Integer, ForeignKey('T_UInt8.iid'), nullable=False)
    bus = relationship(
        "T_UInt8_SQL",
        foreign_keys=[fk_bus_iid])
    fk_cs_iid = Column(Integer, ForeignKey('T_UInt8.iid'), nullable=False)
    cs = relationship(
        "T_UInt8_SQL",
        foreign_keys=[fk_cs_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.bus = T_UInt8_SQL(pyObj.bus)
        pyObj.Reset(state)
        self.cs = T_UInt8_SQL(pyObj.cs)
        pyObj.Reset(state)


class TC74s_All_Data_indexes_SQL(Base):
    __tablename__ = 'TC74s_All_Data_indexes'
    __table_args__ = (UniqueConstraint('idx', 'fk_TC74s_All_Data_iid'),)
    iid = Column(Integer, primary_key=True)
    idx = Column(Integer, CheckConstraint('idx>=0 AND idx<5'), nullable=False)
    fk_TC74s_All_Data_iid = Column(
        Integer,
        ForeignKey('TC74s_All_Data.iid'),
        nullable=False)
    fk_TC74s_All_Data_elem_iid = Column(
        Integer,
        ForeignKey('TC74s_All_Data_elem.iid'),
        nullable=False)
    array = relationship(
        "TC74s_All_Data_SQL",
        foreign_keys=[fk_TC74s_All_Data_iid],
        backref='arrIndexes_TC74s_All_Data')
    data = relationship(
        "TC74s_All_Data_elem_SQL",
        foreign_keys=[fk_TC74s_All_Data_elem_iid])

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

class TC74s_All_Data_SQL(Base):
    __tablename__ = 'TC74s_All_Data'
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            TC74s_All_Data_SQL).filter(TC74s_All_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = TC74s_All_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()

        for idx, idxObj in enumerate(self.arrIndexes_TC74s_All_Data):
            pyObj.Reset(state)
            idxObj.data.assignToASN1object(pyObj[idxObj.idx])
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        for c in self._children:
            session.add(c[0])
            session.add(c[1])
        session.commit()
        return self.iid

    def __init__(self, pyObj):
        self._children = []
        state = pyObj.GetState()
        for i in range(pyObj.GetLength()):
            pyObj.Reset(state)
            newIndex = TC74s_All_Data_indexes_SQL()
            newIndex.idx = i
            newIndex.array = self
            newData = TC74s_All_Data_elem_SQL(pyObj[i])
            newIndex.data = newData
            self._children.append((newIndex, newData))

        pyObj.Reset(state)


class IMU_All_Data_SQL(Base):
    __tablename__ = 'IMU_All_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            IMU_All_Data_SQL).filter(IMU_All_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = IMU_All_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.mgt_raw.assignToASN1object(pyObj.mgt_raw)
        pyObj.Reset(state)
        self.mgt_mgauss.assignToASN1object(pyObj.mgt_mgauss)
        pyObj.Reset(state)
        self.accel_raw.assignToASN1object(pyObj.accel_raw)
        pyObj.Reset(state)
        self.accel_mg.assignToASN1object(pyObj.accel_mg)
        pyObj.Reset(state)
        self.gyro_raw.assignToASN1object(pyObj.gyro_raw)
        pyObj.Reset(state)
        self.gyro_mdps.assignToASN1object(pyObj.gyro_mdps)
        pyObj.Reset(state)
        self.mgt_valid.assignToASN1object(pyObj.mgt_valid)
        pyObj.Reset(state)
        self.acc_valid.assignToASN1object(pyObj.acc_valid)
        pyObj.Reset(state)
        self.gyro_valid.assignToASN1object(pyObj.gyro_valid)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_mgt_raw_iid = Column(Integer, ForeignKey('MGT_Raw_Data.iid'), nullable=False)
    mgt_raw = relationship(
        "MGT_Raw_Data_SQL",
        foreign_keys=[fk_mgt_raw_iid])
    fk_mgt_mgauss_iid = Column(Integer, ForeignKey('MGT_MilliGauss_Data.iid'), nullable=False)
    mgt_mgauss = relationship(
        "MGT_MilliGauss_Data_SQL",
        foreign_keys=[fk_mgt_mgauss_iid])
    fk_accel_raw_iid = Column(Integer, ForeignKey('ACC_Raw_Data.iid'), nullable=False)
    accel_raw = relationship(
        "ACC_Raw_Data_SQL",
        foreign_keys=[fk_accel_raw_iid])
    fk_accel_mg_iid = Column(Integer, ForeignKey('ACC_MilliG_Data.iid'), nullable=False)
    accel_mg = relationship(
        "ACC_MilliG_Data_SQL",
        foreign_keys=[fk_accel_mg_iid])
    fk_gyro_raw_iid = Column(Integer, ForeignKey('GYRO_Raw_Data.iid'), nullable=False)
    gyro_raw = relationship(
        "GYRO_Raw_Data_SQL",
        foreign_keys=[fk_gyro_raw_iid])
    fk_gyro_mdps_iid = Column(Integer, ForeignKey('GYRO_MilliDPS_Data.iid'), nullable=False)
    gyro_mdps = relationship(
        "GYRO_MilliDPS_Data_SQL",
        foreign_keys=[fk_gyro_mdps_iid])
    fk_mgt_valid_iid = Column(Integer, ForeignKey('Content_Validity.iid'), nullable=False)
    mgt_valid = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_mgt_valid_iid])
    fk_acc_valid_iid = Column(Integer, ForeignKey('Content_Validity.iid'), nullable=False)
    acc_valid = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_acc_valid_iid])
    fk_gyro_valid_iid = Column(Integer, ForeignKey('Content_Validity.iid'), nullable=False)
    gyro_valid = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_gyro_valid_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.mgt_raw = MGT_Raw_Data_SQL(pyObj.mgt_raw)
        pyObj.Reset(state)
        self.mgt_mgauss = MGT_MilliGauss_Data_SQL(pyObj.mgt_mgauss)
        pyObj.Reset(state)
        self.accel_raw = ACC_Raw_Data_SQL(pyObj.accel_raw)
        pyObj.Reset(state)
        self.accel_mg = ACC_MilliG_Data_SQL(pyObj.accel_mg)
        pyObj.Reset(state)
        self.gyro_raw = GYRO_Raw_Data_SQL(pyObj.gyro_raw)
        pyObj.Reset(state)
        self.gyro_mdps = GYRO_MilliDPS_Data_SQL(pyObj.gyro_mdps)
        pyObj.Reset(state)
        self.mgt_valid = Content_Validity_SQL(pyObj.mgt_valid)
        pyObj.Reset(state)
        self.acc_valid = Content_Validity_SQL(pyObj.acc_valid)
        pyObj.Reset(state)
        self.gyro_valid = Content_Validity_SQL(pyObj.gyro_valid)
        pyObj.Reset(state)


class OBSW_DP_Data_imu_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_imu'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_imu_SQL).filter(OBSW_DP_Data_imu_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_imu()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('IMU_All_Data.iid'), nullable=False)
    data = relationship(
        "IMU_All_Data_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = IMU_All_Data_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class OBSW_DP_Data_tc74s_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_tc74s'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_tc74s_SQL).filter(OBSW_DP_Data_tc74s_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_tc74s()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('TC74s_All_Data.iid'), nullable=False)
    data = relationship(
        "TC74s_All_Data_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = TC74s_All_Data_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class PS_All_Data_SQL(Base):
    __tablename__ = 'PS_All_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PS_All_Data_SQL).filter(PS_All_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PS_All_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.calib.assignToASN1object(pyObj.calib)
        pyObj.Reset(state)
        self.raw.assignToASN1object(pyObj.raw)
        pyObj.Reset(state)
        self.processed.assignToASN1object(pyObj.processed)
        pyObj.Reset(state)
        self.validity.assignToASN1object(pyObj.validity)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_calib_iid = Column(Integer, ForeignKey('PS_Calibration_Data.iid'), nullable=False)
    calib = relationship(
        "PS_Calibration_Data_SQL",
        foreign_keys=[fk_calib_iid])
    fk_raw_iid = Column(Integer, ForeignKey('PS_Raw_Data.iid'), nullable=False)
    raw = relationship(
        "PS_Raw_Data_SQL",
        foreign_keys=[fk_raw_iid])
    fk_processed_iid = Column(Integer, ForeignKey('PS_Processed_Data.iid'), nullable=False)
    processed = relationship(
        "PS_Processed_Data_SQL",
        foreign_keys=[fk_processed_iid])
    fk_validity_iid = Column(Integer, ForeignKey('Content_Validity.iid'), nullable=False)
    validity = relationship(
        "Content_Validity_SQL",
        foreign_keys=[fk_validity_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.calib = PS_Calibration_Data_SQL(pyObj.calib)
        pyObj.Reset(state)
        self.raw = PS_Raw_Data_SQL(pyObj.raw)
        pyObj.Reset(state)
        self.processed = PS_Processed_Data_SQL(pyObj.processed)
        pyObj.Reset(state)
        self.validity = Content_Validity_SQL(pyObj.validity)
        pyObj.Reset(state)


class PT1000s_Raw_Data_indexes_SQL(Base):
    __tablename__ = 'PT1000s_Raw_Data_indexes'
    __table_args__ = (UniqueConstraint('idx', 'fk_PT1000s_Raw_Data_iid'),)
    iid = Column(Integer, primary_key=True)
    idx = Column(Integer, CheckConstraint('idx>=0 AND idx<6'), nullable=False)
    fk_PT1000s_Raw_Data_iid = Column(
        Integer,
        ForeignKey('PT1000s_Raw_Data.iid'),
        nullable=False)
    fk_PT1000s_Raw_Data_elem_iid = Column(
        Integer,
        ForeignKey('PT1000s_Raw_Data_elem.iid'),
        nullable=False)
    array = relationship(
        "PT1000s_Raw_Data_SQL",
        foreign_keys=[fk_PT1000s_Raw_Data_iid],
        backref='arrIndexes_PT1000s_Raw_Data')
    data = relationship(
        "PT1000s_Raw_Data_elem_SQL",
        foreign_keys=[fk_PT1000s_Raw_Data_elem_iid])

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

class PT1000s_Raw_Data_SQL(Base):
    __tablename__ = 'PT1000s_Raw_Data'
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PT1000s_Raw_Data_SQL).filter(PT1000s_Raw_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PT1000s_Raw_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()

        for idx, idxObj in enumerate(self.arrIndexes_PT1000s_Raw_Data):
            pyObj.Reset(state)
            idxObj.data.assignToASN1object(pyObj[idxObj.idx])
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        for c in self._children:
            session.add(c[0])
            session.add(c[1])
        session.commit()
        return self.iid

    def __init__(self, pyObj):
        self._children = []
        state = pyObj.GetState()
        for i in range(pyObj.GetLength()):
            pyObj.Reset(state)
            newIndex = PT1000s_Raw_Data_indexes_SQL()
            newIndex.idx = i
            newIndex.array = self
            newData = PT1000s_Raw_Data_elem_SQL(pyObj[i])
            newIndex.data = newData
            self._children.append((newIndex, newData))

        pyObj.Reset(state)


class OBSW_DP_Data_ps1_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_ps1'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_ps1_SQL).filter(OBSW_DP_Data_ps1_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_ps1()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('PS_All_Data.iid'), nullable=False)
    data = relationship(
        "PS_All_Data_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = PS_All_Data_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class OBSW_DP_Data_ps2_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_ps2'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_ps2_SQL).filter(OBSW_DP_Data_ps2_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_ps2()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('PS_All_Data.iid'), nullable=False)
    data = relationship(
        "PS_All_Data_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = PS_All_Data_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class PT1000s_All_Data_SQL(Base):
    __tablename__ = 'PT1000s_All_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            PT1000s_All_Data_SQL).filter(PT1000s_All_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = PT1000s_All_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.raw.assignToASN1object(pyObj.raw)
        pyObj.Reset(state)
        self.celsius.assignToASN1object(pyObj.celsius)
        pyObj.Reset(state)
        self.validity.assignToASN1object(pyObj.validity)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_raw_iid = Column(Integer, ForeignKey('PT1000s_Raw_Data.iid'), nullable=False)
    raw = relationship(
        "PT1000s_Raw_Data_SQL",
        foreign_keys=[fk_raw_iid])
    fk_celsius_iid = Column(Integer, ForeignKey('PT1000s_Celsius_Data.iid'), nullable=False)
    celsius = relationship(
        "PT1000s_Celsius_Data_SQL",
        foreign_keys=[fk_celsius_iid])
    fk_validity_iid = Column(Integer, ForeignKey('PT1000s_All_Data_validity.iid'), nullable=False)
    validity = relationship(
        "PT1000s_All_Data_validity_SQL",
        foreign_keys=[fk_validity_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.raw = PT1000s_Raw_Data_SQL(pyObj.raw)
        pyObj.Reset(state)
        self.celsius = PT1000s_Celsius_Data_SQL(pyObj.celsius)
        pyObj.Reset(state)
        self.validity = PT1000s_All_Data_validity_SQL(pyObj.validity)
        pyObj.Reset(state)


class OBSW_DP_Data_pt1000s_SQL(Base):
    __tablename__ = 'OBSW_DP_Data_pt1000s'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_pt1000s_SQL).filter(OBSW_DP_Data_pt1000s_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data_pt1000s()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.data.assignToASN1object(pyObj.data)
        pyObj.Reset(state)
        self.timestamp.assignToASN1object(pyObj.timestamp)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_data_iid = Column(Integer, ForeignKey('PT1000s_All_Data.iid'), nullable=False)
    data = relationship(
        "PT1000s_All_Data_SQL",
        foreign_keys=[fk_data_iid])
    fk_timestamp_iid = Column(Integer, ForeignKey('T_Double.iid'), nullable=False)
    timestamp = relationship(
        "T_Double_SQL",
        foreign_keys=[fk_timestamp_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.data = PT1000s_All_Data_SQL(pyObj.data)
        pyObj.Reset(state)
        self.timestamp = T_Double_SQL(pyObj.timestamp)
        pyObj.Reset(state)


class OBSW_DP_Data_SQL(Base):
    __tablename__ = 'OBSW_DP_Data'
    __table_args__ = (UniqueConstraint('iid'),)
    iid = Column(Integer, primary_key=True)

    @staticmethod
    def loadFromDB(session, iid):
        return session.query(
            OBSW_DP_Data_SQL).filter(OBSW_DP_Data_SQL.iid == iid).first()

    @property
    def asn1(self):
        if hasattr(self, "_cache"):
            return self._cache
        pyObj = OBSW_DP_Data()
        self.assignToASN1object(pyObj)
        self._cache = pyObj
        return pyObj

    def assignToASN1object(self, pyObj):
        state = pyObj.GetState()
        pyObj.Reset(state)
        self.gps.assignToASN1object(pyObj.gps)
        pyObj.Reset(state)
        self.imu.assignToASN1object(pyObj.imu)
        pyObj.Reset(state)
        self.tc74s.assignToASN1object(pyObj.tc74s)
        pyObj.Reset(state)
        self.pt1000s.assignToASN1object(pyObj.pt1000s)
        pyObj.Reset(state)
        self.ps1.assignToASN1object(pyObj.ps1)
        pyObj.Reset(state)
        self.ps2.assignToASN1object(pyObj.ps2)
        pyObj.Reset(state)
        self.heater1.assignToASN1object(pyObj.heater1)
        pyObj.Reset(state)
        self.heater2.assignToASN1object(pyObj.heater2)
        pyObj.Reset(state)
        self.anemometer.assignToASN1object(pyObj.anemometer)
        pyObj.Reset(state)

    def save(self, session):
        session.add(self)
        session.commit()
        return self.iid

    fk_gps_iid = Column(Integer, ForeignKey('OBSW_DP_Data_gps.iid'), nullable=False)
    gps = relationship(
        "OBSW_DP_Data_gps_SQL",
        foreign_keys=[fk_gps_iid])
    fk_imu_iid = Column(Integer, ForeignKey('OBSW_DP_Data_imu.iid'), nullable=False)
    imu = relationship(
        "OBSW_DP_Data_imu_SQL",
        foreign_keys=[fk_imu_iid])
    fk_tc74s_iid = Column(Integer, ForeignKey('OBSW_DP_Data_tc74s.iid'), nullable=False)
    tc74s = relationship(
        "OBSW_DP_Data_tc74s_SQL",
        foreign_keys=[fk_tc74s_iid])
    fk_pt1000s_iid = Column(Integer, ForeignKey('OBSW_DP_Data_pt1000s.iid'), nullable=False)
    pt1000s = relationship(
        "OBSW_DP_Data_pt1000s_SQL",
        foreign_keys=[fk_pt1000s_iid])
    fk_ps1_iid = Column(Integer, ForeignKey('OBSW_DP_Data_ps1.iid'), nullable=False)
    ps1 = relationship(
        "OBSW_DP_Data_ps1_SQL",
        foreign_keys=[fk_ps1_iid])
    fk_ps2_iid = Column(Integer, ForeignKey('OBSW_DP_Data_ps2.iid'), nullable=False)
    ps2 = relationship(
        "OBSW_DP_Data_ps2_SQL",
        foreign_keys=[fk_ps2_iid])
    fk_heater1_iid = Column(Integer, ForeignKey('OBSW_DP_Data_heater1.iid'), nullable=False)
    heater1 = relationship(
        "OBSW_DP_Data_heater1_SQL",
        foreign_keys=[fk_heater1_iid])
    fk_heater2_iid = Column(Integer, ForeignKey('OBSW_DP_Data_heater2.iid'), nullable=False)
    heater2 = relationship(
        "OBSW_DP_Data_heater2_SQL",
        foreign_keys=[fk_heater2_iid])
    fk_anemometer_iid = Column(Integer, ForeignKey('OBSW_DP_Data_anemometer.iid'), nullable=False)
    anemometer = relationship(
        "OBSW_DP_Data_anemometer_SQL",
        foreign_keys=[fk_anemometer_iid])

    def __init__(self, pyObj):
        state = pyObj.GetState()
        self.gps = OBSW_DP_Data_gps_SQL(pyObj.gps)
        pyObj.Reset(state)
        self.imu = OBSW_DP_Data_imu_SQL(pyObj.imu)
        pyObj.Reset(state)
        self.tc74s = OBSW_DP_Data_tc74s_SQL(pyObj.tc74s)
        pyObj.Reset(state)
        self.pt1000s = OBSW_DP_Data_pt1000s_SQL(pyObj.pt1000s)
        pyObj.Reset(state)
        self.ps1 = OBSW_DP_Data_ps1_SQL(pyObj.ps1)
        pyObj.Reset(state)
        self.ps2 = OBSW_DP_Data_ps2_SQL(pyObj.ps2)
        pyObj.Reset(state)
        self.heater1 = OBSW_DP_Data_heater1_SQL(pyObj.heater1)
        pyObj.Reset(state)
        self.heater2 = OBSW_DP_Data_heater2_SQL(pyObj.heater2)
        pyObj.Reset(state)
        self.anemometer = OBSW_DP_Data_anemometer_SQL(pyObj.anemometer)
        pyObj.Reset(state)

