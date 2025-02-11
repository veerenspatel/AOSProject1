# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(unsorted-thread-list) begin
(unsorted-thread-list) sorted index 6
(unsorted-thread-list) end
EOF
pass;
