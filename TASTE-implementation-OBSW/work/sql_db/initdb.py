from sqlalchemy import create_engine
from tasec_lab_b2space_model import Base
engine = create_engine(
    'postgresql+psycopg2://taste:tastedb@localhost/tasec_lab_b2space', echo=False)
Base.metadata.create_all(engine)
