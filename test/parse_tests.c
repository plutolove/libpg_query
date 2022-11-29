const char* tests[] = {
  "SELECT FALSE",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"A_Const\":{\"boolval\":{\"boolval\":false},\"location\":7}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT NULL",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"A_Const\":{\"isnull\":true,\"location\":7}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT 1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"A_Const\":{\"ival\":{\"ival\":1},\"location\":7}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT 1; SELECT 2",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"A_Const\":{\"ival\":{\"ival\":1},\"location\":7}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}},\"stmt_len\":8},{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"A_Const\":{\"ival\":{\"ival\":2},\"location\":17}},\"location\":17}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}},\"stmt_location\":9}]}",
  "select sum(unique1) FILTER (WHERE unique1 IN (SELECT unique1 FROM onek where unique1 < 100)) FROM tenk1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"FuncCall\":{\"funcname\":[{\"String\":{\"sval\":\"sum\"}}],\"args\":[{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":11}}],\"agg_filter\":{\"SubLink\":{\"subLinkType\":\"ANY_SUBLINK\",\"testexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":34}},\"subselect\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":53}},\"location\":53}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"onek\",\"inh\":true,\"relpersistence\":\"p\",\"location\":66}}],\"whereClause\":{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"\\u003c\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":77}},\"rexpr\":{\"A_Const\":{\"ival\":{\"ival\":100},\"location\":87}},\"location\":85}},\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}},\"location\":42}},\"funcformat\":\"COERCE_EXPLICIT_CALL\",\"location\":7}},\"location\":7}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"tenk1\",\"inh\":true,\"relpersistence\":\"p\",\"location\":98}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "select sum(unique1) FILTER (WHERE unique1 = ANY (SELECT unique1 FROM onek where unique1 < 100)) FROM tenk1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"FuncCall\":{\"funcname\":[{\"String\":{\"sval\":\"sum\"}}],\"args\":[{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":11}}],\"agg_filter\":{\"SubLink\":{\"subLinkType\":\"ANY_SUBLINK\",\"testexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":34}},\"operName\":[{\"String\":{\"sval\":\"=\"}}],\"subselect\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":56}},\"location\":56}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"onek\",\"inh\":true,\"relpersistence\":\"p\",\"location\":69}}],\"whereClause\":{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"\\u003c\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unique1\"}}],\"location\":80}},\"rexpr\":{\"A_Const\":{\"ival\":{\"ival\":100},\"location\":90}},\"location\":88}},\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}},\"location\":42}},\"funcformat\":\"COERCE_EXPLICIT_CALL\",\"location\":7}},\"location\":7}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"tenk1\",\"inh\":true,\"relpersistence\":\"p\",\"location\":101}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "CREATE FOREIGN TABLE films (code char(5) NOT NULL, title varchar(40) NOT NULL, did integer NOT NULL, date_prod date, kind varchar(10), len interval hour to minute) SERVER film_server;",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"CreateForeignTableStmt\":{\"base\":{\"relation\":{\"relname\":\"films\",\"inh\":true,\"relpersistence\":\"p\",\"location\":21},\"tableElts\":[{\"ColumnDef\":{\"colname\":\"code\",\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"bpchar\"}}],\"typmods\":[{\"A_Const\":{\"ival\":{\"ival\":5},\"location\":38}}],\"typemod\":-1,\"location\":33},\"is_local\":true,\"constraints\":[{\"Constraint\":{\"contype\":\"CONSTR_NOTNULL\",\"location\":41}}],\"location\":28}},{\"ColumnDef\":{\"colname\":\"title\",\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"varchar\"}}],\"typmods\":[{\"A_Const\":{\"ival\":{\"ival\":40},\"location\":65}}],\"typemod\":-1,\"location\":57},\"is_local\":true,\"constraints\":[{\"Constraint\":{\"contype\":\"CONSTR_NOTNULL\",\"location\":69}}],\"location\":51}},{\"ColumnDef\":{\"colname\":\"did\",\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"int4\"}}],\"typemod\":-1,\"location\":83},\"is_local\":true,\"constraints\":[{\"Constraint\":{\"contype\":\"CONSTR_NOTNULL\",\"location\":91}}],\"location\":79}},{\"ColumnDef\":{\"colname\":\"date_prod\",\"typeName\":{\"names\":[{\"String\":{\"sval\":\"date\"}}],\"typemod\":-1,\"location\":111},\"is_local\":true,\"location\":101}},{\"ColumnDef\":{\"colname\":\"kind\",\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"varchar\"}}],\"typmods\":[{\"A_Const\":{\"ival\":{\"ival\":10},\"location\":130}}],\"typemod\":-1,\"location\":122},\"is_local\":true,\"location\":117}},{\"ColumnDef\":{\"colname\":\"len\",\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"interval\"}}],\"typmods\":[{\"A_Const\":{\"ival\":{\"ival\":3072},\"location\":148}}],\"typemod\":-1,\"location\":139},\"is_local\":true,\"location\":135}}],\"oncommit\":\"ONCOMMIT_NOOP\"},\"servername\":\"film_server\"}},\"stmt_len\":182}]}",
  "CREATE FOREIGN TABLE ft1 () SERVER no_server",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"CreateForeignTableStmt\":{\"base\":{\"relation\":{\"relname\":\"ft1\",\"inh\":true,\"relpersistence\":\"p\",\"location\":21},\"oncommit\":\"ONCOMMIT_NOOP\"},\"servername\":\"no_server\"}}}]}",
  "SELECT parse_ident(E'\"c\".X XXXX\002XXXXXX')",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"FuncCall\":{\"funcname\":[{\"String\":{\"sval\":\"parse_ident\"}}],\"args\":[{\"A_Const\":{\"sval\":{\"sval\":\"\\\"c\\\".X XXXX\\u0002XXXXXX\"},\"location\":19}}],\"funcformat\":\"COERCE_EXPLICIT_CALL\",\"location\":7}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "ALTER ROLE postgres LOGIN SUPERUSER PASSWORD 'xyz'",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"AlterRoleStmt\":{\"role\":{\"roletype\":\"ROLESPEC_CSTRING\",\"rolename\":\"postgres\",\"location\":11},\"options\":[{\"DefElem\":{\"defname\":\"canlogin\",\"arg\":{\"Boolean\":{\"boolval\":true}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":20}},{\"DefElem\":{\"defname\":\"superuser\",\"arg\":{\"Boolean\":{\"boolval\":true}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":26}},{\"DefElem\":{\"defname\":\"password\",\"arg\":{\"String\":{\"sval\":\"xyz\"}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":36}}],\"action\":1}}}]}",
  "SELECT extract($1 FROM $2)",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"FuncCall\":{\"funcname\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"extract\"}}],\"args\":[{\"ParamRef\":{\"number\":1,\"location\":15}},{\"ParamRef\":{\"number\":2,\"location\":23}}],\"funcformat\":\"COERCE_SQL_SYNTAX\",\"location\":7}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "WITH w AS NOT MATERIALIZED (SELECT * FROM big_table) SELECT * FROM w LIMIT 1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"A_Star\":{}}],\"location\":60}},\"location\":60}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"w\",\"inh\":true,\"relpersistence\":\"p\",\"location\":67}}],\"limitCount\":{\"A_Const\":{\"ival\":{\"ival\":1},\"location\":75}},\"limitOption\":\"LIMIT_OPTION_COUNT\",\"withClause\":{\"ctes\":[{\"CommonTableExpr\":{\"ctename\":\"w\",\"ctematerialized\":\"CTEMaterializeNever\",\"ctequery\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"A_Star\":{}}],\"location\":35}},\"location\":35}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"big_table\",\"inh\":true,\"relpersistence\":\"p\",\"location\":42}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}},\"location\":5}}]},\"op\":\"SETOP_NONE\"}}}]}",
  "CREATE USER test PASSWORD $1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"CreateRoleStmt\":{\"stmt_type\":\"ROLESTMT_USER\",\"role\":\"test\",\"options\":[{\"DefElem\":{\"defname\":\"password\",\"arg\":{\"ParamRef\":{\"number\":1,\"location\":26}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":17}}]}}}]}",
  "ALTER USER test ENCRYPTED PASSWORD $2",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"AlterRoleStmt\":{\"role\":{\"roletype\":\"ROLESPEC_CSTRING\",\"rolename\":\"test\",\"location\":11},\"options\":[{\"DefElem\":{\"defname\":\"password\",\"arg\":{\"ParamRef\":{\"number\":2,\"location\":35}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":16}}],\"action\":1}}}]}",
  "SET SCHEMA $3",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"VariableSetStmt\":{\"kind\":\"VAR_SET_VALUE\",\"name\":\"search_path\",\"args\":[{\"ParamRef\":{\"number\":3,\"location\":11}}]}}}]}",
  "SET ROLE $4",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"VariableSetStmt\":{\"kind\":\"VAR_SET_VALUE\",\"name\":\"role\",\"args\":[{\"ParamRef\":{\"number\":4,\"location\":9}}]}}}]}",
  "SET SESSION AUTHORIZATION $5",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"VariableSetStmt\":{\"kind\":\"VAR_SET_VALUE\",\"name\":\"session_authorization\",\"args\":[{\"ParamRef\":{\"number\":5,\"location\":26}}]}}}]}",
  "SELECT EXTRACT($1 FROM TIMESTAMP $2)",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"FuncCall\":{\"funcname\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"extract\"}}],\"args\":[{\"ParamRef\":{\"number\":1,\"location\":15}},{\"TypeCast\":{\"arg\":{\"ParamRef\":{\"number\":2,\"location\":33}},\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"timestamp\"}}],\"typemod\":-1,\"location\":23},\"location\":-1}}],\"funcformat\":\"COERCE_SQL_SYNTAX\",\"location\":7}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT DATE $1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"TypeCast\":{\"arg\":{\"ParamRef\":{\"number\":1,\"location\":12}},\"typeName\":{\"names\":[{\"String\":{\"sval\":\"date\"}}],\"typemod\":-1,\"location\":7},\"location\":-1}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT INTERVAL $1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"TypeCast\":{\"arg\":{\"ParamRef\":{\"number\":1,\"location\":16}},\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"interval\"}}],\"typemod\":-1,\"location\":7},\"location\":-1}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT INTERVAL $1 YEAR",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"TypeCast\":{\"arg\":{\"ParamRef\":{\"number\":1,\"location\":16}},\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"interval\"}}],\"typmods\":[{\"A_Const\":{\"ival\":{\"ival\":4},\"location\":19}}],\"typemod\":-1,\"location\":7},\"location\":-1}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT INTERVAL (6) $1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"TypeCast\":{\"arg\":{\"ParamRef\":{\"number\":1,\"location\":20}},\"typeName\":{\"names\":[{\"String\":{\"sval\":\"pg_catalog\"}},{\"String\":{\"sval\":\"interval\"}}],\"typmods\":[{\"A_Const\":{\"ival\":{\"ival\":32767},\"location\":-1}},{\"A_Const\":{\"ival\":{\"ival\":6},\"location\":17}}],\"typemod\":-1,\"location\":7},\"location\":-1}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SET search_path = $1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"VariableSetStmt\":{\"kind\":\"VAR_SET_VALUE\",\"name\":\"search_path\",\"args\":[{\"ParamRef\":{\"number\":1,\"location\":18}}]}}}]}",
  "ALTER ROLE postgres LOGIN SUPERUSER PASSWORD $1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"AlterRoleStmt\":{\"role\":{\"roletype\":\"ROLESPEC_CSTRING\",\"rolename\":\"postgres\",\"location\":11},\"options\":[{\"DefElem\":{\"defname\":\"canlogin\",\"arg\":{\"Boolean\":{\"boolval\":true}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":20}},{\"DefElem\":{\"defname\":\"superuser\",\"arg\":{\"Boolean\":{\"boolval\":true}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":26}},{\"DefElem\":{\"defname\":\"password\",\"arg\":{\"ParamRef\":{\"number\":1,\"location\":45}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":36}}],\"action\":1}}}]}",
  "WITH a AS (SELECT * FROM x WHERE x.y = $1 AND x.z = 1) SELECT * FROM a WHERE b = 5",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"A_Star\":{}}],\"location\":62}},\"location\":62}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"a\",\"inh\":true,\"relpersistence\":\"p\",\"location\":69}}],\"whereClause\":{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"=\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"b\"}}],\"location\":77}},\"rexpr\":{\"A_Const\":{\"ival\":{\"ival\":5},\"location\":81}},\"location\":79}},\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"withClause\":{\"ctes\":[{\"CommonTableExpr\":{\"ctename\":\"a\",\"ctematerialized\":\"CTEMaterializeDefault\",\"ctequery\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"A_Star\":{}}],\"location\":18}},\"location\":18}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"x\",\"inh\":true,\"relpersistence\":\"p\",\"location\":25}}],\"whereClause\":{\"BoolExpr\":{\"boolop\":\"AND_EXPR\",\"args\":[{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"=\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"x\"}},{\"String\":{\"sval\":\"y\"}}],\"location\":33}},\"rexpr\":{\"ParamRef\":{\"number\":1,\"location\":39}},\"location\":37}},{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"=\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"x\"}},{\"String\":{\"sval\":\"z\"}}],\"location\":46}},\"rexpr\":{\"A_Const\":{\"ival\":{\"ival\":1},\"location\":52}},\"location\":50}}],\"location\":42}},\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}},\"location\":5}}]},\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT count(*) from testjsonb  WHERE j->'array' ? 'bar'",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"FuncCall\":{\"funcname\":[{\"String\":{\"sval\":\"count\"}}],\"agg_star\":true,\"funcformat\":\"COERCE_EXPLICIT_CALL\",\"location\":7}},\"location\":7}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"testjsonb\",\"inh\":true,\"relpersistence\":\"p\",\"location\":21}}],\"whereClause\":{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"?\"}}],\"lexpr\":{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"-\\u003e\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"j\"}}],\"location\":38}},\"rexpr\":{\"A_Const\":{\"sval\":{\"sval\":\"array\"},\"location\":41}},\"location\":39}},\"rexpr\":{\"A_Const\":{\"sval\":{\"sval\":\"bar\"},\"location\":51}},\"location\":49}},\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT DISTINCT a FROM b",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"distinctClause\":[{}],\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"a\"}}],\"location\":16}},\"location\":16}}],\"fromClause\":[{\"RangeVar\":{\"relname\":\"b\",\"inh\":true,\"relpersistence\":\"p\",\"location\":23}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT * FROM generate_series(1, 2)",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"ColumnRef\":{\"fields\":[{\"A_Star\":{}}],\"location\":7}},\"location\":7}}],\"fromClause\":[{\"RangeFunction\":{\"functions\":[{\"List\":{\"items\":[{\"FuncCall\":{\"funcname\":[{\"String\":{\"sval\":\"generate_series\"}}],\"args\":[{\"A_Const\":{\"ival\":{\"ival\":1},\"location\":30}},{\"A_Const\":{\"ival\":{\"ival\":2},\"location\":33}}],\"funcformat\":\"COERCE_EXPLICIT_CALL\",\"location\":14}},{}]}}]}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "SELECT 1 + 1",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"SelectStmt\":{\"targetList\":[{\"ResTarget\":{\"val\":{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"+\"}}],\"lexpr\":{\"A_Const\":{\"ival\":{\"ival\":1},\"location\":7}},\"rexpr\":{\"A_Const\":{\"ival\":{\"ival\":1},\"location\":11}},\"location\":9}},\"location\":7}}],\"limitOption\":\"LIMIT_OPTION_DEFAULT\",\"op\":\"SETOP_NONE\"}}}]}",
  "COPY vistest FROM stdin FREEZE CSV",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"CopyStmt\":{\"relation\":{\"relname\":\"vistest\",\"inh\":true,\"relpersistence\":\"p\",\"location\":5},\"is_from\":true,\"options\":[{\"DefElem\":{\"defname\":\"freeze\",\"arg\":{\"Boolean\":{\"boolval\":true}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":24}},{\"DefElem\":{\"defname\":\"format\",\"arg\":{\"String\":{\"sval\":\"csv\"}},\"defaction\":\"DEFELEM_UNSPEC\",\"location\":31}}]}}}]}",
  "MERGE into measurement m USING new_measurement nm ON (m.city_id = nm.city_id and m.logdate=nm.logdate) WHEN MATCHED AND nm.peaktemp IS NULL THEN DELETE WHEN MATCHED THEN UPDATE SET peaktemp = greatest(m.peaktemp, nm.peaktemp), unitsales = m.unitsales + coalesce(nm.unitsales, 0) WHEN NOT MATCHED THEN INSERT (city_id, logdate, peaktemp, unitsales) VALUES (city_id, logdate, peaktemp, unitsales)",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"MergeStmt\":{\"relation\":{\"relname\":\"measurement\",\"inh\":true,\"relpersistence\":\"p\",\"alias\":{\"aliasname\":\"m\"},\"location\":11},\"sourceRelation\":{\"RangeVar\":{\"relname\":\"new_measurement\",\"inh\":true,\"relpersistence\":\"p\",\"alias\":{\"aliasname\":\"nm\"},\"location\":31}},\"joinCondition\":{\"BoolExpr\":{\"boolop\":\"AND_EXPR\",\"args\":[{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"=\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"m\"}},{\"String\":{\"sval\":\"city_id\"}}],\"location\":54}},\"rexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"nm\"}},{\"String\":{\"sval\":\"city_id\"}}],\"location\":66}},\"location\":64}},{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"=\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"m\"}},{\"String\":{\"sval\":\"logdate\"}}],\"location\":81}},\"rexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"nm\"}},{\"String\":{\"sval\":\"logdate\"}}],\"location\":91}},\"location\":90}}],\"location\":77}},\"mergeWhenClauses\":[{\"MergeWhenClause\":{\"matched\":true,\"commandType\":\"CMD_DELETE\",\"override\":\"OVERRIDING_NOT_SET\",\"condition\":{\"NullTest\":{\"arg\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"nm\"}},{\"String\":{\"sval\":\"peaktemp\"}}],\"location\":120}},\"nulltesttype\":\"IS_NULL\",\"location\":132}}}},{\"MergeWhenClause\":{\"matched\":true,\"commandType\":\"CMD_UPDATE\",\"override\":\"OVERRIDING_NOT_SET\",\"targetList\":[{\"ResTarget\":{\"name\":\"peaktemp\",\"val\":{\"MinMaxExpr\":{\"op\":\"IS_GREATEST\",\"args\":[{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"m\"}},{\"String\":{\"sval\":\"peaktemp\"}}],\"location\":201}},{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"nm\"}},{\"String\":{\"sval\":\"peaktemp\"}}],\"location\":213}}],\"location\":192}},\"location\":181}},{\"ResTarget\":{\"name\":\"unitsales\",\"val\":{\"A_Expr\":{\"kind\":\"AEXPR_OP\",\"name\":[{\"String\":{\"sval\":\"+\"}}],\"lexpr\":{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"m\"}},{\"String\":{\"sval\":\"unitsales\"}}],\"location\":239}},\"rexpr\":{\"CoalesceExpr\":{\"args\":[{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"nm\"}},{\"String\":{\"sval\":\"unitsales\"}}],\"location\":262}},{\"A_Const\":{\"ival\":{\"ival\":0},\"location\":276}}],\"location\":253}},\"location\":251}},\"location\":227}}]}},{\"MergeWhenClause\":{\"commandType\":\"CMD_INSERT\",\"override\":\"OVERRIDING_NOT_SET\",\"targetList\":[{\"ResTarget\":{\"name\":\"city_id\",\"location\":309}},{\"ResTarget\":{\"name\":\"logdate\",\"location\":318}},{\"ResTarget\":{\"name\":\"peaktemp\",\"location\":327}},{\"ResTarget\":{\"name\":\"unitsales\",\"location\":337}}],\"values\":[{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"city_id\"}}],\"location\":356}},{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"logdate\"}}],\"location\":365}},{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"peaktemp\"}}],\"location\":374}},{\"ColumnRef\":{\"fields\":[{\"String\":{\"sval\":\"unitsales\"}}],\"location\":384}}]}}]}}}]}",
  "ALTER TABLE ALL IN TABLESPACE foo OWNED BY bar, quux SET TABLESPACE fred NOWAIT",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"AlterTableMoveAllStmt\":{\"orig_tablespacename\":\"foo\",\"objtype\":\"OBJECT_TABLE\",\"roles\":[{\"RoleSpec\":{\"roletype\":\"ROLESPEC_CSTRING\",\"rolename\":\"bar\",\"location\":43}},{\"RoleSpec\":{\"roletype\":\"ROLESPEC_CSTRING\",\"rolename\":\"quux\",\"location\":48}}],\"new_tablespacename\":\"fred\",\"nowait\":true}}}]}",
  "CREATE PUBLICATION foo FOR TABLES IN SCHEMA bar",
  "{\"version\":150001,\"stmts\":[{\"stmt\":{\"CreatePublicationStmt\":{\"pubname\":\"foo\",\"pubobjects\":[{\"PublicationObjSpec\":{\"pubobjtype\":\"PUBLICATIONOBJ_TABLES_IN_SCHEMA\",\"name\":\"bar\",\"location\":44}}]}}}]}",
};

size_t testsLength = __LINE__ - 4;
