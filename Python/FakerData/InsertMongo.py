import imp
import time
from xmlrpc.client import _iso8601_format
import pymongo
from datetime import datetime
from faker import Faker

fake = Faker()
date = datetime.now()
mongo_conn = pymongo.MongoClient(host='localhost',port=27017)
db = mongo_conn.admin
db = mongo_conn.get_database("local")
col = db.get_collection("testdb")

for i in range(1000):
    col.insert_one({
        '_id':i,
        'name':fake.name(),
        'score':fake.numerify(),
        'credit':fake.numerify(),
        'ssn':fake.ssn(),
        'company':fake.company(),
        'job':fake.job(),
        'phone_number':fake.phone_number(),
        'birth_date':fake.date_time(),
        'address':fake.address(),
        'createdAt':time.asctime(time.localtime(time.time())),
        'expireTime': date.isoformat()
    })
