CREATE TABLE IF NOT EXISTS account_controller_bindings (
    action INTEGER PRIMARY KEY CHECK(action BETWEEN 0 AND 49),
    primary_button INTEGER NOT NULL CHECK(primary_button BETWEEN 0 AND 29),
    secondary_button INTEGER NOT NULL CHECK(secondary_button BETWEEN 0 AND 29),
    flags INTEGER NOT NULL CHECK(flags BETWEEN 0 AND 2)
) STRICT;
