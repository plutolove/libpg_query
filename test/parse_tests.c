const char* tests[] = {
  "SELECT 1",
  "[{\"RawStmt\": {\"stmt\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 1}}, \"location\": 7}}, \"location\": 7}}], \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}}}]",
  "select sum(unique1) FILTER (WHERE unique1 IN (SELECT unique1 FROM onek where unique1 < 100)) FROM tenk1",
  "[{\"RawStmt\": {\"stmt\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"FuncCall\": {\"funcname\": [{\"String\": {\"str\": \"sum\"}}], \"args\": [{\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 11}}], \"agg_filter\": {\"SubLink\": {\"subLinkType\": \"ANY_SUBLINK\", \"testexpr\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 34}}, \"subselect\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 53}}, \"location\": 53}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"onek\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 66}}], \"whereClause\": {\"A_Expr\": {\"kind\": \"AEXPR_OP\", \"name\": [{\"String\": {\"str\": \"<\"}}], \"lexpr\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 77}}, \"rexpr\": {\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 100}}, \"location\": 87}}, \"location\": 85}}, \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}, \"location\": 42}}, \"location\": 7}}, \"location\": 7}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"tenk1\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 98}}], \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}}}]",
  "select sum(unique1) FILTER (WHERE unique1 = ANY (SELECT unique1 FROM onek where unique1 < 100)) FROM tenk1",
  "[{\"RawStmt\": {\"stmt\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"FuncCall\": {\"funcname\": [{\"String\": {\"str\": \"sum\"}}], \"args\": [{\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 11}}], \"agg_filter\": {\"SubLink\": {\"subLinkType\": \"ANY_SUBLINK\", \"testexpr\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 34}}, \"operName\": [{\"String\": {\"str\": \"=\"}}], \"subselect\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 56}}, \"location\": 56}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"onek\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 69}}], \"whereClause\": {\"A_Expr\": {\"kind\": \"AEXPR_OP\", \"name\": [{\"String\": {\"str\": \"<\"}}], \"lexpr\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"unique1\"}}], \"location\": 80}}, \"rexpr\": {\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 100}}, \"location\": 90}}, \"location\": 88}}, \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}, \"location\": 42}}, \"location\": 7}}, \"location\": 7}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"tenk1\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 101}}], \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}}}]",
  "CREATE FOREIGN TABLE films (code char(5) NOT NULL, title varchar(40) NOT NULL, did integer NOT NULL, date_prod date, kind varchar(10), len interval hour to minute) SERVER film_server;",
  "[{\"RawStmt\": {\"stmt\": {\"CreateForeignTableStmt\": {\"base\": {\"relation\": {\"relname\": \"films\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 21}, \"tableElts\": [{\"ColumnDef\": {\"colname\": \"code\", \"typeName\": {\"names\": [{\"String\": {\"str\": \"pg_catalog\"}}, {\"String\": {\"str\": \"bpchar\"}}], \"typmods\": [{\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 5}}, \"location\": 38}}], \"typemod\": -1, \"location\": 33}, \"is_local\": true, \"constraints\": [{\"Constraint\": {\"contype\": \"CONSTR_NOTNULL\", \"location\": 41}}], \"location\": 28}}, {\"ColumnDef\": {\"colname\": \"title\", \"typeName\": {\"names\": [{\"String\": {\"str\": \"pg_catalog\"}}, {\"String\": {\"str\": \"varchar\"}}], \"typmods\": [{\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 40}}, \"location\": 65}}], \"typemod\": -1, \"location\": 57}, \"is_local\": true, \"constraints\": [{\"Constraint\": {\"contype\": \"CONSTR_NOTNULL\", \"location\": 69}}], \"location\": 51}}, {\"ColumnDef\": {\"colname\": \"did\", \"typeName\": {\"names\": [{\"String\": {\"str\": \"pg_catalog\"}}, {\"String\": {\"str\": \"int4\"}}], \"typemod\": -1, \"location\": 83}, \"is_local\": true, \"constraints\": [{\"Constraint\": {\"contype\": \"CONSTR_NOTNULL\", \"location\": 91}}], \"location\": 79}}, {\"ColumnDef\": {\"colname\": \"date_prod\", \"typeName\": {\"names\": [{\"String\": {\"str\": \"date\"}}], \"typemod\": -1, \"location\": 111}, \"is_local\": true, \"location\": 101}}, {\"ColumnDef\": {\"colname\": \"kind\", \"typeName\": {\"names\": [{\"String\": {\"str\": \"pg_catalog\"}}, {\"String\": {\"str\": \"varchar\"}}], \"typmods\": [{\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 10}}, \"location\": 130}}], \"typemod\": -1, \"location\": 122}, \"is_local\": true, \"location\": 117}}, {\"ColumnDef\": {\"colname\": \"len\", \"typeName\": {\"names\": [{\"String\": {\"str\": \"pg_catalog\"}}, {\"String\": {\"str\": \"interval\"}}], \"typmods\": [{\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 3072}}, \"location\": 148}}], \"typemod\": -1, \"location\": 139}, \"is_local\": true, \"location\": 135}}], \"oncommit\": \"ONCOMMIT_NOOP\"}, \"servername\": \"film_server\"}}, \"stmt_len\": 182}}]",
  "CREATE FOREIGN TABLE ft1 () SERVER no_server",
  "[{\"RawStmt\": {\"stmt\": {\"CreateForeignTableStmt\": {\"base\": {\"relation\": {\"relname\": \"ft1\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 21}, \"oncommit\": \"ONCOMMIT_NOOP\"}, \"servername\": \"no_server\"}}}}]",
  "SELECT parse_ident(E'\"c\".X XXXX\002XXXXXX')",
  "[{\"RawStmt\": {\"stmt\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"FuncCall\": {\"funcname\": [{\"String\": {\"str\": \"parse_ident\"}}], \"args\": [{\"A_Const\": {\"val\": {\"String\": {\"str\": \"\\\"c\\\".X XXXX\\u0002XXXXXX\"}}, \"location\": 19}}], \"location\": 7}}, \"location\": 7}}], \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}}}]",
  "ALTER ROLE postgres LOGIN SUPERUSER PASSWORD 'xyz'",
  "[{\"RawStmt\": {\"stmt\": {\"AlterRoleStmt\": {\"role\": {\"roletype\": \"ROLESPEC_CSTRING\", \"rolename\": \"postgres\", \"location\": 11}, \"options\": [{\"DefElem\": {\"defname\": \"canlogin\", \"arg\": {\"Integer\": {\"ival\": 1}}, \"defaction\": \"DEFELEM_UNSPEC\", \"location\": 20}}, {\"DefElem\": {\"defname\": \"superuser\", \"arg\": {\"Integer\": {\"ival\": 1}}, \"defaction\": \"DEFELEM_UNSPEC\", \"location\": 26}}, {\"DefElem\": {\"defname\": \"password\", \"arg\": {\"A_Const\": {\"val\": {\"String\": {\"str\": \"xyz\"}}, \"location\": 45}}, \"defaction\": \"DEFELEM_UNSPEC\", \"location\": 36}}], \"action\": 1}}}}]",
  "ALTER ROLE postgres LOGIN SUPERUSER PASSWORD ?",
  "[{\"RawStmt\": {\"stmt\": {\"AlterRoleStmt\": {\"role\": {\"roletype\": \"ROLESPEC_CSTRING\", \"rolename\": \"postgres\", \"location\": 11}, \"options\": [{\"DefElem\": {\"defname\": \"canlogin\", \"arg\": {\"Integer\": {\"ival\": 1}}, \"defaction\": \"DEFELEM_UNSPEC\", \"location\": 20}}, {\"DefElem\": {\"defname\": \"superuser\", \"arg\": {\"Integer\": {\"ival\": 1}}, \"defaction\": \"DEFELEM_UNSPEC\", \"location\": 26}}, {\"DefElem\": {\"defname\": \"password\", \"arg\": {\"ParamRef\": {\"location\": 45}}, \"defaction\": \"DEFELEM_UNSPEC\", \"location\": 36}}], \"action\": 1}}}}]",
  "SELECT extract($1 FROM $2)",
  "[{\"RawStmt\": {\"stmt\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"FuncCall\": {\"funcname\": [{\"String\": {\"str\": \"pg_catalog\"}}, {\"String\": {\"str\": \"date_part\"}}], \"args\": [{\"ParamRef\": {\"number\": 1, \"location\": 15}}, {\"ParamRef\": {\"number\": 2, \"location\": 23}}], \"location\": 7}}, \"location\": 7}}], \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}}}]",
  "WITH a AS (SELECT * FROM x WHERE x.y = ? AND x.z = 1) SELECT * FROM a WHERE b = 5",
  "[{\"RawStmt\": {\"stmt\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"ColumnRef\": {\"fields\": [{\"A_Star\": {}}], \"location\": 61}}, \"location\": 61}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"a\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 68}}], \"whereClause\": {\"A_Expr\": {\"kind\": \"AEXPR_OP\", \"name\": [{\"String\": {\"str\": \"=\"}}], \"lexpr\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"b\"}}], \"location\": 76}}, \"rexpr\": {\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 5}}, \"location\": 80}}, \"location\": 78}}, \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"withClause\": {\"ctes\": [{\"CommonTableExpr\": {\"ctename\": \"a\", \"ctematerialized\": \"CTEMaterializeDefault\", \"ctequery\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"ColumnRef\": {\"fields\": [{\"A_Star\": {}}], \"location\": 18}}, \"location\": 18}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"x\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 25}}], \"whereClause\": {\"BoolExpr\": {\"boolop\": \"AND_EXPR\", \"args\": [{\"A_Expr\": {\"kind\": \"AEXPR_OP\", \"name\": [{\"String\": {\"str\": \"=\"}}], \"lexpr\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"x\"}}, {\"String\": {\"str\": \"y\"}}], \"location\": 33}}, \"rexpr\": {\"ParamRef\": {\"location\": 39}}, \"location\": 37}}, {\"A_Expr\": {\"kind\": \"AEXPR_OP\", \"name\": [{\"String\": {\"str\": \"=\"}}], \"lexpr\": {\"ColumnRef\": {\"fields\": [{\"String\": {\"str\": \"x\"}}, {\"String\": {\"str\": \"z\"}}], \"location\": 45}}, \"rexpr\": {\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 1}}, \"location\": 51}}, \"location\": 49}}], \"location\": 41}}, \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}, \"location\": 5}}]}, \"op\": \"SETOP_NONE\"}}}}]",
  "WITH w AS NOT MATERIALIZED (SELECT * FROM big_table) SELECT * FROM w LIMIT 1",
  "[{\"RawStmt\": {\"stmt\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"ColumnRef\": {\"fields\": [{\"A_Star\": {}}], \"location\": 60}}, \"location\": 60}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"w\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 67}}], \"limitCount\": {\"A_Const\": {\"val\": {\"Integer\": {\"ival\": 1}}, \"location\": 75}}, \"limitOption\": \"LIMIT_OPTION_COUNT\", \"withClause\": {\"ctes\": [{\"CommonTableExpr\": {\"ctename\": \"w\", \"ctematerialized\": \"CTEMaterializeNever\", \"ctequery\": {\"SelectStmt\": {\"targetList\": [{\"ResTarget\": {\"val\": {\"ColumnRef\": {\"fields\": [{\"A_Star\": {}}], \"location\": 35}}, \"location\": 35}}], \"fromClause\": [{\"RangeVar\": {\"relname\": \"big_table\", \"inh\": true, \"relpersistence\": \"p\", \"location\": 42}}], \"limitOption\": \"LIMIT_OPTION_DEFAULT\", \"op\": \"SETOP_NONE\"}}, \"location\": 5}}]}, \"op\": \"SETOP_NONE\"}}}}]"
};

size_t testsLength = __LINE__ - 4;
