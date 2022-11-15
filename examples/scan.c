#include <pg_query.h>
#include <stdio.h>
#include <stdlib.h>

#include "protobuf/pg_query.pb-c.h"

size_t testCount = 13;
const char* tests[] = {
  "SELECT 1",
  "SELECT \\s 1",
  "SELECT * FROM x WHERE z = 2",
  "SELECT 5.41414",
  "SELECT $1",
  "SELECT ?",
  "SELECT update AS left /* comment */ FROM between",
  "--test\nSELECT 1",
  "SELECT 999999999999999999999::numeric/1000000000000000000000",
  "SELECT 4790999999999999999999999999999999999999999999999999999999999999999999999999999999999999 * 9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999",
  //"WITH upsert AS (INSERT INTO schema_columns (table_id, name, position, data_type, default_value, not_null, first_snapshot_id) VALUES (?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?), (?, ?, ?, ?, ?, ?, ?) ON CONFLICT (table_id, name) WHERE invalidated_at_snapshot_id IS NULL DO UPDATE SET (position, data_type, default_value, not_null) = (EXCLUDED.position, EXCLUDED.data_type, EXCLUDED.default_value, EXCLUDED.not_null) RETURNING id, table_id, name), all_ids AS (SELECT id FROM upsert), cleanup AS (UPDATE schema_columns SET invalidated_at_snapshot_id = ? WHERE table_id = ? AND invalidated_at_snapshot_id IS NULL AND id NOT IN (SELECT id FROM all_ids)) SELECT * FROM upsert",
  "SELECT $foo$test$foo$, '123' FROM \"xy\", abc",
  "SELECT '/*not a comment*/', E'\\134', B'10', X'12', -Infinity, U&\"d!0061t!+000061\" UESCAPE '!'"
};

int main() {
  PgQueryScanResult result;
  PgQuery__ScanResult *scan_result;
  PgQuery__ScanToken *scan_token;
  const ProtobufCEnumValue *token_kind;
  const ProtobufCEnumValue *keyword_kind;
  size_t i;
  size_t j;

  for (i = 0; i < testCount; i++) {
    result = pg_query_scan(tests[i]);

    printf("%s\n", tests[i]);
    if (result.error) {
      printf("  error: %s at %d\n", result.error->message, result.error->cursorpos);
    } else {
      scan_result = pg_query__scan_result__unpack(NULL, result.pbuf.len, (void *) result.pbuf.data);

      printf("  version: %d, tokens: %ld, size: %d\n", scan_result->version, scan_result->n_tokens, result.pbuf.len);
      for (j = 0; j < scan_result->n_tokens; j++) {
        scan_token = scan_result->tokens[j];
        token_kind = protobuf_c_enum_descriptor_get_value(&pg_query__token__descriptor, scan_token->token);
        keyword_kind = protobuf_c_enum_descriptor_get_value(&pg_query__keyword_kind__descriptor, scan_token->keyword_kind);
        printf("  \"%.*s\" = [ %d, %d, %s, %s ]\n", scan_token->end - scan_token->start, &(tests[i][scan_token->start]), scan_token->start, scan_token->end, token_kind->name, keyword_kind->name);
      }

      pg_query__scan_result__free_unpacked(scan_result, NULL);
    }

    pg_query_free_scan_result(result);
  }

  // Optional, this ensures all memory is freed upon program exit (useful when running Valgrind)
  pg_query_exit();

  return 0;
}
