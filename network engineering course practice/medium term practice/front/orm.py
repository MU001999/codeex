import MySQLdb as mdb


class Field(object):
    name = None

    def __eq__(self, other):
        return (self.name, "=", other)

    def __ne__(self, other):
        return (self.name, "<>", other)

    def __lt__(self, other):
        return (self.name, "<", other)

    def __le__(self, other):
        return (self.name, "<=", other)

    def __gt__(self, other):
        return (self.name, ">", other)

    def __ge__(self, other):
        return (self.name, ">=", other)


class Expr(object):
    def __init__(self, model, args, kwargs):
        self.model = model
        self.params = [arg[2] for arg in args]
        equations = [' '.join([arg[0], arg[1], '%s']) for arg in args]
        self.params.extend(kwargs.values())
        equations.extend([key + ' = %s' for key in kwargs.keys()])
        self.where_expr = 'where ' + ' and '.join(equations) if len(equations) > 0 else ''

    def update(self, **kwargs):
        keys = []
        params = []
        for key, val in kwargs.iteritems():
            if val is None or key not in self.model.fields:
                continue
            keys.append(key)
            params.append(val)
        params.extend(self.params)
        sql = 'update %s set %s %s;' % (
            self.model.table,
            ', '.join([key + ' = %s' for key in keys]),
            self.where_expr
        )
        return Database.execute(sql, params)

    def limit(self, rows, offset=None):
        self.where_expr += 'limit %s%s' % (
            '%s, ' % offset if offset is not None else '',
            rows
        )
        return self

    def select(self):
        sql = 'select %s from %s %s;' % (
            ', '.join(self.model.fields.keys()),
            self.model.table,
            self.where_expr
        )
        for row in Database.execute(sql, self.params).fetchall():
            instance = self.model()
            for index, val in enumerate(row):
                setattr(instance, self.model.fields.keys()[index], val)
            yield instance

    def count(self):
        sql = 'select count(*) from %s %s;' % (
            self.model.table,
            self.where_expr
        )
        cnt, = Database.execute(sql, self.params).fetchone()
        return cnt


class ModelMetaclass(type):
    table = None

    def __init__(cls, name, bases, attrs):
        super(ModelMetaclass, cls).__init__(name, bases, attrs)
        cls.fields = dict()
        for key, val in cls.__dict__.iteritems():
            if isinstance(val, Field):
                val.name = key
                cls.fields[key] = val


class Model(object):
    __metaclass__ = ModelMetaclass

    def save(self):
        sql = 'insert ignore into %s(%s) values (%s);' % (
            self.table,
            ', '.join(self.__dict__.keys()),
            ', '.join(['%s'] * len(self.__dict__))
        )
        return Database.execute(sql, self.__dict__.values())

    @classmethod
    def where(cls, *args, **kwargs):
        return Expr(cls, args, kwargs)


class Database(object):
    autocommit = True
    connection = None
    db_config = dict()

    @classmethod
    def connect(cls, **db_config):
        cls.connection = mdb.connect(
            host=db_config.get('host', 'localhost'),
            port=int(db_config.get('port', 2222)),
            user=db_config.get('user', 'mysql'),
            passwd=db_config.get('password', 'mysql'),
            db=db_config.get('database', 'test'),
            charset=db_config.get('charset', 'utf8')
        )
        cls.connection.autocommit(cls.autocommit)
        cls.db_config.update(db_config)

    @classmethod
    def get_connection(cls):
        if not cls.connection or not cls.connection.open:
            cls.connect(**cls.db_config)
        try:
            cls.connection.ping()
        except mdb.OperationalError:
            cls.connect(**cls.db_config)
        return cls.connection

    @classmethod
    def execute(cls, *args):
        cursor = cls.get_connection().cursor()
        cursor.execute(*args)
        return cursor

    def __del__(self):
        if self.connection and self.conn.open:
            self.connection.close()


def execute_raw_sql(sql, params=None):
    return Database.execute(sql, params) if params else Database.execute(sql)
