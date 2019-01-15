from orm import *


Database.connect(
    host='localhost',
    port=3306,
    user='mysql',
    password='mysql',
    database='pcaps'
)

class Request(Model):
    table = 'request'

    requestid = Field()
    clientip = Field()
    host = Field()

class Header(Model):
    table = 'header'

    requestid = Field()
    header_key = Field()
    header_value = Field()

