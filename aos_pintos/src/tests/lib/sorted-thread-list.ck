# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(sorted-thread-list) begin
(sorted-thread-list) sorted index 4
(sorted-thread-list) end
EOF
pass;
